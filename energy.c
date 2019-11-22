#include <stdio.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>
#include "msr.h"

int main()
{
        ENRG reg;
        RAPLU a;

        unsigned long last = 0; 
        initscr();
        
        while(1){
                reg.w = rdmsr(ENRG_MSR);
                a.w = rdmsr(RAPLU_MSR);

                mvprintw(0,0,"%f",reg.s.energy*(pow(0.5,(float)a.s.es_units)));
                if(last != 0 )
                        mvprintw(1,0,"%f",(reg.s.energy-last)*(pow(0.5,(float)(a.s.es_units))));
                last = reg.s.energy;
                refresh();
                usleep(1000000);
        }
        endwin();
        return 0;
}
