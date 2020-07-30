#include <stdio.h>
#include "msr.h"

#define READ_VAL  (0x8000001000000000L)
#define WRITE_VAL (0x8000001100000000L)



void read_planes()
{
        VOLT reg;
        int i;

        for(i = 0; i<5;i++){
                reg.w = READ_VAL;
                reg.s.plane = i;
                wrmsr(VOLT_MSR,reg.w);
                reg.w = rdmsr(VOLT_MSR);
                printf("%d %.4f mV\n",i,reg.s.volt/1.024);
        }
}

void write_plane(int plane, float voltage)
{
        VOLT reg;
        reg.w = WRITE_VAL;
        reg.s.volt = voltage*1.024;
        reg.s.plane = plane;
        wrmsr_all(VOLT_MSR, reg.w);
}

void write_planes(float voltage)
{
        for(int i = 0; i<5;i++)
                write_plane(i,voltage);
}


void set_voltage()
{
        VOLT reg;
        //set voltage
        reg.w = 0x80000011F9A00000;
        wrmsr(VOLT_MSR, reg.w);

        //set read
        reg.w = READ_VAL;
        wrmsr(VOLT_MSR, reg.w);
        reg.w = rdmsr(VOLT_MSR);

        printf("%x - %f\n", reg.s.volt, reg.s.volt/1.024);
        
        int i = -50;
        i = i*1.024;

        printf("%x\n",i<<21);
}

int main()
{        
        float voltage = -50; //millivolts
        write_plane(0,voltage);
        write_plane(2,voltage);
        read_planes();
        return 0;
}
