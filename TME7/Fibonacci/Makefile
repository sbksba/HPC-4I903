EXECS = fibo_seq 
EXMP  = fibo_mp
CFLAGS= -O3 
OUT=output.txt 

ifeq ($(OPENMP),1)
CFLAGS += -fopenmp
endif

all: $(EXECS) $(EXMP)

fibo_seq: fibo_seq.c
	gcc $(CFLAGS) -o $@ $<

fibo_mp: fibo_mp.c
	gcc $(CFLAGS) -o $@ $<

exec: all
	rm -rf $(OUT)
	(export N=40 ; for e in $(EXECS) ; do echo "Running $$e ..." ; echo "" >> $(OUT) ; echo "Running $$e ..." >> $(OUT) ; ./$$e $$N >> $(OUT) ; done)
	(export N=40 ; for e in $(EXMP) ; do echo "Running $$e ..." ; echo "" >> $(OUT) ; echo "Running $$e ..." >> $(OUT) ; ./$$e $$N >> $(OUT) ; done)

clean: 
	rm -rf $(EXECS) $(EXMP) *~

.phony: all
