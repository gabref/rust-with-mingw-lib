# rust-with-mingw-lib

* Third Party Lib: libs/libMyLib.a
* Third Party Header: include/LibHeader.h

## Requirements

Install msys64 and mingw64, do all the upgrades that the mingw64 docs say and then install the toolchain:
```
pacman -S mingw-w64-ucrt-x86_64-gcc
pacman -Suy
pacman -S base-devel gcc vim cmake
pacman -S cairo pkgconf
pacman -S mingw-w64-x86_64-toolchain
pacman -S mingw-w64-x86_64-rust
```

## Test Environment

Before using the libMyLib.a, just to check that everything is working. I'm doing this test on WSL. Let's create a simple lib that uses the Third Party Header, and the implementation will only do some printf's.
<br>
First, lets compile `src/MyLibTest.c` and create a static library `libs/libMyLibTest.a`

```
cc -o libMyLibTest.o -c src/MyLibTest.c -Iinclude
ar rcs libMyLibTest.a libMyLibTest.o
mv libMyLibTest.a libs
```

Then let's compile a main.c just to test that the static lib is working:
```
cc -o main src/main.c -Llibs -lMyLibTest
./main
```
Ok, everything is working. Let's try to create the rust .so using this static library. In the build.rs we are linking to the libMyLibTest.a, so just run 
```
cargo build
```
and then in the target/debug directory we will have our .so. To test it, just do:
```
mv target/debug/librust_with_mingw_lib.so .
cc -o test src/test_dll.c -L. -rust_with_mingw_lib
LD_LIBRARY_PATH=. ./test
```
everything seems to be working.

## Real Environment
Now, in the mingw terminal / Environment, we want to compile the actual third party library, `libs/libMyLib.a`. I tried many different methods, but I could not make it work. Testing the simple main.c compiling with the actual third party library works:
```
make main
./main.exe
```
It works. Now let's try to compile it with the rust project, here the problems start.
First, uncomment the section in the build.rs `link to actual library` and comment the `link to dummy library`, and then
```
cargo build
```

## What are we trying to solve?
1. Compile the Rust DLL for win_x86 and win_x64 linking to the cpp static library libMyLib.a.
2. Make it work with cross.rs, so that the development can be done on WSL and the compilation be done at once for win_x86 and win_x64.
3. It seems the `test environment` section works on mingw until we try to run the test.exe, but test.exe display's nothing, what is going on there?
