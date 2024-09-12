#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector> 

using namespace std;

int main(){
   string x;

   string token;
   vector<string> tokens;
   char delimiter = '+';

   int sum = 0;
   int testcases;
   int counter=0;

   cin>>testcases;

   
   while (counter<testcases)
   {
    cin>>x;
    if (x == "P=NP")
   {
    cout<<"skipped"<<endl;
    counter++;
    continue;
   }

    stringstream ss(x);
    while (getline(ss, token, delimiter))
   {
    tokens.push_back(token);
   }
   for (size_t i = 0; i < tokens.size(); i++) {
    sum += stoi(tokens[i]);
}
   cout<<sum<<endl;
   token.clear();
   tokens.clear();
   sum = 0;
   counter++;

   }

   return 0;
}

