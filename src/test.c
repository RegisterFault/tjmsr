#include <stdio.h>
#include "msr.h"

int main()
{
        IA32_PKG_HDC_CTL r;
        IA32_PM_CTL1 p;

        p.w = 0;
        p.s.allow = 1;
        r.w = 0;
        r.s.enable = 1;
        wrmsr(IA32_PKG_HDC_CTL_MSR, r.w);
        wrmsr_all(IA32_PM_CTL1_MSR, p.w);

        r.w = rdmsr(IA32_PKG_HDC_CTL_MSR);
        p.w = rdmsr(IA32_PM_CTL1_MSR);
        printf("IA32_PKG_HDC_CTL\n");
        printf("enable: %lx\n", r.s.enable);
        printf("res: %lx\n", r.s.res);
        printf("IA32_PM_CTL1_MSR\n");
        printf("enable: %lx\n", p.s.allow);
        printf("res: %lx\n", p.s.res);
        return 0;
}
