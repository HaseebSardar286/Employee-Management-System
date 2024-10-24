#include"LinkedList.h"


// *****************************************************************       NODE      *****************************************************************


Node::Node()
{
	next = NULL;
	prev = NULL;
}

Node::Node(const Employee& emp)
{
	data = emp;
	next = NULL;
	prev = NULL;
}

Node::Node(const Node& obj)
{
	data = obj.data;
	next = NULL;
	prev = NULL;
}

// Setters

void Node::setData(const Employee& emp)
{
	data = emp;
}

void Node::setNext(Node* ptr)
{
	next = ptr;
}

void Node::setPrev(Node* ptr)
{
	prev = ptr;
}

// Getters

Employee Node::getData()
{
	return data;
}

Node* Node::getNext()
{
	return next;
}

Node* Node::getPrev()
{
	return prev;
}

Employee* Node::getDataAddress()
{
	return &data;
}

// Member Functions (As Needed)

void Node::displayNode()
{
	data.displayEmployee();
}


// *****************************************************************   LINKED LIST   *****************************************************************


LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
}

void LinkedList::Insert(const Employee& obj)
{
	Node* temp = new Node(obj);

	if (head == NULL && tail == NULL)
	{
		head = temp;
		tail = temp;
	}

	else
	{
		tail->setNext(temp);
		temp->setPrev(tail);
		tail = temp;
	}
}

void LinkedList::displayAllEmployee()
{
	for (Node* i = head; i != NULL; i = i->getNext())
	{
		i->displayNode();
	}
}

bool LinkedList::searchEmployee(string id)
{
	for (Node* i = head; i != NULL; i = i->getNext())
	{
		if (i->getData().getEmployeeID() == id)
		{
			return true;
		}
	}

	return false;
}

void LinkedList::removeEmployee(string id)
{
	for (Node* i = head; i != NULL; i = i->getNext())
	{
		if (i->getData().getEmployeeID() == id)
		{
			Node* temp = i;

			if (i->getNext() != NULL && i->getPrev() != NULL)
			{
				i->getPrev()->setNext(i->getNext());
				i->getNext()->setPrev(i->getPrev());
			}

			else if (i->getPrev() == NULL)
			{
				i->getNext()->setPrev(NULL);
			}

			else if (i->getNext() == NULL)
			{
				i->getPrev()->setNext(NULL);
			}

			delete temp;
			temp = NULL;

			break;
		}
	}
}

void LinkedList::editEmployee(string id)
{
	if (searchEmployee(id))
	{
		for (Node* i = head; i != NULL; i = i->getNext())
		{
			if (i->getData().getEmployeeID() == id)
			{
				int choice;

				do
				{
					system("cls");

					cout << "\nWhat attribute do you want to edit for " << i->getData().getEmployeeName() << "?\n\n";

					cout << "Press 1 to edit the ID\n";
					cout << "Press 2 to edit the Name\n";
					cout << "Press 3 to edit the Age\n";
					cout << "Press 4 to edit the Phone Number\n";
					cout << "Press 5 to edit the Address\n";
					cout << "Press 5 to edit the Department\n";
					cout << "Press 6 to edit the Salary\n";
					cout << "Press 7 to edit the Working Hours\n";

					cout << "\nPress -1 to STOP editing\n\n";


					cout << "Please Choose from the above and Press Enter: ";
					cin >> choice;

					if (choice == 1)
					{
						system("cls");

						Employee* temp = i->getDataAddress();

						string newID;
						cout << "Enter the new ID: ";
						cin >> newID;

						temp->setEmployeeID(newID);

						cout << "\n\nThe EmployeeID has been Successfully edited.\n\n";

						system("pause");
					}

					else if (choice == 2)
					{
						system("cls");

						Employee* temp = i->getDataAddress();

						string newName;
						cout << "Enter the new Name: ";
						cin >> newName;

						temp->setEmployeeName(newName);

						cout << "\n\nThe EmployeeName has been Successfully edited.\n\n";

						system("pause");
					}

					else if (choice == 3)
					{
						system("cls");

						Employee* temp = i->getDataAddress();


						int newAge;
						cout << "Enter the new Age: ";
						cin >> newAge;

						temp->setEmployeeAge(newAge);

						cout << "\n\nThe EmployeeAge has been Successfully edited.\n\n";

						system("pause");
					}

					else if (choice == 4)
					{
						system("cls");

						Employee* temp = i->getDataAddress();

						string newPhone;
						cout << "Enter the new Phone Number: ";
						cin >> newPhone;

						temp->setEmployeePhoneNo(newPhone);

						cout << "\n\nThe EmployeePhoneNo has been Successfully edited.\n\n";

						system("pause");
					}

					else if (choice == 5)
					{
						system("cls");

						Employee* temp = i->getDataAddress();

						string newAddress;
						cout << "Enter the new Address: ";
						cin >> newAddress;

						temp->setEmployeeAddress(newAddress);

						cout << "\n\nThe EmployeeAddress has been Successfully edited.\n\n";

						system("pause");
					}

					else if (choice == 6)
					{
						system("cls");

						Employee* temp = i->getDataAddress();

						string newDepartment;
						cout << "Enter the new Department: ";
						cin >> newDepartment;

						temp->setEmployeeDepartment(newDepartment);

						cout << "\n\nThe EmployeeDepartment has been Successfully edited.\n\n";

						system("pause");
					}

					else if (choice == 7)
					{
						system("cls");

						Employee* temp = i->getDataAddress();

						long int newSalary;
						cout << "Enter the new Salary: ";
						cin >> newSalary;

						temp->setEmployeeSalary(newSalary);

						cout << "\n\nThe EmployeeSalary has been Successfully edited.\n\n";

						system("pause");
					}

					else if (choice == 8)
					{
						system("cls");

						Employee* temp = i->getDataAddress();

						int newWorkingHours;
						cout << "Enter the new Working Hours: ";
						cin >> newWorkingHours;

						temp->setEmployeeWorkingHours(newWorkingHours);

						cout << "\n\nThe EmployeeWorkingHours have been Successfully edited.\n\n";

						system("pause");
					}

					else if (choice == -1)
					{
						system("cls");

						cout << "All of the Edited changes have been saved\n\n";

						system("pause");

						break;
					}

					else
					{
						cout << "\n\n INVALID ENTRY!!! Please Try Again\n\n";
						continue;
					}

				} while (true);
			}
		}
	}

	else
	{
		cout << "\n\nThe Employee with the ID (" << id << ") does not exist.\n\n";

		system("pause");
	}
}

Employee LinkedList::highestPaidEmployee()
{
	Employee highestPaid;

	for (Node* i = head; i != NULL; i = i->getNext())
	{
		if (i->getData().getEmployeeSalary() > highestPaid.getEmployeeSalary())
		{
			highestPaid = i->getData();
		}
	}

	return highestPaid;
}

Employee LinkedList::eldestEmployee()
{
	Employee eldest;

	for (Node* i = head; i != NULL; i = i->getNext())
	{
		if (i->getData().getEmployeeAge() > eldest.getEmployeeAge())
		{
			eldest = i->getData();
		}
	}

	return eldest;
}