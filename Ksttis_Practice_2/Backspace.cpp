#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stack>

using namespace std;

int main(){

string input;
getline(cin, input);
stack<char> holder;
string output = "";

for (char c: input)
{

    if (c == '<')
    {
        holder.pop();
    }else{
        holder.push(c);
    }
}

while (!holder.empty())
{
    output += holder.top();
    holder.pop();
}
reverse(output.begin(), output.end());
cout<<output<<endl;
return 0;

}