#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector> 
#include <cstring>
#include <unordered_map>

using namespace std;

int main(){
    vector<vector<string>> patterns = {
    {"***", "* *", "* *", "* *", "***"},  // 0
    {"  *", "  *", "  *", "  *", "  *"},  // 1
    {"***", "  *", "***", "*  ", "***"},  // 2
    {"***", "  *", "***", "  *", "***"},  // 3
    {"* *", "* *", "***", "  *", "  *"},  // 4
    {"***", "*  ", "***", "  *", "***"},  // 5
    {"***", "*  ", "***", "* *", "***"},  // 6
    {"***", "  *", "  *", "  *", "  *"},  // 7
    {"***", "* *", "***", "* *", "***"},  // 8
    {"***", "* *", "***", "  *", "***"}   // 9
    };

    vector<string> ascii(5);
   
    for (size_t i = 0; i < ascii.size(); i++)
    {
        getline(cin, ascii[i]);
    }
    int nums_digits = (ascii[0].size()+1)/4;

    for (size_t i = 0; i < nums_digits; i++)
    {
        vector<string> each_ascii(5);

        for (size_t j = 0; j < ascii.size(); j++)
        {
            each_ascii.push_back(ascii[j].substr(i*4, 3));
        }
        
    }
    
}