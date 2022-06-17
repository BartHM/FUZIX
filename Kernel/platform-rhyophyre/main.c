#include <kernel.h>
#include <kdata.h>
#include <printf.h>
#include <tty.h>
#include <devtty.h>
#include "config.h"
#include <z180.h>

uint16_t ramtop = PROGTOP;
extern unsigned char irqvector;
uint16_t swap_dev = 0xFFFF;

struct blkbuf *bufpool_end = bufpool + NBUFS; /* minimal for boot -- expanded after we're done with _DISCARD */

void plt_discard(void)
{
    while(bufpool_end < (struct blkbuf*)(KERNTOP - sizeof(struct blkbuf))){
        memset(bufpool_end, 0, sizeof(struct blkbuf));
#if BF_FREE != 0
        bufpool_end->bf_busy = BF_FREE; /* redundant when BF_FREE == 0 */
#endif
        bufpool_end->bf_dev = NO_DEVICE;
        bufpool_end++;
    }
}

void z180_timer_interrupt(void)
{
    unsigned char a;

    /* we have to read both of these registers in order to reset the timer */
    a = TIME_TMDR0L;
    a = TIME_TCR;

    timer_interrupt();
}

void plt_idle(void)
{
    /* Let's go to sleep while we wait for something to interrupt us;
     * Makes the Mark IV's run LED go red, which amuses me greatly. */
    __asm
        halt
    __endasm;
}

void plt_interrupt(void)
{
    switch(irqvector){
        case Z180_INT_TIMER0:
            z180_timer_interrupt(); 
            return;
        case Z180_INT_ASCI0:
            tty_pollirq_asci0();
            return;
        case Z180_INT_ASCI1:
            tty_pollirq_asci1();
            return;
        default:
            return;
    }
}

/*
 *	Temporary stub for the PS/2. We have no VT layer so just route PS/2
 *	keys to the console
 */

void vt_inproc(uint_fast8_t minor, uint_fast8_t ch)
{
    tty_inproc(1, ch);
}