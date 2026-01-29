#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <string>


bool isAdmin(int AdminID, std::string adminPASS);
void adminMenu();
void IncCapacity(int*& ID, std::string*& PASS, std::string*& Name, double*& Salary, std::string*& dept, int & size);
void addUser(int* ID, std::string* PASS, std::string* Name, double* Salary, std::string* dept, int & size, int inc);
void removeUser(int* ID, std::string* PASS, std::string* Name, double* Salary, std::string* dept, int & size);
void updateSalary(int* ID, double* Salary, int size);
void updateDepartment(int* ID, std::string* dept, int size);
void totalExpense(double* Salary,int size);
void listAllUsers(int* ID, std::string* Name, double* Salary, std::string* dept, int size);
void searchUser(int* ID, std::string* Name, double* Salary, std::string* dept, int size);
void BonusEligible(int* ID, std::string* Name, double* Salary, std::string* dept, int size);
void save(int* ID, std::string* PASS, std::string* Name, double* Salary, std::string* dept, int size);


#endif


