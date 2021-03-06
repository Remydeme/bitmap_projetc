CXX= g++
CXXFLAGS= -std=c++14 -Wall -Werror -Wextra -pedantic -g3 -I $(INCLUDE_DIR)

EXEC= reader
SRC= $(wildcard ./src/*.cc)
OBJ= $(patsubst %.cc,%.o,$(wildcard ./src/*.cc))
INCLUDE_DIR=include 
LIB=bitmap.so
VPATH= src
RM=rm -rf

INCLUDE_DIRECTORIES=include

all: $(EXEC)

all_debug:  $(SRC) main.cc
	$(CXX) $(CXXFLAGS) -DDEBUG_MODE $^ -o $@

src/%.o: src/%.cc
	$(CXX) -c $(CXXFLAGS) -fPIC $< -o $@   

lib: $(LIB)

$(LIB) : $(OBJ)
	$(CXX) $(CXXFLAGS) -fPIC -shared  $^ -o $@
	$(RM) $(OBJ)
 
reader_lib: $(LIB) main.cc
	$(CXX) $(CXXFLAGS) -L. $(LIB)  $^ -o $@

$(EXEC) : $(SRC) main.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

clean: 
	$(RM) $(EXEC) $(LIB)

.PHONY: clean all 
