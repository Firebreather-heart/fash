CC=gcc 
CFLAGS = -I./inbuilt

fash.o: main.c tokenizer.c defcom.c path-manage.c utils.c utils.h path-manage.h defcom.h tokenizer.h inbuilt/cd.h
	gcc -I/inbuilt main.c tokenizer.c defcom.c path-manage.c utils.c utils.h path-manage.h defcom.h tokenizer.h inbuilt/cd.h -o runtime/fash.o

fash: fash.o
	gcc  runtime/fash.o -o runtime/fash