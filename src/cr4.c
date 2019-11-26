#include "cr4.h"

unsigned long cr4()
{
        unsigned int out;
        asm volatile("movl cr4, %0"
                     : "=r" (out)
        );
        return out;
}

void print_cr4()
{
        CR4 reg;
        reg.w = cr4();
        printf(
                "vme : %hhx\n"
                "pvi : %hhx\n"
                "tsd : %hhx\n"
                "de  : %hhx\n"
                "pse : %hhx\n"
                "pae : %hhx\n"
                "mce : %hhx\n"
                "pge : %hhx\n"
                "pce : %hhx\n"
                "osfxsr : %hhx\n"
                "osxmmexcpt : %hhx\n"
                "umip : %hhx\n"
                "vmxe : %hhx\n"
                "smxe : %hhx\n"
                "pcide : %hhx\n"
                "osxsave : %hhx\n"
                "smep : %hhx\n"
                "smap : %hhx\n",
                reg.s.vme ,
                reg.s.pvi ,
                reg.s.tsd ,
                reg.s.de  ,
                reg.s.pse ,
                reg.s.pae ,
                reg.s.mce ,
                reg.s.pge ,
                reg.s.pce ,
                reg.s.osfxsr ,
                reg.s.osxmmexcpt ,
                reg.s.umip ,
                reg.s.vmxe ,
                reg.s.smxe ,
                reg.s.pcide ,
                reg.s.osxsave ,
                reg.s.smep ,
                reg.s.smap);
}


