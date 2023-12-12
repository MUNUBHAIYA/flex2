#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class student
{
public:
	string name;
	string roll_no;
	string contact;
	int courses;
	float attendance;
	float marks;
	int age;
	fstream file;

	student()
	{
		name = ' ';
		roll_no = ' ';
		contact = ' ';
		courses = 0;
		attendance = 0.0;
		marks = 0.0;
		age = 0;
	}
	student(string n, string r)
	{
		name = n;
		roll_no = r;
	}
	void showAlreadyEnrolledStudemts()
	{
		string enrStd;
		cout << "1.Already Enrolled Student...\n";
		file.open("AlreadyEnrolledStudents.txt", ios::in);//read
		if (file.is_open())
		{
			while (getline(file, enrStd))
			{
				cout << enrStd << endl;
			}
		}

	}
	void enrollstudent()
	{
		cout << "Enter the information of new student to enroll...\n";
		cin.ignore();
		cout << "Enter name=";
		//cin >> name;
		getline(cin, name);
		cout << "Enter Roll_no=";
		getline(cin, roll_no);
		cout << "Enter Age=";
		cin >> age;
		cin.ignore();
		cout << "Enter Contact=";
		getline(cin, contact);
		file.open("AlreadyEnrolledStudents.txt", ios::app);//Append
		if (file.is_open())
		{
			file << endl << name << endl;
			file << roll_no << endl;
			file << age << endl;
			file << contact << endl;
		}
		file.close();
		cout << "Student information successfully saved\n";
	}
	void removestudent()
	{
		string str;
		const string filename = "ALreadyEnrolledStudents.txt";
		ifstream fil(filename);
		ofstream tempfile("temp.txt");
		cout << "Enter the name of student to remove=";
		getline(cin, name);
		cin.ignore();
		/*cout << "Enter Roll No=";
		getline(cin, roll_no);*/
		fil.open("AlreadyEnrolledStudents.txt", ios::in);
		if (fil.is_open())
		{
			while (getline(fil, str))
			{
				if (str.find(name) == string::npos)
				{
					tempfile << str << endl;
				}
			}
		}
		fil.close();
		tempfile.close();
		remove(filename.c_str());
		//rename("temp.txt", filename.c_str());
	}
	void editstudentsdetail()
	{
		cout << "Enter the name of student whose information you want to edit=";
		cin >> name;

	}
	/*void registerstudents()
	{

	}*/
	void mark_attendance()
	{
		string course;
		int c_at = 0;
		char att;
		file.open("Available Courses.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, course))
			{
				cout << course << endl;
			}
		}
		file.close();
		cout << "Choose the no from 1 to 5 to mark attendance of students of particular course respectively=";
		cin >> c_at;
		if (c_at == 1)
		{
			cout << "Enter 'p' for present and 'a' for absent...\n";
			file.open("Probability.txt", ios::in);
			if (file.is_open())
			{

				while (getline(file, course))
				{
					cout << "Mark attendance of " << course << "=";
					cin >> att;
				}
			}
			file.close();
		}
		if (c_at == 2)
		{
			cout << "Enter 'p' for present and 'a' for absent...\n";
			file.open("Object Oriented Programming.txt", ios::in);
			if (file.is_open())
			{

				while (getline(file, course))
				{
					cout << "Mark attendance of " << course << "=";
					cin >> att;
				}
			}
			file.close();
		}
		if (c_at == 3)
		{
			cout << "Enter 'p' for present and 'a' for absent...\n";
			file.open("Data Structures.txt", ios::in);
			if (file.is_open())
			{

				while (getline(file, course))
				{
					cout << "Mark attendance of " << course << "=";
					cin >> att;
				}
			}
			file.close();
		}
		if (c_at == 4)
		{
			cout << "Enter 'p' for present and 'a' for absent...\n";
			file.open("Digital Logic Design.txt", ios::in);
			if (file.is_open())
			{

				while (getline(file, course))
				{
					cout << "Mark attendance of " << course << "=";
					cin >> att;
				}
			}
			file.close();
		}
		if (c_at == 5)
		{
			cout << "Enter 'p' for present and 'a' for absent...\n";
			file.open("Assembly Language.txt", ios::in);
			if (file.is_open())
			{

				while (getline(file, course))
				{
					cout << "Mark attendance of " << course << "=";
					cin >> att;
				}
			}
			file.close();
		}
	}
	void assign_marks()
	{

	}
	void withdraw()
	{

	}
};
class course :public student
{
public:
	//student name("Ali","21L 7566");
	fstream file;
	string newname;
	string code;
	string c_name;
	string instructor;
	int credits;
	int capacity;
	course()
	{
		code = ' ';
		c_name = ' ';
		instructor = ' ';
		credits = 0;
		capacity = 0;
		newname = ' ';
	}
	course(string c, string n, string i, int cr, int cap)
	{
		code = c;
		c_name = n;
		instructor = i;
		credits = cr;
		capacity = cap;
	}
	void addstudents()   //add students to course
	{
		//cout << "Enter the name of student you want to register the course=";
		//getline(cin,name);
		//cin.ignore();
		////cin >> name;
		//cout << "Enter course name=";
		//getline(cin, c_name);
		//cin.ignore();

		//file.open("c_name.txt", ios::app);//Append
		//if(file.is_open())
		//{
		//	while (getline(file, name))
		//	{
		//		if (newname == name)
		//		{
		//			file << endl << c_name;
		//			cin.ignore();
		//		}
		//	}
		//}
		string str;
		int cr = 0;
		cin.ignore();
		cout << "Enter the name of student you want to register=";
		getline(cin, name);
		//cin.ignore();
		file.open("Available Courses.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, str))
			{
				cout << str << endl;
			}
		}
		file.close();
		cout << "Enter the number 1 to 5 to choose course respectively=";
		cin >> cr;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cr == 1)
		{
			file.open("Probability.txt", ios::app);
			if (file.is_open())
			{
				file << endl << name;
			}
		}
		if (cr == 2)
		{
			file.open("Object Oriented Programming.txt", ios::app);
			if (file.is_open())
			{
				file << endl << name;
			}
		}
		if (cr == 3)
		{
			file.open("Data Structures.txt", ios::app);
			if (file.is_open())
			{
				file << endl << name;
			}
		}
		if (cr == 4)
		{
			file.open("Digital Logic Design.txt", ios::app);
			if (file.is_open())
			{
				file << endl << name;
			}
		}
		if (cr == 5)
		{
			file.open("Asembly Language.txt", ios::app);
			if (file.is_open())
			{
				file << endl << name;
			}
		}
		cout << "Course Registered Succcessfully...\n";
	}
	void removeSTudents_course()
	{

	}

};
class System :public course
{
public:
	//student* s1;
	fstream menu;
	fstream file;
	string data;
	System()
	{
		data = " ";
	}
	System(string n)
	{
		data = n;
	}

