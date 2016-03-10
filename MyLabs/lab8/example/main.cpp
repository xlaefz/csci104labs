#include <iostream>
#include "pair.h"

int main() {

	Pair<double, std::string> student(1234567890, "Nikhil Bedi");
	Pair<std::string, int> question("What is the answer to life, universe, and everything?", 42);

	std::cout << question.getFirst() << std::endl;
	std::cout << student.getFirst() / student.getFirst() * question.getSecond() << std::endl;

}
