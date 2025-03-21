#include <iostream>
#include <string>
#include <vector>
using namespace std;


string minimizeDistinctPermutations(const string& s) {
    vector<int> freq(26, 0);


    for (char c : s) {
        freq[c - 'a']++;
    }


    int maxFreq = 0;
    char mostFrequentChar = s[0];
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mostFrequentChar = 'a' + i;
        }
    }
    string result = s;
    for (char& c : result) {
        if (c != mostFrequentChar) {
            c = mostFrequentChar;
            break;
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string result = minimizeDistinctPermutations(s);
        cout << result << endl;
    }
    return 0;
}
