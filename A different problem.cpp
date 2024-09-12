#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector> 

using namespace std;

int main(){
    long long int num1;
    long long int num2;
    while(cin>>num1>>num2){
        long long int num3 = abs(num2-num1);
        cout<<num3<<endl;
    }

    
    
    return 0;

}