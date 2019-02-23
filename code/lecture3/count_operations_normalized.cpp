#include "../grostig_tools/boost_headers.h"
#include "count_operations.h"
#include "functorized.h"

boost_log_init();
BOOST_LOG_TRIVIAL(debug) << "Top of main().";

int main() {  
    count_operations(16, 16 * 1028 * 1028, sort_functor(), normalized_by_nlogn1);
    count_operations(16, 16 * 1028 * 1028, sort_unique_functor(), normalized_by_nlogn1);
    count_operations(16, 16 * 1028 * 1028, setsort_functor(), normalized_by_nlogn1);
    count_operations(16, 16 * 1028 * 1028, setsort_unique_functor(), normalized_by_nlogn1);
    count_operations(16, 16 * 1028 * 1028, stable_sort_functor(), normalized_by_nlogn1);
    count_operations(16, 16 * 1028 * 1028, heap_sort_functor(), normalized_by_nlogn1);
}
                      
