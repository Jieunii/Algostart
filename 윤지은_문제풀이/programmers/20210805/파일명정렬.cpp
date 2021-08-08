#include <algorithm>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int numID(string str)
{
    int i;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            break;
    }
    return i;
}

bool NUMBER(string str1, string str2) { 
    int num1 = stoi(str1.substr( numID(str1) ));
    int num2 = stoi(str2.substr( numID(str2) ));
    return num1 < num2; 
}

bool HEAD(string str1, string str2) { 
    string s1 = str1.substr(0, numID(str1));
    string s2 = str2.substr(0, numID(str2));
    
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    
    return s1.compare(s2) < 0; 
}

vector<string> solution(vector<string> files)
{   
    stable_sort(files.begin(), files.end(), NUMBER);
    stable_sort(files.begin(), files.end(), HEAD);

    return files;
}