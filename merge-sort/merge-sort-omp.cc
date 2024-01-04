#include <algorithm>
#include <omp.h>
#include <cmath>

typedef unsigned long long data_t;

void psort(int n, data_t* data) {
    int k = (int)(std::log2(omp_get_max_threads()));
    k = 2 << k;
    k = k >> 1;

    if(n < k) {
        std::sort(data, data + n);
        return ;
    }

    int nn = n / k;
    int m = k * nn;

    #pragma omp parallel num_threads(k)
    {
        int i = omp_get_thread_num();

        std::sort(data + nn * i, data + nn * (i + 1));

        if(i == k - 1) {
            std::sort(data + m, data + n);
        }
    }
    while(k > 1) {
        #pragma omp parallel for
        for(int i=0; i < k; i += 2) {
            int a = nn * i;
            int b = (nn << 1) + a;

            std::inplace_merge(data + a, data + (nn + a), data + b);

            if(i == k - 2) {
                std::inplace_merge(data + a, data + b, data + n);
            }
        }
        k = (k + 1) >> 1;
        nn = nn << 1;
    }
}
