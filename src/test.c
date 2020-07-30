#include <stdio.h>
#include "msr.h"

int main()
{
        PKG_HDC_CTL r;
        PM_CTL1 p;

        p.w = 0;
        p.s.allow = 1;
        wrmsr_all(PM_CTL1_MSR, p.w);

        r.w = rdmsr(PKG_HDC_CTL_MSR);
        p.w = rdmsr(PM_CTL1_MSR);
        printf("PKG_HDC_CTL\n");
        printf("enable: %lx\n", r.s.enable);
        printf("res: %lx\n", r.s.res);
        printf("PM_CTL1_MSR\n");
        printf("enable: %lx\n", p.s.allow);
        printf("res: %lx\n", p.s.res);
        return 0;
}
