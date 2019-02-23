#ifndef COUNT_OPERATIONS_H
#define COUNT_OPERATIONS_H
#include <vector>
#include <algorithm>
#include <cmath>
#include "iota.h"
#include "instrumented.h"
#include "table_util.h"

double normalized_by_n(double x, double n) { return x / n; }
double normalized_by_nlogn(double x, double n) { 
  return x / (n * (log(n) / log(2))); 
}
double normalized_by_nlogn1(double x, double n) { 
  return x / (n * log(n) - n); 
}
double dont_normalize(double x, double) { return x; }

template <typename Function>
void count_operations(size_t count_qty, size_t count_limit, Function function_tested, double (*normalize)(double, double) = dont_normalize) {
// measure operations on an interval of a given length 
// ranging from i to j and going through i, 2i, 4i, ... up to and including j

  size_t cols = instrumented<double>::number_ops;
 
  size_t decimals[cols];
  size_t normalized((normalize == dont_normalize) ? 0 : 2);  // todo: what does 2 mean?
  *decimals = 0;                                        // todo: put a zero at 0th position?
  std::fill(decimals + 1, decimals + cols, normalized);
  
  table_util table;
  table.print_headers(instrumented<double>::counter_names, instrumented<double>::number_ops, 12); 
 
  while (count_qty <= count_limit) {
   
    std::vector<instrumented<double> > data_vector_instrumented(count_qty);
    course::iota(data_vector_instrumented.begin(), data_vector_instrumented.end(), 0.0);
    std::random_shuffle(data_vector_instrumented.begin(), data_vector_instrumented.end());

    instrumented<double>::initialize(count_qty);
    function_tested(data_vector_instrumented.begin(), data_vector_instrumented.end());
    
    double* count_p = instrumented<double>::operation_counts;  // c vector of doubles
    
    for (size_t k(1); k < cols; ++k)
        count_p[k] = normalize(count_p[k], count_p[0]);

    table.print_row(count_p, decimals);

    count_qty <<= 1;
  }
}

#endif
