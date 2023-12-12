#pragma once
#pragma once
#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
#define Max_options 3
class Withdraw {

private:
	int selectedOption;
	Font font;
	Text withdrawmenu[Max_options];

public:
	Withdraw(float width, float height);
	void draw(RenderWindow& window);
	void Moveup();
	void MoveDown();
	int MenuPress() {
		return selectedOption;
	}
	~Withdraw();
};
