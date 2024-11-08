out: main.o SDBAPP.o SDB.o
	gcc -o out main.o SDBAPP.o SDB.o

main.o: main.c SDB.h SDBAPP.h STD.h
	gcc -c main.c

SDBAPP.o: SDBAPP.c SDBAPP.h STD.h
	gcc -c SDBAPP.c

SDB.o: SDB.c SDB.h STD.h
	gcc -c SDB.c

run:
	./out.exe

all:
	gcc -c SDB.c
	gcc -c SDBAPP.c
	gcc -c main.c
	gcc -o out main.o SDBAPP.o SDB.o
	./out.exe

push:
	git add .
	git commit -m "$(msg)"
	git push -u origin main

OBJS = main.o SDBAPP.o SDB.o
Target = out
clean:
	rm $(OBJS) $(Target)
