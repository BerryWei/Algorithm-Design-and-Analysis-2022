CC = gcc
CFLAGS = -g
OBJS = HW1_Cash.o
EXE = HW1_Cash

main: ${OBJS}
	${CC} -o ${EXE} ${OBJS} 

	echo "\n\n"
	./ ${EXE}
%.o : %.c
	${CC} -c $^ -o $@
	

clean:
	rm -f ${EXE} ${OBJS}