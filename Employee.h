#pragma once
#include<iostream>
#include<string>

using namespace std;


class Employee
{
private:
	string EmployeeID;
	string EmployeeName;
	int EmployeeAge;
	string EmployeePhoneNo;
	string EmployeeAddress;
	string EmployeeDepartment;
	long int EmployeeSalary;
	int EmployeeWorkingHours;


public:
	Employee();							// Default Constructor
	Employee(string id, string name, int age, string phone, string address, string depart, long int salary, int workHours);   // Parameterized Constructor
	Employee(const Employee& obj);		// Copy Constructor

	// Setters

	void setEmployeeID(string id);

	void setEmployeeName(string name);

	void setEmployeeAge(int age);

	void setEmployeePhoneNo(string phone);

	void setEmployeeAddress(string address);

	void setEmployeeDepartment(string department);

	void setEmployeeSalary(long int salary);

	void setEmployeeWorkingHours(int workHours);

	// Getters

	string getEmployeeID();

	string getEmployeeName();

	int getEmployeeAge();

	string getEmployeePhoneNo();

	string getEmployeeAddress();

	string getEmployeeDepartment();

	long int getEmployeeSalary();

	int getEmployeeWorkingHours();

	// Member Functions (As Required)

	void displayEmployee();

	long int calculateTax();
};