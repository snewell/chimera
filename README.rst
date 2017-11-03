chimera
=======
chimera is a library designed to manage the internals of Japanese-style role
playing games.


Building
--------
chimera uses CMake_ as its build system.  It requires a C++ 17 compiler, and
is currently tested using gcc-7.2.0 and clang-5.0 with libc++.

1. :code:`mkdir build`
2. :code:`cd build`
3. :code:`cmake path/to/chimera/src`
4. :code:`cmake --build .`
5. :code:`cmake --build . --target install`

Adjust the above if necessary, but that should be close to what you want.


.. _CMake: https://www.cmake.org
