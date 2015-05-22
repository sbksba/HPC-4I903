BLAS_DIR=/users/Enseignants/fortin/DOWNLOAD/OpenBLAS/xianyi-OpenBLAS-9c51cdf
CC=gcc
CFLAGS=-O3
PERFFLAGS= -ftree-vectorize -mavx
OMPFLAGS = -fopenmp #-simd
SIMDFLAGS= -mavx2
BLASFLAGS= $(BLAS_DIR)/libopenblas.a -lpthread
EXECS     = matmul
EXECSPERF = matmulPerf
EXECSOMP  = matmulOMP
EXECSBLAS = matmulBLAS

all: $(EXECS) $(EXECSPERF) $(EXECSOMP) $(EXECSBLAS)

$(EXECS): $(EXECS).c
	$(CC) -o $@ $<

$(EXECSPERF): $(EXECSPERF).c
	$(CC) $(CFLAGS) -o $@ $<

$(EXECSOMP): $(EXECSOMP).c
	$(CC) $(CFLAGS) $(OMPFLAGS) -o $@ $<

$(EXECSBLAS): $(EXECSBLAS).c
	$(CC) $(CFLAGS) -I$(BLAS_DIR) $< -o $@ $(BLASFLAGS)

.PHONY: all proper clean cleanpaper test bench

proper:
	rm -f *~

clean: proper
	rm -rf $(EXECS) $(EXECSPERF) $(EXECSOMP) $(EXECSBLAS)

cleanpaper: proper
	rm -f data_*.txt

test:
	@echo "##########"
	@echo "# MATMUL #"
	@echo "##########"
	./matmul 16
	@echo ""
	@echo "##############"
	@echo "# MATMULPERF #"
	@echo "##############"
	./matmulPerf 16
	@echo ""
	@echo "#############"
	@echo "# MATMULOMP #"
	@echo "#############"
	./matmulOMP 16
	@echo ""
	@echo "##############"
	@echo "# MATMULBLAS #"
	@echo "##############"
	./matmulBLAS 16
	@echo ""

bench:
	@echo "# MATMUL #"
	./run.sh matmul
	@echo ""
	@echo "# MATMULPERF #"
	./run.sh matmulPerf
	@echo ""
	@echo "# MATMULOMP #"
	./run.sh matmulOMP
	@echo ""
	@echo "# MATMULBLAS #"
	./run.sh matmulBLAS
	@echo ""
