#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
class University
{
protected:
	string luserid, lpw, lid, lpassword;
	string ruserid, rpw, rid, rpassword;
	string fuserid, fpw, fid, fpassword;
public:
	void LogIn();
	void Registration();
	void Forgot();

};
class Administration :public University {
protected:
	string timetable;
};
class Professors :public University {
private:
	string course;
	string office_hours;
};


int main()
{
	University u;

	system("color 0b");
	int choice;
	
		system("cls");
		cout << "\t\t\t\t----->\tWelcome To Eclass System\t<-----" << endl;
		cout << "\t\t-----------------------------------------------------------------" << endl;
		cout << "\t\t|\t1: Login As a Student\t\t\t\t\t|" << endl;
		cout << "\t\t|\t2: Login As a Faculty\t\t\t\t\t|" << endl;		
		cout << "\t\t|\t3: Exit\t\t\t\t\t\t\t|" << endl;
		cout << "\t\t-----------------------------------------------------------------" << endl;
		cout << "\t\t\tEnter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				u.LogIn();

			}break;
			case 2:
			{
				//Forgot();
			}break;
		default:
			system("cls");
			cout << "\t\t|\t Please choose the options given above \n" << endl;
			main();
		}
		
}
void University::LogIn() {
	int count=0;
	/*char pass[32];
	
	char a;
	int i = 0;*/
	system("cls");
	cout << "\t\t\t\t----->\tEnter the Username and password\t<-----" << endl;
	cout << "\t\t|\tUSERNAME: ";
	cin >> luserid;
	cout << "\t\t|\tPASSWORD: ";
	cin >> lpw;
	
	//for (i = 0;;)//infinite loop
	//{
	//	a = _getch();//stores char typed in a
	//	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
	//		//check if a is numeric or alphabet
	//	{
	//		pass[i] = a;//stores a in pass
	//		++i;
	//		cout << "*";
	//	}
	//	if (a == '\b' && i >= 1)//if user typed backspace
	//		//i should be greater than 1.
	//	{
	//		cout << "\b \b";//rub the character behind the cursor.
	//		--i;
	//	}
	//	if (a == '\r')//if enter is pressed
	//	{
	//		pass[i] = '\0';//null means end of string.
	//		break;//break the loop
	//	}
	//}


	ifstream input("data.txt");

	while (input >> luserid >> lpassword)
	{
		if (lid == luserid && lpw == lpassword)
		{
			count = 1;
			system("cls");
		}
	}
	input.close();

	if (count == 1)
	{
		cout << "\t\t\t\t----->\tYou've successfully logged in\t<-----" << endl;
		cout << "\t\t\tUSERNAME: " << luserid << endl;
		cout << "\t\t\tPASSWORD: " << lpw << endl;
		main();
	}

	else
	{
		a1:
		int a;
		cout << "\t\t\t\t----->\tLOGIN ERROR!\t<-----" << endl;
		cout << "\t\t\tCheck your username and password!" << endl;
		cout << "\n\n\t\t\tForgot password?" << endl;
		cout << "\t\t\t1. Find password" << endl;
		cout << "\t\t\t2. Back to main menu" << endl;
		cout << "\t\t\tChoose the option: ";
		cin >> a;
		switch (a)
		{
			case 1:
			{
				Forgot();
			}break;
			case 2:
			{
				main();
			}
			default:
				cout << "\t\t\tWrong choise, try again!" << endl;
				goto a1;
		}

		

	}
}
void University::Registration()
{
	system("cls");
	cout << "\t\t\t\t----->\tCreate New Account\t<-----" << endl;
	cout << "\t\t\tEnter Username: ";
	cin >> ruserid;
	cout << "\t\t\tEnter Password: ";
	cin >> rpw;
	ofstream reg("data.txt", ios::app);
	reg << ruserid << '  ' << rpw << endl;
	system("cls");
	cout << "\t\t\t\t----->\tRegistrated Successfully!\t<-----" << endl;
	
}
void University::Forgot()
{
	int option;
	system("cls");
x1:
	
	cout << "\t\t\t\t----->\tForgot Your Password?\t<-----" << endl;
	cout << "\t\t|\t1. Reset password\t\t\t\t\t|" << endl;
	cout << "\t\t|\t2. Go back to main menu\t\t\t\t\t|" << endl;
	cout << "\t\t\tEnter Your Choice: ";
	cin >> option;
	switch (option)
	{
		case 1:
		{
			int count = 0;
			cout << "\t\t\tEnter Username: ";
			cin >> fuserid;

			ifstream forg("data.txt");
			while (forg >> fid >> fpassword)
			{
				if (fid == fuserid)
				{
					count = 1;
				}
			}
			forg.close();
				if (count == 1)
				{
					cout << "\t\t\t\t----->\tYour details are found!\t<-----" << endl;
					cout << "\t\t\tYour Password: " << fpassword;
					main();
				}
				else
				{
					cout << "\t\t\t\t----->\tYour account not found!\t<-----" << endl;
					goto x1;
				}
		}break;
		case 2:
		{
			main();
		}
		default:
			cout << "\t\t\tWrong choise, try again!" << endl;
			goto x1;
	}	
	


}