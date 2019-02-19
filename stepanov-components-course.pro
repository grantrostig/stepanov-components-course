# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

TARGET = stepanov-components-course

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        code/lecture2/singleton.cpp

HEADERS = \
#   $$PWD/code/lecture1/concepts.h \
#   $$PWD/code/lecture1/count_operations.h \
#   $$PWD/code/lecture1/functorized.h \
#   $$PWD/code/lecture1/iota.h \
#   $$PWD/code/lecture1/setsort.h \
#   $$PWD/code/lecture1/table_util.h \
#   $$PWD/code/lecture10/algorithm.h \
#   $$PWD/code/lecture10/binary_counter.h \
#   $$PWD/code/lecture10/list_pool.h \
#   $$PWD/code/lecture10/min_element1_2.h \
#   $$PWD/code/lecture10v2/algorithm.h \
#   $$PWD/code/lecture10v2/binary_counter.h \
#   $$PWD/code/lecture10v2/list_pool.h \
#   $$PWD/code/lecture10v2/min_element1_2.h \
#   $$PWD/code/lecture11/algorithm.h \
#   $$PWD/code/lecture11/binary_counter.h \
#   $$PWD/code/lecture11/list_pool.h \
#   $$PWD/code/lecture11/min_element1_2.h \
#   $$PWD/code/lecture12/algorithm.h \
#   $$PWD/code/lecture12/binary_counter.h \
#   $$PWD/code/lecture12/list_algorithm.h \
#   $$PWD/code/lecture12/list_pool.h \
#   $$PWD/code/lecture12/merge_linked.h \
#   $$PWD/code/lecture13/search.h \
#   $$PWD/code/lecture14/algorithm.h \
#   $$PWD/code/lecture14/merge_inplace.h \
#   $$PWD/code/lecture14/search.h \
#   $$PWD/code/lecture15/algorithm.h \
#   $$PWD/code/lecture15/merge.h \
#   $$PWD/code/lecture15/merge_inplace.h \
#   $$PWD/code/lecture15/search.h \
#   $$PWD/code/lecture15/test_sort.h \
#   $$PWD/code/lecture15/timer.h \
#   $$PWD/code/lecture15/type_description.h \
#   $$PWD/code/lecture17/algorithm.h \
#   $$PWD/code/lecture17/insertion_sort.h \
#   $$PWD/code/lecture17/merge.h \
#   $$PWD/code/lecture17/merge_inplace.h \
#   $$PWD/code/lecture17/search.h \
#   $$PWD/code/lecture17/test_sort.h \
#   $$PWD/code/lecture17/timer.h \
#   $$PWD/code/lecture17/type_description.h \
#   $$PWD/code/lecture18/algorithm.h \
#   $$PWD/code/lecture18/insertion_sort.h \
#   $$PWD/code/lecture18/merge.h \
#   $$PWD/code/lecture18/merge_inplace.h \
#   $$PWD/code/lecture18/search.h \
#   $$PWD/code/lecture18/test_sort.h \
#   $$PWD/code/lecture18/timer.h \
#   $$PWD/code/lecture18/type_description.h \
#   $$PWD/code/lecture19/algorithm.h \
#   $$PWD/code/lecture19/insertion_sort.h \
#   $$PWD/code/lecture19/merge.h \
#   $$PWD/code/lecture19/merge_inplace.h \
#   $$PWD/code/lecture19/search.h \
#   $$PWD/code/lecture19/test_sort.h \
#   $$PWD/code/lecture19/timer.h \
#   $$PWD/code/lecture19/type_description.h \
   $$PWD/code/lecture2/singleton.h \
#   $$PWD/code/lecture20/algorithm.h \
#   $$PWD/code/lecture20/insertion_sort.h \
#   $$PWD/code/lecture20/merge.h \
#   $$PWD/code/lecture20/merge_inplace.h \
#   $$PWD/code/lecture20/search.h \
#   $$PWD/code/lecture20/sort_akraft.h \
#   $$PWD/code/lecture20/sort_bert.h \
#   $$PWD/code/lecture20/sort_ph.h \
#   $$PWD/code/lecture20/sort_rjernst.h \
#   $$PWD/code/lecture20/test_sort.h \
#   $$PWD/code/lecture20/timer.h \
#   $$PWD/code/lecture20/type_description.h \
#   $$PWD/code/lecture3/concepts.h \
#   $$PWD/code/lecture3/count_operations.h \
#   $$PWD/code/lecture3/functorized.h \
#   $$PWD/code/lecture3/instrumented.h \
#   $$PWD/code/lecture3/iota.h \
#   $$PWD/code/lecture3/setsort.h \
#   $$PWD/code/lecture3/singleton.h \
#   $$PWD/code/lecture3/table_util.h \
#   $$PWD/code/lecture4/min.h \
#   $$PWD/code/lecture4/swap.h \
#   $$PWD/code/lecture5/algorithm.h \
#   $$PWD/code/lecture5/concepts.h \
#   $$PWD/code/lecture5/minmax.h \
#   $$PWD/code/lecture5/timed.h \
#   $$PWD/code/lecture6/binary_counter.h \
#   $$PWD/code/lecture7/binary_counter.h \
#   $$PWD/code/lecture8/binary_counter.h \
#   $$PWD/code/lecture8/list_pool.h \
#   $$PWD/code/lecture9/binary_counter.h \
#   $$PWD/code/lecture9/list_pool.h \
#   $$PWD/code/lecture9/min_element1_2.h

