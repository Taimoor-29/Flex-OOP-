#include"enroll.h"
Enroll::Enroll(float width, float height)
{
	if (!font.loadFromFile("Fonts/arial.ttf")) {
		cout << "No font found\n";
	}
	enroll[0].setFont(font);
	enroll[0].setFillColor(Color::White);
	enroll[0].setString("1):Display already enrolled students");
	enroll[0].setCharacterSize(40);
	enroll[0].setPosition(50, 20);

	enroll[1].setFont(font);
	enroll[1].setFillColor(Color::White);
	enroll[1].setString("2):Add a student");
	enroll[1].setCharacterSize(40);
	enroll[1].setPosition(50, 120);

	enroll[2].setFont(font);
	enroll[2].setFillColor(Color::White);
	enroll[2].setString("3):Remove a student");
	enroll[2].setCharacterSize(40);
	enroll[2].setPosition(50, 220);

	enroll[3].setFont(font);
	enroll[3].setFillColor(Color::White);
	enroll[3].setString("4):Edit a student");
	enroll[3].setCharacterSize(40);
	enroll[3].setPosition(50, 320);

	enroll[4].setFont(font);
	enroll[4].setFillColor(Color::White);
	enroll[4].setString("5):Back");
	enroll[4].setCharacterSize(40);
	enroll[4].setPosition(50, 420);


	selectedOption = -1;
}
void Enroll::draw(RenderWindow& window) {
	for (int i = 0; i < Max_options; i++) {
		window.draw(enroll[i]);
	}
}
void Enroll::Moveup() {
	if (selectedOption - 1 >= -1) {
		enroll[selectedOption].setFillColor(Color::White);
		selectedOption--;
		if (selectedOption == -1)
			selectedOption = 4;
		enroll[selectedOption].setFillColor(Color::Red);
	}
}

void Enroll::MoveDown() {
	if (selectedOption + 1 <= Max_options) {
		enroll[selectedOption].setFillColor(Color::White);
		selectedOption++;
		if (selectedOption == 5) {
			selectedOption = 0;
		}
		enroll[selectedOption].setFillColor(Color::Red);
	}
}
Enroll::~Enroll() {

}

