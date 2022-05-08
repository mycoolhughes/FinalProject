#include "Employee_C.h"

Employee_C::Employee_C()
{
	fullName = "";
	IDNumber = 0;
	salary = 0;
	gender = ' ';
}

Employee_C::Employee_C(string fName, int ID, double sal, char gen)
{
	fullName = fName;
	IDNumber = ID;
	salary = sal;
	gender = gen;
}

void Employee_C::Set_Name(string fName)
{
	fullName = fName;
}

void Employee_C::Set_ID(int ID)
{
	IDNumber = ID;
}

void Employee_C::Set_Salary(double sal)
{
	salary = sal;
}

void Employee_C::Set_Gender(char gen)
{
	gender = gen;
}

string Employee_C::Get_Name() const
{
	return fullName;
}

int Employee_C::Get_ID() const
{
	return IDNumber;
}

double Employee_C::Get_Salary() const
{
	return salary;
}

char Employee_C::Get_Gender() const
{
	return gender;
}