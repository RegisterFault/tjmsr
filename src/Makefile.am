ACLOCAL_AMFLAGS = -I m4
bin_PROGRAMS = throttles undervolt listmsrs energy lowpower highpower test medpower intel_rapl amd_pstate

noinst_LIBRARIES = libmsr.a
libmsr_a_SOURCES = msr.c

throttles_SOURCES = throttles.c 
undervolt_SOURCES = undervolt.c 
listmsrs_SOURCES = listmsrs.c 
energy_SOURCES = energy.c 
lowpower_SOURCES = lowpower.c
medpower_SOURCES = medpower.c
highpower_SOURCES = highpower.c
test_SOURCES = test.c
intel_rapl_SOURCES = intel_rapl.c
amd_pstate_SOURCES = amd_pstate.c

throttles_LDADD = libmsr.a
undervolt_LDADD = libmsr.a
listmsrs_LDADD = libmsr.a
energy_LDADD = libmsr.a
lowpower_LDADD = libmsr.a
medpower_LDADD = libmsr.a
highpower_LDADD = libmsr.a
test_LDADD = libmsr.a
intel_rapl_LDADD = libmsr.a
amd_pstate_LDADD = libmsr.a
