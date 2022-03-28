#include "BruteForce.hpp"

BruteForce::BruteForce(){
	numCities = 0;
	minDistance = 1000000000.00;
	graph.ReadFile();
}

void BruteForce::setNumCities(int numCities){

	this->numCities = numCities;
	loadS();
	
}

int BruteForce::getNumCities(){

	return numCities;

}

void BruteForce::loadS(){
	
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

void BruteForce::printS(){
	

	std::cout <<"{";

	for(int i=0; i<numCities+1; i++){
		
		std::cout << s[i] <<", ";
	}

	std::cout <<"}";
	std::cout << std::endl;
}

void BruteForce::permute(int permsThisCall){
	
	int m, k, p, q, i;
	int numElements = numCities;
	//printS();
	findMin();
	for(i=1; i< permsThisCall; i++){
		m = numElements - 2;
		while(s[m] > s[m + 1]){
			m = m - 1;
		}

		k = numElements - 1;
		while(s[m] > s[k]){
			k = k - 1;
		}

		swap(m,k);
		p = m + 1;
		q = numElements - 1;
		while( p < q){	
			swap(p,q);
			p++;
			q--;
		}
		//printS();
		findMin();
	}
}

void BruteForce::swap(int a, int b){

	int temp = s[a];
	s[a] = s[b];
	s[b] = temp;
}

void BruteForce::findMin(){
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

int BruteForce::factorial(int numCities){
	int num = numCities-1;
	int total =1;

	for(int i=1;i<num+1;i++){
		total *= i;
	}
	
	return total;

}

void BruteForce::displayResults(){
	std::cout<< "Cities visited: " << numCities << std::endl;
	std::cout<< "Optimal Cost from Brute Force: " << minDistance << std::endl;
	std::cout << "Optimal Tour: {";
	for(int i=0;i<numCities+1;i++){
		std::cout << minArray[i] << ",";
	}
	std::cout<< "}" << std::endl;
	std::cout<< "Time taken in Brute Force: " << std::endl;
}
