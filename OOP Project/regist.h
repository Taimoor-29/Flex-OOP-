#pragma once
#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
#define Max_options 3
class Registration {

private:
	int selectedOption;
	Font font;
	Text registermenu[Max_options];

public:
	Registration(float width, float height);
	void draw(RenderWindow& window);
	void Moveup();
	void MoveDown();
	int MenuPress() {
		return selectedOption;
	}
	~Registration();
};
