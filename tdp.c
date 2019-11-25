#include <stdio.h>
#include <unistd.h>
#include "msr.h"

int main()
{
        TDP reg;
        reg.w = 0;
        reg.s.tdp = 3;

        wrmsr(TDP_MSR,reg.w);

        sleep(5);
        reg.w = 0;
        reg.s.tdp = 1;

        wrmsr(TDP_MSR, reg.w);
                
        return 0;        
}       
