/*
 * for components info see: wiki/COMPONENTS.md
 *
 * extra configs in can be found in `components_config.h`
 */

/* for usleep */
#define _SEC *1000
#define _MIN *(60 _SEC)
#define _HR *(60 _MIN)

/* interval to run only once */
#define ONCE ((unsigned int)-1)

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 256
/*
 * if you want to change buffer size for each segment,
 * then change `BUFF_SZ` in lib/util.h
 */

#define IFC "wlp0s20f3" /* wifi interface */
#define BATTERY "CMB0"

/* clang-format off */
static struct arg_t args[] = {

/* function       format                        argument                interval (in ms) */

#if USE_X
/* { bspwm_ws,    " [ %s ]%%{r}",               NULL,                   0,          END }, */
#endif
{ cpu_perc,       "^fg(f4005f)cpu: %s%%",       NULL,                   1 _SEC,     END },
{ cpu_freq,       " %sHz",                      NULL,                   1 _SEC,     END },
{ ram_perc,       " ^fg(98e024)mem: %s%%",      NULL,                   1 _SEC,     END },
{ disk_perc,      " ^fg(e0d561)root: %s%%",     "/",                    30 _SEC,    END },
{ disk_perc,      " ^fg(9d65ff)home: %s%%",     "/home",                30 _SEC,    END },
{ battery_perc,   " ^fg(f4005f)bat: %s%%",      BATTERY,                10 _SEC,    END },
{ battery_state,  " %s",                        BATTERY,                10 _SEC,    END },
{ run_command,    " ^fg(58d1eb)light: %s%%",    "xbacklight -get",      1 _SEC,     END },
{ ipv4,           " ^fg(f6f6ef)net: %s",        "enp7s0",               3 _SEC,     END },
{ vol_perc,       " ^fg(98e024)vol: %s",        NULL,                   1,          END },
{ wifi_perc,      " ^fg(e0d561)wifi: %s%%",     IFC,                    5 _SEC,     END },
{ wifi_essid,     " (%s)",                      IFC,                    5 _SEC,     END },
{ datetime,       " ^fg(9d65ff)dat: %s",        "%d-%m-%y %H:%M",    1 _SEC,     END },
#if USE_X && USE_XKB
{ keymap,       "-[ %s] ", NULL,        0, END },
#endif

};
/* clang-format on */
