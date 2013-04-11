dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(gmp, 0.01, igoral@gmail.com,,https://github.com/igoral5/gmp)
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_AUX_DIR([build-aux])
AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE([-Wall -Werror])
AM_GNU_GETTEXT_VERSION([0.18])
AM_GNU_GETTEXT([external])
AC_PROG_CXX
AC_LANG([C++])
AC_CHECK_HEADERS([gmp.h],,AC_MSG_ERROR(Not found header files gmp.h))
AC_CHECK_HEADERS([gmpxx.h],,AC_MSG_ERROR(Not found header files gmpxx.h))
LIBS_SAVED="$LIBS"
LIBS="$LIBS -lgmp"
AC_MSG_CHECKING([for libgmp library])
AC_TRY_LINK([#include <gmp.h>],
	[ mpz_t x; mpz_init(x);],
	[ AC_MSG_RESULT(yes)
	  GMP_EXTRA_LIBS="-lgmp"
	],
	[ AC_MSG_RESULT(no)
	  AC_MSG_ERROR(Unable to link with the libgmp library)
	])
LIBS="$LIBS -lgmpxx"
AC_MSG_CHECKING([for libgmpxx library])
AC_TRY_LINK([#include <gmpxx.h>],
	[ mpz_class x; x = 1;],
	[ AC_MSG_RESULT(yes)
	  GMP_EXTRA_LIBS="$GMP_EXTRA_LIBS -lgmpxx"
	],
	[ AC_MSG_RESULT(no)
	  AC_MSG_ERROR(Unable to link with the libgmpxx library)
	])
LIBS="$LIBS_SAVED"
AC_SUBST(GMP_EXTRA_LIBS)
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_FILES(Makefile src/Makefile po/Makefile.in)
AC_OUTPUT
