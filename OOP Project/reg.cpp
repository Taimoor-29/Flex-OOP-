#include"regist.h"
Registration::Registration(float width, float height)
{
	if (!font.loadFromFile("Fonts/arial.ttf")) {
		cout << "No font found\n";
	}
	registermenu[0].setFont(font);
	registermenu[0].setFillColor(Color::White);
	registermenu[0].setString("1):Available Courses");
	registermenu[0].setCharacterSize(40);
	registermenu[0].setPosition(50, 20);

	registermenu[1].setFont(font);
	registermenu[1].setFillColor(Color::White);
	registermenu[1].setString("2):Register Courses");
	registermenu[1].setCharacterSize(40);
	registermenu[1].setPosition(50, 115);

	registermenu[2].setFont(font);
	registermenu[2].setFillColor(Color::White);
	registermenu[2].setString("3):Back");
	registermenu[2].setCharacterSize(40);
	registermenu[2].setPosition(50, 210);
	

	selectedOption = -1;
}
void Registration::draw(RenderWindow& window) {
	for (int i = 0; i < Max_options; i++) {
		window.draw(registermenu[i]);
	}
}
void Registration::Moveup() {
	if (selectedOption - 1 >= -1) {
		registermenu[selectedOption].setFillColor(Color::White);
		selectedOption--;
		if (selectedOption == -1)
			selectedOption = 2;
		registermenu[selectedOption].setFillColor(Color::Red);
	}
}

void Registration::MoveDown() {
	if (selectedOption + 1 <= Max_options) {
		registermenu[selectedOption].setFillColor(Color::White);
		selectedOption++;
		if (selectedOption == 3)
			selectedOption = 0;
		registermenu[selectedOption].setFillColor(Color::Red);
	}
}
Registration::~Registration() {

}

