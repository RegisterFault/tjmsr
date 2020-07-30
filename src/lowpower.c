#include <stdio.h>
#include "msr.h"

int main()
{ 
        HWP_REQUEST rq;
        rq.w = rdmsr(HWP_REQUEST_MSR);

        rq.s.nrg_pref = 0xff;

        wrmsr_all(HWP_REQUEST_MSR, rq.w);

        return 0;
}
