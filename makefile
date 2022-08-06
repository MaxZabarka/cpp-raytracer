CC = g++
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
CFLAGS= -lSDL2 -lSDL2main -std=c++20 -Wall

raytracer: $(OBJ)
	$(CC)  $(LDFLAGS) $(LIBS) -o raytracer $(patsubst src/,obj,$(OBJ)) $(CFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o ./src/$(@F)  

run: raytracer
	./raytracer

clean :
	rm src/*.o
	rm raytracer