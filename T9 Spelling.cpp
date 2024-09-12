#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector> 
#include <cstring>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<char, string> t9Map;
    t9Map['a'] = "2"; t9Map['b'] = "22"; t9Map['c'] = "222";
    t9Map['d'] = "3"; t9Map['e'] = "33"; t9Map['f'] = "333";
    t9Map['g'] = "4"; t9Map['h'] = "44"; t9Map['i'] = "444";
    t9Map['j'] = "5"; t9Map['k'] = "55"; t9Map['l'] = "555";
    t9Map['m'] = "6"; t9Map['n'] = "66"; t9Map['o'] = "666";
    t9Map['p'] = "7"; t9Map['q'] = "77"; t9Map['r'] = "777"; t9Map['s'] = "7777";
    t9Map['t'] = "8"; t9Map['u'] = "88"; t9Map['v'] = "888";
    t9Map['w'] = "9"; t9Map['x'] = "99"; t9Map['y'] = "999"; t9Map['z'] = "9999";
    t9Map[' '] = "0"; 
    
    string str;
    int num;
    int counter = 0;
    cin>>num;
    cin.ignore();
    cin.clear();
    for (size_t i = 0; i < num; i++)
    {
        getline(cin, str);
        string acc = "";
        string tmp = "";
        for (size_t j = 0; j < str.size(); j++)
        {
            

            if(tmp.find(t9Map[str[j]]) != string::npos || t9Map[str[j]].find(tmp) != string::npos){
                acc += " " + t9Map[str[j]];
                tmp = t9Map[str[j]];
            }else{
                acc += t9Map[str[j]];
                tmp = t9Map[str[j]];
            }
            
            
        }
        counter++;
        cout << "Case #" << counter << ":" << acc << endl;
        
    }
    
    return 0;
}