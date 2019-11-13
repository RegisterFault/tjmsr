#include <stdio.h>
#include "msr.h"

void print_voltage()
{
        VOLT reg;
        reg.w = rdmsr(VOLT_MSR);
        printf("%x - %d\n", reg.s.volt, reg.s.volt);
}

int main()
{
        print_voltage();
        return 0;
}
