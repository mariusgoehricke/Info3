#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{

    
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    int count =20;
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "Number of iterations")->default_val(count);
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());
    fmt::print("Die eingegebene Anzahl ist:{}\n",count);
    /* INSERT YOUR CODE HERE */
    std::vector<unsigned int> vec1 (count);

    for (int i = 0; i < count; ++i) {
        vec1[i] = std::rand() % 50;  // Zufallszahlen zwischen 0 und 99
        std::cout << vec1[i] << std::endl;
    }


    std::cout << "Vector aufsteigend sortiert:" << std::endl;
    for (int i : vec1){
        std::sort(vec1.begin(), vec1.end());
        std::cout << i << " ";
    }

    std::cout << std::endl;

    std::cout << "Vector absteigend sortiert:" << std::endl;
    for (int j : vec1){
        std::sort(vec1.end(), vec1.begin(), std::greater<int>());
        std::cout << j << " ";
    }
    return 0; /* exit gracefully*/
}
