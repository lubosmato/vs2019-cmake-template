@echo OFF
rmdir /q /s build
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
conan install . -if ./build/ -g cmake_find_package_multi -s build_type=Debug --build missing
conan install . -if ./build/ -g cmake_find_package_multi -s build_type=Release --build missing
