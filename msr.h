#ifndef MSR_H
#define MSR_H

#define THERM_MSR 0x19C
typedef union {  //msr 0x19C
        struct  {
                unsigned status:1;
                unsigned slog:1;
                unsigned prochot:1;
                unsigned prochotlog:1;
                unsigned crit:1;
                unsigned critlog:1;
                unsigned thresh1:1;
                unsigned thresh1l:1;
                unsigned thresh2:1;
                unsigned thresh2l:1;
                unsigned powl:1;
                unsigned powll:1;
                unsigned curl:1;
                unsigned curll:1;
                unsigned xdoml:1;
                unsigned xdomll:1;
                unsigned ro:7;
                unsigned pad1:4;
                unsigned res:4;
                unsigned valid:1;
                unsigned pad:32;
        }s __attribute__ ((packed));
        unsigned long w;
} THERM;


#define LIMITS_MSR 0x64F
typedef union { //msr 0x64F
        struct{
                unsigned prochot:1;
                unsigned thermal:1;
                unsigned res1:2;
                unsigned rsr:1;
                unsigned ratl:1;
                unsigned vreg:1;
                unsigned cur:1;
                unsigned other:1;
                unsigned res2:1;
                unsigned pl1:1;
                unsigned pl2:1;
                unsigned max_turbo:1;
                unsigned ttas:1;
                unsigned res3:2;
                unsigned prochot_log:1;
                unsigned thermal_log:1;
                unsigned res4:2;
                unsigned rsr_log:1;
                unsigned ratl_log:1;
                unsigned vreg_log:1;
                unsigned cur_log:1;
                unsigned other_log:1;
                unsigned res5:1;
                unsigned pl1_log:1;
                unsigned pl2_log:1;
                unsigned max_turbo_log:1;
                unsigned ttas_log:1;
                unsigned long res6:34;
        }s __attribute__ ((packed));
        unsigned long w;
}LIMITS;


#define PWCTL_MSR 0x1FC
typedef union{
        struct {
                unsigned res1:1;
                unsigned c1e_enable;
                unsigned res2:17;
                unsigned r2h_disable:1;
                unsigned eeo_disable:1;
                unsigned long res3:43;
        }s __attribute__ ((packed));
        unsigned long w;
}PWCTL;

#define PPLC_MSR 0x65C //power limit control register
typedef union {
        struct {
                unsigned pl1_value:15; //long duration power limit. multiplied by MSR_RAPLPOWER_UNIT
                unsigned pl1_enable:1;
                unsigned pl1_clamping:1;
                unsigned pl1_window:7;
                unsigned res1:8;
                unsigned pl2_value:15;
                unsigned pl2_enable:1;
                unsigned pl2_clamping:1;
                unsigned pl2_window:7;
                unsigned res2:14;
                unsigned lock:1;

        }s __attribute__ ((packed));
        unsigned long w;
}PPLC;


#define RAPLU_MSR 0x606  //power unit register
typedef union {
        struct {
                unsigned power_units:4; // 1 / 2^power_units. default 3 = 1/8 watts
                unsigned res1:4;
                unsigned es_units:5;
                unsigned res2:2;
                unsigned time_units:4;
                unsigned long res3:44;
        }s __attribute__ ((packed));
        unsigned long w;
}RAPLU;

#define SPEC_MSR 0x48
typedef union {
        struct {
                unsigned ibrs:1;
                unsigned stibp:1;
                unsigned ssbd:1;
                unsigned long res1:61;
        }s __attribute__ ((packed));
        unsigned long w;
}SPEC;

#define ENER_MSR 0x64D
typedef union {
        struct {
                unsigned long energy:32; //multiply by RAPL_UNITS
                unsigned long res1:32;
        }s __attribute__ ((packed));
        unsigned long w;
}ENER;

#define VOLT_MSR 0x150 //undocumented voltage msr
typedef union {
        struct {
                unsigned long res1:21;
                unsigned volt:11;
                unsigned long res2:32;
        }s __attribute__ ((packed));
        unsigned long w;
}VOLT;


void fail(void);
unsigned long rdmsr(unsigned int);
unsigned long wrmsr(unsigned int, unsigned long);

#endif
