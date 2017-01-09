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

bool Neighbourhood_generator::is_inside(std::shared_ptr<Solution> candidate)
{
	for (auto & base : candidate->bases)
	{
		if (base.x < 0 || base.x > width || base.y < 0 || base.y > height)
		{
			return false;
		}
	}
	return true;
}
 

std::shared_ptr<Solution> Neighbourhood_generator::next( std::shared_ptr<Solution> actual)
{
	auto t1 = high_resolution_clock::now();
	std::shared_ptr<Solution> neighbour = std::make_shared<Solution>(*actual);

	int basic_nei_counter = 0;
	do
	{
		int neighbourhood_type = std::rand() % 3;
		switch(neighbourhood_type)
		{
			case 0:
				if (0.1 < actual_temp / start_temp)
				{
					neighbour = generate_wider_neighbourhood(actual);
					simple_used = false;
					break;
				}
			case 2:
				neighbour = generate_simple_neighbourhood(actual);
				simple_used = true;
				break;
			case 1:
				neighbour = generate_random_neighbourhood(actual);
				simple_used = false;
				break;
			
		}
	} while (!this->is_new(neighbour) || !(this->is_inside(neighbour)) );

	generated.push_back(std::multiset<Base>(neighbour->bases.begin(), neighbour->bases.end()));
	#ifdef BENCHMARKS
	std::cout << "generating new: " << duration_cast<milliseconds>(high_resolution_clock::now() - t1).count() << "ms" << std::endl;
	#endif BENCHMARKS
	return neighbour;
}

std::shared_ptr<Solution>  Neighbourhood_generator::generate_simple_neighbourhood(std::shared_ptr<Solution> actual)
{
		std::shared_ptr<Solution> neighbour = std::make_shared<Solution>(*actual);
		std::vector<Base> candidate_bases = std::vector<Base>(actual->bases.begin(), actual->bases.end());
		unsigned int base;
		int repeat_lottery = std::rand() % 2;
		int where_to_move;
		if ( simple_used  && better && repeat_lottery )
		{
			where_to_move = prev_move;
			base = prev_base;
		}
		else
		{
			where_to_move = (std::rand() % 8);
			base = (std::rand() % (candidate_bases.size() - 1)) + 1;
		}
		prev_move = where_to_move;
		prev_base = base;

		auto & base_to_move = (candidate_bases[base]);
		switch (where_to_move)
		{
		case 0:
			base_to_move.x--;
			base_to_move.y++;
			break;
		case 1:
			base_to_move.y++;
			break;
		case 2:
			base_to_move.x++;
			base_to_move.y++;
			break;
		case 3:
			base_to_move.x++;
			break;
		case 4:
			base_to_move.x++;
			base_to_move.y--;
			break;
		case 5:
			base_to_move.y--;
			break;
		case 6:
			base_to_move.y--;
			base_to_move.x--;
			break;
		case 7:
			base_to_move.x--;
			break;
		default:
			break;
		}

		neighbour->move_bases(candidate_bases);
		return neighbour;
}
std::shared_ptr<Solution>  Neighbourhood_generator::generate_wider_neighbourhood(std::shared_ptr<Solution> actual)
{
	std::shared_ptr<Solution> neighbour = std::make_shared<Solution>(*actual);
	std::vector<Base> candidate_bases = std::vector<Base>(actual->bases.begin(), actual->bases.end());
	unsigned int base = (std::rand() % (candidate_bases.size() - 1)) + 1;
	
	int	x_to_move = static_cast<int> (((std::rand() % (width / 4)) - (width / 8)) * (actual_temp / start_temp));
	int	y_to_move = static_cast<int>(((std::rand() % (height / 4)) - (height / 8)) * (actual_temp / start_temp));
	
	auto & base_to_move = (candidate_bases[base]);

	base_to_move.x += x_to_move;
	base_to_move.y += y_to_move;

	neighbour->move_bases(candidate_bases);
	return neighbour;
}

std::shared_ptr<Solution> Neighbourhood_generator::generate_random_neighbourhood(std::shared_ptr<Solution> actual)
{
	std::shared_ptr<Solution> neighbour = std::make_shared<Solution>(*actual);
	std::vector<Base> candidate_bases = std::vector<Base>(actual->bases.begin(), actual->bases.end());

	int rand_base = (std::rand() % (candidate_bases.size() - 1) + 1);

	candidate_bases[rand_base].x = std::rand() % width + 1;
	candidate_bases[rand_base].y = std::rand() % height + 1;
	
	neighbour->move_bases(candidate_bases);
	return neighbour;
}
