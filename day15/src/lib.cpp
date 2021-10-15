#include <algorithm>
#include<map>

#include "lib.hpp"

int part1(const std::vector<int>& numbers)
{
	std::map<size_t, size_t> game_log; // Map of turn to number spoken

	// Load initial numbers into game_log
	for (auto turn{ 1 }; turn < numbers.size() + 1; ++turn)
	{
		game_log[turn] = numbers[turn - 1];
	}

	// Play the game
	for (auto turn{ game_log.size() + 1 }; turn < 2021; ++turn)
	{
		// If last number spoken is only in game_log once, then this turn's number is 0.
		// Otherwise, this turn's number is last turn minus the last time that number was spoken.
		auto last_number_spoken{ game_log.at(turn - 1) };
		auto last_turn_last_number_spoken{ std::find_if(std::next(game_log.rbegin()), game_log.rend(),
			[last_number_spoken](const auto& m) {return m.second == last_number_spoken; }) };
		if (last_turn_last_number_spoken == game_log.rend())
		{
			// Last turn was the first time this number was spoken
			game_log[turn] = 0;
		}
		else
		{
			auto last_turn{ last_turn_last_number_spoken->first };
			game_log[turn] = (turn - 1) - last_turn;
		}
	}
	return static_cast<int>(game_log[2020]);
}
