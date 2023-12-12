#include <SFML/Graphics.hpp>
#include"Mainmenu.h"
#include"enroll.h"
#include"regist.h"
#include"att.h"
#include"marks.h"
#include"withdraw.h"
using namespace sf;
#include<iostream>
#include<string>
using namespace std;
#include<iostream>
#include<string>
using namespace std;
#include<iostream>
#include<string>
using namespace std;

class Student {
private:
	string name;
	string rollno;
	int age;
	string contact;
public:
	Student() {
		name = "";
		rollno = "";
		age = 0;
		contact = "";

	}
	Student(string Name, string roll, int Age, string Contact) {
		name = Name;
		rollno = roll;
		age = Age;
		contact = Contact;

	}
	void operator =(Student& obj) {
		this->name = obj.name;
		this->rollno = obj.rollno;
		this->age = obj.age;
		this->contact = obj.contact;
	}
	void setRoll(string rollno) {
		this->rollno = rollno;
	}
	void setName(string Name) {
		this->name = Name;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setContact(string phoneno) {
		this->contact = phoneno;
	}

	string getRollno() {
		return this->rollno;
	}
	string getContact() {
		return this->contact;
	}
	string getName() {
		return this->name;
	}
	int getAge() {
		return this->age;
	}
	void display() {
		cout << "Name: " << this->name << endl;
		cout << "Roll no: " << this->rollno << endl;
		cout << "Age: " << this->age << endl;
		cout << "Contact no: " << this->contact << endl;

	}
	~Student() {

	}

};
//defining global variales for temp space;
string temp1_name;
string temp1_contact;
int temp1_age;

class studentEnrollment {
private:
	Student* std;
	int size;
	int capacity;
	static studentEnrollment* se;
	bool searchStudent(string s) {
		for (int i = 0; i < size; i++) {
			if (s == std[i].getRollno()) {
				return true;
			}
		}
		return false;
	}
	studentEnrollment() {
		capacity = 1;
		std = new Student[capacity];
		size = 0;
	}

public:

	static studentEnrollment* getInstance() {
		if (se == NULL) {
			se = new studentEnrollment;

		}
		return se;

	}

	bool addStudent(Student& s) {
		if (searchStudent(s.getRollno()) == true) {
			cout << "\nStudent already enrolled in University\n";
			return false;
		}
		if (size < capacity) {
			std[size++] = s;
		}
		else {
			capacity = capacity * 2;
			Student* temp = new Student[capacity];
			for (int i = 0; i < size; i++) {
				temp[i] = std[i];
			}
			delete[]std;
			std = temp;
			temp = nullptr;
			std[size++] = s;
		}
		cout << "\nStudent added\n";
		return true;
	}
	bool removeStudent(string s) {
		bool flag = false;
		if (size > 0) {
			for (int i = 0; i < size; i++) {
				if (s == std[i].getRollno()) {
					size--;
					flag = true;
					for (int j = i; j < size; j++) {
						std[j] = std[j + 1];
					}
					cout << "\nStudent removed\n";
					return true;
				}
			}
			if (flag == false) {
				cout << "\nStudent does not exist\n";
				return false;
			}
		}
		else {
			cout << "No student is currently enrolled\n";
			return false;
		}
	}
	bool editDetails(string S) {
		if (searchStudent(S) == true) {
			for (int i = 0; i < size; i++) {
				if (S == std[i].getRollno()) {
					string t_name, contact, r_no;
					int age;
					//cout << "Enter new roll_no\n";
					//getline(cin, r_no);
					cout << "Enter new name\n";
					
				
					getline(cin, t_name);
					cout << "Enter new age\n";
					cin >> age;
					cin.ignore();
					cout << "Enter new contact\n";
					getline(cin, contact);
					cin.ignore();
					std[i].setName(t_name);
					std[i].setAge(age);
					std[i].setContact(contact);
					//std[i].setRoll(r_no);
					cout << "\nDetails updated\n";
					temp1_name = t_name;
					temp1_contact = contact;
					temp1_age = age;
					return true;
				}
				
			}
		}
		else {
			cout << "\nStudent does not exist\n";
			return false;
		}
	}
	void display() {
		if (size != 0) {
			cout << "\nStudents enrolled in the university are: \n";
			for (int i = 0; i < size; i++) {
				cout << "\nInformation of Student " << i + 1 << " is given as:\n";
				std[i].display();
			}
		}
	}

	~studentEnrollment() {
		delete[]std;
		std = nullptr;
	}
};


class Course {
private:
	string code;
	string name;
	string instructor;
	int credits;
	int capacity = 50;
	string* enrolled_std = new string[capacity];
	int size;
	bool searchStudent(string std) {
		for (int i = 0; i < size; i++) {
			if (std == enrolled_std[i]) {
				return true;
			}
		}
		return false;
	}

public:
	Course() {
		code = "";
		name = "";
		instructor = "";
		credits = 0;
		size = 0;
	}
	Course(string code, string name, string instructor, int credits) {
		this->code = code;
		this->name = name;
		this->instructor = instructor;
		this->credits = credits;
		this->size = 0;
	}
	void operator =(Course& obj) {
		this->code = obj.code;
		this->name = obj.name;
		this->instructor = obj.instructor;
		this->credits = obj.credits;
		this->size = obj.size;
		this->capacity = obj.capacity;
		this->enrolled_std = new string[capacity];
		for (int i = 0; i < size; i++) {
			this->enrolled_std[i] = obj.enrolled_std[i];
		}

	}

