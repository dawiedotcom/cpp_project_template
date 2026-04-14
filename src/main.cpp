/// @file 
/// @brief Main entry point
///
/// @mainpage 
/// C++ Project template

#include <cstdlib>
#include <exception>
#include <iostream>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>
#include <boost/program_options/variables_map.hpp>

/// @brief Program entry point in a example project
int main(int argc, const char** argv) {
  namespace po = boost::program_options;

  try {
    // Variables and default values for optional arguments.
    unsigned int times = 1;

    // Optional arguments descriptions
    po::options_description optional_arguments("options");
    optional_arguments.add_options()
      ("times,n", po::value<unsigned int>(&times)->default_value(times), "An optional argument")
      ("help,h", "Displays this message")
      ;

    // All arguments
    po::options_description all_arguments("usage: main [options] positional");
    all_arguments.add(optional_arguments);
    all_arguments.add_options()("POSITIONAL", "A positional argument");

    // Define positions of positional arguments
    po::positional_options_description pos_opt_desc;
    pos_opt_desc.add("POSITIONAL", 1);

    // Parse
    po::variables_map variables_map;
    auto parser = po::command_line_parser(argc, argv)
      .options(all_arguments)
      .positional(pos_opt_desc)
      .run();
    po::store(parser, variables_map);
    po::notify(variables_map);

    // Print help
    if (variables_map.contains("help") || !variables_map.contains("POSITIONAL")) {
      std::cout 
        << "usage: main [options] POSITIONAL\n"
        << "  POSITIONAL              A positional argument\n"
        << optional_arguments 
        << "\n";
      return EXIT_SUCCESS;
    }

    // Do the work
    for (unsigned int i=0; i<times; i++) {
      std::cout << "Hello " << variables_map.at("POSITIONAL").as<std::string>() << "\n";
    }
  }
  catch (std::exception &e) {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }
  catch (...) {
    const std::exception_ptr exception = std::current_exception();
    std::clog <<(exception ? exception.__cxa_exception_type()->name() : "null") << '\n';
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
