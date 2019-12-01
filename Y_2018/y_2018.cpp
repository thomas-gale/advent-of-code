#include "y_2018.h"

#include "d_01.h"
#include "d_02.h"

namespace aoc::y2018 {
	void calculate(int day, std::istream& input) {
		switch (day)
		{
		case 1:
			aoc::y2018::d01::calculate(input); break;
		case 2:
			aoc::y2018::d02::calculate(input); break;
		default:
			throw std::runtime_error("Unrecognised day");
		}
	}
}