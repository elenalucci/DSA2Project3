#include "BruteForce.hpp"

BruteForce::BruteForce(){
	numCities = 0;
	minDistance = 1000000000.00;
	graph.ReadFile();
}

void BruteForce::SetNumCities(int numCities){

	this->numCities = numCities;
	LoadS();
	
}

int BruteForce::GetNumCities(){

	return numCities;

}

void BruteForce::LoadS(){
	
	s = new int [numCities +1];	

	for(int i=0; i<numCities; i++){
		s[i] = i;
	}
	s[numCities] = 0;

	minArray = new int [numCities +1];

	for(int i=0; i <numCities; i++){
		minArray[i] = i;
	}
	minArray[numCities] = 0;
}

void BruteForce::PrintS(){
	

	std::cout <<"{";

	for(int i=0; i<numCities+1; i++){
		
		std::cout << s[i] <<", ";
	}

	std::cout <<"}";
	std::cout << std::endl;
}

void BruteForce::Permute(int permsThisCall){
	
	int m, k, p, q, i;
	int numElements = numCities;
	//PrintS();
	FindMin();
	for(i=1; i< permsThisCall; i++){
		m = numElements - 2;
		while(s[m] > s[m + 1]){
			m = m - 1;
		}

		k = numElements - 1;
		while(s[m] > s[k]){
			k = k - 1;
		}

		Swap(m,k);
		p = m + 1;
		q = numElements - 1;
		while( p < q){	
			Swap(p,q);
			p++;
			q--;
		}
		//PrintS();
		FindMin();
	}
}

void BruteForce::Swap(int a, int b){

	int temp = s[a];
	s[a] = s[b];
	s[b] = temp;
}

void BruteForce::FindMin(){
	double tempDistance = 0;

	for(int i=0; i<numCities;i++){
		tempDistance += graph.GetDistance(s[i],s[i+1]);
	}
	//std::cout << tempDistance << std::endl;

	if(tempDistance < minDistance){

		minDistance = tempDistance;
		for(int i=0; i <numCities+1; i++){
			minArray[i] = s[i];
		}
	}
}

int BruteForce::Factorial(int numCities){
	int num = numCities-1;
	int total =1;

	for(int i=1;i<num+1;i++){
		total *= i;
	}
	
	return total;

}

void BruteForce::DisplayResults(){
	std::cout<< "Cities visited: " << numCities << std::endl;
	std::cout<< "Optimal Cost from Brute Force: " << minDistance << std::endl;
	std::cout << "Optimal Tour: {";
	for(int i=0;i<numCities+1;i++){
		std::cout << minArray[i] << ",";
	}
	std::cout<< "}" << std::endl;
	std::cout<< "Time taken in Brute Force: " << std::endl;
}
