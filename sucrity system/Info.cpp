#include "Info.hpp"

using namespace std;

void intro()
{
    cout <<
    "**********************************" << endl;
    cout <<
    "*    Welcome to SecureSys v1.0   *" << endl;
    cout <<
    "**********************************" << endl;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void showINFO(int ID[], string Name[], double Salary[], string dept[], int AI)
{
    cout << "User Information:" << endl;
    cout << "ID: " << ID[AI] << endl;
    cout << "Name: " << Name[AI] << endl;
    cout << "Salary: " << Salary[AI] << endl;
    cout << "Department: " << dept[AI] << endl;
}

