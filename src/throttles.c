#include <stdio.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include "msr.h"

void throttles()
{ 
        LIMITS a;
        
        a.w = rdmsr(LIMITS_MSR);

        printf( "prochot: %hhx\n"
                "thermal: %hhx\n"
                "rsr: %hhx\n"
                "ratl: %hhx\n"
                "vreg: %hhx\n"
                "cur: %hhx\n"
                "other: %hhx\n"
                "pl1: %hhx\n"
                "pl2: %hhx\n"
                "max_turbo: %hhx\n"
                "ttas: %hhx\n",
                a.s.prochot ,
                a.s.thermal ,
                a.s.rsr ,
                a.s.ratl ,
                a.s.vreg ,
                a.s.cur ,
                a.s.other ,
                a.s.pl1 ,
                a.s.pl2 ,
                a.s.max_turbo ,
                a.s.ttas);
 
}




int main()
{
        throttles();
        return 0;
}

