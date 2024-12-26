import time 
import ctypes
import numpy as np
from numpy.ctypeslib import ndpointer
lib_path = '/home/sina-fz/assignment2/libmysort.so'
mySortLib = ctypes.CDLL(lib_path)

# Define input argument types for bubble sort
mySortLib.bubbleSort.argtypes = [ndpointer(ctypes.c_int, flags="C_CONTIGUOUS"), ctypes.c_int]
mySortLib.bubbleSort.restype = None

# Define input argument types for insertion sort
mySortLib.insertionSort.argtypes = [ndpointer(ctypes.c_int, flags="C_CONTIGUOUS"), ctypes.c_int]
mySortLib.insertionSort.restype = None

# Define input argument types for merge sort
mySortLib.mergeSort.argtypes = [ndpointer(ctypes.c_int, flags="C_CONTIGUOUS"), ctypes.c_int]
mySortLib.mergeSort.restype = None

# Define input argument types for heap sort
mySortLib.heapSort.argtypes = [ndpointer(ctypes.c_int, flags="C_CONTIGUOUS"), ctypes.c_int]
mySortLib.heapSort.restype = None

# Define input argument types for counting sort
mySortLib.countingSort.argtypes = [ndpointer(ctypes.c_int, flags="C_CONTIGUOUS"), ctypes.c_int]
mySortLib.countingSort.restype = None
# Running a simple test
# Creating a large test case
arr = np.random.choice(np.arange(-1000000, 1000000, dtype=np.int32), size=500000, replace=False)
n = len(arr)
print("Original array:", arr)

