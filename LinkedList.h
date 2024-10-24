#pragma once
#include"Employee.h";

class Node
{
private:
	Employee data;
	Node* next;
	Node* prev;

public:
	Node();

	Node(const Employee& emp);

	Node(const Node& obj);

	// Setters

	void setData(const Employee& emp);

	void setNext(Node* ptr);

	void setPrev(Node* ptr);

	// Getters

	Employee getData();

	Node* getNext();

	Node* getPrev();

	Employee* getDataAddress();

	// Member Functions (As Needed)

	void displayNode();
};

class LinkedList
{
public:
	Node* head;
	Node* tail;

	LinkedList();

	// Member Functions (As Needed)
	void Insert(const Employee& obj);

	void displayAllEmployee();

	bool searchEmployee(string id);

	void removeEmployee(string id);

	void editEmployee(string id);

	Employee highestPaidEmployee();

	Employee eldestEmployee();

};