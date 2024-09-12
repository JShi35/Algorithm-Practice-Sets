#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool isAnagram(string s, string t) {
    vector<int> holder(26, 0);
    for(char c: s){
        holder[c-97] += 1;
    }
    for(char c: t){
        holder[c-97] -= 1;
    }
    for(int i: holder){
        if (i == 0)
        {
            continue;
        }else{
            return false;
        }
        
    }
    return true;

}