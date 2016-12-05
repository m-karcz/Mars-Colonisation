#include "Neighbourhood_generator.hpp"

using namespace std;

bool Neighbourhood_generator::is_new(std::shared_ptr<Solution> candidate)
{
	if (generated.size() == 0)
		return true;
	if (begin(generated)->size() != candidate->bases.size())
		return true;
	return all_of(begin(generated), end(generated), [&](multiset<Base>& bases){
		for (auto it1 = begin(bases), it2 = begin(candidate->bases); it1 != end(bases); ++it1, ++it2) {
			if ((it1->x != it2->x) || (it1->y != it2->y))
				return true;
		}
		return false;
	});
}

std::shared_ptr<Solution> Neighbourhood_generator::next()
{

	std::shared_ptr<Solution> neighbour = std::make_shared<Solution>(*actual);
	do
	{
		unsigned int base_to_move = (std::rand() % (actual->bases.size() - 1)) + 1;
		int where_to_move = (std::rand() % 8);
		neighbour->move(base_to_move, where_to_move);
	} while (!this->is_new(neighbour));

	generated.push_back(neighbour->bases);
	return neighbour;
}
