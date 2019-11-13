#include <stdio.h>

typedef union {
        struct {
                unsigned vme:1; /* virtual 8086 */
                unsigned pvi:1; /* protected mode virtual interrupts */
                unsigned tsd:1; /* timestamp disable */
                unsigned de:1;  /* debugging extensions */
                unsigned pse:1; /* page size extension */
                unsigned pae:1; /* physical address extensions */
                unsigned mce:1; /* machine check extensions */
                unsigned pge:1; /* page global extensions */
                unsigned pce:1; /* performace monitoring counter */
                unsigned osfxsr:1; /* fxsave fxstore */
                unsigned osxmmexcpt:1; /* unmasked simd float exceptions */
                unsigned umip:1; /* user mode instruction prevention */
                unsigned vmxe:1; /* virtual machine extensions enable */
                unsigned smxe:1; /* safe mode extensions enable */
                unsigned pcide:1; /* pcid enable */
                unsigned osxsave:1; /* xsave processor extended states enable */
                unsigned smep:1; /* supervisor mode extensions enable */
                unsigned smap:1; /* supervisor mode access protection enable*/
        }s __attribute__ ((packed));
        unsigned int w;
}CR4;