#SOURCES = \
#   $$PWD/code/lecture1/count_operations.cpp \
#   $$PWD/code/lecture1/count_operations_normalized.cpp \
#   $$PWD/code/lecture10/min.cpp \
#   $$PWD/code/lecture10v2/min.cpp \
#   $$PWD/code/lecture11/lisp/binary-counter.lisp \
#   $$PWD/code/lecture11/lisp/min.lisp \
#   $$PWD/code/lecture11/lisp/util.lisp \
#   $$PWD/code/lecture11/python/min.py \
#   $$PWD/code/lecture11/min.cpp \
#   $$PWD/code/lecture12/sort.cpp \
#   $$PWD/code/lecture14/sort.cpp \
#   $$PWD/code/lecture15/ideas.txt \
#   $$PWD/code/lecture15/sort.cpp \
#   $$PWD/code/lecture15/test_sort.cpp \
#   $$PWD/code/lecture17/ideas.txt \
#   $$PWD/code/lecture17/sort.cpp \
#   $$PWD/code/lecture17/test_insertion_sort.cpp \
#   $$PWD/code/lecture17/test_sort.cpp \
#   $$PWD/code/lecture18/ideas.txt \
#   $$PWD/code/lecture18/sort.cpp \
#   $$PWD/code/lecture18/test_insertion_sort.cpp \
#   $$PWD/code/lecture18/test_sort.cpp \
#   $$PWD/code/lecture19/ideas.txt \
#   $$PWD/code/lecture19/sort.cpp \
#   $$PWD/code/lecture19/test_insertion_sort.cpp \
#   $$PWD/code/lecture19/test_sort.cpp \
#   $$PWD/code/lecture2/singleton.cpp \
#   $$PWD/code/lecture20/ideas.txt \
#   $$PWD/code/lecture20/sort.cpp \
#   $$PWD/code/lecture20/test.cpp \
#   $$PWD/code/lecture20/test_insertion_sort.cpp \
#   $$PWD/code/lecture20/test_sort.cpp \
#   $$PWD/code/lecture3/count_operations.cpp \
#   $$PWD/code/lecture3/count_operations_normalized.cpp \
#   $$PWD/code/lecture3/instrumented.cpp \
#   $$PWD/code/lecture4/example.cpp \
#   $$PWD/code/lecture5/minmax.cpp \
#   $$PWD/code/lecture6/min.cpp \
#   $$PWD/code/lecture7/min.cpp \
#   $$PWD/code/lecture8/min.cpp \
#   $$PWD/code/lecture9/min.cpp

#INCLUDEPATH = \
#    $$PWD/code/lecture1 \
#    $$PWD/code/lecture10 \
#    $$PWD/code/lecture10v2 \
#    $$PWD/code/lecture11 \
#    $$PWD/code/lecture12 \
#    $$PWD/code/lecture13 \
#    $$PWD/code/lecture14 \
#    $$PWD/code/lecture15 \
#    $$PWD/code/lecture17 \
#    $$PWD/code/lecture18 \
#    $$PWD/code/lecture19 \
#    $$PWD/code/lecture2 \
#    $$PWD/code/lecture20 \
#    $$PWD/code/lecture3 \
#    $$PWD/code/lecture4 \
#    $$PWD/code/lecture5 \
#    $$PWD/code/lecture6 \
#    $$PWD/code/lecture7 \
#    $$PWD/code/lecture8 \
#    $$PWD/code/lecture9

#   $$PWD/papers/knuth-computer-programming-as-art.pdf \
#   $$PWD/papers/mcilroy-components.txt \
#   $$PWD/papers/quicksort.pdf \
#   $$PWD/papers/trusting-trust-thompson.pdf \
#   $$PWD/code/lecture16/concepts A9.pdf \
#   $$PWD/code/lecture16/concepts A9.pptx \
#   $$PWD/code/lecture16/concepts design for stl.pdf \
#   $$PWD/code/lecture16/concepts lite.pdf \

#DEFINES = 

