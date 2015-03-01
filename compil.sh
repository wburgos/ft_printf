clear
make re
gcc -Wall -Wextra -Werror -g3 main.c -lftprintf -lefence -L. -I. -Iincludes/
./a.out