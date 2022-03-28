#include "Graph.hpp"

void Graph::ReadFile(){

	inFile.open("distances.txt");

     for(int i=0; i<20; i++){
     	for(int j=0; j<20; j++){
        	if(i == j){
            	graph[i][j] = 0;
            }
            else{
            	float value =0;
				inFile >> value;
                graph[i][j] = value;
            }
        }
     }

	 inFile.close();
}

double Graph::GetDistance(int i, int j){
	
	return graph[i][j];

}
