/* Enable to make ^Z dump the inode table for debug */
#define CONFIG_IDUMP
/* Enable to make ^A drop back into the monitor */
#undef CONFIG_MONITOR
/* Profil syscall support (not yet complete) */
#undef CONFIG_PROFIL

#define CONFIG_32BIT
//#define CONFIG_LEVEL_2

#define CONFIG_MULTI
#define CONFIG_FLAT
#define CONFIG_SPLIT_ID
#define CONFIG_PARENT_FIRST
/* It's not that meaningful but we currently chunk to 512 bytes */
#define CONFIG_BANKS 	(65536/512)

#define CONFIG_LARGE_IO_DIRECT(x)	1

#define CONFIG_SPLIT_UDATA
#define UDATA_SIZE	1024
#define UDATA_BLKS	2

#define TICKSPERSEC	200		/* Ticks per second */

#define BOOT_TTY (512 + 1)	/* Set this to default device for stdio, stderr */
			  /* In this case, the default is the first TTY device */
			    /* Temp FIXME set to serial port for debug ease */

/* We need a tidier way to do this from the loader */
#define CMDLINE	NULL		/* Location of root dev name */

/* Device parameters */
#define NUM_DEV_TTY 1
#define TTYDEV   BOOT_TTY	/* Device used by kernel for messages, panics */

/* Could be bigger but we need to add hashing first and it's not clearly
   a win with a CF card anyway */
#define PTABSIZE 	8
#define NBUFS    	5	/* Number of block buffers */
#define NMOUNTS	 	2	/* Number of mounts at a time */

#define CONFIG_TD_NUM	1
#define CONFIG_TD_SD

#define plt_copyright()

#define BOOTDEVICENAMES "hd#"

#define TTY_INIT_BAUD	B38400
