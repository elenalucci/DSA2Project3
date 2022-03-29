//DSA2 Project 3 Elena Lucci
#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Graph.hpp"
#include "BruteForce.hpp"
#include "GeneticAlgorithm.hpp"

int main(){

	int numCities;
	int numTours;
	int numGenerations;
	double percentMutation;
	Graph graph;
	BruteForce bf;
	GeneticAlgorithm ga;

	std::cout << "Enter the number of cities to run: ";
	std::cin >> numCities;
	std::cout << std::endl;
	std::cout << "Enter the number of tours in a given generation: ";
	std:: cin >> numTours;
	std::cout << std::endl;
	std::cout << "Enter the number of generations to run: ";
	std::cin >> numGenerations;
	std::cout << std::endl;
	std::cout << "Enter the percentage each generation comprised of mutated tours as a decimal (ie: 0.0): ";
	std::cin >> percentMutation;
	std::cout << std::endl;

	bf.SetNumCities(numCities);
	
	struct timeval * t;
	
	t= (struct timeval *)malloc(sizeof(struct timeval));
	gettimeofday(t,NULL);
	time_t startSec = t -> tv_sec;

	bf.Execute();

	gettimeofday(t, NULL);
	printf("\n seconds: %d.%d", t-> tv_sec - startSec, t-> tv_usec);

	std::cout<< std::endl;
	std::cout << std::endl;

	ga.SetNumCities(numCities);
	ga.SetNumTours(numTours);
	ga.SetNumGenerations(numGenerations);
	ga.SetPercentMutation(percentMutation);
	ga.SetBFOptimal(bf.GetMinDistance());

	struct timeval * time;
	time =(struct timeval *)malloc(sizeof(struct timeval));
	gettimeofday(time, NULL);
	time_t startSecond = time -> tv_sec;

	ga.Execute();

	gettimeofday(time, NULL);
	printf("\n seconds: %d.%d", time-> tv_sec - startSecond, time-> tv_usec);
	

	return 0;
}
