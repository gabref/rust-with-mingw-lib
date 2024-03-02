
# compile main using hte real library
# it only works on mingw
main:
	@echo "Compiling main"
	x86_64-w64-mingw32-g++ -o main.exe src/main.c -fpermissive -Iinclude -Llibs -static -Wl,--start-group -lMyLib -lkernel32 -luser32 -lgdi32 -lwinspool -lshell32 -lole32 -loleaut32 -luuid -lcomdlg32 -ladvapi32 -lwsock32 -lsetupapi -Wl,--end-group

# compile main with my test library
main_test: mylib_test
	@echo "Compiling main"
	x86_64-w64-mingw32-g++ -o main.exe src/main.c -fpermissive -Iinclude -Llibs -static -Wl,--start-group -lMyLibTest -lkernel32 -luser32 -lgdi32 -lwinspool -lshell32 -lole32 -loleaut32 -luuid -lcomdlg32 -ladvapi32 -lwsock32 -lsetupapi -Wl,--end-group

# compile my test library
mylib_test: clean
	@echo "Compiling MyLibTest"
	x86_64-w64-mingw32-gcc -o libMyLibTest.o -c src/MyLibTest.c -Iinclude
	ar rcs libMyLibTest.a libMyLibTest.o
	mv libMyLibTest.a libs

# after cargo build, which builds the dll, test it with this c program
test_rust_dll:
	@echo "Compiling Rust DLL"
	cargo build
	mv target/debug/rust_with_mingw_lib.dll librust_with_mingw_lib.dll
	@echo "Compiling with Rust DLL"
	x86_64-w64-mingw32-gcc -o test.exe src/test_dll.c -L. -lrust_with_mingw_lib
	# LD_LIBRARY_PATH=target/debug ./test.exe

clean: 
	rm -f main.exe test.exe libMyLibTest.a libMyLibTest.o

PHONY: compile_main clean
