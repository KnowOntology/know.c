# Hello, World! for Know.c

This is a trivial _"Hello, world!"_ example [built with CMake], serving to
validate that the Know Framework for C can be installed and used via Conan.

## Prerequisites

- [CMake] 3.15+
- [Conan] 2.4+

## Installing the Package

```console
$ conan remote add know https://conan.cloudsmith.io/knowontology/sdk/
$ conan download know.c -r know
```

## Cloning the Repository

```console
$ git clone https://github.com/KnowOntology/know.c.git
$ cd know.c
```

## Building the Example

```console
$ cd doc/examples/hello
$ conan install . --output-folder=build --build=missing
```

### Building the Example on macOS and Linux

```console
$ cd build
$ cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
$ cmake --build .
$ ./hello
```

### Building the Example on Windows

```console
$ cd build
$ cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -G "Visual Studio 15 2017"
$ cmake --build . --config Release
$ Release\hello.exe
```

[CMake]: https://cmake.org
[Conan]: https://conan.io

[built with CMake]: https://docs.conan.io/2/tutorial/consuming_packages/build_simple_cmake_project.html
