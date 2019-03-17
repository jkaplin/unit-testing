#!/bin/bash/python3

from subprocess import call

tests = [
	"memset",
	"bzero",
	"memcpy",
	"memccpy",
	"memmove",
	"memchr",
	"memcmp",
	"strlen",
	"strdup",
	"strcpy",
	"strncpy",
	"strcat",
	"strncat",
	"strlcat",
	"strchr",
	"strrchr",
	"strstr",
	"strnstr",
	"strcmp",
	"strncmp",
	"atoi",
	"isalpha",
	"isdigit",
	"isalnum",
	"isascii",
	"isprint",
	"toupper",
	"tolower",
	"memalloc",
	"memdel",
	"strnew",
	"strdel",
	"strclr",
	"striter",
	"striteri",
	"strmap",
	"strmapi",
	"strequ",
	"strnequ",
	"strsub",
	"strjoin",
	"strtrim",
	"strsplit",
	"itoa",
	"putchar",
	"putstr",
	"putendl",
	"putnbr",
	"putchar_fd",
	"putstr_fd",
	"putendl_fd",
	"putnbr_fd",
	"lstnew",
	"lstdelone",
	"lstdel",
	"lstadd",
	"lstiter",
	"lstmap"
]

print("\n\n\n-----------------------------------------------------------------------------\n")
print("VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n\n")
i = 1
while (i <= len(tests)):
    print(str(i) + ")", end =' ')
    if (tests[:2] == "put"):
        call("test_print.py")
    call("./test " + tests[i - 1])
