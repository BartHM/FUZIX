.SUFFIXES: .c -vt52.rel -ansi.rel -termcap.rel

CSRCS = beep.c blockio.c display.c doscall.c editcor.c exec.c find.c
CSRCS += flexcall.c gemcall.c globals.c insert.c main.c misc.c modify.c
CSRCS += move.c rmxcall.c ucsd.c undo.c unixcall.c wildargs.c

HFILES = extern.h grep.h levee.h proto.h
OBJSVT52 = $(CSRCS:.c=-vt52.rel)
OBJSANSI = $(CSRCS:.c=-ansi.rel)
OBJSTERMCAP = $(CSRCS:.c=-termcap.rel)

all:	levee-vt52 levee-ansi levee-termcap

levee-vt52: $(OBJSVT52)
	fcc -o levee-vt52 $(OBJSVT52)

levee-ansi: $(OBJSANSI)
	fcc -o levee-ansi $(OBJSANSI)

levee-termcap: $(OBJSTERMCAP)
	fcc -o levee-termcap $(OBJSTERMCAP)

%-ansi.rel:	%.c $(HFILES)
	fcc -O3 -DVT52=0 -DANSI=1 -DTERMCAP=0 -c $< -o $@

%-vt52.rel:	%.c $(HFILES)
	fcc -O3 -DVT52=1 -DANSI=0 -DTERMCAP=0 -c $< -o $@

%-termcap.rel:	%.c $(HFILES)
	fcc -O3 -DVT52=0 -DANSI=0 -DTERMCAP=1 -c $< -o $@

clean:
	rm -rf $(OBJSVT52) $(OBJSANSI) $(OBJSTERMCAP) *.lst *.sym *.map *.noi *.lk *.ihx *.tmp *~ *.rel *.asm levee levee.bin
