OBJ = kernel.o main.o protect.o i8259.o schedule.o syscall.o tick.o keyboard.o tty.o \
		console.o ipc.o systask.o proc.o hd.o

all : build-in.o

build-in.o : $(OBJ)
	$(LD) $(LDFLAGS) -r -o $@ $^

%.o : %.asm
	$(ASM) $(ASMKFLAGS) -o $@ $<

%.o : %.c
	$(CC) $(CFLAGS) -o $@ $<
