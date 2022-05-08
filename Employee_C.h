#ifndef Employee_C_
#define Employee_C_

#include<iostream>
#include<string>

using namespace std;

class Employee_C
{
private:
	string fullName;
	int IDNumber;
	double salary;
	char gender;

	static double totalSalaries;
public:
	Employee_C();
	Employee_C(string, int, double, char);

	void Set_Name(string);
	void Set_ID(int);
	void Set_Salary(double);
	void Set_Gender(char);

	string Get_Name() const;
	int Get_ID() const;
	double Get_Salary() const;
	char Get_Gender() const;
};
#endif Employee_C_