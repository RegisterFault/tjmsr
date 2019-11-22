AC_INIT([rdmsr], [1.0], [registerfault@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
LT_PREREQ([2.2])
LT_INIT()
LT_OUTPUT()
AC_PROG_CC
AC_CHECK_HEADER([math.h])
AC_CHECK_LIB([m],[pow])
AC_CHECK_HEADER([ncurses.h])
AC_CHECK_LIB([ncurses],[initscr])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
