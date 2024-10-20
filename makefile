CFLAGS = -Wall -g
SOURCE_FILES = main.c prompt.c commands/echo.c
OUTPUT_FILENAME = shell.out

all:
	gcc ${CFLAGS} ${SOURCE_FILES} -o ${OUTPUT_FILENAME}

clean:
	rm -f ./${OUTPUT_FILENAME} .history.txt