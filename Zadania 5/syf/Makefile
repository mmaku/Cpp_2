GCC := g++
CC_FLAGS := --std=c++11 -Wall -g
SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)
NAME := zad3

tabiter: $(OBJ)
	$(GCC) -o $(NAME) $(OBJ) --std=c++11

%.o: %.cpp
	$(GCC) -o $@ -c $< $(CC_FLAGS)

clean:
	rm $(OBJ)

.PHONY: clean
