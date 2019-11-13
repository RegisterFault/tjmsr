#include <stdio.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

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
        reg.w = rdmsr(PPLC_MSR);
        printf("pl1: %f watts\n",reg.s.pl1_value*0.032);
        printf("pl2: %f watts\n",reg.s.pl2_value*0.032);
}

int main(int argc, char *argv[])
{
        if( argc > 2)
                fail();

        if(argc == 2)
                if(strcmp(argv[1],"-d") == 0)
                        decrement_power();
                else if (strcmp(argv[1],"-i") ==0 )
                        increment_power();
        show_pl();
        return 0;
}

