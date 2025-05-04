game:main.o menu.o minimap.o minmaxf.o perso.o collisionPP.o quiz.o enemie.o background.o scrolling.o
	gcc main.o minmaxf.o menu.o minimap.o perso.o collisionPP.o quiz.o enemie.o background.o scrolling.o -o game -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer -lSDL_gfx
menu.o:menu.c
	gcc -c menu.c -g
minimap.o:minimap.c
	gcc -c minimap.c -g
main.o:main.c
	gcc -c main.c -g
perso.o:perso.c
	gcc -c perso.c -g
quiz.o:quiz.c
	gcc -c quiz.c -g
enemie.o:enemie.c
	gcc -c enemie.c -g
collisionPP.o:collisionPP.c
	gcc -c collisionPP.c -g
background.o:background.c
	gcc -c background.c -g
scrolling.o:scrolling.c
	gcc -c scrolling.c -g
minmaxf.o:minmaxf.c
	gcc -c minmaxf.c -g


