#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
#define Max_options 3
class Attendance {

private:
	int selectedOption;
	Font font;
	Text AttMenu[Max_options];

public:
	Attendance(float width, float height);
	void draw(RenderWindow& window);
	void Moveup();
	void MoveDown();
	int MenuPress() {
		return selectedOption;
	}
	~Attendance();
};