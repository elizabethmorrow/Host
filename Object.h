#include <iostream>
#include <stdlib.h>
#include <string>

class Object {
public:
	int health;

	void setHealth(int x) {
		health = x;
	}

	void printHealth() {
		std::cout<<"Object's Health Level: " << health << std::endl;
	}
};
