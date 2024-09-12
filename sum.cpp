#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string sumUp(string num1, string num2){
    int carry = 0;
    string result;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    if (num1.size()<num2.size())
    {
        swap(num1, num2);
    }
    
    for (size_t i = 0; i < num2.size(); i++)
    {
        int digit = num1[i] - '0' + num2[i] - '0' + carry;

        carry = digit/10;
        digit = digit%10;
        
        result.push_back(digit);
    }
    
}

int main(){
    int x;
    int y;
    cout<<"first num:"<<endl;
    cin>>x;
    cout<<"second:"<<endl;
    cin>>y;
    
    int z = x+y;
    cout<<z<<endl;
}