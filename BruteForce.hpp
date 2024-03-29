//DSA2 Project3 Elena Lucci
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
		void SetNumCities(int numCities);
		int GetNumCities();
		void LoadS();
		void PrintS();
		void Permute(int permsThisCall);
		void Swap(int a, int b);
		void FindMin();
		int Factorial(int numCities);
		void DisplayResults();
		void Execute();
		double GetMinDistance();
};

#endif
