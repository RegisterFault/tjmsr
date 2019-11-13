#include <stdio.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include "msr.h"

void increment_power()
{ 
        PPLC c;
        c.w = rdmsr(PPLC_MSR);
        c.s.pl1_value +=1;
        c.s.pl2_value +=1;
        wrmsr(PPLC_MSR,c.w);
 
}

void decrement_power()
{ 
        PPLC c;
        c.w = rdmsr(PPLC_MSR);
        c.s.pl1_value -=1;
        c.s.pl2_value -=1;
        wrmsr(PPLC_MSR,c.w);
}



void get_power_units()
{
        RAPLU a;
        a.w = rdmsr(RAPLU_MSR);
        printf("unit: %d\n",a.s.power_units);
}

void show_pl()
{
        PPLC reg;
        reg.w = rdmsr(PPLC_MSR);
        printf("pl1: %f watts\n",reg.s.pl1_value*0.032);
        printf("pl2: %f watts\n",reg.s.pl2_value*0.032);
}

int main()
{
        increment_power();
        show_pl();
        return 0;
}

