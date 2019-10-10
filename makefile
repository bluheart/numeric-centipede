main: main.c
	gcc -std=c99 -pedantic -Wall -Werror -o main main.c list.c higher_order.c
