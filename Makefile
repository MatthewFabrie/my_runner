CC	= gcc
CFLAGS	= -W -Wall -Wextra -g3
CPPFLAGS	= -I/usr/local/include
LDFLAGS	= 	-L/usr/share/doc -lcsfml-graphics -lcsfml-window -lcsfml-system\
-lcsfml-audio -lm

SRC	=	$(wildcard *.c)
OBJ	=	$(SRC:.c=.o)

TARGET	=	my_runner

all	:	$(TARGET)

$(TARGET)	:	$(OBJ)
			$(CC) -o $@ $^ $(LDFLAGS)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(TARGET)

re	:	fclean all
