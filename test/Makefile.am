## Process this file with automake to produce Makefile.in.

SUBDIRS = volte

bin_PROGRAMS = testepc

testepc_SOURCES = \
	abts.h abts_tests.h testutil.h \
	abts.c testutil.c testpacket.h testpacket.c \
	s1ap_message_test.c nas_message_test.c gtp_message_test.c \
	security_test.c s1setup_test.c attach_test.c volte_test.c handover_test.c \
	$(NULL)

testepc_LDADD = \
    $(top_srcdir)/src/libepc.la \
	$(NULL)

AM_CPPFLAGS = \
    -I$(top_srcdir)/lib/core/include \
    -I$(top_srcdir)/lib \
    -I$(top_srcdir)/src \
    -I$(top_srcdir)/lib/s1ap/asn1c \
	-I$(top_srcdir)/lib/@FREEDIAMETER_DIR@/include \
	@MONGOC_CFLAGS@ \
	$(NULL)

AM_CFLAGS = \
	-Wall -Werror \
	-Wno-unused-function -Wno-unused-variable \
	@OSCPPFLAGS@ \
	$(NULL)

MAINTAINERCLEANFILES = Makefile.in 
MOSTLYCLEANFILES = core *.stackdump
