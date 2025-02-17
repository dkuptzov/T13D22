CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
LIBS = cipher.c
# change ../build/cipher
QUEST1 = cipher

#all: $(TARGET)

#$(TARGET): $(LIBS)
#	$(CC) $(CFLAGS) $^ -o $(QUEST1)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

cipher: $(LIBS)
	$(CC) $(CFLAGS) $^ -o $(QUEST1)

.PHONY: clean

clean:
	rm -rf $(QUEST1) $(TARGET)

rebuild: clean $(TARGET)