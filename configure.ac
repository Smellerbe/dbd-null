dnl Process this file with autoconf to produce a configure script.
AC_INIT([libdbd-null],[4],[algernon@balabit.hu])
AM_INIT_AUTOMAKE([foreign subdir-objects])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([no])])

AC_CONFIG_SRCDIR([src/dbd-null.c])
AC_CONFIG_HEADERS([config.h])

AC_CANONICAL_HOST

driverdir=$libdir/dbd
AC_SUBST(driverdir)

dnl ====================================
dnl Check for programs
dnl ====================================

AC_PROG_CC
AC_PROG_CC_C_O
AC_PROG_CPP
LT_PATH_LD
AC_PROG_INSTALL
LT_INIT

dnl ==============================
dnl Check for libraries
dnl ==============================

AC_DEFUN([AC_FIND_FILE],
[
$3=no
for i in $2; do
        for j in $1; do
                if test -r "$i/$j"; then
                        $3=$i
                        break 2
                fi
        done
done
])

AC_DEFUN([AC_CHECK_DBI],
[
AM_CONDITIONAL(HAVE_DBI, false)
ac_dbi_incdir="no"

# exported variables
DBI_INCLUDE=""

AC_MSG_CHECKING(for libdbi framework)

AC_ARG_WITH(dbi-incdir,
        [  --with-dbi-incdir       Specifies where the libdbi include files are.],
        [  ac_dbi_incdir="$withval" ])

if test "$ac_dbi_incdir" = "no"; then
        dbi_incdirs="/usr/include /usr/local/include /sw/include"
        AC_FIND_FILE(dbi/dbi.h, $dbi_incdirs, ac_dbi_incdir)
        if test "$ac_dbi_incdir" = "no"; then
                AC_MSG_RESULT(no)
                AC_MSG_ERROR([Invalid libdbi directory - include files not found.])
        fi
fi
AC_MSG_RESULT([yes: headers in $ac_dbi_incdir])
AM_CONDITIONAL(HAVE_DBI, true)

DBI_INCLUDE=-I$ac_dbi_incdir

AC_SUBST(DBI_INCLUDE)
])

AC_CHECK_DBI

AC_CONFIG_FILES([
	Makefile
	])
AC_OUTPUT
