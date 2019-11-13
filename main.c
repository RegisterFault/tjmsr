#include <stdio.h>
#include "msr.h"

typedef union {
        struct {
                unsigned vme:1; /* virtual 8086 */
                unsigned pvi:1; /* protected mode virtual interrupts */
                unsigned tsd:1; /* timestamp disable */
                unsigned de:1;  /* debugging extensions */
                unsigned pse:1; /* page size extension */
                unsigned pae:1; /* physical address extensions */
                unsigned mce:1; /* machine check extensions */
                unsigned pge:1; /* page global extensions */
                unsigned pce:1; /* performace monitoring counter */
                unsigned osfxsr:1; /* fxsave fxstore */
                unsigned osxmmexcpt:1; /* unmasked simd float exceptions */
                unsigned umip:1; /* user mode instruction prevention */
                unsigned vmxe:1; /* virtual machine extensions enable */
                unsigned smxe:1; /* safe mode extensions enable */
                unsigned pcide:1; /* pcid enable */
                unsigned osxsave:1; /* xsave processor extended states enable */
                unsigned smep:1; /* supervisor mode extensions enable */
                unsigned smap:1; /* supervisor mode access protection enable*/
        }s __attribute__ ((packed));
        unsigned int w;
}CR4;

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

void tinker()
{
        SPEC reg;
        reg.w = rdmsr(SPEC_MSR);
        printf("%llx\n",reg.w);
}

void print_voltage()
{
        VOLT reg;
        reg.w = rdmsr(VOLT_MSR);
        printf("%x - %d\n", reg.s.volt, reg.s.volt);
}

int main()
{
        print_voltage();
        return 0;
}
