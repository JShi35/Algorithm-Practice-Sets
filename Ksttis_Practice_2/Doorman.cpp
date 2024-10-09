#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(){
    int diff;
    string line;

    cin >> diff;
    cin.ignore();
    getline(cin, line);

    int i = 0;
    int counter = 0;
    char Next_Gender;
    
    while (i < line.size()) {
        if(abs(counter) < diff) {
            if (line[i] == 'W') {
                counter--;
                i++;
            } else if (line[i] == 'M') {
                counter++;
                i++;
            }
        } else {
            if (counter>0)
            {
                Next_Gender = 'W';
            }else if (counter<0)
            {
                Next_Gender = 'M';
            }
            
            

            if (line[i] == Next_Gender) {
                if (line[i] == 'W') {
                    counter--;
                } else if (line[i] == 'M') {
                    counter++;
                }
                i++;
            }
            
            else if (i + 1 < line.size() && line[i + 1] == Next_Gender) {
                swap(line[i], line[i + 1]);
                if (line[i] == 'W') {
                    counter--;
                } else if (line[i] == 'M') {
                    counter++;
                }
                i++;
            } else {
            
                break;
            }
        }
    }

    cout << i << endl;

    return 0;
}
