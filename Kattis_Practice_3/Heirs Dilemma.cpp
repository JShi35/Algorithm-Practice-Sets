#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int num1;
    int num2;
    cin >> num1 >> num2;

    int counter = num1;
    int acc = 0;

    while (counter <= num2) {
        string counter_s = to_string(counter);

        set<char> digits;
        bool divble = true;

        for (char d : counter_s) {

            if (d == '0' || digits.count(d)) {
                divble = false; 
                break;
            }


            digits.insert(d);
        }

        if (divble) {

            for (char d : counter_s) {
                
                if (counter % (d-'0') != 0) {
                    divble = false; 
                    break;
                }


            }

        }

            if (divble) {
            acc++;
        }

        counter++; 
    }

    cout << acc << endl;

    return 0;
}
