#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<string> vowel_sort(string& text) {
    int num_v = 0;
    int num_r = 0;
    int diff = 0;
    vector<string> output;
    multimap<pair<int, string>, string> holder;  // Using multimap with composite key

    string acc = "";

    // Loop through each character in the string
    for (char c : text) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            num_v++;
            acc += c;
        } else if (c == ' ') {
            // At a space, calculate the difference and store the accumulated word
            if (!acc.empty()) {  // Only process if we have a word
                diff = abs(num_v - num_r);
                holder.insert({{diff, acc}, acc});  // Composite key with diff and word
            }
            acc.clear();
            num_v = 0;
            num_r = 0;
        } else {
            if (c >= 'a' && c <= 'z') { // Count only letters as consonants
                num_r++;
            }
            acc += c;
        }
    }

    // Handle the last word (if no trailing space)
    if (!acc.empty()) {
        diff = abs(num_v - num_r);
        holder.insert({{diff, acc}, acc});
    }

    // Add all words from the multimap to the output vector
    for (const auto& pair : holder) {
        output.push_back(pair.second);  // Push each word into the output vector
    }

    return output;
}

int main(){
    string text = "banana banana banana";

    vector<string> as = vowel_sort(text);

    for (const string& s : as)
    {
        cout << s << " ";
    }
    return 0;
}
