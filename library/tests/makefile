#/*
#2018 Maximilian Wittmer
#wittmaxi@linux.pizza
#
#https://github.com/Wittmaxi/ZENeural/blob/master/LICENSE
#
#*/

all:
	g++ -lpthread -O0 --std=c++17 test_main.cpp -g -o test -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused
	time ./test
	rm -f ./test

test_cov:
	g++ -lpthread test_main.cpp -g -fprofile-arcs -ftest-coverage -o ./test
	gcov ./test_main.cpp -m
	rm -f ./*.gcov

valgrind:
	g++ -lpthread test_valgrind.cpp -g -o test
	valgrind ./test