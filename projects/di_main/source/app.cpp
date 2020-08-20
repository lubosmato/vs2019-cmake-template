#include "di_main/app.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <functional>
#include <boost/filesystem/path.hpp>
#include <boost/dll/import.hpp>

#include "module_a/module.hpp"

namespace dll = boost::dll;

void App::run() {
    std::cout << "Hello from modular app. Loading modules from dlls...\n";

    boost::filesystem::path dllPath = "module_a";
    using Factory = std::function<ModuleA*()>;
    auto factory = dll::import<Factory>(
        dllPath,
        "createModule",
        dll::load_mode::append_decorations
    );

    auto moduleA = (*factory)();
    moduleA->doSomething();
}
