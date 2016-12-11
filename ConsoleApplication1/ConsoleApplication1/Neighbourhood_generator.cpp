#include "Neighbourhood_generator.hpp"
#include "Base.hpp"
#include <iostream>
#include <chrono>



using namespace std;
using namespace std::chrono;

bool Neighbourhood_generator::is_new(std::shared_ptr<Solution> candidate)
{
	std::multiset<Base> candidate_bases(candidate->bases.begin(), candidate->bases.end());

	if (generated.size() == 0)
		return true;
	if (begin(generated)->size() != candidate_bases.size())
		return true;
	return all_of(begin(generated), end(generated), [&](multiset<Base>& bases){
		for (auto it1 = begin(bases), it2 = begin(candidate_bases); it1 != end(bases); ++it1, ++it2) {
			if ((it1->x != it2->x) || (it1->y != it2->y))
				return true;
		}
		return false;
	});
}

std::shared_ptr<Solution> Neighbourhood_generator::next( std::shared_ptr<Solution> actual)
{
	auto t1 = high_resolution_clock::now();
	std::shared_ptr<Solution> neighbour = std::make_shared<Solution>(*actual);
	std::vector<Base> bases(neighbour->bases.begin(), neighbour->bases.end());

	int basic_nei_counter = 0;
	do
	{
		neighbour->bases = std::vector<Base>(actual->bases.begin(), actual->bases.end());
		unsigned int base = (std::rand() % (actual->bases.size() - 1)) + 1;
		int where_to_move = (std::rand() % 8); 
		Base & base2move = bases[base];
		while ( (base2move.x == 0 && (where_to_move == 0 || where_to_move >= 6 )) || (base2move.x == width && (where_to_move >= 2 && where_to_move <= 4)) || (base2move.y == 0 && (where_to_move >= 4 && where_to_move <= 6)) || (base2move.y == height && (where_to_move >= 0 && where_to_move <= 2)) )
		{		//when the base lies on the left border										//when the base lies on the right border								//when the base lies on the bottom border							//when the base lies on the upper border
			where_to_move = (std::rand() % 8);
		}
		if(base2move.x==0)
		{
			System::Diagnostics::Debug::WriteLine(where_to_move.ToString());
		}
		if (10 < basic_nei_counter++)
		{
			neighbour->move_rand(width,height);
		}
		else
		{
			neighbour->move(base2move, where_to_move);
		}
	} while (!this->is_new(neighbour));

	generated.push_back(std::multiset<Base>(neighbour->bases.begin(), neighbour->bases.end()));
	#ifdef BENCHMARKS
	std::cout << "generating new: " << duration_cast<milliseconds>(high_resolution_clock::now() - t1).count() << "ms" << std::endl;
	#endif BENCHMARKS
	return neighbour;
}
