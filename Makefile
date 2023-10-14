OBJS =  main.o

.PHONY: all clean

all: main


main: $(OBJS)
	g++ -o $@  $(OBJS) -O3

%.o: %.cpp 
	g++ -c $< -Wall -O3 

clean:
	rm -rf *.o main

