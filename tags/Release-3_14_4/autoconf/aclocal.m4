# Search path for a program which passes the given test.
# Ulrich Drepper <drepper@cygnus.com>, 1996.
#
# This file can be copied and used freely without restrictions.  It can
# be used in projects which are not available under the GNU Public License
# but which still want to provide support for the GNU gettext functionality.
# Please note that the actual code is *not* freely available.

# Define a conditional.

AC_DEFUN(AM_CONDITIONAL,
[AC_SUBST($1_TRUE)
AC_SUBST($1_FALSE)
if $2; then
  $1_TRUE=
  $1_FALSE='#'
else
  $1_TRUE='#'
  $1_FALSE=
fi])


AC_DEFUN(AC_TYPE_SOCKETLEN_T,
[ dnl check for socklen_t (in Unix98)
  AC_MSG_CHECKING(for socklen_t)
  AC_TRY_COMPILE([
  #include <sys/types.h>
  #include <sys/socket.h>
  socklen_t x;
  ],[],[AC_MSG_RESULT(yes)],[
  AC_TRY_COMPILE([
  #include <sys/types.h>
  #include <sys/socket.h>
  int accept (int, struct sockaddr *, size_t *);
  ],[],[
  AC_MSG_RESULT(size_t)
  AC_DEFINE(socklen_t,size_t)], [
  AC_MSG_RESULT(int)
  AC_DEFINE(socklen_t,int)])])
])

# pkg.m4 - Macros to locate and utilise pkg-config.            -*- Autoconf -*-
# 
# Copyright © 2004 Scott James Remnant <scott@netsplit.com>.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
#
# As a special exception to the GNU General Public License, if you
# distribute this file as part of a program that contains a
# configuration script generated by Autoconf, you may include it under
# the same distribution terms that you use for the rest of that program.

# PKG_PROG_PKG_CONFIG([MIN-VERSION])
# ----------------------------------
AC_DEFUN([PKG_PROG_PKG_CONFIG],
[m4_pattern_forbid([^_?PKG_[A-Z_]+$])
m4_pattern_allow([^PKG_CONFIG(_PATH)?$])
AC_ARG_VAR([PKG_CONFIG], [path to pkg-config utility])dnl
if test "x$ac_cv_env_PKG_CONFIG_set" != "xset"; then
	AC_PATH_TOOL([PKG_CONFIG], [pkg-config])
fi
if test -n "$PKG_CONFIG"; then
	_pkg_min_version=m4_default([$1], [0.9.0])
	AC_MSG_CHECKING([pkg-config is at least version $_pkg_min_version])
	if $PKG_CONFIG --atleast-pkgconfig-version $_pkg_min_version; then
		AC_MSG_RESULT([yes])
	else
		AC_MSG_RESULT([no])
		PKG_CONFIG=""
	fi
		
fi[]dnl
])# PKG_PROG_PKG_CONFIG

# PKG_CHECK_EXISTS(MODULES, [ACTION-IF-FOUND], [ACTION-IF-NOT-FOUND])
#
# Check to see whether a particular set of modules exists.  Similar
# to PKG_CHECK_MODULES(), but does not set variables or print errors.
#
#
# Similar to PKG_CHECK_MODULES, make sure that the first instance of
# this or PKG_CHECK_MODULES is called, or make sure to call
# PKG_CHECK_EXISTS manually
# --------------------------------------------------------------
AC_DEFUN([PKG_CHECK_EXISTS],
[AC_REQUIRE([PKG_PROG_PKG_CONFIG])dnl
if test -n "$PKG_CONFIG" && \
    AC_RUN_LOG([$PKG_CONFIG --exists --print-errors "$1"]); then
  m4_ifval([$2], [$2], [:])
m4_ifvaln([$3], [else
  $3])dnl
fi])


# _PKG_CONFIG([VARIABLE], [COMMAND], [MODULES])
# ---------------------------------------------
m4_define([_PKG_CONFIG],
[if test -n "$PKG_CONFIG"; then
    if test -n "$$1"; then
        pkg_cv_[]$1="$$1"
    else
        PKG_CHECK_EXISTS([$3],
                         [pkg_cv_[]$1=`$PKG_CONFIG --[]$2 "$3" 2>/dev/null`],
			 [pkg_failed=yes])
    fi
else
	pkg_failed=untried
fi[]dnl
])# _PKG_CONFIG

