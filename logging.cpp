#include "logging.h"
#include "main_boost.h"
#include "utils.h"

void my_boost_log_init(Program_options const& program_options) {  // todo there has to be a better way, but I don't want to study boost logging at this time.
    switch (program_options.diagnostic_logging) {
    case Diagnostic_logging::trace :
        boost::log::core::get()->set_filter( boost::log::trivial::severity >= boost::log::trivial::trace);  // maybe I don't need my Diagnostic_loggin enum, could have embedded boost's symbols here, but that would create a hard dependancy
        break;
    case Diagnostic_logging::debug :
        boost::log::core::get()->set_filter( boost::log::trivial::severity >= boost::log::trivial::debug);
        break;
    case Diagnostic_logging::info :
        boost::log::core::get()->set_filter( boost::log::trivial::severity >= boost::log::trivial::info);
        break;
    case Diagnostic_logging::warning :
        boost::log::core::get()->set_filter( boost::log::trivial::severity >= boost::log::trivial::warning);
        break;
    case Diagnostic_logging::error :
        boost::log::core::get()->set_filter( boost::log::trivial::severity >= boost::log::trivial::error);
        break;
    case Diagnostic_logging::fatal :
        boost::log::core::get()->set_filter( boost::log::trivial::severity >= boost::log::trivial::fatal);
        break;
    default:
        throw std::logic_error( program_options.this_executable_name + "::logging() switch: empty setting failure." );
//        break;
    };
}

void boost_log_init() {
        boost::log::core::get()->set_filter( boost::log::trivial::severity >= boost::log::trivial::info);
}

/*
        BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
        BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
        BOOST_LOG_TRIVIAL(info) << "An informational severity message";
        BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
        BOOST_LOG_TRIVIAL(error) << "An error severity message";
        BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
*/
