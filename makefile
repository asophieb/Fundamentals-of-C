CC = gcc
CFLAGS = -Wall -Werror -ansi -lm

OBJ = Main.o LinkedList.o Login.o User.o Admin.o AddUser.o Validate.o Encrypt.o

rebuild : clean build

build : $(OBJ)
	$(CC) $(CFLAGS) -o Bank $(OBJ) 

clean :
	rm *.out *.o