#include <stdio.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>
#include "msr.h"

int main()
{
        RAPL_POWER_UNIT a;
        NRGP reg;
        PLATFORM_ENERGY_COUNTER plat;
        PP0_NRG pp0;
        PP1_NRG pp1;
        DRAM_NRG dram;

        unsigned long last = 0; 
        unsigned long plat_last = 0; 
        unsigned long pp0_last = 0; 
        unsigned long pp1_last = 0; 
        unsigned long dram_last = 0; 

        initscr();
        
        while(1){
                reg.w = rdmsr(NRGP_MSR);
                a.w = rdmsr(RAPL_POWER_UNIT_MSR);
                plat.w = rdmsr(PLATFORM_ENERGY_COUNTER_MSR);
                pp0.w = rdmsr(PP0_NRG_MSR);
                pp1.w = rdmsr(PP1_NRG_MSR);
                dram.w = rdmsr(DRAM_NRG_MSR);

                mvprintw(0,0,"PKG: %f",reg.s.energy*(pow(0.5,(float)a.s.es_units)));
                mvprintw(2,0,"PP0: %f",pp0.s.energy*(pow(0.5,(float)a.s.es_units)));
                mvprintw(4,0,"PP1: %f",pp1.s.energy*(pow(0.5,(float)a.s.es_units)));
                mvprintw(6,0,"DRAM: %f",dram.s.energy*(pow(0.5,(float)a.s.es_units)));
                mvprintw(8,0,"PLAT: %f",plat.s.energy*(pow(0.5,(float)a.s.es_units)));
                if(last != 0 )
                        mvprintw(1,0,"%f",(reg.s.energy-last)*(pow(0.5,(float)(a.s.es_units))));
                if(pp0_last != 0 )
                        mvprintw(3,0,"%f",(pp0.s.energy-pp0_last)*(pow(0.5,(float)(a.s.es_units))));
                if(pp1_last != 0 )
                        mvprintw(5,0,"%f",(pp1.s.energy-pp1_last)*(pow(0.5,(float)(a.s.es_units))));
                if(dram_last != 0 )
                        mvprintw(7,0,"%f",(dram.s.energy-dram_last)*(pow(0.5,(float)(a.s.es_units))));
                if(plat_last != 0 )
                        mvprintw(9,0,"%f",(plat.s.energy-plat_last)*(pow(0.5,(float)(a.s.es_units))));
                last = reg.s.energy;
                pp0_last = pp0.s.energy;
                pp1_last = pp1.s.energy;
                dram_last = dram.s.energy;
                plat_last = plat.s.energy;
                refresh();
                usleep(1000000);
        }
        endwin();
        return 0;
}
