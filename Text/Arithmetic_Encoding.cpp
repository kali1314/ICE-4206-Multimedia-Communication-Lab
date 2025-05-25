#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    map<char, double> prob;

    // Taking probability input from user
    cout << "Enter character and its probability (separated by space):\n";
    for (int i = 0; i < n; ++i) {
        char ch;
        double p;
        cin >> ch >> p;
        prob[ch] = p;
    }

    // Cumulative Probability Table
    map<char, double> low, high;
    double cumulative = 0.0;
    for (auto p : prob) {
        low[p.first] = cumulative;
        high[p.first] = cumulative + p.second;
        cumulative = high[p.first];
    }

    // Message Input
    string message;
    cout << "Enter message (using given characters): ";
    cin >> message;

    // Initial Range
    double range_low = 0.0, range_high = 1.0;

    // Encoding Process
    for (char c : message) {
        double range = range_high - range_low;
        range_high = range_low + range * high[c];
        range_low  = range_low + range * low[c];
    }


    cout << fixed << setprecision(8);
    cout << "Final Range: [" << range_low << ", " << range_high << ")" << endl;

    return 0;
}
