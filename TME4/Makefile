GCC=gcc
CC=mpicc
CFLAGS=
RUN=mpirun

all: CONVOLVANILLA CONVOLSTRAWBERRY

# ==========
# EXECUTABLE
# ==========
CONVOLVANILLA: convol.c
	${GCC} -o $@ $^ -lm

CONVOLSTRAWBERRY: convolStrawberry.c
	${CC} -o $@ $^

.PHONY: all proper clean

proper:
	rm -f *~ *.ras

clean: proper
	rm -f CONVOLVANILLA CONVOLSTRAWBERRY

bench:
	@echo "## CONVOLVANILLA ##"
	./CONVOLVANILLA Images/Sukhothai_4080x6132.ras 4 10
	@echo ""
