echo OFF
mkdir build
cd build
conan install .. -g cmake_multi -s build_type=Debug --build missing
conan install .. -g cmake_multi -s build_type=Release --build missing
pause
