CC = gcc
CFLAGS = -g -lcurl -lxml2 -Wall -Wextra -Wconversion

SOURCES = main.c linked_list.c parse.c curl_data.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = weatherProgram

.PHONY: clean

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
