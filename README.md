## Parallel Sorting Algorithms

This is a collections of different parallel sorting algorithms, with some benchmarking results on 
various array sizes.

- [Quick-sort for integers, multithredded with OpenMP](./quick-sort)  
100 000: 0.03 s  
1 000 000: 0.03 s  
10 000 000: 0.13 s  
100 000 000: 0.9 s

- [Merge-sort for integers, multithredded with OpenMP](./quick-sort)  
&nbsp;&nbsp;&nbsp;&nbsp;100 000: 0.004 s  
&nbsp;&nbsp;1 000 000: 0.02 s  
&nbsp;10 000 000: 0.13 s  
100 000 000: 1.07 s

The benchmarks were done on a machine with following specs:

- Intel Xeon W-2255, 10 cores, 20 threads, 3.70 / 4.50 GHz
- 64GB DDR4 (4 x 16)
- Nvidia Quadro RTX 4000
