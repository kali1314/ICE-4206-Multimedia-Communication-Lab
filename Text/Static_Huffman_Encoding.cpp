#include<bits/stdc++.h>
using namespace std;

// Huffman Tree Node Structure
struct Node {
    char character;
    int frequency;
    Node *left, *right;

    Node(char c, int f) : character(c), frequency(f), left(nullptr), right(nullptr) {}
};

// Compare class for priority queue (Min-Heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

// Function to print Huffman Codes from the tree
void printCodes(Node* root, string code) {
    if (!root) return;

    // If this is a leaf node, print the character and its code
    if (root->character != '#') {
        cout << root->character << " : " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Taking character and frequency input
    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cout << "Enter character and its frequency (separated by space): ";
        cin >> ch >> freq;
        pq.push(new Node(ch, freq));
    }

    // Building Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with combined frequency
        Node* merged = new Node('#', left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    // Printing Huffman Codes
    cout << "\nHuffman Codes:\n";
    printCodes(pq.top(), "");

    return 0;
}
