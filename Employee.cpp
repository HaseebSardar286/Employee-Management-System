#include"Employee.h"


Employee::Employee()							// Default Constructor
{
	EmployeeID = '\0';
	EmployeeName = '\0';
	EmployeeAge = 0;
	EmployeePhoneNo = '\0';
	EmployeeAddress = '\0';
	EmployeeDepartment = '\0';
	EmployeeSalary = 0;
	EmployeeWorkingHours = 0;
}

Employee::Employee(string id, string name, int age, string phone, string address, string depart, long int salary, int workHours)   // Parameterized Constructor
{
	EmployeeID = id;
	EmployeeName = name;
	EmployeeAge = age;
	EmployeePhoneNo = phone;
	EmployeeAddress = address;
	EmployeeDepartment = depart;
	EmployeeSalary = salary;
	EmployeeWorkingHours = workHours;
}

Employee::Employee(const Employee& obj)		// Copy Constructor
{
	EmployeeID = obj.EmployeeID;
	EmployeeName = obj.EmployeeName;
	EmployeeAge = obj.EmployeeAge;
	EmployeePhoneNo = obj.EmployeePhoneNo;
	EmployeeAddress = obj.EmployeeAddress;
	EmployeeDepartment = obj.EmployeeDepartment;
	EmployeeSalary = obj.EmployeeSalary;
	EmployeeWorkingHours = obj.EmployeeWorkingHours;
}

// Setters

void Employee::setEmployeeID(string id)
{
	EmployeeID = id;
}

void Employee::setEmployeeName(string name)
{
	EmployeeName = name;
}

void Employee::setEmployeeAge(int age)
{
	EmployeeAge = age;
}

void Employee::setEmployeePhoneNo(string phone)
{
	EmployeePhoneNo = phone;
}

void Employee::setEmployeeAddress(string address)
{
	EmployeeAddress = address;
}

void Employee::setEmployeeDepartment(string department)
{
	EmployeeDepartment = department;
}

void Employee::setEmployeeSalary(long int salary)
{
	EmployeeSalary = salary;
}

void Employee::setEmployeeWorkingHours(int workHours)
{
	EmployeeWorkingHours = workHours;
}

// Getters

string Employee::getEmployeeID()
{
	return EmployeeID;
}

string Employee::getEmployeeName()
{
	return EmployeeName;
}

int Employee::getEmployeeAge()
{
	return EmployeeAge;
}

string Employee::getEmployeePhoneNo()
{
	return EmployeePhoneNo;
}

string Employee::getEmployeeAddress()
{
	return EmployeeAddress;
}

string Employee::getEmployeeDepartment()
{
	return EmployeeDepartment;
}

long int Employee::getEmployeeSalary()
{
	return EmployeeSalary;
}

int Employee::getEmployeeWorkingHours()
{
	return EmployeeWorkingHours;
}

// Member Functions (As Required)

void Employee::displayEmployee()
{
	cout << "\n-----------------------------------------------------------------------------------\n";

	cout << "\nID: " << EmployeeID;
	cout << "\nName: " << EmployeeName;
	cout << "\nAge: " << EmployeeAge;
	cout << "\nPhone Number: " << EmployeePhoneNo;
	cout << "\nAddress: " << EmployeeAddress;
	cout << "\nDepartment: " << EmployeeDepartment;
	cout << "\nSalary: " << EmployeeSalary;
	cout << "\nSalary after Tax Deduction: " << EmployeeSalary - calculateTax();
	cout << "\nWorking Hours in a Day: " << EmployeeWorkingHours;

	cout << "\n\n-----------------------------------------------------------------------------------\n\n";
}

long int Employee::calculateTax()
{
	long int tax;

	if (EmployeeSalary * 12 > 600000 && EmployeeSalary * 12 <= 1200000)
	{
		tax = 0;
	}

	else if (EmployeeSalary * 12 > 1200000 && EmployeeSalary * 12 <= 2400000)
	{
		tax = 15000 / 12;
	}

	else if (EmployeeSalary * 12 > 2400000 && EmployeeSalary * 12 <= 3600000)
	{
		tax = 165000 / 12;
	}

	else if (EmployeeSalary * 12 > 3600000 && EmployeeSalary * 12 <= 6000000)
	{
		tax = 405000 / 12;
	}

	else if (EmployeeSalary * 12 > 6000000 && EmployeeSalary * 12 <= 12000000)
	{
		tax = 1005000 / 12;
	}

	else if (EmployeeSalary * 12 > 12000000)
	{
		tax = 2955000 / 12;
	}

	else
	{
		tax = 0;
	}

	return tax;
}