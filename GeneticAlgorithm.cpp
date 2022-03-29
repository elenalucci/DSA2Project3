//DSA2 Project3 Elena Lucci
#include "GeneticAlgorithm.hpp"
#include "Graph.hpp"
#include <iostream>

GeneticAlgorithm::GeneticAlgorithm(){
	
	numCities = 0;
	numTours = 0;
	numGenerations = 0;
	percentMutation = 0.0;
	minDistance = 100000000.0;
	graph.ReadFile();

}

void GeneticAlgorithm::SetNumCities(int numCities){
	this->numCities = numCities;
	LoadArray();
}

void GeneticAlgorithm::SetNumTours(int numTours){
	this->numTours = numTours;
}

void GeneticAlgorithm::SetNumGenerations(int numGenerations){
	this->numGenerations = numGenerations;
}

void GeneticAlgorithm::SetPercentMutation(double percentMutation){
	this->percentMutation = percentMutation;
}
//creates array s and min array
void GeneticAlgorithm::LoadArray(){
	
	s = new int [numCities +1];
	
	for(int i=0; i<numCities; i++){
		s[i]=i;
	}
	
	s[numCities] = 0;

	minArray = new int [numCities +1];
	
	for(int i =0; i<numCities; i++){
		minArray[i] = i;
	}

	minArray[numCities] = 0;

}

void GeneticAlgorithm::Swap(int a, int b){

	int temp = s[a];
	s[a] = s[b];
	s[b] = temp;

}

void GeneticAlgorithm::PrintS(){

	std::cout<< "{";

	for(int i=0; i<numCities+1; i++){
		std::cout << s[i] << ", ";
	}

	std::cout << "}";
	std::cout <<std::endl;
}

void GeneticAlgorithm::Permute(int permsThisCall){
	int m, k, p, q, i;
	int numElements = numCities;
	
	//PrintS();
	FindMin();
	for(i=1; i<permsThisCall; i++){
		m = numElements - 2;
		while(s[m] > s[m+1]){
			m = m - 1;
		}
		
		k = numElements - 1;
		while(s[m] > s[k]){
			k = k - 1;
		}

		Swap(m,k);
		p = m + 1;
		q = numElements - 1;
		while(p < q){
			Swap(p,q);
			p++;
			q--;
		}
		
	//	PrintS();
		FindMin();
	}
}
//Compares each tour to find min distance and saves the tour with the min distance in minArray
void GeneticAlgorithm::FindMin(){
	double tempDistance = 0;

	for(int i=0; i < numCities; i++){
		tempDistance += graph.GetDistance(s[i],s[i+1]);
	}
	//std::cout << tempDistance << std::endl;

	if(tempDistance < minDistance){
		minDistance = tempDistance;
		for(int i=0; i<numCities+1;i++){
			minArray[i] = s[i];
		}
	}
	
	/*std::cout << "minArray: ";
	for(int i=0; i<numCities+1;i++){
		std::cout << minArray[i] << " ";
	}
	std::cout<<std::endl;
*/
}

void GeneticAlgorithm::Execute(){
	for(int i=0;i<numGenerations;i++){
		Permute(numTours - GenerateNumMutated());	
		for(int j=0;j<GenerateNumMutated();j++){
			Mutation();
		}
	SetElite();
	}
	DisplayResults();
}

int GeneticAlgorithm::GenerateNumMutated(){
	int num;

	num = numTours * percentMutation;
	return num;

}

void GeneticAlgorithm::Mutation(){
	
	int numElements = numCities;
	bool rand1 = false;

	srand(time(NULL));
	
	rand1 = rand() % 1;

	if(rand1 == 1){
		if(s[numElements/2] != 0){
			//std::cout << s[numElements/2] << "swap" << s[1] <<std::endl;
			Swap(s[numElements/2],s[1]);
		}
	}
	
	if(rand1 == 0){
	//std::cout<< s[1] <<"swap" <<s[numElements-1] << std::endl;
	if(s[1] > s[numElements-1]){
	Swap(s[1], s[numElements-1]);
	}
	else if(s[numElements-2] != 0){
		Swap(s[1],s[numElements-2]);
	}
}
	//PrintS();
	FindMin();
	
}

void GeneticAlgorithm::SetElite(){
	for(int i=0;i<numCities+1;i++){
		s[i] = minArray[i];
	}
/*	std::cout<< "New Elite: ";

	for(int i=0; i<numCities+1;i++){
		std::cout<<s[i] << ",";
	}

	std::cout<<std::endl;*/
}

void GeneticAlgorithm::DisplayResults(){
	
		std::cout<< "Optimal Cost from Genetic ALgorithm: " << minDistance << std::endl;
		std::cout << "Optimal Tour: {";
		for(int i=0;i<numCities+1;i++){
			std::cout <<minArray[i] << ", ";
		}
		std::cout << "}" << std::endl;
		std::cout<< "Percent Optimal: " << PercentOptimal() <<std::endl;
		std::cout<< "Time taken in Genetic ALgorithm: " << std::endl;
}

void GeneticAlgorithm::SetBFOptimal(double bfOptimal){
	this->bfOptimal = bfOptimal;
}

double GeneticAlgorithm::PercentOptimal(){

	return bfOptimal / minDistance;
}
