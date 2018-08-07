SRCS = $(wildcard *.c)
TRGT = ../Library/libapc.so
IFLAG = -I../Include

${TRGT} : ${SRCS}
	gcc -fPIC -shared ${IFLAG} $^ -o $@

clean :
	rm ${TRGT}
