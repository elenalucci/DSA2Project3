CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o Graph.o BruteForce.o GeneticAlgorithm.o

main: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS}

clean :
	rm ${OBJS} main Graph  BruteForce GeneticAlgorithm
