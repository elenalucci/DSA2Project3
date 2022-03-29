#ifndef GeneticAlgorithm_hpp
#define GeneticAlgorithm_hpp
#include "Graph.hpp"
#include "BruteForce.hpp"
#include <ctime>

class GeneticAlgorithm{

	private:
		int numCities;
		int numTours;
		int numGenerations;
		double percentMutation;
		double minDistance;
		int * s;
		int * minArray;
		Graph graph;
		double percentOptimal;
		double bfOptimal;
		
	public:
		GeneticAlgorithm();
		void SetNumCities(int numCities);
		void SetNumTours(int numTours);
		void SetNumGenerations(int numGenerations);
		void SetPercentMutation(double percentMutation);
		void LoadArray();
		void Swap(int a, int b);
		void PrintS();
		void Permute(int permsThisCall);	
		void FindMin();
		void Execute();	
		int GenerateNumMutated();	
		void Mutation();
		void SetElite();
		void DisplayResults();
		void SetBFOptimal(double bfOptimal);
		double PercentOptimal();
};
#endif
