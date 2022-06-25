# simplexxd
simplexxd is a fast, straightforward hexdump utility. It reads a file and
outputs its bytes as unformatted lowercase hexadecimal characters.

## Prerequisites
- Boost (with its headers available to include in C++ source files)
- A C++17 compiler, aliased as `g++`
- make

## Quick Start
```sh
$ git clone https://github.com/thomasebsmith/simplexxd.git
$ cd simplexxd
$ make
$ ./build/simplexxd myfile
```

## License
simplexxd is licensed under the MIT License. See [LICENSE](./LICENSE) for
details.
