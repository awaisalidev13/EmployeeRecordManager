#ifndef LOGIN_CHECK_H
#define LOGIN_CHECK_H

#include <string>


void LoginSystemID(int ID[], int size, int & AI, bool & FOUND);
void LoginSystemPASS(std::string PASS[],std::string name[], int & AI, bool & FOUND , bool & AD);

#endif