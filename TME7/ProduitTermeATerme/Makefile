CC4= /opt/gcc-4.9.1/bin/gcc
EXECS =  ProduitTermeATerme_scal
EXECSPERF =  ProduitTermeATermePerf_scal
EXECSOMP =  ProduitTermeATermeOMP_scal
EXECSSIMD =  ProduitTermeATermeSIMD_scal
CFLAGS= -O3
PERFFLAGS= -ftree-vectorize -mavx2 -ftree-vectorizer-verbose=2
OMPFLAGS= -fopenmp-simd
SIMDFLAGS= -mavx2
OUT=output.txt 

all: $(EXECS) $(EXECSPERF) $(EXECSOMP) $(EXECSSIMD)

ProduitTermeATerme_scal: ProduitTermeATerme.c
	gcc -S $(CFLAGS) -o $@.s $< ; grep -i mul $@.s
	gcc $(CFLAGS) -o $@ $<

ProduitTermeATermePerf_scal: ProduitTermeATermePerf.c
	gcc -S $(CFLAGS) $(PERFFLAGS) -o $@.s $< ; grep -i mul $@.s
	gcc $(CFLAGS) $(PERFFLAGS) -o $@ $<

ProduitTermeATermeOMP_scal: ProduitTermeATermeOMP.c
	$(CC4) -S $(CFLAGS) $(OMPFLAGS) -o $@.s $< ; grep -i mul $@.s
	$(CC4) $(CFLAGS) $(OMPFLAGS) -o $@ $<

ProduitTermeATermeSIMD_scal: ProduitTermeATermeSIMD.c
	gcc -S $(CFLAGS) $(SIMDFLAGS) -o $@.s $< ; grep -i mul $@.s
	gcc $(CFLAGS) $(SIMDFLAGS) -o $@ $<

exec: all 
	rm -rf $(OUT)
	(for e in $(EXECS) ; do echo "Running $$e ..." ; echo "" >> $(OUT) ; echo "Running $$e ..." >> $(OUT) ; ./$$e $$N >> $(OUT) ; done)
	(for e in $(EXECSPERF) ; do echo "Running $$e ..." ; echo "" >> $(OUT) ; echo "Running $$e ..." >> $(OUT) ; ./$$e $$N >> $(OUT) ; done)
	(for e in $(EXECSOMP) ; do echo "Running $$e ..." ; echo "" >> $(OUT) ; echo "Running $$e ..." >> $(OUT) ; ./$$e $$N >> $(OUT) ; done)
	(for e in $(EXECSSIMD) ; do echo "Running $$e ..." ; echo "" >> $(OUT) ; echo "Running $$e ..." >> $(OUT) ; ./$$e $$N >> $(OUT) ; done)

clean: 
	rm -rf $(EXECS) $(EXECSPERF) $(EXECSOMP) $(EXECSSIMD) *~ *.s 

.phony: all
