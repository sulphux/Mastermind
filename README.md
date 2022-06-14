# Mastermind

Mastermind is a simple board game ([wiki](https://en.wikipedia.org/wiki/Mastermind_(board_game))) about guessing the color pattern. This project implements this game as a C++ program.

## How to build

Project has been built on fedora remix 35 on WSL2 with CMake (ver:3.22.2) and it requires:
- g++ and gcc
- python
- make

To build, just run commands being inside root folder of project:
```bash

mkdir build
cd build
cmake ..

```

It should looks like:
```bash
[sulphux@DESKTOP-OQTF1Q9 Mastermind]$ pwd
/home/sulphux/winhome/source/repos/Mastermind
[sulphux@DESKTOP-OQTF1Q9 Mastermind]$ mkdir build
[sulphux@DESKTOP-OQTF1Q9 Mastermind]$ cd build
[sulphux@DESKTOP-OQTF1Q9 build]$ cmake ..
-- The C compiler identification is GNU 11.3.1
-- The CXX compiler identification is GNU 11.3.1
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found Python: /usr/bin/python3.10 (found version "3.10.4") found components: Interpreter
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Configuring done
-- Generating done
-- Build files have been written to: /home/sulphux/winhome/source/repos/Mastermind/build
```

After that procedure we also need to run ` make `:
```bash
[sulphux@DESKTOP-OQTF1Q9 build]$ make
[  5%] Building CXX object source/CMakeFiles/Mastermind_lib.dir/src/Arbiter.cpp.o
[ 10%] Building CXX object source/CMakeFiles/Mastermind_lib.dir/src/Code.cpp.o
[ 15%] Building CXX object source/CMakeFiles/Mastermind_lib.dir/src/CodeFactory.cpp.o
[ 21%] Building CXX object source/CMakeFiles/Mastermind_lib.dir/src/GameSession.cpp.o
[ 26%] Building CXX object source/CMakeFiles/Mastermind_lib.dir/src/Suggestion.cpp.o
[ 31%] Linking CXX static library libMastermind_lib.a
[ 31%] Built target Mastermind_lib
[ 36%] Building CXX object source/CMakeFiles/Mastermind.dir/Mastermind.cpp.o
[ 42%] Linking CXX executable ../bin/Mastermind
[ 42%] Built target Mastermind
[ 47%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 52%] Linking CXX static library ../../../lib/libgtest.a
[ 52%] Built target gtest
[ 57%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 63%] Linking CXX static library ../../../lib/libgtest_main.a
[ 63%] Built target gtest_main
[ 68%] Building CXX object tests/CMakeFiles/Mastermind-tests.dir/Code-test.cpp.o
[ 73%] Building CXX object tests/CMakeFiles/Mastermind-tests.dir/Arbiter-test.cpp.o
[ 78%] Linking CXX executable ../bin/Mastermind-tests
[ 78%] Built target Mastermind-tests
[ 84%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 89%] Linking CXX static library ../../../lib/libgmock.a
[ 89%] Built target gmock
[ 94%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[100%] Linking CXX static library ../../../lib/libgmock_main.a
[100%] Built target gmock_main
[sulphux@DESKTOP-OQTF1Q9 build]$
```
And now we  are able to run main executable and tests from ` bin` folder:
```bash
[sulphux@DESKTOP-OQTF1Q9 build]$ ls bin/
Mastermind  Mastermind-tests
[sulphux@DESKTOP-OQTF1Q9 build]$ ./bin/Mastermind
```

## Gameplay

Rules are simple, just type four digits unique code for guessing the code, for example *1564*.
Try to guess the code, you have 10 attempts, and digits are from range [1,8].
Game is showing you your last guesses with the hint, how many digits are in position or present but not at position on the right side of every attempt.
Program also inform you if you finished the game without solution or you win with exact code.

```
[sulphux@DESKTOP-OQTF1Q9 build]$ ./bin/Mastermind
Welcome to Mastermind game!

Try to guess the code! Code has 4 digits, which should be unique
each other and also in range = [1,8]

You have 10 attempts

Let's start!


---------------------------------------------------------
write your next guess:
1564

---------------------------------------------------------
your last guesses:
Attempt 1: | 1 | 5 | 6 | 4 | | AtPos: 2 | NotAtPos: 0 |
write your next guess:
2367

---------------------------------------------------------
your last guesses:
Attempt 1: | 1 | 5 | 6 | 4 | | AtPos: 2 | NotAtPos: 0 |
Attempt 2: | 2 | 3 | 6 | 7 | | AtPos: 1 | NotAtPos: 1 |
write your next guess:
2356

---------------------------------------------------------
your last guesses:
Attempt 1: | 1 | 5 | 6 | 4 | | AtPos: 2 | NotAtPos: 0 |
Attempt 2: | 2 | 3 | 6 | 7 | | AtPos: 1 | NotAtPos: 1 |
Attempt 3: | 2 | 3 | 5 | 6 | | AtPos: 0 | NotAtPos: 2 |
write your next guess:

```
Have fun!

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)