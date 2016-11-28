#include "Neighbourhood_generator.hpp"

bool Neighbourhood_generator::is_new(Solution & candidate)
{
	return(generated.end() ==  generated.find(candidate.bases));
}
/*
Solution Neighbourhood_generator::next()
{
	Solution neighbour;
	neighbour = actual;
	do
	{
		int base_to_move = (std::rand() % (actual.bases.size() - 1)) + 1;
		int where_to_move = (std::rand() % 8);
		actual.move(base_to_move, where_to_move);
	} while (this->is_new(neighbour));
	generated.push(neighbour)
	return neighbour;
}*/
