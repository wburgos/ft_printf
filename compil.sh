clear
make re
gcc -Wall -Wextra -Werror main.c -lftprintf -L. -I. -Iincludes/
./a.out
make fclean