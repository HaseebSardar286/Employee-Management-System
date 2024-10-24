#include"Employee.h"
#include"LinkedList.h"
#include<fstream>

void UpdateCorpus(LinkedList Employees);

int main()
{
	LinkedList Employees;

	ifstream fin;

	fin.open("Corpus.txt");

	int iteration = 0;

	string EmployeeID = "\0";
	string EmployeeName = "\0";
	int EmployeeAge = 0;
	string EmployeePhoneNo = "\0";
	string EmployeeAddress = "\0";
	string EmployeeDepartment = "\0";
	long int EmployeeSalary = 0;
	int EmployeeWorkingHours = 0;

	while (!fin.eof())
	{
		if (iteration == 0)
		{
			getline(fin, EmployeeID);

		}

		if (iteration != 0)
		{
			fin >> ws;
			getline(fin, EmployeeID);
			fin >> ws;
			getline(fin, EmployeeName);
			fin >> EmployeeAge;
			fin >> ws;
			getline(fin, EmployeePhoneNo);
			fin >> ws;
			getline(fin, EmployeeAddress);
			fin >> ws;
			getline(fin, EmployeeDepartment);
			fin >> EmployeeSalary;
			fin >> EmployeeWorkingHours;

			Employee temp(EmployeeID, EmployeeName, EmployeeAge, EmployeePhoneNo, EmployeeAddress, EmployeeDepartment, EmployeeSalary, EmployeeWorkingHours);

			Employees.Insert(temp);
		}

		iteration++;
	}

	fin.close();

	system("cls");

	do
	{
		cout << "\n*****************                            **********************";
		cout << "\n*****************                            **********************";
		cout << "\n***************** Employee Management System **********************";
		cout << "\n*****************                            **********************";
		cout << "\n*****************                            **********************\n\n";

		cout << "MAIN MENU\n\n";

		int choice;

		cout << "Press 1 to Add an Employee\n";
		cout << "Press 2 to Delete an Employee\n";
		cout << "Press 3 to Search for an Employee\n";
		cout << "Press 4 to Edit an Employee's Attributes\n";
		cout << "Press 5 to Display all the Employees in the Corpus\n";
		cout << "Press 6 to Display the Highest Paid Employee\n";
		cout << "Press 7 to Display the Eldest Employee\n";
		cout << "\nPress -1 to EXIT the Employee Management System\n\n";

		cout << "Enter your choice: ";
		cin >> choice;


		if (choice == 1)
		{
			do
			{
				system("cls");

				cout << "\n\n******************** Adding an Employee ********************\n\n";

				cout << "Enter the ID of the Employee you want to ADD (CASE SENSITIVE): ";
				cin >> ws;
				getline(cin, EmployeeID);

				cout << "\nEnter the Name of the Employee you want to ADD (CASE SENSITIVE): ";
				cin >> ws;
				getline(cin, EmployeeName);

				cout << "\nEnter the Age of the Employee you want to ADD: ";
				cin >> EmployeeAge;

				cout << "\nEnter the Phone Number of the Employee you want to ADD: ";
				cin >> ws;
				getline(cin, EmployeePhoneNo);

				cout << "\nEnter the Address of the Employee you want to ADD (CASE SENSITIVE): ";
				cin >> ws;
				getline(cin, EmployeeAddress);

				cout << "\nEnter the Department of the Employee you want to ADD (CASE SENSITIVE): ";
				cin >> ws;
				getline(cin, EmployeeDepartment);

				cout << "\nEnter the Salary of the Employee you want to ADD: ";
				cin >> EmployeeSalary;

				cout << "\nEnter the Working Hours of the Employee you want to ADD: ";
				cin >> EmployeeWorkingHours;

				Employee temp(EmployeeID, EmployeeName, EmployeeAge, EmployeePhoneNo, EmployeeAddress, EmployeeDepartment, EmployeeSalary, EmployeeWorkingHours);

				Employees.Insert(temp);

				cout << "\n\nDo you want to ADD more Employees? (Y/N): ";
				char choice;
				cin >> choice;

				if (choice == 'y' || choice == 'Y')
				{
					continue;
				}

				else if (choice == 'n' || choice == 'N')
				{
					UpdateCorpus(Employees);
					break;
				}

			} while (true);
		}

		else if (choice == 2)
		{
			do
			{
				system("cls");

				cout << "\n\n******************** Deleting an Employee ********************\n\n";

				cout << "Enter the ID of the Employee you want to DELETE (CASE SENSITIVE): ";
				cin >> ws;
				getline(cin, EmployeeID);

				Employees.removeEmployee(EmployeeID);

				cout << "\n\nDo you want to DELETE more Employees? (Y/N): ";
				char choice;
				cin >> choice;

				if (choice == 'y' || choice == 'Y')
				{
					continue;
				}

				else if (choice == 'n' || choice == 'N')
				{
					UpdateCorpus(Employees);
					break;
				}

			} while (true);
		}

		else if (choice == 3)
		{
			do
			{
				system("cls");

				cout << "\n\n******************** Searching an Employee ********************\n\n";

				cout << "Enter the ID of the Employee you want to SEARCH (CASE SENSITIVE): ";
				cin >> ws;
				getline(cin, EmployeeID);

				if (Employees.searchEmployee(EmployeeID))
				{
					cout << "\n\nThe Employee with the ID (" << EmployeeID << ") EXISTS in the Corpus.\n\n";
				}

				else
				{
					cout << "\n\nThe Employee with the ID (" << EmployeeID << ") does NOT EXIST in the Corpus.\n\n";
				}

				cout << "\n\nDo you want to SEARCH more Employees? (Y/N): ";
				char choice;
				cin >> choice;

				if (choice == 'y' || choice == 'Y')
				{
					continue;
				}

				else if (choice == 'n' || choice == 'N')
				{
					break;
				}

			} while (true);
		}


		else if (choice == 4)
		{
			do
			{
				system("cls");

				cout << "\n\n******************** Editing an Employee ********************\n\n";

				cout << "Enter the ID of the Employee you want to Edit (CASE SENSITIVE): ";
				cin >> ws;
				getline(cin, EmployeeID);

				Employees.editEmployee(EmployeeID);

				cout << "\n\nDo you want to Edit more Employees? (Y/N): ";
				char choice;
				cin >> choice;

				if (choice == 'y' || choice == 'Y')
				{
					continue;
				}

				else if (choice == 'n' || choice == 'N')
				{
					UpdateCorpus(Employees);
					break;
				}

			} while (true);
		}

		else if (choice == 5)
		{
			system("cls");

			cout << "\n\n******************** Displaying All Employee ********************\n\n";

			Employees.displayAllEmployee();

			cout << endl << endl;
			system("pause");
		}

		else if (choice == 6)
		{
			system("cls");

			cout << "\n\n******************** Displaying Highest Paid Employee ********************\n\n";

			Employees.highestPaidEmployee().displayEmployee();

			cout << endl << endl;
			system("pause");
		}

		else if (choice == 7)
		{
			system("cls");

			cout << "\n\n******************** Displaying Eldest Employee ********************\n\n";

			Employees.eldestEmployee().displayEmployee();

			cout << endl << endl;
			system("pause");
		}

		else if (choice == -1)
		{
			system("cls");

			cout << "\n\n******************** THANK YOU FOR USING OUR EMPLOYEE MANAGEMENT SYSTEM ********************\n\n";

			system("pause");
			break;
		}


		else
		{
			cout << "\n\nINVALID INPUT. PLEASE TRY AGAIN.\n\n";
			system("pause");
			continue;
		}

		system("cls");

	} while (true);

	return 0;
}


