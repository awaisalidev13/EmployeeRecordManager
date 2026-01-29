#include "LoginCheck.hpp"
#include <iostream>
using namespace std;


void LoginSystemID(int ID[], int size, int & AI, bool & FOUND)
{
    int checkID;
    bool found = false;
   
    int activeIndex = -1;

    while(!found )
    {
        cout << "Enter your ID : ";
        cin >> checkID;

        
        for(int i = 0; i < size; i++)
        {
            if(ID[i] == checkID || checkID == 9999)
            {
                found = true;
                activeIndex = i;
                break;
            }
        }

        if(found)
        {
            
            AI  = activeIndex;
            FOUND = true;
        }
        else
        {
            cout << "ID not found! Please try again." << endl;
        }
    }

    
}


void LoginSystemPASS(string PASS[],string name[], int & AI, bool & FOUND, bool & AD)
{
    string checkPASS;
    bool found = false;
    int attemps = 0;

    while(!found && attemps < 3)
    {
        cout << "Enter your Password : ";
        cin >> checkPASS;
        attemps++;

        if(checkPASS == "admin123")
        {
            cout << "Admin Login Successful!" << endl;
            AD = true;
            found = true;
            FOUND = true;
            break;
        } 
        else if(PASS[AI] == checkPASS)
        {
            found = true;
            FOUND = true;
            cout << "Login Successful! Welcome, " << name[AI] << "." << endl;
        }
        else
        {
            cout << "Incorrect Password! Please try again." << endl;
        }


    }

       
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

