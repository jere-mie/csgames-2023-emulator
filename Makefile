CFLAGS= -O 
.KEEP_STATE:

all: fake6502.c readwrite.c
		gcc -include fake6502.c readwrite.c -o program
		./program
compile: fake6502.c readwrite.c
		gcc -include fake6502.c readwrite.c -o program
run: program
		./program
clean: 
		rm program