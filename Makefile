all:
	set -xe
	gcc blue.c -o test.elf -I/usr/include/freetype3 -I/usr/include/libpng16 -Wall -lGL -lGLU -lglut -lGLEW -lglfw -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor -lfreetype
	chmod +x test.elf
	./test.elf
