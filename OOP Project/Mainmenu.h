#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
#define Max_options 6
class MainMenu {

private:
	int selectedOption;
	Font font;
	Text mainMenu[Max_options];

public:
	MainMenu(float width, float height);
	void draw(RenderWindow& window);
	void Moveup();
	void MoveDown();
	int MenuPress() {
		return selectedOption;
	}
	~MainMenu();
};
