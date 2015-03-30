GCC=gcc
CC=mpicc
CFLAGS=
RUN=mpirun

all: MANDEL MANDELVANILLA MANDELSLAVE

# ==========
# EXECUTABLE
# ==========
MANDEL: mandel.c
	${GCC} -o $@ $^ -lm

MANDELVANILLA: mandelVanilla.c
	${CC} -o $@ $^

MANDELSLAVE: mandelSlave.c
	${CC} -o $@ $^

.PHONY: all proper clean

proper:
	rm -f *~ *.ras *.png

clean: proper
	rm -f MANDEL MANDELVANILLA MANDELSLAVE

bench:
	@echo "## MANDEL ##"
	./MANDEL
	@echo ""
	@echo "## MANDELVANILLA ##"
	${RUN} -n 2 --hostfile hostfile ./MANDELVANILLA
	@echo ""
	@echo "## MANDELVANILLA ##"
	${RUN} -n 4 --hostfile hostfile ./MANDELVANILLA
	@echo ""
	@echo "## MANDELVANILLA ##"
	${RUN} -n 8 --hostfile hostfile ./MANDELVANILLA
	@echo ""
	@echo "## MANDELSLAVE ##"
	${RUN} -n 2 --hostfile hostfile ./MANDELSLAVE
	@echo ""
	@echo "## MANDELSLAVE ##"
	${RUN} -n 4 --hostfile hostfile ./MANDELSLAVE
	@echo ""
	@echo "## MANDELSLAVE ##"
	${RUN} -n 8 --hostfile hostfile ./MANDELSLAVE
	@echo ""
