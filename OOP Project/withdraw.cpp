#include"withdraw.h"
Withdraw::Withdraw(float width, float height)
{
	if (!font.loadFromFile("Fonts/arial.ttf")) {
		cout << "No font found\n";
	}
	withdrawmenu[0].setFont(font);
	withdrawmenu[0].setFillColor(Color::White);
	withdrawmenu[0].setString("1):Enrolled Courses");
	withdrawmenu[0].setCharacterSize(40);
	withdrawmenu[0].setPosition(50, 20);

	withdrawmenu[1].setFont(font);
	withdrawmenu[1].setFillColor(Color::White);
	withdrawmenu[1].setString("2):Drop a Course");
	withdrawmenu[1].setCharacterSize(40);
	withdrawmenu[1].setPosition(50, 115);

	withdrawmenu[2].setFont(font);
	withdrawmenu[2].setFillColor(Color::White);
	withdrawmenu[2].setString("3):Back");
	withdrawmenu[2].setCharacterSize(40);
	withdrawmenu[2].setPosition(50, 210);


	selectedOption = -1;
}
void Withdraw::draw(RenderWindow& window) {
	for (int i = 0; i < Max_options; i++) {
		window.draw(withdrawmenu[i]);
	}
}
void Withdraw::Moveup() {
	if (selectedOption - 1 >= -1) {
		withdrawmenu[selectedOption].setFillColor(Color::White);
		selectedOption--;
		if (selectedOption == -1)
			selectedOption = 2;
		withdrawmenu[selectedOption].setFillColor(Color::Red);
	}
}

void Withdraw::MoveDown() {
	if (selectedOption + 1 <= Max_options) {
		withdrawmenu[selectedOption].setFillColor(Color::White);
		selectedOption++;
		if (selectedOption == 3)
			selectedOption = 0;
		withdrawmenu[selectedOption].setFillColor(Color::Red);
	}
}
Withdraw::~Withdraw() {

}

