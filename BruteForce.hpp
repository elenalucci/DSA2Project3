#ifndef BruteForce_hpp
#define BruteForce_hpp
#include "Graph.hpp"
#include <iostream>

class BruteForce{

	private:
		int numCities;
		int * s;
		Graph graph;
		double minDistance;
		int * minArray;
				
	public:
		BruteForce();
		void setNumCities(int numCities);
		int getNumCities();
		void loadS();
		void printS();
		void permute(int permsThisCall);
		void swap(int a, int b);
		void findMin();
		int factorial(int numCities);
		void displayResults();


};

#endif
