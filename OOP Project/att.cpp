#include"att.h"
Attendance::Attendance(float width, float height)
{
	if (!font.loadFromFile("Fonts/arial.ttf")) {
		cout << "No font found\n";
	}
	AttMenu[0].setFont(font);
	AttMenu[0].setFillColor(Color::White);
	AttMenu[0].setString("1):Display Attendance");
	AttMenu[0].setCharacterSize(40);
	AttMenu[0].setPosition(50, 20);

	AttMenu[1].setFont(font);
	AttMenu[1].setFillColor(Color::White);
	AttMenu[1].setString("2):Mark Attendance");
	AttMenu[1].setCharacterSize(40);
	AttMenu[1].setPosition(50, 110);

	AttMenu[2].setFont(font);
	AttMenu[2].setFillColor(Color::White);
	AttMenu[2].setString("3):Back");
	AttMenu[2].setCharacterSize(40);
	AttMenu[2].setPosition(50, 200);


	selectedOption = -1;
}
void Attendance::draw(RenderWindow& window) {
	for (int i = 0; i < Max_options; i++) {
		window.draw(AttMenu[i]);
	}
}
void Attendance::Moveup() {
	if (selectedOption - 1 >= -1) {
		AttMenu[selectedOption].setFillColor(Color::White);
		selectedOption--;
		if (selectedOption == -1)
			selectedOption = 2;
		AttMenu[selectedOption].setFillColor(Color::Red);
	}
}

void Attendance::MoveDown() {
	if (selectedOption + 1 <= Max_options) {
		AttMenu[selectedOption].setFillColor(Color::White);
		selectedOption++;
		if (selectedOption == 3)
			selectedOption = 0;
		AttMenu[selectedOption].setFillColor(Color::Red);
	}
}
Attendance::~Attendance() {

}

