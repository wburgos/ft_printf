clear
make re
gcc -g3 main.c -lftprintf -L. -I. -Iincludes/
./a.out
make fclean