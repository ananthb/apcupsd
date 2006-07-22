/* Copyright (C) 1995, 1996, 1997, 1998 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#ifdef HAVE_CYGWIN

#include <sys/types.h>

/* Mode bits for `msgget', `semget', and `shmget'.  */
#define IPC_CREAT       01000           /* Create key if key does not exist. */
#define IPC_EXCL        02000           /* Fail if key exists.  */
#define IPC_NOWAIT      04000           /* Return error on wait.  */

/* Control commands for `msgctl', `semctl', and `shmctl'.  */
#define IPC_RMID        0               /* Remove identifier.  */
#define IPC_SET         1               /* Set `ipc_perm' options.  */
#define IPC_STAT        2               /* Get `ipc_perm' options.  */
#define IPC_INFO        3               /* See ipcs.  */

/* Special key values.  */
#define IPC_PRIVATE     ((__key_t) 0)   /* Private key.  */


/* Data structure used to pass permission information to IPC operations.  */
struct ipc_perm
  {
    __key_t __key;                      /* Key.  */
    unsigned short int uid;             /* Owner's user ID.  */
    unsigned short int gid;             /* Owner's group ID.  */
    unsigned short int cuid;            /* Creator's user ID.  */
    unsigned short int cgid;            /* Creator's group ID.  */
    unsigned short int mode;            /* Read/write permission.  */
    unsigned short int __seq;           /* Sequence number.  */
  };
   
/* Shared memory control operation.  */
extern int shmctl (int __shmid, int __cmd, void *__buf);

/* Get shared memory segment.  */
extern int shmget (key_t __key, int __size, int __shmflg);

/* Attach shared memory segment.  */
extern void *shmat (int __shmid, __const void *__shmaddr, int __shmflg);

/* Detach shared memory segment.  */
extern int shmdt (const void *__shmaddr);

#endif /* HAVE_CYGWIN */ 