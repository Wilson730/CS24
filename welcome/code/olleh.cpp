#include <string>
#include <iostream>

using namespace std;

int main ()
{
  unsigned long i=0;
  string str;
  string finalString = "";
  string temp = "";
  
  cout << "";
  getline(cin, str);
  
  while (str[i])
  {
    temp += str[i];        
    if (ispunct(str[i]) || isspace(str[i]) || i == str.size() - 1 ) 
    {
        for(int f = temp.size() - 1; f >= 0; --f)                   
        {                                          
            if (!ispunct(temp[f]) && !isspace(temp[f]))   
            {
            finalString += temp[f];                                                
            }
        }    
    if ((ispunct(str[i])) || (isspace(str[i])))
    {
        finalString += str[i];  
    } 
    temp = "";                                                          
    }
    i++;
  }
  cout << finalString << "\n";
  return 0;
}

/* aibohporypapoigruoimedoleta
Q
/
	esaelP niatniaM	laicoS     ecnatsiD   
 (emiT, uoht tsetapicitna ym daerd stiolpxe.)
 tI tsoc $943.59, tub I thguob ti yawyna.
*/
