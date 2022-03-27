#ifndef Graph_hpp
#define Graph_hpp
#include <fstream>

class Graph{

	private:
		std::ifstream inFile;
		double graph[20][20];

	public:
		void ReadFile();
		double GetDistance(int i, int j);	

};

#endif
