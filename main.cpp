#include <iostream>
#include <fstream>
#include "Graph.hpp"
#include "BruteForce.hpp"

int main(){

	int numCities;
	int numTours;
	int numGenerations;
	double percentMutation;
	Graph graph;
	BruteForce bf;

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
	bf.Permute(bf.Factorial(numCities));
	bf.DisplayResults();	

		
	return 0;
}
