CC4= /opt/gcc-4.9.1/bin/gcc
EXECS = ProduitScalaire_scal 
EXECSPERF =  ProduitScalairePerf_scal
EXECSOMP =  ProduitScalaireOMP_scal
EXECSSIMD =  ProduitScalaireSIMD_scal
CFLAGS= -O3 
PERFFLAGS= -ftree-vectorize -mavx2 -ftree-vectorizer-verbose=2
OMPFLAGS= -fopenmp-simd
SIMDFLAGS= -mavx2
OUT=output.txt 
GREP_PATTERN= -i -e mul -e fmadd

all: $(EXECS) $(EXECSPERF) $(EXECSSIMD) #$(EXECSOMP)

ProduitScalaire_scal: ProduitScalaire.c
	gcc -S $(CFLAGS) -o $@.s $< ; grep $(GREP_PATTERN) $@.s
	gcc $(CFLAGS) -o $@ $<

ProduitScalairePerf_scal: ProduitScalairePerf.c
	gcc -S $(CFLAGS) $(PERFFLAGS) -o $@.s $< ; grep -i mul $@.s
	gcc $(CFLAGS) $(PERFFLAGS) -o $@ $<

ProduitScalaireOMP_scal: ProduitScalaireOMP.c
	$(CC4) -S $(CFLAGS) $(OMPFLAGS) -o $@.s $< ; grep -i mul $@.s
	$(CC4) $(CFLAGS) $(OMPFLAGS) -o $@ $<

ProduitScalaireSIMD_scal: ProduitScalaireSIMD.c
	gcc -S $(CFLAGS) $(SIMDFLAGS) -o $@.s $< ; grep -i mul $@.s
	gcc $(CFLAGS) $(SIMDFLAGS) -o $@ $<

exec: all 
	rm -rf $(OUT)
	(for e in $(EXECS) ; do echo "Running $$e ..." ; echo "" >> $(OUT) ; echo "Running $$e ..." >> $(OUT) ; ./$$e $$N >> $(OUT) ; done)
	(for e in $(EXECSPERF) ; do echo "Running $$e ..." ; echo "" >> $(OUT) ; echo "Running $$e ..." >> $(OUT) ; ./$$e $$N >> $(OUT) ; done)
	(for e in $(EXECSSIMD) ; do echo "Running $$e ..." ; echo "" >> $(OUT) ; echo "Running $$e ..." >> $(OUT) ; ./$$e $$N >> $(OUT) ; done)
	#(for e in $(EXECSOMP) ; do echo "Running $$e ..." ; echo "" >> $(OUT) ; echo "Running $$e ..." >> $(OUT) ; ./$$e $$N >> $(OUT) ; done)

clean: 
	rm -rf $(EXECS) $(EXECSPERF) $(EXECSOMP) $(EXECSSIMD) *~ *.s 

.phony: all