	bool addStudent(string std) {
		if (searchStudent(std) == true) {
			cout << "\nStudent already enrolled in course\n";
			return false;
		}
		if (size < capacity) {
			enrolled_std[size++] = std;
			cout << "\nStudent added to the course\n";
			return true;
		}
		else {
			cout << "\nCourse Capacity is full you can not add student\n";
			return false;
		}
	}
	bool removeStudent(string std) {
		if (searchStudent(std) == true) {
			for (int i = 0; i < size; i++) {
				if (std == enrolled_std[i]) {
					size--;
					for (int j = i; j < size; j++) {
						enrolled_std[j] = enrolled_std[j + 1];
					}
					cout << "\nStudent removed from the course\n";
					break;
				}
			}
			return true;
		}
		else {
			cout << "\nStudent does not exist\n";
			return false;
		}
	}
	string getCode() {
		return this->code;
	}
	string getName() {
		return this->name;
	}
	string* getallStudent()
	{
		return enrolled_std;
	}
	void display() {
		cout << "\nCode: " << this->code;
		cout << "\nCourse name: " << this->name;
		cout << "\nInstructor: " << this->instructor;
		cout << "\nCredit :" << this->credits;
		if (size > 0) {
			cout << "\nEnrolled Student's roll nos are:\n";
			for (int i = 0; i < size; i++) {
				cout << enrolled_std[i];
				cout << endl;
			}
		}
	}
	~Course() {
		/*delete[]enrolled_std;
		enrolled_std = nullptr;*/
	}
};

class CourseCatalogue {
private:
	Course* availableCourses;
	int size;
	int capacity;
	static CourseCatalogue* CC;
	bool searchCourse(string c) {
		for (int i = 0; i < size; i++) {
			if (c == availableCourses[i].getCode()) {
				return true;
			}
		}
		return false;
	}
public:
	Course search(string code) {
		for (int i = 0; i < size; i++) {
			if (code == availableCourses[i].getCode()) {
				return availableCourses[i];
			}
		}
		Course temp;
		return temp;
	}
	CourseCatalogue() {
		capacity = 1;
		availableCourses = new Course[capacity];
		size = 0;
	}

public:
	static CourseCatalogue* getInstance() {
		if (CC == NULL) {
			CC = new CourseCatalogue;

		}
		return CC;

	}
	void addCourse(Course& c) {
		if (this->searchCourse(c.getCode()) == true) {
			cout << "\nCourse already registered in University\n";
			return;
		}
		if (size < capacity) {
			availableCourses[size++] = c;
		}
		else {
			capacity = capacity * 2;
			Course* temp = new Course[capacity];
			for (int i = 0; i < size; i++) {
				temp[i] = availableCourses[i];
			}
			delete[]availableCourses;
			availableCourses = temp;
			temp = nullptr;
			availableCourses[size++] = c;
		}
		cout << "\nCourse added\n";
	}
	void removeCourse(string c) {
		if (searchCourse(c) == true) {
			for (int i = 0; i < size; i++) {
				if (c == availableCourses[i].getCode()) {
					size--;
					for (int j = i; j < size; j++) {
						availableCourses[j] = availableCourses[j + 1];
					}
					cout << "\nCourse removed from the catalogue\n";
					break;
				}
			}
		}
		else {
			cout << "\nCourse does not exist\n";
		}
	}

	void display() {
		cout << "\nAvailable Courses in the university are: \n";
		for (int i = 0; i < size; i++) {
			cout << "\nInformation of Course " << i + 1 << " is given as:\n";
			availableCourses[i].display();
		}
	}
	bool addstudentToaCourse(string rollno, string code)
	{
		if (size != 0)
		{
			for (int i = 0; i < size; i++)
			{
				if (availableCourses[i].getCode() == code) {
					bool flag = availableCourses[i].addStudent(rollno);
					return flag;
				}
			}
			
			return false;
		}
		return false;
	}

	bool removestudentfromaCourse(string rollno, string code)
	{
		if (size != 0)
		{
			for (int i = 0; i < size; i++)
			{
				if (availableCourses[i].getCode() == code) {
					bool flag = availableCourses[i].removeStudent(rollno);
					return flag;
				}
			}
			return false;
		}
		return false;
	}
	~CourseCatalogue() {
		delete[]availableCourses;
		availableCourses = nullptr;
	}
};

class studentinfoManagament {
private:
	Student* s;
	Course* c;
	double* Marks;
	double* Attendance;
	int count;
	int capacity;
public:
	void operator =(studentinfoManagament& a) {
		this->s = new Student(a.s->getName(), a.s->getRollno(), a.s->getAge(), a.s->getContact());
		this->count = a.count;
		this->capacity = a.capacity;
		this->c = new Course[capacity];
		this->Marks = new double[capacity];
		this->Attendance = new double[capacity];
		for (int i = 0; i < count; i++) {
			this->c[i] = a.c[i];
			this->Marks[i] = a.Marks[i];
			this->Attendance[i] = a.Attendance[i];
		}
	}

	studentinfoManagament() {

		s = nullptr;
		c = nullptr;
		Marks = nullptr;
		Attendance = nullptr;
		count = 0;
		capacity = 0;
	}
	studentinfoManagament(Student* s1, Course* c1, double* m1, double* Attendance, int count) {
		s = s1;
		c = c1;
		Marks = m1;
		this->Attendance = Attendance;
		this->count = count;
		capacity = 0;
	}
	studentinfoManagament(Student* s1) {
		s = s1;
		this->count = 0;
		capacity = 0;
		c = nullptr;
		Marks = nullptr;
		Attendance = nullptr;
	}

