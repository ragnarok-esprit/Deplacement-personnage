prog:main.o collision.o
	gcc main.o collision.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
collision.o:collision.c
	gcc -c collision.c
main.o:main.c
	gcc -c main.c
