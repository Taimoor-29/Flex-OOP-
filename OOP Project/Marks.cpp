#include"marks.h"
Marks::Marks(float width, float height)
{
	if (!font.loadFromFile("Fonts/arial.ttf")) {
		cout << "No font found\n";
	}
	markMenu[0].setFont(font);
	markMenu[0].setFillColor(Color::White);
	markMenu[0].setString("1):Display Marks");
	markMenu[0].setCharacterSize(40);
	markMenu[0].setPosition(50, 20);

	markMenu[1].setFont(font);
	markMenu[1].setFillColor(Color::White);
	markMenu[1].setString("2):Assign Marks ");
	markMenu[1].setCharacterSize(40);
	markMenu[1].setPosition(50, 110);

	markMenu[2].setFont(font);
	markMenu[2].setFillColor(Color::White);
	markMenu[2].setString("3):Back");
	markMenu[2].setCharacterSize(40);
	markMenu[2].setPosition(50, 200);


	selectedOption = -1;
}
void Marks::draw(RenderWindow& window) {
	for (int i = 0; i < Max_options; i++) {
		window.draw(markMenu[i]);
	}
}
void Marks::Moveup() {
	if (selectedOption - 1 >= -1) {
		markMenu[selectedOption].setFillColor(Color::White);
		selectedOption--;
		if (selectedOption == -1) {
			selectedOption = 2;
		}
		markMenu[selectedOption].setFillColor(Color::Red);
	}
}

void Marks::MoveDown() {
	if (selectedOption + 1 <= Max_options) {
		markMenu[selectedOption].setFillColor(Color::White);
		selectedOption++;
		if (selectedOption == 3)
			selectedOption = 0;

		markMenu[selectedOption].setFillColor(Color::Red);
	}
}
Marks::~Marks() {

}
