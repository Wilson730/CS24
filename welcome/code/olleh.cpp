#include <string>
#include <iostream>

using namespace std;

int main ()
{
  int i=0;
  string str;
  string finalString = "";
  string temp = "";
  
  cout << "Input: ";
  getline(cin, str);
  
  while (str[i])
  {
    temp += str[i];
    if (ispunct(str[i]) || isspace(str[i]) || i == str.size() -1 )
    {
        for(int f = temp.size() - 1; f >= 0; f--)                      
        {                                          
            if (temp[f] != str[i])
            {
            finalString += temp[f];
            }
        }    
        finalString += str[i];
    temp = "";
    }
    i++;
  }
  cout << finalString;
  return 0;
}