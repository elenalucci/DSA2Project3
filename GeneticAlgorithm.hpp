#ifndef GeneticAlgorithm_hpp
#define GeneticAlgorithm_hpp

class GeneticAlgorithm{

	private:
		int numCities;
		int numTours;
		int numGenerations;
		double percentMutation;	

	public:
		GeneticAlgorithm();
		void SetNumCities(int numCities);
		void SetNumTours(int numTours);
		void SetNumGenerations(int numGenerations);
		void SetPercentMutation(double percentMutation);

};
#endif
