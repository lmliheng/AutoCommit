CC = gcc
CFLAGS = -Wall
TARGET = commit
OBJ = src/commit.o

commit: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)