#ifndef LOGGING_H
#define LOGGING_H
#include "main_boost.h"

enum class Diagnostic_logging: int {
    trace,      // "A trace severity message"
    debug,      // "A debug severity message"
    info,       // "An informational severity message"
    warning,    // "A warning severity message"
    error,      // "An error severity message"
    fatal      // "A fatal severity message"
};

class Program_options;  // to avoid ciruclar include files

void my_boost_log_init(Program_options const& program_options);

void boost_log_init();

#endif // LOGGING_H
