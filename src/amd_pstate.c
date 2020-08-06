#include <stdio.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>
#include "msr.h"

uint32_t MSRS[] = {
        AMDPS0_MSR,
        AMDPS1_MSR,
        AMDPS2_MSR,
        AMDPS3_MSR,
        AMDPS4_MSR,
        AMDPS5_MSR,
        AMDPS6_MSR,
        AMDPS7_MSR,
        0,
};

int main()
{
        AMD_PS r;
        uint32_t *msr;
        int line=0;

        initscr();
        
        while(1){
                for (msr = MSRS; *msr != 0; msr++){
                        r.w = rdmsr(*msr);
                        mvprintw(line++, 0, "m: 0x%x d: 0x%x v: 0x%x I: 0x%x Id: 0x%x e: 0x%x",
                                        r.s.cfid,
                                        r.s.cdid,
                                        r.s.cvid,
                                        r.s.ciddv,
                                        r.s.ciddd,
                                        r.s.en
                        );
                }
                line = 0 ;
                refresh();
                usleep(1000000);
        }
        endwin();
        return 0;
}