# _PKG_SHORT_ERRORS_SUPPORTED
# -----------------------------
AC_DEFUN([_PKG_SHORT_ERRORS_SUPPORTED],
[AC_REQUIRE([PKG_PROG_PKG_CONFIG])
if $PKG_CONFIG --atleast-pkgconfig-version 0.20; then
        _pkg_short_errors_supported=yes
else
        _pkg_short_errors_supported=no
fi[]dnl
])# _PKG_SHORT_ERRORS_SUPPORTED


# PKG_CHECK_MODULES(VARIABLE-PREFIX, MODULES, [ACTION-IF-FOUND],
# [ACTION-IF-NOT-FOUND])
#
#
# Note that if there is a possibility the first call to
# PKG_CHECK_MODULES might not happen, you should be sure to include an
# explicit call to PKG_PROG_PKG_CONFIG in your configure.ac
#
#
# --------------------------------------------------------------
AC_DEFUN([PKG_CHECK_MODULES],
[AC_REQUIRE([PKG_PROG_PKG_CONFIG])dnl
AC_ARG_VAR([$1][_CFLAGS], [C compiler flags for $1, overriding pkg-config])dnl
AC_ARG_VAR([$1][_LIBS], [linker flags for $1, overriding pkg-config])dnl

pkg_failed=no
AC_MSG_CHECKING([for $1])

_PKG_CONFIG([$1][_CFLAGS], [cflags-only-I], [$2])
_PKG_CONFIG([$1][_LIBS], [libs], [$2])

m4_define([_PKG_TEXT], [Alternatively, you may set the environment variables $1[]_CFLAGS
and $1[]_LIBS to avoid the need to call pkg-config.
See the pkg-config man page for more details.])

if test $pkg_failed = yes; then
        _PKG_SHORT_ERRORS_SUPPORTED
        if test $_pkg_short_errors_supported = yes; then
	        $1[]_PKG_ERRORS=`$PKG_CONFIG --short-errors --errors-to-stdout --print-errors "$2"`
        else 
	        $1[]_PKG_ERRORS=`$PKG_CONFIG --errors-to-stdout --print-errors "$2"`
        fi
	# Put the nasty error message in config.log where it belongs
	echo "$$1[]_PKG_ERRORS" >&AS_MESSAGE_LOG_FD

	ifelse([$4], , [AC_MSG_ERROR(dnl
[Package requirements ($2) were not met:

$$1_PKG_ERRORS

Consider adjusting the PKG_CONFIG_PATH environment variable if you
installed software in a non-standard prefix.

_PKG_TEXT
])],
		[$4])
elif test $pkg_failed = untried; then
	ifelse([$4], , [AC_MSG_FAILURE(dnl
[The pkg-config script could not be found or is too old.  Make sure it
is in your PATH or set the PKG_CONFIG environment variable to the full
path to pkg-config.

_PKG_TEXT

To get pkg-config, see <http://www.freedesktop.org/software/pkgconfig>.])],
		[$4])
else
	$1[]_CFLAGS=$pkg_cv_[]$1[]_CFLAGS
	$1[]_LIBS=$pkg_cv_[]$1[]_LIBS
        AC_MSG_RESULT([yes])
	ifelse([$3], , :, [$3])
fi[]dnl
])# PKG_CHECK_MODULES


dnl @synopsis AX_FUNC_WHICH_GETHOSTBYNAME_R
dnl
dnl Determines which historical variant of the gethostbyname_r() call
dnl (taking three, five, or six arguments) is available on the system
dnl and defines one of the following macros accordingly:
dnl
dnl   HAVE_FUNC_GETHOSTBYNAME_R_6
dnl   HAVE_FUNC_GETHOSTBYNAME_R_5
dnl   HAVE_FUNC_GETHOSTBYNAME_R_3
dnl
dnl If used in conjunction with gethostname.c, the API demonstrated in
dnl test.c can be used regardless of which gethostbyname_r() is
dnl available. These example files can be found at
dnl http://www.csn.ul.ie/~caolan/publink/gethostbyname_r
dnl
dnl based on David Arnold's autoconf suggestion in the threads faq
dnl
dnl Originally named "AC_caolan_FUNC_WHICH_GETHOSTBYNAME_R". Rewritten
dnl for Autoconf 2.5x by Daniel Richard G.
dnl
dnl @category InstalledPackages
dnl @author Caolan McNamara <caolan@skynet.ie>
dnl @author Daniel Richard G. <skunk@iskunk.org>
dnl @version 2005-01-21
dnl @license GPLWithACException

AC_DEFUN([AX_FUNC_WHICH_GETHOSTBYNAME_R], [

    AC_LANG_PUSH(C)
    AC_MSG_CHECKING([how many arguments gethostbyname_r() takes])

    AC_CACHE_VAL(ac_cv_func_which_gethostbyname_r, [

################################################################

ac_cv_func_which_gethostbyname_r=unknown

#
# ONE ARGUMENT (sanity check)
#

# This should fail, as there is no variant of gethostbyname_r() that takes
# a single argument. If it actually compiles, then we can assume that
# netdb.h is not declaring the function, and the compiler is thereby
# assuming an implicit prototype. In which case, we're out of luck.
#
AC_COMPILE_IFELSE(
    AC_LANG_PROGRAM(
	[[#include <netdb.h>]],
	[[
	    char *name = "www.gnu.org";
	    (void)gethostbyname_r(name) /* ; */
	]]),
    ac_cv_func_which_gethostbyname_r=no)

#
# SIX ARGUMENTS
# (e.g. Linux)
#

if test "$ac_cv_func_which_gethostbyname_r" = "unknown"; then

AC_COMPILE_IFELSE(
    AC_LANG_PROGRAM(
	[[#include <netdb.h>]],
	[[
	    char *name = "www.gnu.org";
	    struct hostent ret, *retp;
	    char buf@<:@1024@:>@;
	    int buflen = 1024;
	    int my_h_errno;
	    (void)gethostbyname_r(name, &ret, buf, buflen, &retp, &my_h_errno) /* ; */
	]]),
    ac_cv_func_which_gethostbyname_r=six)

fi

#
# FIVE ARGUMENTS
# (e.g. Solaris)
#

if test "$ac_cv_func_which_gethostbyname_r" = "unknown"; then

AC_COMPILE_IFELSE(
    AC_LANG_PROGRAM(
	[[#include <netdb.h>]],
	[[
	    char *name = "www.gnu.org";
	    struct hostent ret;
	    char buf@<:@1024@:>@;
	    int buflen = 1024;
	    int my_h_errno;
	    (void)gethostbyname_r(name, &ret, buf, buflen, &my_h_errno) /* ; */
	]]),
    ac_cv_func_which_gethostbyname_r=five)

fi

#
# THREE ARGUMENTS
# (e.g. AIX, HP-UX, Tru64)
#

if test "$ac_cv_func_which_gethostbyname_r" = "unknown"; then

AC_COMPILE_IFELSE(
    AC_LANG_PROGRAM(
	[[#include <netdb.h>]],
	[[
	    char *name = "www.gnu.org";
	    struct hostent ret;
	    struct hostent_data data;
	    (void)gethostbyname_r(name, &ret, &data) /* ; */
	]]),
    ac_cv_func_which_gethostbyname_r=three)

fi

################################################################

]) dnl end AC_CACHE_VAL

case "$ac_cv_func_which_gethostbyname_r" in
    three)
    AC_MSG_RESULT([three])
    AC_DEFINE(HAVE_FUNC_GETHOSTBYNAME_R_3)
    ;;

    five)
    AC_MSG_RESULT([five])
    AC_DEFINE(HAVE_FUNC_GETHOSTBYNAME_R_5)
    ;;

    six)
    AC_MSG_RESULT([six])
    AC_DEFINE(HAVE_FUNC_GETHOSTBYNAME_R_6)
    ;;

    no)
    AC_MSG_RESULT([cannot find function declaration in netdb.h])
    ;;

    unknown)
    AC_MSG_RESULT([can't tell])
    ;;

    *)
    AC_MSG_ERROR([internal error])
    ;;
esac

AC_LANG_POP(C)

]) dnl end AC_DEFUN

dnl
dnl Find GNU make
dnl
AC_DEFUN(
   [AC_PROG_GMAKE],
   [AC_CACHE_CHECK(for GNU make,_cv_gnu_make_command,
      _cv_gnu_make_command='' ;
      dnl Search all the common names for GNU make
      for a in "$MAKE" make gmake gnumake ; do
         if test -z "$a" ; then continue ; fi ;
         if  ( sh -c "$a --version" 2> /dev/null | grep GNU  2>&1 > /dev/null ) ; then
            _cv_gnu_make_command=$a ;
            break;
         fi
      done ;
   ) ;
   MAKE=$_cv_gnu_make_command;
   if test -z "$_cv_gnu_make_command" ; then
      AC_MSG_ERROR([Could not find GNU make]) ;
   fi ; ]
)
