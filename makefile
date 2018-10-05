CC = gcc
CFLAGS = -Wall -Werror -ansi -lm

OBJ = Main.o LinkedList.o Login.o User.o Admin.o AddUser.o Validate.o

rebuild : clean build

build : $(OBJ)
	$(CC) $(CFLAGS) -o Bank.out $(OBJ) 

LinkedList.o :
	$(CC) $(CFLAGS) -o LinkedList.o LinkedList.c

Login.o : 
	$(CC) $(CFLAGS) -o Login.o Login.c

User.o : 
	$(CC) $(CFLAGS) -o User.o User.c

Admin.o : 
	$(CC) $(CFLAGS) -o Admin.o Admin.c

AddUser.o :
	$(CC) $(CFLAGS) -o AddUser.o AddUser.c

Validate.o :
	$(CC) $(CFLAGS) -o Validate.o Validate.c


clean :
	rm *.out *.o