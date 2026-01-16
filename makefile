COMPILER: gcc
CFLAGS = -Wall -Wextra -g
TARGET = output

SRCS = main.c parser.c $(wildcard commands/*.c)

all:  
	$(CC) $(CFLAGS) $(S) $(SRCS) -o $(TARGET)

clean:
	 rm -f $(TARGET)

run: all 
		./$(TARGET)

