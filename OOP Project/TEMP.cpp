//#include<iostream>
//#include<string>
//using namespace std;
//
//class Student {
//private:
//	string name;
//	string rollno;
//	int age;
//	string contact;
//public:
//	Student() {
//		name = "";
//		rollno = "";
//		age = 0;
//		contact = "";
//		
//	}
//	Student(string Name, string roll, int Age, string Contact) {
//		name = Name;
//		rollno = roll;
//		age = Age;
//		contact = Contact;
//		
//	}
//	void operator =(Student&obj) {
//		this->name = obj.name;
//		this->rollno = obj.rollno;
//		this->age = obj.age;
//		this->contact = obj.contact;
//	}
//	void setRoll(string rollno) {
//		this->rollno = rollno;
//	}
//	void setName(string Name) {
//		this->name = Name;
//	}
//	void setAge(int age) {
//		this->age = age;
//	}
//	void setContact(string phoneno) {
//		this->contact = phoneno;
//	}
//
//	string getRollno() {
//		return this->rollno;
//	}
//	string getContact() {
//		return this->contact;
//	}
//	string getName() {
//		return this->name;
//	}
//	int getAge() {
//		return this->age;
//	}
//	void display() {
//		cout << "Name: " << this->name << endl;
//		cout << "Roll no: " << this->rollno << endl;
//		cout << "Age: " << this->age << endl;
//		cout << "Contact no: " << this->contact << endl;
//		
//	}
//	~Student() {
//		
//	}
//
//};
// //defining global variales for temp space;
//string temp1_name;
//string temp1_contact;
//int temp1_age;
//
//class studentEnrollment {
//private:
//	Student* std;
//	int size;
//	int capacity;
//	static studentEnrollment* se;
//	bool searchStudent(string s) {
//		for (int i = 0; i < size; i++) {
//			if (s == std[i].getRollno()) {
//				return true;
//			}
//		}
//		return false;
//	}
//	studentEnrollment() {
//		capacity = 1;
//		std = new Student[capacity];
//		size = 0;
//	}
//
//public:
//
//	static studentEnrollment* getInstance() {
//		if (se == NULL) {
//			se = new studentEnrollment;
//
//		}
//		return se;
//
//	}
//
//	void addStudent(Student& s) {
//		if (searchStudent(s.getRollno()) == true) {
//			cout << "\nStudent already enrolled in University\n";
//			return;
//		}
//		if (size < capacity) {
//			std[size++] = s;
//		}
//		else {
//			capacity = capacity * 2;
//			Student* temp = new Student[capacity];
//			for (int i = 0; i < size; i++) {
//				temp[i] = std[i];
//			}
//			delete[]std;
//			std = temp;
//			temp = nullptr;
//			std[size++] = s;
//		}
//		cout << "\nStudent added\n";
//	}
//	bool removeStudent(string s) {
//		bool flag = false;
//		if (size > 0) {
//			for (int i = 0; i < size; i++) {
//				if (s == std[i].getRollno()) {
//					size--;
//					flag = true;
//					for (int j = i; j < size; j++) {
//						std[j] = std[j + 1];
//					}
//					cout << "\nStudent removed\n";
//					return true;
//				}
//			}
//			if (flag == false) {
//				cout << "\nStudent does not exist\n";
//				return false;
//			}
//		}
//		else {
//			cout << "No student is currently enrolled\n";
//			return false;
//		}
//	}
//	bool editDetails(string S) {
//		if (searchStudent(S) == true) {
//			for (int i = 0; i < size; i++) {
//				if (S == std[i].getRollno()) {
//					string t_name, contact, r_no;
//					int age;
//					cout << "Enter new roll_no\n";
//					getline(cin, r_no);
//					cout << "Enter new name\n";
//					getline(cin, t_name);
//					cout << "Enter new age\n";
//					cin >> age;
//					cin.ignore();
//					cout << "Enter new contact\n";
//					getline(cin, contact);
//					std[i].setName(t_name);
//					std[i].setAge(age);
//					std[i].setContact(contact);
//					std[i].setRoll(r_no);
//					cout << "\nDetails updated\n";
//					temp1_name=t_name;
//					temp1_contact=contact;
//					temp1_age=age;
//				}
//				return true;
//			}
//		}
//		else {
//			cout << "\nStudent does not exist\n";
//			return false;
//		}
//	}
//	void display() {
//		if (size != 0) {
//			cout << "\nStudents enrolled in the university are: \n";
//			for (int i = 0; i < size; i++) {
//				cout << "\nInformation of Student " << i + 1 << " is given as:\n";
//				std[i].display();
//			}
//		}
//	}
//
//	~studentEnrollment() {
//		delete[]std;
//		std = nullptr;
//	}
//};
//
//
//class Course {
//private:
//	string code;
//	string name;
//	string instructor;
//	int credits;
//	int capacity = 50;
//	string * enrolled_std = new string[capacity];
//	int size;
//	bool searchStudent(string std) {
//		for (int i = 0; i < size; i++) {
//			if (std == enrolled_std[i]) {
//				return true;
//			}
//		}
//		return false;
//	}
//
//public:
//	Course() {
//		code = "";
//		name = "";
//		instructor = "";
//		credits = 0;
//		size = 0;
//	}
//	Course(string code, string name, string instructor, int credits) {
//		this->code = code;
//		this->name = name;
//		this->instructor = instructor;
//		this->credits = credits;
//		this->size = 0;
//	}
//	void operator =(Course& obj) {
//		this->code = obj.code;
//		this->name = obj.name;
//		this->instructor = obj.instructor;
//		this->credits = obj.credits;
//		this->size = obj.size;
//		this->capacity = obj.capacity;
//		this->enrolled_std = new string[capacity];
//		for (int i = 0; i < size; i++) {
//			this->enrolled_std[i] = obj.enrolled_std[i];
//		}
//
//	}
//
//	void addStudent(string std) {
//		if (searchStudent(std) == true) {
//			cout << "\nStudent already enrolled in course\n";
//			return;
//		}
//		if (size < capacity) {
//			enrolled_std[size++] = std;
//			cout << "\nStudent added to the course\n";
//		}
//		else {
//			cout << "\nCourse Capacity is full you can not add student\n";
//		}
//	}
//	void removeStudent(string std) {
//		if (searchStudent(std) == true) {
//			for (int i = 0; i < size; i++) {
//				if (std == enrolled_std[i]) {
//					size--;
//					for (int j = i; j < size; j++) {
//						enrolled_std[j] = enrolled_std[j + 1];
//					}
//					cout << "\nStudent removed from the course\n";
//					break;
//				}
//			}
//		}
//		else {
//			cout << "\nStudent does not exist\n";
//		}
//	}
//	string getCode() {
//		return this->code;
//	}
//	string getName() {
//		return this->name;
//	}
//	string* getallStudent()
//	{
//		return enrolled_std;
//	}
//	void display() {
//		cout << "\nCode: " << this->code;
//		cout << "\nCourse name: " << this->name;
//		cout << "\nInstructor: " << this->instructor;
//		cout << "\nCredit :" << this->credits;
//		if (size > 0) {
//			cout << "\nEnrolled Student's roll nos are:\n";
//			for (int i = 0; i < size; i++) {
//				cout<<enrolled_std[i];
//				cout << endl;
//			}
//		}
//	}
//	~Course() {
//		/*delete[]enrolled_std;
//		enrolled_std = nullptr;*/
//	}
//};
//
//class CourseCatalogue {
//private:
//	Course* availableCourses;
//	int size;
//	int capacity;
//	static CourseCatalogue* CC;
//	bool searchCourse(string c) {
//		for (int i = 0; i < size; i++) {
//			if (c == availableCourses[i].getCode()) {
//				return true;
//			}
//		}
//		return false;
//	}
//public:
//	Course search(string code) {
//		for (int i = 0; i < size; i++) {
//			if (code == availableCourses[i].getCode()) {
//				return availableCourses[i];
//			}
//		}
//		Course temp;
//		return temp;
//	}
//	CourseCatalogue() {
//		capacity = 1;
//		availableCourses = new Course[capacity];
//		size = 0;
//	}
//
//public:
//	static CourseCatalogue* getInstance() {
//		if (CC == NULL) {
//			CC = new CourseCatalogue;
//
//		}
//		return CC;
//
//	}
//	void addCourse(Course& c) {
//		if (this->searchCourse(c.getCode()) == true) {
//			cout << "\nCourse already registered in University\n";
//			return;
//		}
//		if (size < capacity) {
//			availableCourses[size++] = c;
//		}
//		else {
//			capacity = capacity * 2;
//			Course* temp = new Course[capacity];
//			for (int i = 0; i < size; i++) {
//				temp[i] = availableCourses[i];
//			}
//			delete[]availableCourses;
//			availableCourses = temp;
//			temp = nullptr;
//			availableCourses[size++] = c;
//		}
//		cout << "\nCourse added\n";
//	}
//	void removeCourse(string c) {
//		if (searchCourse(c) == true) {
//			for (int i = 0; i < size; i++) {
//				if (c == availableCourses[i].getCode()) {
//					size--;
//					for (int j = i; j < size; j++) {
//						availableCourses[j] = availableCourses[j + 1];
//					}
//					cout << "\nCourse removed from the catalogue\n";
//					break;
//				}
//			}
//		}
//		else {
//			cout << "\nCourse does not exist\n";
//		}
//	}
//
//	void display() {
//		cout << "\nAvailable Courses in the university are: \n";
//		for (int i = 0; i < size; i++) {
//				cout << "\nInformation of Course " << i + 1 << " is given as:\n";
//			availableCourses[i].display();
//		}
//	}
//	void addstudentToaCourse(string rollno, string code)
//	{
//		if (size != 0)
//		{
//			for (int i = 0; i < size; i++)
//			{
//				if (availableCourses[i].getCode() == code)
//					availableCourses[i].addStudent(rollno);
//				return ;
//			}
//		}
//		return;
//	}
//
//	void removestudentfromaCourse(string rollno, string code)
//	{
//		if (size != 0)
//		{
//			for (int i = 0; i < size; i++)
//			{
//				if (availableCourses[i].getCode() == code)
//					availableCourses[i].removeStudent(rollno);
//				return;
//			}
//		}
//		return;
//	}
//	~CourseCatalogue() {
//		delete[]availableCourses;
//		availableCourses = nullptr;
//	}
//};
//
//class studentinfoManagament {
//private:
//	Student*s;
//	Course* c;
//	double* Marks;
//	double* Attendance;
//	int count;
//	int capacity;
//public:
//	void operator =(studentinfoManagament&a) {
//		this->s = new Student(a.s->getName(), a.s->getRollno(), a.s->getAge(), a.s->getContact());
//		this->count = a.count;
//		this->capacity = a.capacity;
//		this->c = new Course[capacity];
//		this->Marks = new double[capacity];
//		this->Attendance = new double[capacity];
//		for (int i = 0; i < count; i++) {
//			this->c[i] = a.c[i];
//			this->Marks[i] = a.Marks[i];
//			this->Attendance[i] = a.Attendance[i];
//		}
//	}
//
//	studentinfoManagament() {
//
//		s = nullptr;
//		c = nullptr;
//		Marks = nullptr;
//		Attendance = nullptr;
//		count = 0;
//		capacity = 0;
//	}
//	studentinfoManagament(Student*s1,Course*c1,double*m1,double*Attendance,int count) {
//		s = s1;
//		c = c1;
//		Marks = m1;
//		this->Attendance = Attendance;
//		this->count = count;
//		capacity = 0;
//	}
//	studentinfoManagament(Student* s1) {
//		s = s1;
//		this->count = 0;
//		capacity = 0;
//		c = nullptr;
//		Marks = nullptr;
//		Attendance = nullptr;
//	}
//
//	bool search(string courseId) {
//		for (int i = 0; i < count; i++) {
//			if (c[i].getCode() == courseId) {
//				return true;
//			}
//		}
//		return false;
//	}
//
//	void registerCourse(Course&C) {
//		if (search(C.getCode()) == true) {
//			cout << "\nStudent already enrolled in the course\n";
//			return;
//		}
//		else {
//			if (capacity == 0) {
//				capacity = 1;
//				c = new Course[capacity];
//				Marks = new double[capacity];
//				Attendance = new double[capacity];
//				c[0] = C;
//				Marks[0] = 0;
//				Attendance[0] = 0;
//				count++;
//				
//			}
//			else if (count < capacity) {
//				c[count] = C;
//				Marks[count] = 0;
//				Attendance[count] = 0;
//				count++;
//			}
//			else  {
//				capacity = capacity * 2;
//				Course* temp1 = new Course[capacity];
//				double* temp2 = new double[capacity];
//				double* temp3 = new double[capacity];
//				for (int i = 0; i < count; i++) {
//					temp1[i] = c[i];
//					temp2[i] = Marks[i];
//					temp3[i] = Attendance[i];
//				}
//				delete[]c;
//				delete[]Marks;
//				delete[]Attendance;
//				c = temp1;
//				Marks = temp2;
//				Attendance = temp3;
//				c[count] = C;
//				Marks[count] = 0;
//				Attendance[count] = 0;
//				count++;
//
//
//			}
//			cout << "\nStudent registered in the course sucessfully\n";
//		}
//
//	}
//	string getRollNo() {
//		return s->getRollno();
//	}
//	void updateMarks(double marks, string code) {
//		if (search(code) == false) {
//			cout << "\nStudent is not registered in that course\n";
//			return;
//		}
//		else {
//			for (int i = 0; i < count; i++) {
//				if (c[i].getCode() == code) {
//					Marks[i] = marks;
//					cout << "Marks has been updated\n";
//					return;
//				}
//				
//			}
//		}
//	}
//	void updateAttendance(double A, string code) {
//		if (search(code) == false) {
//			cout << "\nStudent is not registered in that course\n";
//			return;
//		}
//		else {
//			for (int i = 0; i < count; i++) {
//				if (c[i].getCode() == code) {
//					Attendance[i] = A;
//					cout << "Marks has been updated\n";
//					return;
//				}
//
//			}
//		}
//	}
//	void withdrawCourse(string id) {
//		if (search(id) == false) {
//			cout << "\nStudent is not enrolled in that course\n";
//			return;
//		}
//		else {
//			for (int i = 0; i < count; i++) {
//				if (c[i].getCode() == id) {
//					for (int j = i; j < count - 1; j++) {
//						c[j] = c[j + 1];
//					}
//					count--;
//					cout << "\nCourse has been withdrawn\n";
//				}
//			}
//		}
//
//	}
//	bool editDetails(string name,int age,string contact) {
//					s->setName(name);
//					s->setAge(age);
//					s->setContact(contact);
//	}
//
//	void displayMarks() {
//		if (count == 0)
//		{
//			cout << "\nStudent is not enrolled in any course yet" << endl;
//			return;
//
//		}
//		cout << "\nStudent Marks in each course are as follows :\n";
//		for (int i = 0; i < count; i++) {
//			cout << "Marks in : " << c[i].getName() << " are: " << Marks[i]<<endl;
//		}
//	}
//	void displayAttendance() {
//		if (count == 0)
//		{
//			cout << "\nStudent is not enrolled in any course yet" << endl;
//			return;
//
//		}
//		cout << "\nStudent Attendance in each course are as follows :\n";
//		for (int i = 0; i < count; i++) {
//			cout << "Attendance in : " << c[i].getName() << " is: " << Attendance[i] <<"%"<< endl;
//		}
//	}
//	void displayAllCourses()
//	{
//		if (count == 0)
//		{
//			cout << "\nStudent is not enrolled in any course yet" << endl;
//			return;
//
//		}
//		for (int i = 0; i < count; i++)
//		{
//			cout << "Course " << i + 1 << " : " << c[i].getName() << endl;
//		}
//	}
//	~studentinfoManagament() {
//		/*delete[]c;
//		delete[]Marks;
//		delete[]Attendance;*/
//	}
//};
//CourseCatalogue* CourseCatalogue::CC = nullptr;
//studentEnrollment* studentEnrollment::se = nullptr;
//
//class System {
//private:
//	CourseCatalogue* AllCourses = CourseCatalogue::getInstance();
//	studentEnrollment*AllStudents = studentEnrollment::getInstance();
//	studentinfoManagament* stm;
//	static System* ins;
//	int count;
//	const int capacity=1000;
//	System() {
//		int count = 0;
//		stm = new studentinfoManagament[capacity];
//	}
//public:
//	
//	static System* getInstance() {
//		if (ins == NULL) {
//		ins  = new System;
//
//		}
//		return ins;
//
//	}
//	 void addStudent(Student S) {
//		AllStudents->addStudent(S);
//		studentinfoManagament temp2(&S);
//		stm[count++] = temp2;
//
//	}
//	void AddNewCourseToUni(Course c)
//	{
//		AllCourses->addCourse(c);
//
//	}
//	void DisplayAllStudents()
//	{
//		AllStudents->display();
//	}
//	void DisplayAllCourses()
//	{
//		AllCourses->display();
//	}
//
//	void removeStudent(string id) {
//		
//		if (count != 0) {
//			bool flag=	AllStudents->removeStudent(id);
//			if (flag) {
//				for (int i = 0; i < count; i++) {
//					if (stm[i].getRollNo() == id) {
//						for (int j = i; j < count - 1; j++) {
//							stm[j] = stm[j + 1];
//						}
//						count--;
//						return;
//					}
//				}
//			}
//		}
//		else {
//			cout << "\nNo Student registred yet\n";
//		}
//
//	}
//	void editStdDetails(string rollno) {
//		bool flag=AllStudents->editDetails(rollno);
//		if (flag) {
//			for (int i = 0; i < count; i++) {
//				if (stm[i].getRollNo() == rollno) {
//					stm[i].editDetails(temp1_name, temp1_age, temp1_contact);
//					return;
//
//				}
//			}
//		}
//	}
//	void displayAttendance(string rollno) {
//		if (count != 0) {
//			for (int i = 0; i < count; i++) {
//				if (stm[i].getRollNo() == rollno) {
//					stm[i].displayAttendance();
//					return;
//
//				}
//			}
//
//		}
//		else {
//			cout << "\nNo Student enrolled yet\n";
//		}
//	}
//	void markAttendance(string rollno) {
//		if (count != 0) {
//			for (int i = 0; i < count; i++) {
//				if (stm[i].getRollNo() == rollno) {
//					string a;
//					double a3;
//					cout << "\nEnter the course code for which you want to mark attendance\n";
//					cin >> a;
//					cout << "\nEnter the attendance percentage\n";
//					cin >> a3;
//
//					stm[i].updateAttendance(a3, a);
//					return;
//
//				}
//			}
//
//		}
//		else {
//			cout << "\nNo Student enrolled yet\n";
//		}
//	}
//	void displayMarks(string rollno) {
//		if (count != 0) {
//			for (int i = 0; i < count; i++) {
//				if (stm[i].getRollNo() == rollno) {
//					stm[i].displayMarks();
//					return;
//
//				}
//			}
//
//		}
//		else {
//			cout << "\nNo Student enrolled yet\n";
//		}
//	}
//	void assignMarks(string rollno) {
//		if (count != 0) {
//			for (int i = 0; i < count; i++) {
//				if (stm[i].getRollNo() == rollno) {
//					string a;
//					double a3;
//					cout << "\nEnter the course code for which you want to assign marks\n";
//					cin >> a;
//					cout << "\nEnter the marks\n";
//					cin >> a3;
//
//					stm[i].updateMarks(a3, a);
//					return;
//
//				}
//			}
//
//		}
//		else {
//			cout << "\nNo Student enrolled yet\n";
//		}
//	}
//
//	void enrolledCourses(string rollno) {
//		if (count != 0) {
//			for (int i = 0; i < count; i++) {
//				if (stm[i].getRollNo() == rollno) {
//					stm[i].displayAllCourses();
//					return;
//
//				}
//			}
//
//		}
//		else {
//			cout << "\nNo Student enrolled yet\n";
//		}
//	}
//
//	void registerCourse(string rollno,Course c) {
//		if (count != 0) {
//			for (int i = 0; i < count; i++) {
//				if (stm[i].getRollNo() == rollno) {
//					stm[i].registerCourse(c);
//					AllCourses->addstudentToaCourse(rollno, c.getCode());
//					return;
//
//				}
//			}
//
//		}
//		else {
//			cout << "\nNo Student enrolled yet\n";
//		}
//	}
//	void WithdrawCourse(string rollno, Course c) {
//		if (count != 0) {
//			for (int i = 0; i < count; i++) {
//				if (stm[i].getRollNo() == rollno) {
//					stm[i].withdrawCourse(c.getCode());
//					AllCourses->removestudentfromaCourse(rollno, c.getCode());
//					return;
//
//				}
//			}
//
//		}
//		else {
//			cout << "\nNo Student enrolled yet\n";
//		}
//	}
//
//	~System()
//	{
//		delete[]stm;
//	}
//};
//System* System::ins = nullptr;
//System* S = System::getInstance();
//
//int main() {
//	/*cout << "\nPlease enter student details\n ";
//	string name, rollno, contact;
//	int age;
//	cout << "\nEnter name:\n";
//	cin >> name;
//	cout << "\nEnter rollno:\n";
//	cin >> rollno;
//	cout << "\nEnter phone-no:\n";
//	cin >> contact;
//	cout << "\nEnter age:\n";
//	cin >> age;*/
//	CourseCatalogue* C = CourseCatalogue::getInstance();
//	Student s1("Ali", "20L-", 21, "0300");
//	Student s2("Ahmed", "21L-", 21, "0301");
//	Student s3("Hamza", "23L-", 22, "0302");
//	Course C1("Cs-100", "PF", "Faraz", 3);
//	Course C2("ds-100", "OOP", "Ahmad", 2);
//	S->AddNewCourseToUni(C1);
//	S->DisplayAllCourses();
//	S->addStudent(s1);
//	Course C3 = C->search("Cs-500");
//	if (C3.getCode() == "") {
//		cout << "Wrong course code\n";
//	}
//	else {
//		S->registerCourse("20L-", C3);
//	}
//	
//	S->assignMarks("20L-");
//	S->displayMarks("20L-");
//}
