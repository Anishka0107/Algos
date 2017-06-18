#include <bits/stdc++.h>
using namespace std;

void lookup (const string & pattern, vector<int> & lookup_table) {
    int j = 0, i = 1;
    lookup_table[0] = 0;
    while (i < pattern.length()) {
        if (pattern[i] == pattern[j]) {
            lookup_table[i] = j+1;
            j++;
            i++;
        }
        else {
            if (j > 0)
                j = lookup_table[j-1];
            else {
                lookup_table[i] = 0;      // j is 0, so value of lookup_table[0] is 0, hence assign 0
                i++;
            }
        }
    }
}

void KMP (const string & text, const string & pattern) {
    vector<int> lookup_table (pattern.length());
    lookup (pattern, lookup_table);
    int i = 0, j = 0;        // i iterates over the text, j iterates over the pattern
    while (i < text.length()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == pattern.length()) {
            cout << i - j << " ";    // pattern startes at index (i - pattern.length())
            j = lookup_table[j-1];
        }
        else if (i < text.length() && text[i] != pattern[j]) {
            if (j > 0)
                j = lookup_table[j-1];
            else
                i++;
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text : ";
    cin >> text;
    cout << "Enter the pattern : ";
    cin >> pattern;
    cout << "Pattern found at : ";
    KMP (text, pattern);
    return 0;
}
