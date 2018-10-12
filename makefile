CC = gcc
CFLAGS = -Wall -Werror -ansi -lm
OBJ = Main.o LinkedList.o Login.o User.o Admin.o AddUser.o Validate.o Encrypt.c Log.o

build : $(OBJ)
	$(CC) $(CFLAGS) -o Bank $(OBJ) 

debug : $(OBJ)
	$(CC) $(CFLAGS) -DDEBUG=1 -o Bank $(OBJ) 

clean :
	rm *.out *.o