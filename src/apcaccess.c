/*
 * apcaccess.c
 *
 * Text based IPC management tool for apcupsd package.
 */

/*
 * Copyright (C) 2000-2006 Kern Sibbald
 * Copyright (C) 1996-99 Andre M. Hedrick <andre@suse.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2 of the GNU General
 * Public License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 * MA 02111-1307, USA.
 */

#include "apc.h"

/* Get and print status from apcupsd NIS server */
static int do_pthreads_status(const char *host, int port, const char *par)
{
   int sockfd, n;
   char recvline[MAXSTRING + 1];

   if ((sockfd = net_open(host, NULL, port)) < 0) {
      fprintf(stderr, "Error contacting apcupsd @ %s:%d: %s\n",
         host, port, strerror(-sockfd));
      return 1;
   }

   net_send(sockfd, "status", 6);

   while ((n = net_recv(sockfd, recvline, sizeof(recvline))) > 0) {
      recvline[n] = 0;
      if (par) {
        char *line;
        char *r = NULL;
        char *var;

        var = strtok_r(recvline, ":", &r);
        if (!var)
           continue;
        line = recvline + strlen(var) + 1;
        if ((r = strchr( var, ' ' )))
           *r = '\0';
        if (!strcmp(par, var)) {
           while(*line && *line == ' ')
              line++;
           fputs(line, stdout);
           par = NULL;
           break;
        }
        continue;
      }
      fputs(recvline, stdout);
   }

   if (n < 0) {
      fprintf(stderr, "Error reading status from apcupsd @ %s:%d: %s\n",
         host, port, strerror(-n));
      net_close(sockfd);
      return 1;
   }

   net_close(sockfd);
   return par ? 2 : 0;
}

/*********************************************************************/

#if defined(HAVE_MINGW)
#undef main
#endif

void usage()
{
   fprintf(stderr, 
      "usage: apcaccess [-f <config-file>] [-h <host>[:<port>]] "
                       "[-p <pattern>] [<command>] [<host>[:<port>]]\n");
   
}

int main(int argc, char **argv)
{
   const char *par = NULL;
   char *cfgfile = NULL;
   char DEFAULT_HOST[] = "localhost";
   char *host = NULL;
   const char *cmd = "status";
   int port = NISPORT;
   FILE *cfg;

#ifdef HAVE_MINGW
   WSA_Init();                   /* init MS networking */
#endif

   // Process standard options
   char ch;
   while ((ch = getopt(argc, argv, "f:h:p:")) != -1)
   {
      switch (ch)
      {
      case 'f':
         cfgfile = optarg;
         break;
      case 'h':
         host = optarg;
         break;
      case 'p':
         par = optarg;
         break;
      case '?':
      default:
         usage();
         return 1;
      }
   }

   // Default cfgfile if not provided on command line
   // Remember if we defaulted so we know later if conf failure is fatal
   bool fatal = cfgfile != NULL;
   if (!cfgfile)
      cfgfile = APCCONF;

   // Parse conf file for defaults
   if ((cfg = fopen(cfgfile, "r")))
   {
      fclose(cfg);
      UPSINFO ups;
      memset(&ups, 0, sizeof(UPSINFO));
      init_ups_struct(&ups);
      check_for_config(&ups, cfgfile);
      port = ups.statusport;
      if (!host) // Don't override command line -h
         host = ups.nisip;
   }
   else if (fatal)
   {
      // Failure to find explicitly specified conf file is fatal
      fprintf(stderr, "Unable to open config file '%s'\n", cfgfile);
      return 2;
   }

   // Remaining non-option arguments are optional command and host:port
   // These are from legacy apcaccess syntax.  They take priority over
   // the default from the conf file and/or switch values.
   int optleft = argc - optind;
   if (optleft >= 1)
      cmd = argv[optind];
   if (optleft >= 2)
      host = argv[optind + 1];

   // If still no host, use default
   if (!host)
      host = DEFAULT_HOST;

   // Separate host and port
   char *p = strchr(host, ':');
   if (p) {
      *p++ = 0;
      port = atoi(p);
   }

   // Translate host of 0.0.0.0 to localhost
   // This is due to NISIP in apcupsd.conf being 0.0.0.0 for listening on all
   // interfaces. In that case just use loopback.
   if (!strcmp(host, "0.0.0.0"))
      host = DEFAULT_HOST;

   if (!strcmp(cmd, "status"))
   {
      return do_pthreads_status(host, port, par);
   }
   else
   {
      fprintf(stderr, "Unknown command %s\n", cmd);
      usage();
      return 1;
   }
}
