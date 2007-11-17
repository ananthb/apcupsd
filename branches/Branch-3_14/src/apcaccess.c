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

extern const char *net_errmsg;

/* Default values for contacting daemon */
static const char *host = "localhost";
static int port = NISPORT;

/* Get and print status from apcupsd NIS server */
static void do_pthreads_status(const char *host, int port)
{
   int sockfd, n;
   char recvline[MAXSTRING + 1];

   if ((sockfd = net_open(host, NULL, port)) < 0)
      Error_abort0(net_errmsg);

   net_send(sockfd, "status", 6);

   while ((n = net_recv(sockfd, recvline, sizeof(recvline))) > 0) {
      recvline[n] = 0;
      fputs(recvline, stdout);
   }

   if (n < 0)
      Error_abort0(net_errmsg);

   net_close(sockfd);
}

/*********************************************************************/

#if defined(HAVE_MINGW)
#undef main
#endif

int main(int argc, char **argv)
{
   int mode = 0;

#ifdef HAVE_MINGW
   WSA_Init();                   /* init MS networking */
#endif

   if (argc < 2) {
      /* Assume user wants "status" */
      mode = 2;
   } else {
      if (strcmp(argv[1], "status") == 0) {
         mode = 2;
      } else {
         Error_abort1(_("Unknown command %s\n"), argv[1]);
      }
   }

   if (argc > 2) {                 /* assume host:port */
      char *p;

      host = argv[2];
      p = strchr(host, ':');
      if (p) {
         *p++ = 0;
         port = atoi(p);
      }
   }

   if (!*host || strcmp(host, "0.0.0.0") == 0)
      host = "localhost";

   switch (mode) {
   case 2:       /* status */
      do_pthreads_status(host, port);
      break;

   default:
      Error_abort0(_("Strange mode\n"));
   }

   return 0;
}