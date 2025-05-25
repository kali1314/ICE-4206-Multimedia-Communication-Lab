#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Node structure for Huffman tree
struct Node {
    char ch;
    Node* left;
    Node* right;
    Node(char c = '#') : ch(c), left(nullptr), right(nullptr) {}
};

// Insert code into the Huffman tree
void insertCode(Node* root, const string& code, char ch) {
    Node* current = root;
    for (char bit : code) {
        if (bit == '0') {
            if (!current->left) current->left = new Node();
            current = current->left;
        } else { // bit == '1'
            if (!current->right) current->right = new Node();
            current = current->right;
        }
    }
    current->ch = ch;  // leaf node
}

// Decode function
string decode(Node* root, const string& encoded) {
    string decoded = "";
    Node* current = root;

    for (char bit : encoded) {
        current = (bit == '0') ? current->left : current->right;
        if (!current->left && !current->right) {  // leaf node
            decoded += current->ch;
            current = root;
        }
    }
    return decoded;
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    Node* root = new Node();

    cout << "Enter character and its Huffman code (e.g. a 101):\n";
    for (int i = 0; i < n; ++i) {
        char ch;
        string code;
        cin >> ch >> code;
        insertCode(root, code, ch);
    }

    string encoded;
    cout << "Enter encoded bitstring: ";
    cin >> encoded;

    string decoded = decode(root, encoded);

    cout << "Decoded string: " << decoded << endl;

    // Calculate frequency of each character in decoded string
    unordered_map<char, int> freqMap;
    for (char c : decoded) {
        freqMap[c]++;
    }

    cout << "\nCharacter Frequencies:\n";
    for (auto& p : freqMap) {
        cout << p.first << " : " << p.second << endl;
    }

    return 0;
}
