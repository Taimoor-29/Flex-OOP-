#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
#define Max_options 5
class Enroll {

private:
	int selectedOption;
	Font font;
	Text enroll[Max_options];

public:
	Enroll(float width, float height);
	void draw(RenderWindow& window);
	void Moveup();
	void MoveDown();
	int MenuPress() {
		return selectedOption;
	}
	~Enroll();
};
