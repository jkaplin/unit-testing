# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_all.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 10:34:18 by jkaplin           #+#    #+#              #
#    Updated: 2019/03/02 10:37:17 by jkaplin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

var=1

printf "\n\n\n-----------------------------------------------------------------------------\n"
printf "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n\n"
make ...
printf "$var) "
./test memset
let "var++"
printf "$var) "
./test bzero
let "var++"
printf "$var) "
./test memcpy
let "var++"
printf "$var) "
./test memccpy
let "var++"
printf "$var) "
./test memmove
let "var++"
printf "$var) "
./test memchr
let "var++"
printf "$var) "
./test memcmp
let "var++"
printf "$var) "
./test strlen
let "var++"
printf "$var) "
./test strdup
let "var++"
printf "$var) "
./test strcpy
let "var++"
printf "$var) "
./test strncpy
let "var++"
printf "$var) "
./test strcat
let "var++"
printf "$var) "
./test strncat
let "var++"
printf "$var) "
./test strlcat
let "var++"
printf "$var) "
./test strchr
let "var++"
printf "$var) "
./test strrchr
let "var++"
printf "$var) "
./test strstr
let "var++"
printf "$var) "
./test strnstr
let "var++"
printf "$var) "
./test strcmp
let "var++"
printf "$var) "
./test strncmp
let "var++"
printf "$var) "
./test atoi
let "var++"
printf "$var) "
./test isalpha
let "var++"
printf "$var) "
./test isdigit
let "var++"
printf "$var) "
./test isalnum
let "var++"
printf "$var) "
./test isascii
let "var++"
printf "$var) "
./test isprint
let "var++"
printf "$var) "
./test toupper
let "var++"
printf "$var) "
./test tolower

