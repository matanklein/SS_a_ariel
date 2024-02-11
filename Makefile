CC = gcc
FLAGS = -Wall -g

all: connections my_Knapsack

my_graph: my_graph.o my_mat.o
	$(CC) $(FLAGS) -o connections my_graph.o my_mat.o

my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

my_Knapsack: my_Knapsack.o
	$(CC) $(FLAGS) -o my_Knapsack my_Knapsack.o

my_Knapsack.o: my_Knapsack.c mat.h
	$(CC) $(FLAGS) -c my_Knapsack.c

clean:
	rm -f *.o connections my_Knapsack