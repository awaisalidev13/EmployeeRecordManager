#include "Administrator.hpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool isAdmin(int AdminID, string adminPASS)
{
    const int ADMIN_ID = 9999;
    const string ADMIN_PASS = "admin123";

    return (AdminID == ADMIN_ID && adminPASS == ADMIN_PASS);
}


void IncCapacity(int*& ID, string*& PASS, string*& Name, double*& Salary, string*& dept, int & size)
{
    cout << "Enter Number of users you want to add : ";
    int added; 
    cin >> added;

    int* TempID = new int[size+added];
    string* TempPASS = new string[size+added];
    string* TempName = new string[size+added];
    double* TempSalary = new double[size+added];
    string* Tempdept = new string[size+added];
    
    for(int i=0 ; i < size; i++)
    {
        TempID[i]  = ID[i];
        TempPASS[i]= PASS[i];
        TempName[i]= Name[i];
        TempSalary[i] = Salary[i];
        Tempdept[i] = dept[i];
    }

    delete[] ID;
    delete[] PASS;
    delete[] Name;
    delete[] Salary;
    delete[] dept;

    ID = TempID;
    PASS = TempPASS;
    Name = TempName;
    Salary = TempSalary;
    dept = Tempdept;
   

    addUser(ID,PASS,Name,Salary,dept,size,added);
    size += added;

    
}

void addUser(int* ID, std::string* PASS, std::string* Name, double* Salary, std::string* dept, int & size, int inc )
{
    for(int i=size ; i<size+inc ; i++)
    {
        cout << "Enter ID of user " << i+1 << " : ";
        cin >> ID[i];
        cout << "Enter Password for user " << i+1 << " : ";
        cin >> PASS[i];
        cout << "Enter Name of user " << i+1 << " : ";
        cin >> Name[i];
        cout << "Enter Salary of user " << i+1 << " : ";
        cin >> Salary[i];
        cout << "Enter Department of user " << i+1 << " : ";
        cin >> dept[i];
    }
}


void updateSalary(int* ID, double* Salary, int size)
{
    cout << "Enter User ID : ";
    int tempID;
    cin >> tempID;
    int IDindex=-1;
    bool found = false;
    bool cont = true;

    while(cont && !found)
    {
        for(int i=0;i<size;i++)
        {
            if(tempID==ID[i])
            {
                IDindex = i;
                found = true;
                cont = false;
            }
        }
        if(found)
        {
            cout << "Current Salary: " << Salary[IDindex] << endl;
            cout << "Enter New Salary: ";
            cin >> Salary[IDindex];
            cout << "Salary Updated Successfully!" << endl;
        }
        else
        {
            cout << "ID not found! Please try again." << endl;
            cout << "Enter User ID : ";
            cin >> tempID;  
        }
        

    }
}


void updateDepartment(int* ID, std::string* dept, int size)
{
    cout << "Enter User ID : ";
    int tempID;
    cin >> tempID;
    int IDindex=-1;
    bool found = false;
    bool cont = true;

    while(cont && !found)
    {
        for(int i=0;i<size;i++)
        {
            if(tempID==ID[i])
            {
                IDindex = i;
                found = true;
                cont = false;
            }
        }
        if(found)
        {
            cout << "Current Department: " << dept[IDindex] << endl;
            cout << "Enter New Department: ";
            cin >> dept[IDindex];
            cout << "Department Updated Successfully!" << endl;
        }
        else
        {
            cout << "ID not found! Please try again." << endl;
            cout << "Enter User ID : ";
            cin >> tempID;  
        }
        

    }
}
void totalExpense(double* Salary,int size)
{
    double total = 0.0;
    for(int i=0;i<size;i++)
    {
        total += Salary[i];
    }
    cout << "Total Expense on Salaries: " << total << endl;
}

void listAllUsers(int* ID, std::string* Name, double* Salary, std::string* dept, int size)
{
    cout << "Listing All Users:" << endl;
    for(int i=0;i<size;i++)
    {
        cout << "ID: " << ID[i] << ", Name: " << Name[i] << ", Salary: " << Salary[i] << ", Department: " << dept[i] << endl;
    }
}

void searchUser(int* ID, std::string* Name, double* Salary, std::string* dept, int size)
{
    cout << "Enter User ID to search: ";
    int tempID;
    cin >> tempID;
    bool found = false;

    for(int i=0;i<size;i++)
    {
        if(ID[i] == tempID)
        {
            cout << "User Found:" << endl;
            cout << "ID: " << ID[i] << ", Name: " << Name[i] << ", Salary: " << Salary[i] << ", Department: " << dept[i] << endl;
            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "User with ID " << tempID << " not found." << endl;
    }
}

void BonusEligible(int* ID, std::string* Name, double* Salary, std::string* dept, int size)
{
    cout << "Users Eligible for Bonus (Salary > 5000):" << endl;
    for(int i=0;i<size;i++)
    {
        if(Salary[i] > 5000)
        {
            cout << "ID: " << ID[i] << ", Name: " << Name[i] << ", Salary: " << Salary[i] << ", Department: " << dept[i] << endl;
        }
    }
}

void save(int* ID, std::string* PASS, std::string* Name, double* Salary, std::string* dept, int size)
{
    ofstream fout("Data.txt",ios::trunc);
    fout << size << endl;
    for(int i=0;i<size;i++)
    {
        fout << ID[i] << " " << PASS[i] << " " << Name[i] << " " << dept[i] << " " << Salary[i] << endl;
    }
    fout.close();
    cout << "Data saved successfully to users.txt" << endl;
}