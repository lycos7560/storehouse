#include <iostream>
#include <list>

using namespace std;

list <pair<int, int>> tempList;
list <pair<int, int>>::iterator it;

pair<int, int> temp;

int main()
{
   bool check = true;
   while (!cin.eof()) {
       if (check) { 
           cin >> temp.first; 
           check = !check;
       }
       else {
           cin >> temp.second;
           check = !check;
           tempList.push_back(temp);
       }
   }

   for (it = tempList.begin(); it != tempList.end(); it++)
       cout << it->first + it->second << "\n";

   return 0;
}