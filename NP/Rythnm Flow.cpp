#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to calculate points based on time difference
int calculatePoints(int diff) {
    if (diff <= 15) return 7;
    else if (diff <= 23) return 6;
    else if (diff <= 43) return 4;
    else if (diff <= 102) return 2;
    else return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> expected(n);
    vector<int> actual(m);
    
    for (int i = 0; i < n; ++i) {
        cin >> expected[i];
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> actual[i];
    }
    
    int i = 0, j = 0, score = 0;
    
    // Two-pointer technique to match button presses
    while (i < n && j < m) {
        int diff = abs(expected[i] - actual[j]);
        int points = calculatePoints(diff);
        
        // If we get points, we move to the next pair
        if (points > 0) {
            score += points;
            ++i;
            ++j;
        } 
        // Move to the next expected press if actual press is behind
        else if (actual[j] < expected[i]) {
            ++j;
        }
        // Move to the next actual press if expected press is behind
        else {
            ++i;
        }
    }
    
    cout << score << endl;
    
    return 0;
}
