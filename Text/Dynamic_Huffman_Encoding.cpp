#include<bits/stdc++.h>
using namespace std;

// Function to insert or update character in frequency map
void updateFrequency(unordered_map<char, int>& freqMap, char c) {
    freqMap[c]++;
}

// Function to print current frequencies (simulate tree update)
void printFrequencies(const unordered_map<char, int>& freqMap) {
    cout << "Current Frequencies: \n";
    for (auto& p : freqMap) {
        cout << p.first << " : " << p.second << endl;
    }
    cout << "----------------------\n";
}

int main() {
    unordered_map<char, int> freqMap;
    string input;
    cout << "Enter text stream (no space): ";
    cin >> input;

    for (char c : input) {
        if (freqMap.find(c) == freqMap.end()) {
            cout << "New character found: " << c << " | Encoding NYT + Binary of char\n";
        } else {
            cout << "Existing character: " << c << " | Encoding using updated tree\n";
        }

        // Update frequency
        updateFrequency(freqMap, c);

        // Show current state (simulate tree update)
        printFrequencies(freqMap);
    }

    cout << "Final Frequency Table:\n";
    printFrequencies(freqMap);

    return 0;
}
