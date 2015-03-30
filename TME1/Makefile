CC=mpicc
CFLAGS=
RUN=mpirun

all: EX1 EX2 COLLECTSUM COLLECTSUMALL

# ==========
# EXECUTABLE
# ==========
EX1: ex1.c
	${CC} -o $@ $^

EX2: ex2.c
	${CC} -o $@ $^

COLLECTSUM: collectSum.c
	${CC} -o $@ $^

COLLECTSUMALL: collectSumAll.c
	${CC} -o $@ $^

.PHONY: all proper clean cleanall

proper:
	rm -f *~

clean: proper
	rm -f EX1 EX2 COLLECTSUM COLLECTSUMALL

bench:
	@echo "## EX1 ##"
	${RUN} -np 2 --hostfile hostfile ./EX1
	@echo ""
	@echo "## EX2 ##"
	${RUN} -np 4 --hostfile hostfile ./EX2
	@echo ""
	@echo "## COLLECTSUM ##" 
	${RUN} -np 10 --hostfile hostfile ./COLLECTSUM
	@echo ""
	@echo "## COLLECTSUMALL ##"
	${RUN} -np 10 --hostfile hostfile ./COLLECTSUMALL
