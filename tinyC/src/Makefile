TARGET=tinyC
GCC11=-std=c++11
AST_SRC=$(wildcard ast/*.cpp) $(wildcard ast/*/*.cpp)
C_SRCFILES=${TARGET}_parser.cpp ${TARGET}_lexer.cpp $(AST_SRC) main.cpp
OBJ_FILES=${C_SRCFILES:.cpp=.o}
TOKENS=tokens.h
.PHONY:	clean

all: ${TARGET}

$(TARGET):	$(OBJ_FILES)
	g++ $(GCC11) -o $@ $(OBJ_FILES)

${TARGET}_lexer.cpp: ${TARGET}.l
	flex -i -o $@ $<

${TARGET}_parser.cpp: ${TARGET}.y
	bison -Werror --report=all --defines=${TOKENS} -o $@ $<

%.o: %.cpp ${TOKENS}
	g++ $(GCC11) -c -o $@ $@

clean:
	rm -f $(wildcard *.o)
	rm -f $(wildcard ast/*.o)
	rm -f $(wildcard ast/statements/*.o)
	rm -f ${TARGET}_lexer.cpp
	rm -f ${TARGET}_parser.cpp
	rm -f ${TOKENS}
	rm -f ${TARGET}
	rm -f ${TARGET}_parser.output