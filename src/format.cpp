#include <string>

#include "format.h"

using std::string;
using std::to_string;

string formatted(int input) {
	if (input >= 10) {
		return to_string(input);
	} 
	
	return "0" + to_string(input);
}

string Format::ElapsedTime(long seconds) {
	int hh = seconds / 3600;
	int mm = (seconds % 3600) / 60;
	int ss = seconds % 60;
	
	return formatted(hh) + ":" + formatted(mm) + ":" + formatted(ss);
}
