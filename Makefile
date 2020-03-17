TARGET=main
# all .cpp files in this directory are my sources
SOURCES=$(wildcard *.cpp)

OBJS=$(SOURCES:.cpp=.o)

INC_DIR=../include
CC=g++
CFLAGS= -c -pedantic -Wall -ansi -g -I$(INC_DIR)
CXXFLAGS=$(CFLAGS)
LDLIBS = -lgtest -lgtest_main -pthread -g
.PHONY: clean run gdb
# linking
$(TARGET): $(OBJS)

include .depends

.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends

clean:
	rm -f $(OBJS) $(TARGET) .depends

run: $(TARGET)
	./$(TARGET)

memcheck: valgrid ./$(TARGET)

# Do not forget to add '-g' to CFLAGS
gdb: $(TARGET)
	gdb -q ./$(TARGET)

