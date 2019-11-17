#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "msr.h"


int main()
{
        for(int i = 0; i<0x1000;i++){
                unsigned long long reg = (unsigned long long) rdmsr(i);
                if(!reg)
                        continue;
                printf("%x %llx\n", i, reg);
        }

        return 0;
}
