#include <stdio.h>
#include "msr.h"

int main()
{
        PKG_POWER_LIMIT r;
        r.w = rdmsr(PKG_POWER_LIMIT_MSR);
        printf("limit: 0x%hx enable: 0x%hx clamp: 0x%hx timew: 0x%hx  lock: 0x%hx ",
                        r.s.limit,
                        r.s.enable,
                        r.s.clamp,
                        r.s.timew,
                        r.s.lock
              );
}
