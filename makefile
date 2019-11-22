all: main run

main: main.o reg.o reg_validate.o
	gcc main.o reg.o reg_validate.o -o main

main.o: main.c
	gcc -c main.c

reg.o: reg.c
	gcc -c reg.c

reg_validate.o: reg_validate.c
	gcc -c reg_validate.c

clear:
	rm *.o

run:
	./main "1abcdban1333" "\d[abc]\w[^abc2]\d\d\d"

test: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11

test1:
	./main "abc123abc321123" "/w/w/w/d/d/d[abc][^123][12c]"

test2:
	./main "abc" "/w/w/d"

test3:
	./main "123" "/d/d/w"

test4:
	./main "abc" "/w/w"

test5:
	./main "abc123d" "/w/w/w[^3214]"

test6:
	./main "ab" "/w/w/w"

test7:
	./main "abc" "/w/w/w"

test8:
	./main "abc /d" "/w/w/w/d"

test9:
	./main "abcd12245" "/w/w/w/w[12245]"

test10:
	./main "ABC[aA]" "/w/w/w[aa]"

test11:
	./main "abcd" "\w[bcd"