	void mainMenu()
	{
		menu.open("mainMenu.txt", ios::in);
		if (menu.is_open())
		{
			while (getline(menu, data))
			{
				cout << data << endl;
			}
		}
		menu.close();
	}
	void submenu()
	{
		int n = 0, cr = 0, at = 0, ma = 0, cw = 0;
		while (n != 6) {

			cout << "Enter number from 1 to 6 to perform specific task=" << endl;
			cout << "1: Enroll student " << endl;
			cout << "2: Course Registration" << endl;
			cout << "3: Attendence " << endl;
			cout << "4: Marks " << endl;
			cout << "5: Course Withdraw" << endl;
			cout << "6: Exit" << endl;

			cin >> n;
			if (n == 1)
			{

				cout << "---Enrolled a student---\n";
				cout << "1.Display already enrolled students\n2.Add a student\n3.Remove a student\n4.Edit student detal\n5.Back\n";
				int enr = 0;
				cout << "Enter no from 1 to 4 to perform specific task=";
				cin >> enr;
				if (enr == 1)
				{
					showAlreadyEnrolledStudemts();
				}
				else if (enr == 2)
				{
					enrollstudent();
				}
				else if (enr == 3)
				{
					removestudent();
				}
				else if (enr == 4)
				{
					editstudentsdetail();
				}

			}
			else if (n == 2)
			{
				cout << "Course Registration\n";
				cout << "1.Available Cources\n2.Register cource\n3.Back\n";
				cout << "Enter no from 1 to 3 to perform specific task=";
				cin >> cr;
				if (cr == 1)
				{
					file.open("Available Courses.txt", ios::in);
					if (file.is_open())
					{
						while (getline(file, data))
						{
							cout << data << endl;
						}
					}
					file.close();
				}
				if (cr == 2)
				{
					//registerstudents();
					addstudents();
				}
				if (cr >= 3)
				{
					mainMenu();
				}
			}
			else if (n == 3)
			{
				int cc = 0;
				cout << "Attendance\n";
				cout << "1.Display Attendance\n2.Mark Attendance\n3.Back\n";
				cout << "Enter number from 1 to 3 to perform specific task=";
				cin >> at;
				if (at == 1)
				{
					file.open("Available Courses.txt", ios::in);
					if (file.is_open())
					{
						while (getline(file, data))
						{
							cout << data << endl;
						}
					}
					file.close();
					cout << "Choose the no from 1 to 5 to show attendance of students of particular course respectively=";
					cin >> cc;
					if (cc == 1)
					{
						file.open("Probability Attendance.txt", ios::in);
						if (file.is_open())
						{
							while (getline(file, data))
							{
								cout << data << endl;
							}
						}
						file.close();
					}
					if (cc == 2)
					{
						file.open("Object Oriented Programming Attendance.txt", ios::in);
						if (file.is_open())
						{
							while (getline(file, data))
							{
								cout << data << endl;
							}
						}
						file.close();
					}
					if (cc == 3)
					{
						file.open("Data Structures Attendance.txt", ios::in);
						if (file.is_open())
						{
							while (getline(file, data))
							{
								cout << data << endl;
							}
						}
						file.close();
					}
					if (cc == 4)
					{
						file.open("Digital Logic Design Attendance.txt", ios::in);
						if (file.is_open())
						{
							while (getline(file, data))
							{
								cout << data << endl;
							}
						}
						file.close();
					}
					if (cc == 5)
					{
						file.open("Assembly Language Attendance.txt", ios::in);
						if (file.is_open())
						{
							while (getline(file, data))
							{
								cout << data << endl;
							}
						}
						file.close();
					}
				}
				else if (at == 2)
				{
					mark_attendance();
				}
				else if (at == 3)
				{
					mainMenu();
				}
			}
			else if (n == 4)
			{
				cout << "Marks\n";
				cout << "1.Display Marks\n2.Assign marks\n3.Back\n";
				cout << "Enter number from 1 to 3 to perform specific task=";
				if (ma == 1)
				{

				}
				else if (ma == 2)
				{
					assign_marks();
				}
				else if (ma == 3)
				{
					mainMenu();
				}
			}
			else if (n == 5)
			{
				cout << "Course Withdraw\n";
				cout << "1.Enrolled cources\n2.Withdraw course\n3.Back\n";
				cout << "Enter number from 1 to 3 to perform specific task=";
				if (cw == 1)
				{

				}
				else if (cw == 2)
				{
					withdraw();
				}
				else if (cw == 3)
				{
					mainMenu();
				}

			}
			system("CLS");
		}


	}

};


int main()
{
	System menuobj;
	menuobj.mainMenu();
	menuobj.submenu();
	student s1;




	system("pause");
	return 0;
}