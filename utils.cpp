/* .cpp

   Copyright (c) 2017 Grant Rostig. All rights reserved. Use by written
   permission only, evidenced with blue ink on paper or a verifyable (pgp) email
   interaction with Grant Rostig.
   Permission is granted to use these files during and in support of CppMSG
   meetup group events and projects.

   Inspired by: -

   Shows how to:
   -
   -
   -
*/
#include "utils.h"
#include "main_boost.h"
#include "reporting.h"

std::ostream& operator<<(std::ostream & os, Program_options const& d) {  // compile error if placed in .cpp file - claims 3 parameters??? todo
    std::string program_algorithm = (*d.po_vm)["algorithm"].as<std::string>() ;
    std::string lrt_transform_algorithm = (*d.po_vm)["lrt_transform_algorithm"].as<std::string>();
    lrt_transform_algorithm.resize(20);             // consider marking string as having been truncated.
            //          "12345678901234567890"
    os      << rpt_separator('|')
            << rpt_cell("program_algorithm",41)  // taking two fields plus one separator char.
            << rpt_cell("updt_rndpt_perceptrn",20)
            << rpt_cell("lrt_transform_algor>",20)  // using / to show truncation of value todo rethink abbreviation of some other values here.

            << rpt_cell("n_uc_num_samples",20)
            << rpt_cell("num_desired_trials",20)
            << rpt_cell("per_cent_noise",20)
            << rpt_cell("n_desired_propab_tts",20)

            << rpt_cell("show_plot_graph",20)
            << rpt_cell("diagnostic_logging",20)

            << rpt_cell("measure_e_in",20)
            << rpt_cell("measure_e_out",20)
            << rpt_cell("n_desird_e_out_tests",20)
            << endl
            << "==================================================================================" << endl;
    os      << rpt_separator('|')
            << rpt_cell(program_algorithm,41)  // need to rethink sizing of cells and how to parameterize them  todo
            << rpt_cell(d.update_random_point_perceptron,20)
            << rpt_cell(lrt_transform_algorithm,20)

            << rpt_cell(d.n_uc_num_samples,20)
            << rpt_cell(d.num_desired_trials,20)
            << rpt_cell(d.per_cent_noise,20)
            << rpt_cell(d.num_desired_propability_tests,20)

            << rpt_cell(d.show_plot_graph,20)
            << rpt_cell((*d.po_vm)["diagnostic_logging"].as<std::string>(),20)

            << rpt_cell(d.measure_e_in,20)
            << rpt_cell(d.measure_e_out,20)
            << rpt_cell(d.num_desired_e_out_tests,20)

//            << rpt_custom_cell(rpt_field(static_cast<int>(d.algorithm),20))  // alternative use
            << endl;
    return os;
}


/* boost.program_options */
/* Function used to check that 'opt1' and 'opt2' are not specified
   at the same time.
   NOT USED YET todo */
void conflicting_options(const boost::program_options::variables_map& vm,
                         const char* opt1, const char* opt2)
{
    if (vm.count(opt1) && !vm[opt1].defaulted()
        && vm.count(opt2) && !vm[opt2].defaulted())
        throw std::logic_error(std::string("Conflicting options '")
                          + opt1 + "' and '" + opt2 + "'.");
}

/* Function used to check that of 'for_what' is specified, then
   'required_option' is specified too.
    NOT USED YET todo */
void option_dependency(const boost::program_options::variables_map& vm,
                        const char* for_what, const char* required_option)
{
    if (vm.count(for_what) && !vm[for_what].defaulted())
        if (vm.count(required_option) == 0 || vm[required_option].defaulted())
            throw std::logic_error(std::string("Option '") + for_what
                              + "' requires option '" + required_option + "'.");
}

class E_too_many_attempts : public std::exception { // todo what is this thing?
  virtual const char *what() const throw() {
    return "Too_many_attempts_exception happened";
  }
};

