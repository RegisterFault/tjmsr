#include <stdio.h>
#include "msr.h"

int main()
{ 
        IA32_HWP_REQUEST rq;
        rq.w = rdmsr(IA32_HWP_REQUEST_MSR);

        rq.s.nrg_pref = 0x00;

        wrmsr_all(IA32_HWP_REQUEST_MSR, rq.w);

        return 0;
}
