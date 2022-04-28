#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<string_view>
#include<regex>
#include<stdlib.h>
using namespace std;

// Email Vaildation Pattern
bool Emailcheck(string email)
{
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return regex_match(email, pattern);
}



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
	string name, id_no, course, address, email_id, timetable;
	long long int contact_no;
	
public:
	void menu();
	void insert();
	void display();
	void modify();
	void search();
	void deleted();

};
class Professors :public University {
private:
	string course;
	string office_hours;
};


int main()
{
	University u;
	Administration a;
	Professors p;
	system("color 0b");
	int choice;
	
		
		cout << "\t\t\t\t----->\tWelcome To Eclass System\t<-----" << endl;
		cout << "\t\t-----------------------------------------------------------------" << endl;
		cout << "\t\t|\t1: Login As a Student\t\t\t\t\t|" << endl;
		cout << "\t\t|\t2: Registration "<< endl;		
		cout << "\t\t|\t3: Exit\t\t\t\t\t\t\t|" << endl;
		cout << "\t\t-----------------------------------------------------------------" << endl;
		cout << "\t\t\tEnter Your Choice: ";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
		{
			string admin, password;
			cout << "\t\t\tUSERNAME: ";
			cin >> admin;
			cout << "\t\t\tPASSWORD: ";
			cin >> password;
			if (admin == "admin" && password == "admin")
			{
				cout << "\t\t-----------------------------------------------------------------" << endl;
              cout << "\t\t|\t1: Students' information\t\t\t\t|" << endl;//O'ktamjon, Abdusomad
              cout << "\t\t|\t2: Staff's information\t\t\t\t\t|" << endl;//Sirojiddin
              cout << "\t\t|\t3: Professors' information\t\t\t\t|" << endl;//Sirojiddin
              cout << "\t\t|\t0: Exit\t\t\t\t\t\t\t|" << endl;
              cout << "\t\t-----------------------------------------------------------------" << endl;
			}
			else
			{
				cout << "\t\t\t\t----->\tLOGIN ERROR!\t<-----" << endl;
				main();
			}
		}break;
		case 2:
		{
			
		}break;
			case 3:
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
	
	system("cls");
	cout << "\t\t\t\t----->\tEnter the Username and password\t<-----" << endl;
	cout << "\t\t|\tUSERNAME: ";
	cin >> luserid;
	cout << "\t\t|\tPASSWORD: ";
	cin >> lpw;
	
	ifstream input("data.txt");

	while (input >> luserid >> lpassword)
	{
		if (lid == luserid && lpw == lpassword)
		{
			count = 1;
			
		}
	}
	input.close();

	if (count = 1)
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
	reg << ruserid << " " << rpw << endl;
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
void Administration::menu()
{
menustart:
	int choice;
	char x;
	system("cls");
	cout << "\t\t\t-----------------------------" << endl;
	cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
	cout << "\t\t\t-----------------------------" << endl;
	cout << "\t\t\t 1. Enter New Record" << endl;
	cout << "\t\t\t 2. Display Record" << endl;
	cout << "\t\t\t 3. Modify Record" << endl;
	cout << "\t\t\t 4. Search Record" << endl;
	cout << "\t\t\t 5. Delete Record" << endl;
	cout << "\t\t\t 6. Exit\n"
		<< endl;

	cout << "\t\t\t............................" << endl;
	cout << "\t\t\tChoose Options:[1/2/3/4/5/6]" << endl;
	cout << "\t\t\t............................" << endl;
	cout << " Enter Your Choose: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		do
		{
			insert();
			cout << "\n\n\t\t\t Add Another Student Record (Y, N) : ";
			cin >> x;
		} while (x == 'y' || x == 'Y');
		break;
	case 2:
		display();
		break;
	case 3:
		modify();
		break;
	case 4:
		search();
		break;
	case 5:
		deleted();
		break;
	case 6:
		cout << "\n\t\t\t Program Is Exit";
		exit(0);
	default:
		cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
	}
	_getch();
	goto menustart;
}
