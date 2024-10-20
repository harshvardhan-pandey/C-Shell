#ifndef __HEADERS_H
#define __HEADERS_H

//system headers
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include <assert.h>

//custom headers
#include "prompt.h"
#include "commands/echo.h"
#include "commands/pwd.h"

//constant definitions
#define LEN 512

//global variable
extern char delims[3];
extern char homeDirectoryPath[LEN];
extern char userName[LEN];
extern char systemName[LEN];

#endif