	bool search(string courseId) {
		for (int i = 0; i < count; i++) {
			if (c[i].getCode() == courseId) {
				return true;
			}
		}
		return false;
	}

	void registerCourse(Course& C) {
		if (search(C.getCode()) == true) {
			cout << "\nStudent already enrolled in the course\n";
			return;
		}
		else {
			if (capacity == 0) {
				capacity = 1;
				c = new Course[capacity];
				Marks = new double[capacity];
				Attendance = new double[capacity];
				c[0] = C;
				Marks[0] = 0;
				Attendance[0] = 0;
				count++;

			}
			else if (count < capacity) {
				c[count] = C;
				Marks[count] = 0;
				Attendance[count] = 0;
				count++;
			}
			else {
				capacity = capacity * 2;
				Course* temp1 = new Course[capacity];
				double* temp2 = new double[capacity];
				double* temp3 = new double[capacity];
				for (int i = 0; i < count; i++) {
					temp1[i] = c[i];
					temp2[i] = Marks[i];
					temp3[i] = Attendance[i];
				}
				delete[]c;
				delete[]Marks;
				delete[]Attendance;
				c = temp1;
				Marks = temp2;
				Attendance = temp3;
				c[count] = C;
				Marks[count] = 0;
				Attendance[count] = 0;
				count++;


			}
			cout << "\nStudent registered in the course sucessfully\n";
		}

	}
	string getRollNo() {
		return s->getRollno();
	}
	bool updateMarks(double marks, string code) {
		if (search(code) == false) {
			cout << "\nStudent is not registered in that course\n";
			return false;
		}
		else {
			for (int i = 0; i < count; i++) {
				if (c[i].getCode() == code) {
					Marks[i] = marks;
					cout << "Marks has been updated\n";
					return true;
				}

			}
		}
	}
	bool updateAttendance(double A, string code) {
		if (search(code) == false) {
			cout << "\nStudent is not registered in that course\n";
			return false;
		}
		else {
			for (int i = 0; i < count; i++) {
				if (c[i].getCode() == code) {
					Attendance[i] = A;
					cout << "Attendance has been updated\n";
					return true;
				}

			}
		}
	}
	void withdrawCourse(string id) {
		if (search(id) == false) {
			cout << "\nStudent is not enrolled in that course\n";
			return;
		}
		else {
			for (int i = 0; i < count; i++) {
				if (c[i].getCode() == id) {
					for (int j = i; j < count - 1; j++) {
						c[j] = c[j + 1];
					}
					count--;
					cout << "\nCourse has been withdrawn\n";
				}
			}
		}

	}
	void editDetails(string name, int age, string contact) {
		s->setName(name);
		s->setAge(age);
		s->setContact(contact);
	}

	bool displayMarks() {
		if (count == 0)
		{
			cout << "\nStudent is not enrolled in any course yet" << endl;
			return false;

		}
		cout << "\nStudent Marks in each course are as follows :\n";
		for (int i = 0; i < count; i++) {
			cout << "Marks in : " << c[i].getName() << " are: " << Marks[i] << endl;
		}
		return true;
	}
	bool displayAttendance() {
		if (count == 0)
		{
			cout << "\nStudent is not enrolled in any course yet" << endl;
			return false;

		}
		cout << "\nStudent Attendance in each course are as follows :\n";
		for (int i = 0; i < count; i++) {
			cout << "Attendance in : " << c[i].getName() << " is: " << Attendance[i] << "%" << endl;
		}
		return true;
	}
	bool displayAllCourses()
	{
		if (count == 0)
		{
			cout << "\nStudent is not enrolled in any course yet" << endl;
			return false;

		}
		for (int i = 0; i < count; i++)
		{
			cout << "Course " << i + 1 << " : " << c[i].getName() << endl;
		}
		return true;
	}
	~studentinfoManagament() {
		/*delete[]c;
		delete[]Marks;
		delete[]Attendance;*/
	}
};
CourseCatalogue* CourseCatalogue::CC = nullptr;
studentEnrollment* studentEnrollment::se = nullptr;

class System {
private:
	CourseCatalogue* AllCourses = CourseCatalogue::getInstance();
	studentEnrollment* AllStudents = studentEnrollment::getInstance();
	studentinfoManagament* stm;
	static System* ins;
	int count;
	const int capacity = 1000;
	System() {
		int count = 0;
		stm = new studentinfoManagament[capacity];
	}
public:

	static System* getInstance() {
		if (ins == NULL) {
			ins = new System;

		}
		return ins;

	}
	bool addStudent(Student S) {

		bool flag = AllStudents->addStudent(S);
		if (flag == true) {
			studentinfoManagament temp2(&S);
			stm[count++] = temp2;
			
		}
		return flag;
	}
	void AddNewCourseToUni(Course c)
	{
		AllCourses->addCourse(c);

	}
	void DisplayAllStudents()
	{
		AllStudents->display();
	}
	void DisplayAllCourses()
	{
		AllCourses->display();
	}

