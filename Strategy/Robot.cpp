#include "Robot.h"

int main(){

	Robot r1("R2");
	Robot r2("D2");
	Robot r3("Z2");

	r1.setStrategy(std::make_unique<AggressiveStrategy>());
	r2.setStrategy(std::make_unique<NeutralStrategy>());
	r3.setStrategy(std::make_unique<DefensiveStrategy>());

	std::cout<<"\n";
	r1.executeCommand();
	r2.executeCommand();
	r3.executeCommand();

	r1.setStrategy(std::make_unique<DefensiveStrategy>());
	r2.setStrategy(std::make_unique<AggressiveStrategy>());

	std::cout<<"\n";
	r1.executeCommand();
	r2.executeCommand();
	r3.executeCommand();

	return 0;
}