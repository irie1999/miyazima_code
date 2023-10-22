OBJS =  main.o cal_Ne.o Ez.o set.o input.o

.PHONY: all clean

all: main


main: $(OBJS) 
	g++ -o $@  $(OBJS) -O3

%.o: %.cpp 
	g++ -c $< -Wall -O3 

clean:
	rm -rf *.o main

