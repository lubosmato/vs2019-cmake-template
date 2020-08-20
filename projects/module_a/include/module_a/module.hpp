#pragma once

#include <boost/dll/alias.hpp>

struct ModuleA {
    virtual void doSomething();
};

ModuleA* createModule();

BOOST_DLL_ALIAS(
    createModule,
    createModule
)