	bool removeStudent(string id) {

		if (count != 0) {
			bool flag = AllStudents->removeStudent(id);
			if (flag) {
				for (int i = 0; i < count; i++) {
					if (stm[i].getRollNo() == id) {
						for (int j = i; j < count - 1; j++) {
							stm[j] = stm[j + 1];
						}
						count--;
						return true;
					}
				}
				cout << "\nStudent does not exist\n";
				return false;
			}
		}
		else {
			cout << "\nNo Student registred yet\n";
			return false;
		}

	}
	bool editStdDetails(string rollno) {
		bool flag = AllStudents->editDetails(rollno);
		if (flag) {
			for (int i = 0; i < count; i++) {
				if (stm[i].getRollNo() == rollno) {
					stm[i].editDetails(temp1_name, temp1_age, temp1_contact);
					return true;

				}
			}
			cout << "\nStudent does not exist\n";
			return false;
		}
		return false;
	}
	bool displayAttendance(string rollno) {
		if (count != 0) {
			for (int i = 0; i < count; i++) {
				if (stm[i].getRollNo() == rollno) {
					bool flag=stm[i].displayAttendance();
					return flag;

				}
			}

		}
		else {
			cout << "\nNo Student enrolled yet\n";
			return false;
		}
	}
	bool markAttendance(string rollno) {
		if (count != 0) {
			for (int i = 0; i < count; i++) {
				if (stm[i].getRollNo() == rollno) {
					string a;
					double a3;
					cout << "\nEnter the course code for which you want to mark attendance\n";
					cin >> a;
					cout << "\nEnter the attendance percentage\n";
					cin >> a3;

					bool flag = stm[i].updateAttendance(a3, a);
					return flag;

				}
			}

		}
		else {
			cout << "\nNo Student enrolled yet\n";
			return false;
		}
	}
	bool displayMarks(string rollno) {
		if (count != 0) {
			for (int i = 0; i < count; i++) {
				if (stm[i].getRollNo() == rollno) {
					bool flag=stm[i].displayMarks();
					return flag;

				}
			}

		}
		else {
			cout << "\nNo Student enrolled yet\n";
			return false;
		}
	}
	bool assignMarks(string rollno) {
		if (count != 0) {
			for (int i = 0; i < count; i++) {
				if (stm[i].getRollNo() == rollno) {
					string a;
					double a3;
					cout << "\nEnter the course code for which you want to assign marks\n";
					cin >> a;
					cout << "\nEnter the marks\n";
					cin >> a3;

					bool flag=stm[i].updateMarks(a3, a);
					return flag;

				}
			}

		}
		else {
			cout << "\nNo Student enrolled yet\n";
			return false;
		}
	}

	bool enrolledCourses(string rollno) {
		if (count != 0) {
			for (int i = 0; i < count; i++) {
				if (stm[i].getRollNo() == rollno) {
					bool flag =stm[i].displayAllCourses();
					return flag;

				}
			}

		}
		else {
			cout << "\nNo Student enrolled yet\n";
			return false;
		}
	}

	bool registerCourse(string rollno, string code) {
		if (count != 0) {
			Course c = AllCourses->search(code);
			if (c.getCode() == "") {
				cout << "\nWrong Course code\n";
					return false;
			}

			for (int i = 0; i < count; i++) {
				if (stm[i].getRollNo() == rollno) {
					stm[i].registerCourse(c);
					bool flag=AllCourses->addstudentToaCourse(rollno, c.getCode());
					return flag;

				}
			}
			cout << "\nNo such student exists\n";
			return false;

		}
		else {
			cout << "\nNo Student enrolled yet\n";
			return false;
		}
	}
	bool WithdrawCourse(string rollno, string code) {
		if (count != 0) {
			Course c = AllCourses->search(code);
			if (c.getCode() == "") {
				cout << "\nWrong Course code\n";
				return false;
			}
			for (int i = 0; i < count; i++) {
				if (stm[i].getRollNo() == rollno) {
					stm[i].withdrawCourse(c.getCode());
					bool flag=AllCourses->removestudentfromaCourse(rollno, c.getCode());
					return flag;

				}
			}

		}
		else {
			cout << "\nNo Student enrolled yet\n";
			return false;
		}
	}

