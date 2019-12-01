#pragma once
#include "default.h"
#include <set>

namespace aoc::y2018::d01 {	
	void calculate(std::istream& input) {
		std::cout << "Chronal Calibration\n";
		std::vector<std::string> input_strings = aoc::read_input(input);

		std::set<int> freqs{ 0 };
		bool freq_twice_found = false;
		int first_freq_twice = 0;
		int freq_sum = 0;

		while (!freq_twice_found)
		{
			freq_sum = std::accumulate(input_strings.begin(), input_strings.end(), freq_sum, [&freqs, &freq_twice_found, &first_freq_twice](const int& freq_sum_old, const std::string& freq_change_str) {
				int freq_change = std::stoi(freq_change_str);
				// Part 1.
				int freq_sum = freq_sum_old + freq_change;

				// Part 2.
				if (!freq_twice_found)
				{
					if (freqs.find(freq_sum) != freqs.end())
					{
						first_freq_twice = freq_sum;
						freq_twice_found = true;
					}
					else
					{
						freqs.insert(freq_sum);
					}
				}
				return freq_sum;
				}
			);
		}

		std::cout << "1. Frequency Sum:\n";
		std::cout << freq_sum << "\n";

		std::cout << "2. First Frequency Twice:\n";
		std::cout << first_freq_twice << "\n";
	}
}