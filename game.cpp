#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>

class Hero {
private:
	std::string name;
	int health;
	int damage; //rand() % damage -> [0; damage]
	int block;
public:
	std::string GetName() { return name; }
	void SetName(std::string name) {
		this->name = name;
	}

	int GetDamage() { return damage; }
	void SetDamage(int damage) {
		this->damage = damage;
	}

	int GetBlock() { return block; }
	void SetBlock(int block) {
		this->block = block;
	}

	int GetHealth() { return health; }
	void SetHealth(int health) {
		this->health = health;
	}

	Hero(std::string, int, int, int);
	void RemainingHealth();
};

// Constructor
Hero::Hero(std::string name, int damage, int block, int health) {
	this->block = block;
	this->health = health;
	this->damage = damage;
	this->name = name;
}

void Hero::RemainingHealth() {
	std::cout << this->name << " has " << this->health << " health remaining\n";
}

int main() {

	srand(time(NULL)); //so that the seed is different ? and to not get same rand values every time

	Hero hulk("Hulk", 33, 5, 33); //instanciate
	Hero thor("Thor", 25, 8, 40);

	std::cout << hulk.GetName() << ", damage : "
		<< hulk.GetDamage() << ", health : "
		<< hulk.GetHealth() << ", block : "
		<< hulk.GetBlock() << "\n";

	std::cout << thor.GetName() << ", damage : "
		<< thor.GetDamage() << ", health : "
		<< thor.GetHealth() << ", block : "
		<< thor.GetBlock() << "\n";

	int dmg;

	while (hulk.GetHealth() > 0 && thor.GetHealth() > 0) {
		//Hulk's turn
		dmg = rand() % hulk.GetDamage();
		if (thor.GetHealth() - (dmg - thor.GetBlock()) <= thor.GetHealth()) {
			thor.SetHealth(thor.GetHealth() - (dmg - thor.GetBlock()));
		}

		std::cout << hulk.GetName() << " attacks "
			<< thor.GetName() << " and deals "
			<< dmg - thor.GetBlock() << " damage\n";

		if (thor.GetHealth() <= 0) {
			thor.SetHealth(0);
			thor.RemainingHealth();
			std::cout << hulk.GetName() << " Wins !\n";
			return -1;
		}
		
		thor.RemainingHealth();

		//Thor's turn
		dmg = rand() % thor.GetDamage();
		if (hulk.GetHealth() - (dmg - hulk.GetBlock()) <= hulk.GetHealth()) {
			hulk.SetHealth(hulk.GetHealth() - (dmg - hulk.GetBlock()));
		}

		std::cout << thor.GetName() << " attacks "
			<< hulk.GetName() << " and deals "
			<< dmg - hulk.GetBlock() << " damage\n";

		if (hulk.GetHealth() <= 0) {
			hulk.SetHealth(0);
			hulk.RemainingHealth();
			std::cout << thor.GetName() << " Wins !\n";
			return -1;
		}

		hulk.RemainingHealth();
	};

	return 0;
}