#include <algorithm>
#include <map>

#include "lib.hpp"

// A solution with std::map. Keys are numbers and values are numbers or a vector of numbers.
int play_game_map_to_vector(const int final_turn, const std::vector<int>& numbers)
{
	std::map<size_t, size_t> turn_to_number; // Map of turn to number spoken
	std::map<size_t, std::vector<size_t>> number_to_turns; // Map of number spoken to turns

	// Load initial numbers
	for (auto turn{ 1 }; turn < numbers.size() + 1; ++turn)
	{
		turn_to_number[turn] = numbers[turn - 1];
		number_to_turns[numbers[turn - 1]].push_back(turn);
	}

	// Play the game
	for (auto turn{ turn_to_number.size() + 1 }; turn <= final_turn; ++turn)
	{
		// If last number spoken is only in game_log once, then this turn's number is 0.
		// Otherwise, this turn's number is last turn minus the last time that number was spoken.
		auto last_number_spoken{ turn_to_number.at(turn - 1) };
		if (number_to_turns[last_number_spoken].size() <= 1)
		{
			// Last turn was the first time this number was spoken
			turn_to_number[turn] = 0;
			number_to_turns[0].push_back(turn);
		}
		else
		{
			auto next_to_last_turn{ number_to_turns[last_number_spoken].end()[-2] };
			auto number_to_speak{ (turn - 1) - next_to_last_turn };
			turn_to_number[turn] = number_to_speak;
			number_to_turns[number_to_speak].push_back(turn);
		}
	}
	return static_cast<int>(turn_to_number[final_turn]);
}

// A solution with std::map. Keys and values are numbers.
int play_game_map_to_size_t(const int final_turn, const std::vector<int>& numbers)
{
	std::map<size_t, size_t> turn_to_number; // Map of turn to number spoken
	std::map<size_t, size_t> number_to_last_turn; // Map of number spoken to last turn

	// Load initial numbers
	for (auto turn{ 1 }; turn < numbers.size() + 1; ++turn)
	{
		turn_to_number[turn] = numbers[turn - 1];
		number_to_last_turn[numbers[turn - 1]] = turn;
	}

	// Play the game
	for (auto turn{ turn_to_number.size() + 1 }; turn <= final_turn; ++turn)
	{
		// If last number spoken is only in game_log once, then this turn's number is 0.
		// Otherwise, this turn's number is last turn minus the last time that number was spoken.
		auto last_number_spoken{ turn_to_number.at(turn - 1) };
		if (!number_to_last_turn.contains(last_number_spoken))
		{
			// Last turn was the first time this number was spoken
			turn_to_number[turn] = 0;
			number_to_last_turn[last_number_spoken] = turn - 1;
		}
		else
		{
			auto next_to_last_turn{ number_to_last_turn[last_number_spoken] };
			auto number_to_speak{ (turn - 1) - next_to_last_turn };
			turn_to_number[turn] = number_to_speak;
			number_to_last_turn[last_number_spoken] = turn - 1;
		}
	}
	return static_cast<int>(turn_to_number[final_turn]);
}


// A solution with vectors of numbers. Used std::vector because array of 30'000'000
// elements is too large for the stack.
int play_game_with_vectors(const int final_turn, const std::vector<int>& numbers)
{
	std::vector<size_t> turn_to_number(static_cast<size_t>(final_turn + 1), SIZE_MAX); // Turn to number spoken
	std::vector<size_t> number_to_last_turn(static_cast<size_t>(final_turn + 1), SIZE_MAX); // Number spoken to last turn

	// Load initial numbers
	for (auto turn{ 1 }; turn < numbers.size() + 1; ++turn)
	{
		turn_to_number[turn] = numbers[turn - 1];
		number_to_last_turn[numbers[turn - 1]] = turn;
	}

	// Play the game
	for (auto turn{ numbers.size() + 1 }; turn <= final_turn; ++turn)
	{
		// If last number spoken is only in game_log once, then this turn's number is 0.
		// Otherwise, this turn's number is last turn minus the last time that number was spoken.
		auto last_number_spoken{ turn_to_number.at(turn - 1) };
		if (number_to_last_turn[last_number_spoken] == SIZE_MAX)
		{
			// Last turn was the first time this number was spoken
			turn_to_number[turn] = 0;
			number_to_last_turn[last_number_spoken] = turn - 1;
		}
		else
		{
			auto next_to_last_turn{ number_to_last_turn[last_number_spoken] };
			auto number_to_speak{ (turn - 1) - next_to_last_turn };
			turn_to_number[turn] = number_to_speak;
			number_to_last_turn[last_number_spoken] = turn - 1;
		}
	}
	return static_cast<int>(turn_to_number[final_turn]);
}
