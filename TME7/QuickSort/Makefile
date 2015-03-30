EXECS = QuickSort_seq 
EXMP  = QuickSort_mp
CFLAGS= -O3 
OUT   = output.txt

ifeq ($(OPENMP),1)
CFLAGS += -fopenmp
endif

ifneq ($(SIZE), )
CFLAGS += -DSEUIL=$(SIZE)
endif

all: $(EXECS) $(EXMP)

QuickSort_seq: QuickSort_seq.c
	gcc $(CFLAGS) -o $@ $<

QuickSort_mp: QuickSort_mp.c
	gcc $(CFLAGS) -o $@ $<

exec: all
	rm -rf $(OUT)
	(for e in $(EXECS) ; do echo "Running $$e ..." ; echo "" >> $(OUT) ; echo "Running $$e ..." >> $(OUT) ; ./$$e >> $(OUT) ; done)
	(for e in $(EXMP) ; do echo "Running $$e ..." ; echo "" >> $(OUT) ; echo "Running $$e ..." >> $(OUT) ; ./$$e >> $(OUT) ; done)

clean: 
	rm -rf $(EXECS) $(EXMP) *~

.phony: all
