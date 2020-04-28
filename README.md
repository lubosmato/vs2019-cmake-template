# CMake template project for Visual Studio 2019

Contains a few examples how to use CMake with common C++ libraries and techniques.

- Uses [conan.io](https://conan.io/) package manager
- Supports resource files with version info and icon
- Has multi configuration Release/Debug
- Contains examples of:
  - Static library
  - Static library from external `.lib` file
  - Dynamic (shared) library
  - Binary `.exe` file with version and icon
  - Qt, OpenCV, Boost libraries usage
  - GTest tests
  - Nifty usage of CMake `CONFIGURE_DEPENDS` in `file(GLOB ...)`
