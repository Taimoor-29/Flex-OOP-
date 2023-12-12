#include"Mainmenu.h"
MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("Fonts/arial.ttf")) {
		cout << "No font found\n";
	}
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("1):Enroll a Student");
	mainMenu[0].setCharacterSize(40);
	mainMenu[0].setPosition(50, 20);

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("2):Course Registration");
	mainMenu[1].setCharacterSize(40);
	mainMenu[1].setPosition(50, 110);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("3):Attendance");
	mainMenu[2].setCharacterSize(40);
	mainMenu[2].setPosition(50, 200);

	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("4):Marks");
	mainMenu[3].setCharacterSize(40);
	mainMenu[3].setPosition(50, 290);

	mainMenu[4].setFont(font);
	mainMenu[4].setFillColor(Color::White);
	mainMenu[4].setString("5):Course Withdraw");
	mainMenu[4].setCharacterSize(40);
	mainMenu[4].setPosition(50, 380);


	mainMenu[5].setFont(font);
	mainMenu[5].setFillColor(Color::White);
	mainMenu[5].setString("6):Exit");
	mainMenu[5].setCharacterSize(40);
	mainMenu[5].setPosition(50, 470);



	selectedOption = -1;
}
void MainMenu::draw(RenderWindow& window) {
	for (int i = 0; i < Max_options; i++) {
		window.draw(mainMenu[i]);
	}
}
void MainMenu::Moveup() {
	if (selectedOption - 1 >=-1) {
		mainMenu[selectedOption].setFillColor(Color::White);
		selectedOption--;
		if (selectedOption == -1)
			selectedOption = 5;
		mainMenu[selectedOption].setFillColor(Color::Red);
	}
}

void MainMenu::MoveDown() {
	if (selectedOption + 1 <= Max_options) {
		mainMenu[selectedOption].setFillColor(Color::White);
		selectedOption++;
		if (selectedOption == 6)
			selectedOption = 0;
		mainMenu[selectedOption].setFillColor(Color::Red);
	}
}
MainMenu::~MainMenu() {

}