void UpdateCorpus(LinkedList Employees)
{
	ofstream fout;
	string EmployeeID = "\0";
	string EmployeeName = "\0";
	int EmployeeAge = 0;
	string EmployeePhoneNo = "\0";
	string EmployeeAddress = "\0";
	string EmployeeDepartment = "\0";
	long int EmployeeSalary = 0;
	int EmployeeWorkingHours = 0;

	fout.open("Corpus.txt");

	for (Node* i = Employees.head; i != NULL; i = i->getNext())
	{
		EmployeeID = i->getData().getEmployeeID();
		EmployeeName = i->getData().getEmployeeName();
		EmployeeAge = i->getData().getEmployeeAge();
		EmployeePhoneNo = i->getData().getEmployeePhoneNo();
		EmployeeAddress = i->getData().getEmployeeAddress();
		EmployeeDepartment = i->getData().getEmployeeDepartment();
		EmployeeSalary = i->getData().getEmployeeSalary();
		EmployeeWorkingHours = i->getData().getEmployeeWorkingHours();


		fout << endl << EmployeeID << endl;
		fout << EmployeeName << endl;
		fout << EmployeeAge << endl;
		fout << EmployeePhoneNo << endl;
		fout << EmployeeAddress << endl;
		fout << EmployeeDepartment << endl;
		fout << EmployeeSalary << endl;
		fout << EmployeeWorkingHours;
	}

	fout.close();
}