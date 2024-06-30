CC = gcc
TESTFLAGS = -lcheck -g
CFLAGS = -Wall -Wextra -Werror -std=c11
TESTFLAGS2 = -lcheck -lm -lpthread -lrt -lsubunit -g
GCOVFLAGS = -fprofile-arcs -ftest-coverage

all: test

s21_matrix.a: matrix/*.c
	$(CC) $(CFLAGS) -g -std=c11 -c matrix/*.c
	ar rcs s21_matrix.a *.o
	rm -rf *.o

test: test_matrix.c matrix/*.c
	$(CC) $(CFLAGS) test_matrix.c matrix/*.c -o test $(TESTFLAGS)

gcov_report:
	$(CC) $(GCOVFLAGS) $(CFLAGS) test_matrix.c matrix/*.c -o test $(TESTFLAGS)
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	rm -rf gcovreport gcovreport.info *.gcda *.gcno string_test.gcda string_test.gcno

rebuild: clean all

clean: 
	rm -rf *.o test *.a a.out *.gcno *.gcda test.dSYM *.info report

style_check:
	clang-format -style=Google -n *.c *.h *.c

style:
	clang-format -style=Google -i *.c *.h *.c
