/* .h

   Copyright (c) 2017 Grant Rostig. All rights reserved. Use by written permission only, evidenced with blue ink on paper or a verifyable (pgp) email interaction with Grant Rostig.
   Permission is granted to use these files during and in support of CppMSG meetup group events and projects.

   Inspired by: Caltech LFD

   Shows how to:
   -
   -
   -

// #include "../gsl/gsl"   // Standard C++ Foundation: C++14 Guidelines Support Library

// Variable naming convention to correspond to mathematical use of fonts.
// lc=Lower Case, uc=Upper Case, s=script (ie.not block characters), b=bold
*/
#ifndef UTILS_H
#define UTILS_H

//#pragma once
//#include "main_cppheaders.h"
//#include <>
#include "main_boost.h"
#include "logging.h"
#include "main_eigen.h"
#include <ratio>

using std::cin; using std::cerr; using std::cout; using std::endl;

enum class Program_algorithm: int {
    heoffding_inequality,
    perceptron,
    lin_reg_least_sq,
    lin_reg_4classification,
    lin_reg_4class_transformed,
    lin_reg_gradient_descent,
    lin_reg_stoch_grad_descent,
    lin_reg_4c_to_perceptron,
    lin_reg_bias_variance,
    logistic_regression,
    perceptron_multi_layer,
    test_of_graphing
};

enum class Numerical_library: int {
    eigen,
    tensorflow,
    armadillo,
    elemental,
    mxnet
};

enum class Numerical_types: int {
    int_type,
    float_type,
    double_type,
    bool_type
};

enum class Data_source: int {
    hardcoded_data,
    user_supplied_data,
    random_data
};

enum class HMLP_update_algorithm: int {  // perceptron_multi_layer, sub option
    first_point_both_w_lcb,     // experimental, this probably can never work
    first_point_first_w_lcb,    // experimental, this probably can never work
//    random_point_both_w_lcb,  // experimental, this probably can never work
//    random_point_first_w_lcb, // experimental, this probably can never work
    use_perfect_weights         // experimental, this is a hack to show that HMLP can work
};

enum class LRT_transform_algorithm: int { // lin_reg_transformed, sub option
    using_exponentiate_x0_x1_x2,  // todo doc
    using_2nd_order_polynomial     // todo doc
};

namespace po = boost::program_options;

class Program_options {  // data members are documented in main.cpp
public:
    Program_algorithm        algorithm =                        {};             // *** Selection of which one to run.
    bool                     update_random_point_perceptron =   {};  // true: perceptron should choose a random misclassification else use first one. // todo create a options structure that only allows currect subsettings like this one.
    HMLP_update_algorithm    hmlp_update_algorithm_strategy =   HMLP_update_algorithm::use_perfect_weights;
    LRT_transform_algorithm  lrt_transform_algorithm =          {};

    size_t        n_uc_num_samples =        {};            // number of data point/examples/observations/(events?)
    size_t        num_desired_trials =      {};            // Run multiple times to get averaged numbers.
    double        per_cent_noise =          {};            // 10% = 10.0 quanity of errors in label/ground truth.  NOTE: this feature is intended to be use with OLS or Pocket (which is not implemented yet)  not with the regular perceptron which requires total linear separability
    size_t        num_desired_propability_tests = {};

    unsigned long max_update_attempts_times_num_desired_trials = {};   // to avoid endless loops if bugs. Number may need adjusting for difficulty depending on which algorithm is used. // stops program if it is likely to be in an infinite loop. todo : create command line option
    unsigned int  sleep_micro_seconds =     {1000*1000};       // time to wait after display of graph plot. // uint required by std::usleep is there a better typedef?? todo // todo : create command line option

    Eigen_size_t  vector_size =             {3};            // Vector size is the sample dimensionalty + 1. Ie. for d=2 we have 3, and with zero origin vectors this results in: x0,x1,x2.  x0 is always one. What about when we leave off the y-intercept for bias variance analysis specific case?  todo
    Data_source   data_source =             Data_source::random_data; // todo : create command line option
    double        sample_space_upper_bound= {+1.0};        // typically  // todo : create command line option
    double        sample_space_lower_bound= {-1.0};                    // todo : create command line option

    bool          show_plot_graph =         {};             // display or not
    Diagnostic_logging diagnostic_logging = {};             // extra output beyond just reporting.
    std::string   this_executable_name =    { "grantrostig.com/ml_playgroud" }; // used for error messages used by exception handling.
    bool          measure_e_in =            {};             // check for mislabled points and report them.
    bool          measure_e_out =           {};             // Causes re-run of g() with a new set of points to measure "E out".  todo : clarify and verify
    size_t        num_desired_e_out_tests = {};             // changes accuracy of e_out, more is better/slower.
    po::variables_map * po_vm =             {};             // todo make this a smart pointer

    friend std::ostream& operator<<(std::ostream & os, Program_options const& d);
};

/* boost.program_options */
/* Function used to check that 'opt1' and 'opt2' are not specified
   at the same time.
   NOT USED YET todo */
void conflicting_options(const boost::program_options::variables_map& vm,
                         const char* opt1, const char* opt2);

/* Function used to check that of 'for_what' is specified, then
   'required_option' is specified too.
   NOT USED YET todo */
void option_dependency(const boost::program_options::variables_map& vm,
                        const char* for_what, const char* required_option);

template<typename Ratio>
constexpr double math_constant_pi() // pi pie archimedes ' constant.  https://stackoverflow.com/a/51609207/4484362
{
    long double const pi = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214L; // http://oeis.org/A000796/constant
    return static_cast<double>(pi * Ratio::num / Ratio::den);
}
template<typename Ratio>
constexpr double math_constant_e()  // ln() log() natural logarithm e constant
{
    long double const e = 2.71828182845904523536028747135266249775724709369995957496696762772407663035354759457138217852516642742746L;  // https://oeis.org/A001113
    return static_cast<double>(e * Ratio::num / Ratio::den);
}
template<typename Ratio>
constexpr double feet_per_meter()  // ln() log() natural logarithm e constant
{
    long double const e = 3.2808398950131233595800524934383202099737532808398950131233595800524934383202099L;  // http://oeis.org/A224233/constant
    // inches per meter  39.370078740157480314960629921259842519685039370078740157480314960629921259842519
    return static_cast<double>(e * Ratio::num / Ratio::den);
}
template<typename Ratio>
constexpr double speed_of_light_c()  // speed of light c in meters per second  m/sec
{
    long double const e = 299792458L;  // http://oeis.org/A224233/constant  NOTE: this is actually NOT a CONSTANT, but we say it is!!
    return static_cast<double>(e * Ratio::num / Ratio::den);
}

#endif // UTILS_H
