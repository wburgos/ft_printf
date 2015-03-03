clear
make re
clang -g3 main.c -lftprintf -L. -I. -Iincludes/
./a.out
make fclean