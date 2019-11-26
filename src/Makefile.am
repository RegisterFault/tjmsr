ACLOCAL_AMFLAGS = -I m4
bin_PROGRAMS = throttles undervolt listmsrs energy 
noinst_LIBRARIES = libmsr.a
libmsr_a_SOURCES = msr.c

throttles_SOURCES = throttles.c 
undervolt_SOURCES = undervolt.c 
listmsrs_SOURCES = listmsrs.c 
energy_SOURCES = energy.c 

throttles_LDADD = libmsr.a
undervolt_LDADD = libmsr.a
listmsrs_LDADD = libmsr.a
energy_LDADD = libmsr.a
