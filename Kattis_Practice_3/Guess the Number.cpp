#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {

    int low = 1;
    int high = 1000;
    int guess;

    string response;
    
    for (int i = 0; i < 10; ++i) {
        
        guess = (low + high) / 2;
        
        cout << guess <<endl;
        
        cout.clear();
        
        cin >> response;

        if (response == "lower") {
            high = guess - 1; 
        } else if (response == "higher") {
            low = guess + 1; 
        } else if (response == "correct") {
            break; 

        }

    }



    return 0;
}
