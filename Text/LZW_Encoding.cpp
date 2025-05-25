#include<bits/stdc++.h>
using namespace std;

int main() {
    string input;
    cout << "Enter the input string: ";
    cin >> input;

    // Initialize dictionary with single characters
    map<string, int> dictionary;
    int dict_size = 0;

    for (char c : input) {
        string s(1, c);
        if (dictionary.find(s) == dictionary.end()) {
            dictionary[s] = dict_size++;
        }
    }

    string current = "";
    vector<int> encoded;

    for (char c : input) {
        string next = current + c;
        if (dictionary.find(next) != dictionary.end()) {
            current = next;
        } else {
            encoded.push_back(dictionary[current]);
            dictionary[next] = dict_size++;
            current = string(1, c);
        }
    }

    // Last remaining part
    if (!current.empty()) {
        encoded.push_back(dictionary[current]);
    }

    // Output encoded values
    cout << "\nEncoded Output: ";
    for (int code : encoded) {
        cout << code << " ";
    }
    cout << endl;

    // Show final dictionary
    cout << "\nFinal Dictionary:\n";
    for (auto p : dictionary) {
        cout << p.first << " : " << p.second << endl;
    }

    return 0;
}
