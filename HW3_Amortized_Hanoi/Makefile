CC = gcc
LINKER_FLAGS = -g -std=c++17 -lstdc++
CFLAGS = -static -O2 -lstdc++ -std=c++17 -fsanitize=undefined
OBJS = amortizedHanoi.o
EXE = amortizedHanoi

main: ${OBJS}
	${CC} -o ${EXE} ${OBJS} -lstdc++ ${LINKER_FLAGS}
	chmod 711 ${EXE}

	echo "\n\n"

	./${EXE} <input1 
%.o : %.c
	${CC} -c $^ -o $@ ${CFLAGS}
	

clean:
	rm -f ${EXE} ${OBJS}