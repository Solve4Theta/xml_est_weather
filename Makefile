CC = gcc
CFLAGS = -g -lcurl -lxml2 -Wall -Wextra -Wconversion

SOURCES = Homework_III_Uku_Kaarel_Metspalu_Main.c Homework_III_Uku_Kaarel_Metspalu_LinkedList.c Homework_III_Uku_Kaarel_Metspalu_Parse.c Homework_III_Uku_Kaarel_Metspalu_CurlData.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = weatherProgram

.PHONY: clean

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