	~System()
	{
		delete[]stm;
	}
};
System* System::ins = nullptr;






int main() {

	// Main window
	
	System* S1 = System::getInstance();
	Student s1("Ali", "20L-6564", 21, "0300");
	Student s2("Ahmed", "21L-2333", 21, "0301");
	Student s3("Hamza", "22L-6822", 22, "0302");
	Student s4("Haris", "23L-1132", 22, "0302");
	Course C1("Cs-100", "PF", "Faraz", 3);
	Course C2("Ds-100", "OOP", "Ahmad", 2);
	Course C3("Cs-80", "English", "Babar", 1);
	Course C4("EE-80", "Dld", "Shan", 3);
	S1->AddNewCourseToUni(C1);
	S1->AddNewCourseToUni(C2);
	S1->AddNewCourseToUni(C3);
	S1->addStudent(s1);
	S1->addStudent(s2);
	S1->addStudent(s3);
	S1->addStudent(s4);
	S1->registerCourse("22L-6822", "Cs-100");
	S1->registerCourse("22L-6822", "Ds-100");
	S1->registerCourse("22L-6822", "Cs-80");
	S1->registerCourse("22L-6822", "EE-80");
	S1->registerCourse("20L-6564", "Cs-80");
	S1->registerCourse("20L-6564", "Ds-100");
	S1->registerCourse("20L-6564", "Cs-100");
	S1->registerCourse("21L-2333", "EE-80");
	S1->registerCourse("21L-2333", "Cs-80");
	S1->registerCourse("23L-1132", "Cs-100");

    
	sf::RenderWindow Menu(sf::VideoMode(800, 600), "Main Menu");
	//sf::RenderWindow enrolledwindow(sf::VideoMode(800, 600), "enrolled window");
	MainMenu mainmenu(Menu.getSize().x, Menu.getSize().y);
	//Enroll enroll(enrolledwindow.getSize().x, enrolledwindow.getSize().y);
	
	RectangleShape Background;
	Background.setSize(Vector2f(800, 600));
	Background.setFillColor(Color::Cyan);
	Texture backgTexture;
	backgTexture.loadFromFile("Texture/FlexF.jpeg");
	Background.setTexture(&backgTexture);
	sf::Font font;
	if (!font.loadFromFile("Fonts/arial.ttf")) {
		// Handle font loading error
		return EXIT_FAILURE;
	}
	Text addStudentText("Student Added", font, 20);
	addStudentText.setPosition(100, 100);
	addStudentText.setFillColor(Color::Blue);
	Text addCourseText("Course added", font, 20);
	addStudentText.setPosition(100, 100);


	// Create additional windows
	//sf::RenderWindow addStudentWindow(sf::VideoMode(400, 300), "Add Student");
	//sf::RenderWindow addCourseWindow(sf::VideoMode(600, 300), "Add Course");
	// Create more windows as needed
	// Font for text

	// Text for buttons in main window
	while (Menu.isOpen()) {
		sf::Event event;
		while (Menu.pollEvent(event)) {
			if (event.type == Event::Closed) {
				Menu.close();
			}
			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::Up) {
					mainmenu.Moveup();
					break;
				}
				if (event.key.code == Keyboard::Down) {
					mainmenu.MoveDown();
					break;
				}
			}
			if (event.key.code == Keyboard::Return) {
				//RenderWindow Student(VideoMode(960, 720), "Add Student");
				//sf::Text options("1. Display Enrolled Students\n2. Add a Student\n3. Remove a Student\n4. Edit Student Details\n5. Back", font, 20);
				//options.setPosition(50, 150);

				RenderWindow Course(VideoMode(960, 720), "Add Course");
				int x = mainmenu.MenuPress();
				//int selected = enroll.MenuPress();
				if (x == 0)
				{
					sf::RenderWindow enrolledwindow(sf::VideoMode(800, 600), "enrolled window");
					Enroll enroll(enrolledwindow.getSize().x, enrolledwindow.getSize().y);
					while (enrolledwindow.isOpen()) {
						Event enrolledEvent;
						while (enrolledwindow.pollEvent(enrolledEvent)) {
							if (enrolledEvent.type == Event::Closed) {
								enrolledwindow.close();
							}
							if (enrolledEvent.type == sf::Event::KeyPressed) {
								if (enrolledEvent.key.code == Keyboard::Escape) {
									enrolledwindow.close();
								}
							}
							if (enrolledEvent.type == Event::KeyReleased) {
								if (enrolledEvent.key.code == Keyboard::Up) {
									enroll.Moveup();
									break;
								}
								if (enrolledEvent.key.code == Keyboard::Down) {
									enroll.MoveDown();
									break;
								}
							}
							if (enrolledEvent.key.code == Keyboard::Return) {
								int selected = enroll.MenuPress();
								if (selected == 0) {
									sf::RenderWindow dispStdwindow(sf::VideoMode(800, 600), "Display student window");
									while (dispStdwindow.isOpen()) {
										Event dEvent;
										while (dispStdwindow.pollEvent(dEvent)) {
											if (dEvent.type == Event::Closed) {
												dispStdwindow.close();
											}
											if (dEvent.type == sf::Event::KeyPressed) {
												if (dEvent.key.code == Keyboard::Escape) {
													dispStdwindow.close();
												}
											}
										}
										
										
										dispStdwindow.clear();
										sf::Text dispText("Enrolled Students Displayed", font, 20);
										dispText.setPosition(30, 100);
										dispText.setFillColor(Color::Yellow);
										dispText.setCharacterSize(60);
										dispStdwindow.draw(dispText);
										dispStdwindow.display();
									}
									
									S1->DisplayAllStudents();
								}
							
								if (selected == 1) {
									int age;
									string name, rollno, contact,temptext;
									//cin.ignore();
									cout << "\nEnter name\n";
									getline(cin, name);
									cout << "\nEnter rollno\n";
									getline(cin, rollno);
									cout << "\nEnter contact\n";
									getline(cin, contact);
									cout << "\nEnter age\n";
									cin >> age;
									cin.ignore();

									Student S5(name, rollno, age, contact);

									bool flag = S1->addStudent(S5);
									if (flag == true)
										temptext = "Student added";
									else
										temptext = "Error or Student already exist";
									sf::RenderWindow addStdwindow(sf::VideoMode(800, 600), "add student window");
									
									while (addStdwindow.isOpen()) {
										Event addsEvent;
										while (addStdwindow.pollEvent(addsEvent)) {
											if (addsEvent.type == Event::Closed) {
												addStdwindow.close();
											}
											if (addsEvent.type == sf::Event::KeyPressed) {
												if (addsEvent.key.code == Keyboard::Escape) {
													addStdwindow.close();
												}
											}
										}

										addStdwindow.clear();
											sf::Text addStdText(temptext, font, 20);
											addStdText.setPosition(30, 100);
											addStdText.setFillColor(Color::Yellow);
											addStdText.setCharacterSize(60);
											addStdwindow.draw(addStdText);
											addStdwindow.display();
										
									}
						}
								if (selected == 2) {
									
									string rollno,temptext;
									cout << "\nEnter student roll no:\n";
									getline(cin, rollno);
									bool flag = S1->removeStudent(rollno);
									if (flag == true) 
										temptext = "Student removed";
									else
										temptext = "Wrong credentials";
									sf::RenderWindow remStdwindow(sf::VideoMode(800, 600), "remove student window");
									while (remStdwindow.isOpen()) {
										Event remEvent;
										while (remStdwindow.pollEvent(remEvent)) {
											if (remEvent.type == Event::Closed) {
												remStdwindow.close();
											}
											if (remEvent.type == sf::Event::KeyPressed) {
												if (remEvent.key.code == Keyboard::Escape) {
													remStdwindow.close();
												}
											}
										}



										remStdwindow.clear();
										sf::Text remStudentText(temptext, font, 20);

										remStudentText.setPosition(30, 100);
										remStudentText.setFillColor(Color::Yellow);
										remStudentText.setCharacterSize(60);
										remStdwindow.draw(remStudentText);
										remStdwindow.display();
									}
									
									
								}
								if (selected == 3) {
									string rollno, temptext;
									cout << "\nEnter roll no of student:\n";
									getline(cin, rollno);
									bool flag=S1->editStdDetails(rollno);
									if (flag == true)
										temptext = "Details has been updated";
									else
										temptext = "Student does not exist";
									sf::RenderWindow editStdwindow(sf::VideoMode(800, 600), "edit student window");
									while (editStdwindow.isOpen()) {
										Event editEvent;
										while (editStdwindow.pollEvent(editEvent)) {
											if (editEvent.type == Event::Closed) {
												editStdwindow.close();
											}
											if (editEvent.type == sf::Event::KeyPressed) {
												if (editEvent.key.code == Keyboard::Escape) {
													editStdwindow.close();
												}
											}
										}
										editStdwindow.clear();
										sf::Text editStudentText(temptext, font, 20);
										editStudentText.setPosition(30, 100);
										editStudentText.setFillColor(Color::Yellow);
										editStudentText.setCharacterSize(60);
										editStdwindow.draw(editStudentText);
										editStdwindow.display();

									}
									
								}
								if (selected == 4)
									enrolledwindow.close();
								
							}


						}
						Course.close();
						//Student.clear();
						enrolledwindow.clear();
						enroll.draw(enrolledwindow);
						//Menu.clear();
						enrolledwindow.display();
					}
				}



				if (x == 1)
				{
					sf::RenderWindow registerwindow(sf::VideoMode(800, 600), "register window");
					Registration regist(registerwindow.getSize().x, registerwindow.getSize().y);
					while (registerwindow.isOpen()) {
						Event registerEvent;
						while (registerwindow.pollEvent(registerEvent)) {
							if (registerEvent.type == Event::Closed) {
								registerwindow.close();
							}
							if (registerEvent.type == sf::Event::KeyPressed) {
								if (registerEvent.key.code == Keyboard::Escape) {
									registerwindow.close();
								}
							}
							if (registerEvent.type == Event::KeyReleased) {
								if (registerEvent.key.code == Keyboard::Up) {
									regist.Moveup();
									break;
								}
								if (registerEvent.key.code == Keyboard::Down) {
									regist.MoveDown();
									break;
								}
							}
							if (registerEvent.key.code == Keyboard::Return) {
								int selected = regist.MenuPress();
								if (selected == 0) {
									S1->DisplayAllCourses();
									sf::RenderWindow avail_courseswindow(sf::VideoMode(800, 600), "Available Courses");
									while (avail_courseswindow.isOpen()) {
										Event avail_coursesEvent;
										while (avail_courseswindow.pollEvent(avail_coursesEvent)) {
											if (avail_coursesEvent.type == Event::Closed) {
												avail_courseswindow.close();
											}
											if (avail_coursesEvent.type == sf::Event::KeyPressed) {
												if (avail_coursesEvent.key.code == Keyboard::Escape) {
													avail_courseswindow.close();
												}
											}
										}


										avail_courseswindow.clear();
										sf::Text aText("Available Courses Displayed", font, 20);
										aText.setPosition(30, 100);
										aText.setFillColor(Color::Yellow);
										aText.setCharacterSize(60);
										avail_courseswindow.draw(aText);
										avail_courseswindow.display();
									}
									
								}
								if (selected == 1) {
									string rollno, code, temptext;
									
									cout << "\nEnter Student rollno\n";
									getline(cin, rollno);
									cout << "\nEnter Course code\n";
									getline(cin, code);
									bool flag = S1->registerCourse(rollno, code);
									if (flag == true)
										temptext = "Student registered in the course succesfully";
									else
										temptext = "Error during registration";

									sf::RenderWindow reg_courseswindow(sf::VideoMode(800, 600), "Register Courses");
									while (reg_courseswindow.isOpen()) {
										Event reg_coursesEvent;
										while (reg_courseswindow.pollEvent(reg_coursesEvent)) {
											if (reg_coursesEvent.type == Event::Closed) {
												reg_courseswindow.close();
											}
											if (reg_coursesEvent.type == sf::Event::KeyPressed) {
												if (reg_coursesEvent.key.code == Keyboard::Escape) {
													reg_courseswindow.close();
												}
											}
										}


										reg_courseswindow.clear();
										sf::Text aText(temptext, font, 20);
										aText.setPosition(25, 100);
										aText.setFillColor(Color::Yellow);
										aText.setCharacterSize(40);
										reg_courseswindow.draw(aText);
										reg_courseswindow.display();
									}

									
								}
							}
							

						}
						//C1.addStudent(s1);
						Course.close();
						//Student.clear();
						registerwindow.clear();
						regist.draw(registerwindow);
						//Menu.clear();
						registerwindow.display();
					}
				}



				if (x == 2) {
					sf::RenderWindow attwindow(sf::VideoMode(800, 600), "Attendance window");
					Attendance att(attwindow.getSize().x, attwindow.getSize().y);
					while (attwindow.isOpen()) {
						Event attEvent;
						while (attwindow.pollEvent(attEvent)) {
							if (attEvent.type == Event::Closed) {
								attwindow.close();
							}
							if (attEvent.type == sf::Event::KeyPressed) {
								if (attEvent.key.code == Keyboard::Escape) {
									attwindow.close();
								}
							}
							if (attEvent.type == Event::KeyReleased) {
								if (attEvent.key.code == Keyboard::Up) {
									att.Moveup();
									break;
								}
								if (attEvent.key.code == Keyboard::Down) {
									att.MoveDown();
									break;
								}
							}
							if (attEvent.key.code == Keyboard::Return) {
								int select = att.MenuPress();
								if (select == 0) {
									string temptext, rollno;
									cout << "\nEnter Roll no\n";
									getline(cin, rollno);
									bool flag=S1->displayAttendance(rollno);
									if (flag == true) 
									temptext = "Attendence displayed"; 
									else temptext = "No student with the given roll no exist";
									sf::RenderWindow disp_attendancewindow(sf::VideoMode(800, 600), "Attendance display");
									while (disp_attendancewindow.isOpen()) {
										Event dispattEvent;
										while (disp_attendancewindow.pollEvent(dispattEvent)) {
											if (dispattEvent.type == Event::Closed) {
												disp_attendancewindow.close();
											}
											if (dispattEvent.type == sf::Event::KeyPressed) {
												if (dispattEvent.key.code == Keyboard::Escape) {
													disp_attendancewindow.close();
												}
											}
										}


										disp_attendancewindow.clear();
										sf::Text attText(temptext, font, 20);
										attText.setPosition(20, 100);
										attText.setFillColor(Color::Yellow);
										attText.setCharacterSize(40);
										disp_attendancewindow.draw(attText);
										disp_attendancewindow.display();
									}
									
								}
								if (select == 1) {
									string temptext, rollno;
									cout << "\nEnter Roll no\n";
									getline(cin, rollno);
									bool flag =S1->markAttendance(rollno);
									if (flag == true) 
										temptext = "Attendence marked"; 
									else 
										temptext = "Attendance cannot be marked";
									sf::RenderWindow markattwindow(sf::VideoMode(800, 600), "mark attendance");
									while (markattwindow.isOpen()) {
										Event markEvent;
										while (markattwindow.pollEvent(markEvent)) {
											if (markEvent.type == Event::Closed) {
												markattwindow.close();
											}
											if (markEvent.type == sf::Event::KeyPressed) {
												if (markEvent.key.code == Keyboard::Escape) {
													markattwindow.close();
												}
											}
										}


										markattwindow.clear();
										sf::Text markText(temptext, font, 20);
										markText.setPosition(20, 100);
										markText.setFillColor(Color::Yellow);
										markText.setCharacterSize(50);
										markattwindow.draw(markText);
										markattwindow.display();
									}

									
								}
							}

						}
						//C1.addStudent(s1);
						Course.close();
						//Student.clear();
						attwindow.clear();
						att.draw(attwindow);
						//Menu.clear();
						attwindow.display();
					}
				}
				if (x == 3) {
					sf::RenderWindow markwindow(sf::VideoMode(800, 600), "enrolled window");
					Marks mark(markwindow.getSize().x, markwindow.getSize().y);
					while (markwindow.isOpen()) {
						Event markEvent;
						while (markwindow.pollEvent(markEvent)) {
							if (markEvent.type == Event::Closed) {
								markwindow.close();
							}
							if (markEvent.type == sf::Event::KeyPressed) {
								if (markEvent.key.code == Keyboard::Escape) {
									markwindow.close();
								}
							}
							if (markEvent.type == Event::KeyReleased) {
								if (markEvent.key.code == Keyboard::Up) {
									mark.Moveup();
									break;
								}
								if (markEvent.key.code == Keyboard::Down) {
									mark.MoveDown();
									break;
								}
							}
							if (markEvent.key.code == Keyboard::Return) {
								int select = mark.MenuPress();
								if (select == 0) {
									string temptext, rollno;
									cout << "\nEnter Roll no\n";
									//cin.ignore();
									getline(cin, rollno);
									bool flag=S1->displayMarks(rollno);
									if (flag == true)
										temptext = "Marks Displayed";
									else
										temptext = "Marks cannot be displayed";
									sf::RenderWindow disp_markswindow(sf::VideoMode(800, 600), "Marks display");
									while (disp_markswindow.isOpen()) {
										Event dispmarkEvent;
										while (disp_markswindow.pollEvent(dispmarkEvent)) {
											if (dispmarkEvent.type == Event::Closed) {
												disp_markswindow.close();
											}
											if (dispmarkEvent.type == sf::Event::KeyPressed) {
												if (dispmarkEvent.key.code == Keyboard::Escape) {
													disp_markswindow.close();
												}
											}
										}


										disp_markswindow.clear();
										sf::Text marksText(temptext, font, 20);
										marksText.setPosition(30, 100);
										marksText.setFillColor(Color::Yellow);
										marksText.setCharacterSize(50);
										disp_markswindow.draw(marksText);
										disp_markswindow.display();
									}
									
								}
								if (select == 1) {			
									string temptext, rollno;
									cout << "\nEnter Roll no\n";
									getline(cin, rollno);
									bool flag = S1->assignMarks(rollno);
									if (flag == true)
										temptext = "Marks Assigned";
									else
										temptext = "Marks cannot be assigned";
									sf::RenderWindow assignmarkwindow(sf::VideoMode(800, 600), "Assign marks");
									while (assignmarkwindow.isOpen()) {
										Event amarkEvent;
										while (assignmarkwindow.pollEvent(amarkEvent)) {
											if (amarkEvent.type == Event::Closed) {
												assignmarkwindow.close();
											}
											if (amarkEvent.type == sf::Event::KeyPressed) {
												if (amarkEvent.key.code == Keyboard::Escape) {
													assignmarkwindow.close();
												}
											}
										}

										
										assignmarkwindow.clear();
										sf::Text amarkText(temptext, font, 20);
										amarkText.setPosition(30, 100);
										amarkText.setFillColor(Color::Yellow);
										amarkText.setCharacterSize(50);
										assignmarkwindow.draw(amarkText);
										assignmarkwindow.display();
									}

									
								}
							}
						}
						//C1.addStudent(s1);
						Course.close();
						//Student.clear();
						markwindow.clear();
						mark.draw(markwindow);
						//Menu.clear();
						markwindow.display();
					}
					
				}
				if (x == 4) {
					sf::RenderWindow withdrawwindow(sf::VideoMode(800, 600), "withdraw window");
					Withdraw withdraw(withdrawwindow.getSize().x, withdrawwindow.getSize().y);
					while (withdrawwindow.isOpen()) {
						Event withdrawEvent;
						while (withdrawwindow.pollEvent(withdrawEvent)) {
							if (withdrawEvent.type == Event::Closed) {
								withdrawwindow.close();
							}
							if (withdrawEvent.type == sf::Event::KeyPressed) {
								if (withdrawEvent.key.code == Keyboard::Escape) {
									withdrawwindow.close();
								}
							}
							if (withdrawEvent.type == Event::KeyReleased) {
								if (withdrawEvent.key.code == Keyboard::Up) {
									withdraw.Moveup();
									break;
								}
								if (withdrawEvent.key.code == Keyboard::Down) {
									withdraw.MoveDown();
									break;
								}
							}
							if (withdrawEvent.key.code == Keyboard::Return) {
								int select = withdraw.MenuPress();
								if (select == 0) {
									string temptext, rollno;
									cout << "\nEnter Roll no\n";
									getline(cin, rollno);
									bool flag = S1->enrolledCourses(rollno);
									if (flag == true)
										temptext = "Courses Displayed";
									else
										temptext = "Error Courses cannot be displayed";
									
									sf::RenderWindow disp_withdrawindow(sf::VideoMode(800, 600), "Withdraw display");
									Event disp_withdraw;
									while (disp_withdrawindow.isOpen()) {
										while (disp_withdrawindow.pollEvent(disp_withdraw)) {
											if (disp_withdraw.type == Event::Closed) {
												disp_withdrawindow.close();
											}
											if (disp_withdraw.type == sf::Event::KeyPressed) {
												if (disp_withdraw.key.code == Keyboard::Escape) {
													disp_withdrawindow.close();
												}
											}
										}


										disp_withdrawindow.clear();
										sf::Text withText(temptext, font, 20);
										withText.setPosition(25, 100);
										withText.setFillColor(Color::Yellow);
										withText.setCharacterSize(50);
										disp_withdrawindow.draw(withText);
										disp_withdrawindow.display();
									}
									
									
								}
								if (select == 1) {
									string temptext, rollno,code;
									cout << "\nEnter Roll no\n";
									getline(cin, rollno);
									cout << "\nEnter course code\n";
									getline(cin, code);
									bool flag = S1->WithdrawCourse(rollno,code);
									if (flag == true)
										temptext = "Withdrawing Course";
									else
										temptext = "Error Course cannot be withdrawn";
									sf::RenderWindow dropwindow(sf::VideoMode(800, 600), "drop course");
									while (dropwindow.isOpen()) {
										Event dropEvent;
										while (dropwindow.pollEvent(dropEvent)) {
											if (dropEvent.type == Event::Closed) {
												dropwindow.close();
											}
											if (dropEvent.type == sf::Event::KeyPressed) {
												if (dropEvent.key.code == Keyboard::Escape) {
													dropwindow.close();
												}
											}
										}

										dropwindow.clear();
										sf::Text dropText(temptext, font, 20);
										dropText.setPosition(30, 100);
										dropText.setFillColor(Color::Yellow);
										dropText.setCharacterSize(40);
										dropwindow.draw(dropText);
										dropwindow.display();

									}
									
									
								}
								
							}
						}
						//C1.addStudent(s1);
						Course.close();
						//Student.clear();
						withdrawwindow.clear();
						withdraw.draw(withdrawwindow);
						//Menu.clear();
						withdrawwindow.display();
					}
				}
				if (x == 5) {
					exit(0);
				}
				
			}
		}


		Menu.clear();
		Menu.draw(Background);
		mainmenu.draw(Menu);
		Menu.display();
		cout<<"hello"<<endl;
	}
}
	
