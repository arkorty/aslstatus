/*
 * for components info see: wiki/COMPONENTS.md
 *
 * extra configs in can be found in `components_config.h`
 */

/* for usleep */
#define _SEC *1000
#define _MIN *(60 _SEC)
#define _HR  *(60 _MIN)

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

/* function		format		argument	interval (in ms) */

#if USE_X
/* { bspwm_ws,		" [ %s ]%%{r}",	NULL,		0,	END }, */
#endif
{ cpu_perc,       "^fg(78a9ff)cpu: %s%%",       NULL,                   1 _SEC,     END },
{ cpu_freq,       " %sHz",                      NULL,                   1 _SEC,     END },
{ ram_used,       " ^fg(f16da6)mem: %sB/",      NULL,                   1 _SEC,     END },
{ ram_total,      "%sB",                        NULL,                   1 _SEC,     END },
{ disk_used,      " ^fg(25be6a)root: %sB/",     "/",                    30 _SEC,    END },
{ disk_total,     "%sB",                        "/",                    30 _SEC,    END },
{ disk_used,      " ^fg(2dc7c4)home: %sB/",     "/home/ark",            30 _SEC,    END },
{ disk_total,     "%sB",                        "/home/ark",            30 _SEC,    END },
//{ battery_perc,   " ^fg(ee5396)bat: %s%%",      BATTERY,                15 _SEC,    END },
//{ battery_state,  " %s",                        BATTERY,                15 _SEC,    END },
//{ run_command,    " ^fg(25be6a)bri: %s%%",      "xbacklight -get",      1 _SEC,     END },
{ ipv4,           " ^fg(78a9ff)net: %s",        "enp7s0",               3 _SEC,     END },
{ vol_perc,       " ^fg(25be6a)vol: %s",        NULL,                   0,          END },
//{ wifi_perc,      " ^fg(78a9ff)wifi: %s%%",      IFC,                   5 _SEC,     END },
//{ wifi_essid,     " (%s)",                       IFC,                   5 _SEC,     END },
{ datetime,       " ^fg(e4e4e5)dat: %s",         "%a %d-%m-%y %H:%M",   1 _SEC,     END },
#if USE_X && USE_XKB
{ keymap,		"-[ %s] ",	NULL,		 0,	END },
#endif

};
/* clang-format on */
