# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt

data=np.loadtxt("data_matmul.txt")
plt.plot(data[:,0],data[:,1], 'g-^', label='naif')
data=np.loadtxt("data_matmulPerf.txt")
plt.plot(data[:,0],data[:,1], 'b-^', label='rec par bloc')
data=np.loadtxt("data_matmulOMP.txt")
plt.plot(data[:,0],data[:,1], 'r-^', label='omp 8 threads')
data=np.loadtxt("data_matmulBLAS.txt")
plt.plot(data[:,0],data[:,1], 'y-^', label='blas')
plt.legend(loc=0)
plt.ylabel('Gflops')
plt.xlabel('n')
plt.show()
