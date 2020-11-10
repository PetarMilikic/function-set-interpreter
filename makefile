PROG = interpreter
CC = g++
YACC = bison
lex = flex
CFLAGS = -std=c++14 -Wall -pedantic -ansi

$(PROG) : lex.yy.o parser.tab.o Set.o function.o 
	$(CC) $(CFLAGS) -o $@ $^
lex.yy.o : lex.yy.c
	$(CC) $(CFLAGS) -c -o $@ $<
parser.tab.o : parser.tab.cpp
	$(CC) $(CFLAGS) -c -o $@ $<
parser.tab.cpp parser.tab.hpp : parser.ypp
	$(YACC) -d -v $<
lex.yy.c : lexer.lex parser.tab.hpp
	$(LEX) $<
Set.o: Set.cpp Set.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
function.o: function.cpp function.hpp
	$(CC) $(CFLAGS) -c -o $@ $<


.PHONY: clean

clean:
	rm -f $(PROG) *.o *~ *.output *.tab.* *.c
