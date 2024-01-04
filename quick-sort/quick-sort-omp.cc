#include <algorithm>
#include <omp.h>

typedef unsigned long long data_t;

data_t* median(data_t* first, data_t* mid, data_t* last) {
    data_t f = *first;
    data_t m = *mid;
    data_t l = *last;
    if((m < f && f < l) || (l < f && f < m)) return first;
    if((f < m && m < l) || (l < m && m < f)) return mid;
    return last;
}

void quicksort(data_t* first, data_t* last, int tn) {
    if(first == last) return;
    if(tn == 1) {
        std::sort(first, last);
        return;
    }

    data_t pivot = *median(first, (first + (last - first) / 2), last - 1);
    data_t* less = std::partition(first, last, [pivot](data_t e) -> bool { return e < pivot; });
    data_t* gteq = std::partition(less, last, [pivot](data_t e) -> bool { return !(pivot < e); });

    #pragma omp task
    quicksort(first, less, tn - 1);

    #pragma omp task
    quicksort(gteq, last, tn - 1);
}

void psort(int n, data_t* data) {
    int tn = omp_get_max_threads();
    #pragma omp parallel num_threads(tn)
    #pragma omp single
    {
      quicksort(data, data + n, tn);
    }
}
