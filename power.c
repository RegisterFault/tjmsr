#include <stdio.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "msr.h"



void increment_power()
{ 
        PPLC c;
        c.w = rdmsr(PPLC_MSR);
        c.s.pl1_value +=31;
        c.s.pl2_value +=31;
        wrmsr(PPLC_MSR,c.w);
 
}

void decrement_power()
{ 
        PPLC c;
        c.w = rdmsr(PPLC_MSR);
        c.s.pl1_value -=31;
        c.s.pl2_value -=31;
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
        RAPLU u;
        u.w = rdmsr(RAPLU_MSR);
        reg.w = rdmsr(PPLC_MSR);
        printf("pl1: %f watts\n",reg.s.pl1_value*(pow(0.5,u.s.power_units)));
        printf("pl2: %f watts\n",reg.s.pl2_value*(pow(0.5,u.s.power_units)));
}

int main(int argc, char *argv[])
{
        PKGPL reg;
        RAPLU u;
        u.w = rdmsr(RAPLU_MSR);
        reg.w = rdmsr(PKGPL_MSR);
        printf("%x %f %f\n",reg.s.pl2, reg.s.pl2*0.032,
                        reg.s.pl2*(pow(0.5,u.s.power_units)));
        show_pl();
        /*
        if( argc > 2)
                fail();

        if(argc == 2)
                if(strcmp(argv[1],"-d") == 0)
                        decrement_power();
                else if (strcmp(argv[1],"-i") == 0)
                        increment_power();
        show_pl();
        */

        return 0;
}

