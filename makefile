SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

prog: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) -o prog $(patsubst src/,obj/,$(OBJ))

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $(COMPILE)/$(@F)  