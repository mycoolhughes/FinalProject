/*
Michael Hughes
CIS 1202 101
05/05/2022
Cinco de Mayo fever livin la vida loca
*/

#include "Employee_C.h"
#include<fstream>
#include<vector>

void Find_Employees(Employee_C employees[], fstream& binFile, string fileName, int &numEmployees);
void Extract_ID(Employee_C employees[], fstream& binFile, string fileName, int &numEmployees);
void Fill_Array(Employee_C employees[], int &numEmployees);

int main()
{
	fstream binFile;
	string fileName;
	int numEmployees = 0;

	cout << "\nHello my friend, you are now dead... Follow the light, he will show you where to go..." << endl << endl;

	cout << "\nEnter a name for the file: ";
	cin >> fileName;

	Employee_C employees[100];
	Fill_Array(employees, numEmployees);
	Extract_ID(employees, binFile, fileName, numEmployees);

	bool again = true;
	while (again)
	{
		Find_Employees(employees, binFile, fileName, numEmployees);

		cout << "\nEnter 1 to search another employee else enter 0: ";
		cin >> again;
	}
	
}

void Find_Employees(Employee_C employees[], fstream& binFile, string fileName,  int& numEmployees)
{
	int id;

	cout << "\nEnter ID of employee to search: ";
	cin >> id;

	int index = -1;
	bool found = false;
	for (int i = 0; i < numEmployees && !found; i++)
	{
		if (id == employees[i].Get_ID())
		{
			found = true;
			index = i;
		}
	}
	
	if (index == -1)
	{
		cout << "\nEmployee not found...";
	}
	else
	{
		cout << "\nEmployee found: ";
		cout << "\nName: " << employees[index].Get_Name();
		cout << "\nID: " << employees[index].Get_ID();
		cout << "\nSalary: $" << employees[index].Get_Salary();
		cout << "\nGender: " << employees[index].Get_Gender();
	}

}

void Extract_ID(Employee_C employees[], fstream& binFile, string fileName, int &numEmployees)
{
	int ids[100];

	for (int i = 0; i < numEmployees; i++)
	{
		ids[i] = employees[i].Get_ID();
	}

	binFile.open(fileName, ios::out | ios::binary);

	for (int i = 0; i < numEmployees; i++)
	{
		binFile.write(reinterpret_cast<char*>(&ids), sizeof(ids));
	}

	binFile.close();
}

void Fill_Array(Employee_C employees[], int &numEmployees)
{
	string name;
	int id;
	double salary;
	char gender;
	cout << "\nEnter employee data up to 100 employees" << endl;
	cin.ignore();
	cin.clear();

	bool again = true;
	for (int i = 0; i < 100 && again; i++)
	{
		cout << "\nEnter employee name: ";
		getline(cin, name);

		cout << "\nEnter employee id: ";
		cin >> id;

		cout << "\nEnter employee salary: ";
		cin >> salary;

		cout << "\nEnter employee gender (M or F): ";
		cin >> gender;

		employees[i].Set_Name(name);
		employees[i].Set_ID(id);
		employees[i].Set_Salary(salary);
		employees[i].Set_Gender(gender);

		cout << "\nEnter 1 to go again else enter 0: ";
		cin >> again;

		numEmployees++;
		cin.ignore();
		cin.clear();
	}
}