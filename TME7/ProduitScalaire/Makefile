EXECS = ProduitScalaire_scal 
CFLAGS= -O3 
OUT=output.txt 
GREP_PATTERN= -i -e mul -e fmadd

all: $(EXECS)

ProduitScalaire_scal: ProduitScalaire.c
	gcc -S $(CFLAGS) -o $@.s $< ; grep $(GREP_PATTERN) $@.s
	gcc $(CFLAGS) -o $@ $<

exec: all 
	rm -rf $(OUT)
	(for e in $(EXECS) ; do echo "Running $$e ..." ; echo "" >> $(OUT) ; echo "Running $$e ..." >> $(OUT) ; ./$$e $$N >> $(OUT) ; done)

clean: 
	rm -rf $(EXECS) *~ *.s 

.phony: all
