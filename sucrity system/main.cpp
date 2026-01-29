#include "LoginCheck.hpp"
#include "Info.hpp"
#include "Administrator.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void showINFO(int ID[], string Name[], double Salary[], string dept[], int AI);
int main()
{   
    int activeIndex = -1;
   



    ifstream fin("Data.txt");
    int size;
    fin >> size;
    int* ID = new int[size];
    string* PASS = new string[size];
    string* Name = new string[size];
    double* Salary = new double[size];
    string* dept = new string[size];
    
    for(int i=0;i<size;i++)
    {
        fin >> ID[i] >> PASS[i] >> Name[i] >> dept[i] >> Salary[i];
    }

    bool runMain = true;



    while(runMain)
    {  
        bool foundID = false;
        bool foundPASS = false;
        bool runMid = false;
        bool isAdmin = false;
        bool runAdmin = false;

        intro();


        LoginSystemID(ID, size, activeIndex, foundID);


        if(foundID)
        {
            LoginSystemPASS(PASS, Name , activeIndex, foundPASS, isAdmin);
        }

        if(foundID && foundPASS)
        {
            system("clear||cls");
            if(isAdmin)
            {
                cout << "Welcome Admin!" << endl;
                runAdmin = true;    
            }
            else
            {
                cout << "Login Successful! Welcome " << Name[activeIndex] << "." << endl;
                runMid = true;
            }
            
           
        }
        


        while(runMid)
        {
           cout << endl << "===========================" << endl;
           cout << "1. Show Info" << endl;
           cout << "2. Logout" << endl;
              int choice;
                cout << "Enter your choice: ";
                cin >> choice;
                system("clear||cls");
                switch(choice)
                {
                    case 1:
                        showINFO(ID, Name, Salary, dept, activeIndex);
                        break;
                    case 2:
                        cout << "Logging out..." << endl;
                        runMid = false;
                        break;
                    default:
                        cout << "Invalid choice! Please try again." << endl;
            

                }
                
        }
        while (runAdmin)
        {   
            cout << endl << "===========================" << endl;
            cout << "Administrator Menu:" << endl;
            cout << "1. Add User" << endl;
            cout << "2. Update Salary" << endl;
            cout << "3. Update Department" << endl;
            cout << "4. Total Expense" << endl;
            cout << "5. List All Users" << endl;
            cout << "6. Search User" << endl;
            cout << "7. Bonus Eligible" << endl;
            cout << "8. Save Changes" << endl;
            cout << "9. Logout" << endl;
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;
            system("clear||cls");
            switch(choice)
            {
                case 1:
                    IncCapacity(ID, PASS, Name, Salary, dept, size);
                    break;
                case 2:
                    updateSalary(ID, Salary, size);
                    break;
                case 3:
                    updateDepartment(ID, dept, size);
                    break;
                case 4:
                    totalExpense(Salary, size);
                    break;
                case 5:
                    listAllUsers(ID, Name, Salary, dept, size);
                    break;
                case 6:
                    searchUser(ID, Name, Salary, dept, size);
                    break;
                case 7:
                    BonusEligible(ID, Name, Salary, dept, size);
                    break;
                case 8:
                    save(ID, PASS, Name, Salary, dept, size);
                    cout << "Changes saved successfully." << endl;
                    break;
                case 9:
                    cout << "Logging out..." << endl;
                    runAdmin = false;
                    break;
                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
        }
    
    } 
   fin.close();
    delete[] ID;
    delete[] Name;
    delete[] Salary;
    delete[] dept;

    return 0;

}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

