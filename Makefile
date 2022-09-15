#Makros:
PROG  =calculator
CC = gcc-10
CFLAGS =  `pkg-config --cflags gtk+-3.0`
LIBS =  `pkg-config --libs gtk+-3.0`

${PROG}.elf :${PROG}.c

	${CC}  ${CFLAGS} -o ${PROG}.elf ${PROG}.c ${LIBS}

clean: 
	rm *.elf
