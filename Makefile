all: respatcher.cpp
	g++ -s -m32 respatcher.cpp -o respatcher.elf
	i586-mingw32msvc-g++ -s respatcher.cpp -o respatcher.exe
