#include <string>
#include <iostream>

using namespace std;

int main ()
{
  int i=0;
  string str;
  string finalString = "";
  string temp = "";
  
  cout << "";
  getline(cin, str);
  while (str[i])
  {
    if (ispunct(str[i]) || isspace(str[i]))
    {
        for(int f = temp.size() - 1; f >= 0 ; --f)                      
        {                                          
        finalString += temp[f];
        }                     
        finalString += str[i];                       
        temp = "";
    } else {
        temp += str[i];
    }
    
    i++;
  }
  
  cout << finalString;
  return 0;
}


