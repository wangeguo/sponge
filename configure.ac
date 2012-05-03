#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT([Sponge], [0.1], [wangeguo@gmail.com],
		[sponge], [http://github.com/wangeguo/sponge])
AC_CONFIG_SRCDIR([src/indexd/indexd.cc])
AC_CONFIG_HEADER([include/config.h])
AM_INIT_AUTOMAKE([1.10 -Wall no-define foreign])

AC_LANG(C++)

# Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL

# Checks for libraries.
# Get LevelDB library and include locations
#AC_LANG_PUSH(C++)

AC_ARG_WITH([leveldb],
  [AS_HELP_STRING([--with-leveldb@<:@=PATH@:>@],
    [Directory where leveldb was built. Example: --with-leveldb=/opt/leveldb])],
  [
    #CFLAGS="$CFLAGS -I${withval}/include"
    CPPFLAGS="$CPPFLAGS -I${withval}/include"
    #CXXFLAGS="$CXXFLAGS -I${withval}/include"
    AC_SUBST(CXXFLAGS)
    LDFLAGS="$LDFLAGS -lleveldb -L${withval}"
    AC_SUBST(LDFLAGS)
  ])
AC_CHECK_HEADER([leveldb/db.h],,AC_MSG_ERROR([cannot find headers for leveldb]))

#AC_LANG_POP()

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_C_VOLATILE

# Checks for library functions.

AC_CONFIG_FILES([Makefile
		src/Makefile
		src/indexd/Makefile
		src/noded/Makefile
		examples/Makefile
		examples/net/Makefile
		examples/net/echo/Makefile])
AC_OUTPUT
