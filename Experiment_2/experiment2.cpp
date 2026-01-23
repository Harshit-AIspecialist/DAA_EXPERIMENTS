#include <iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
struct node{
    char ch;
    int freq;
    node* left;
    node* right;
    node(char c,int freq){
        ch = c;
        this->freq = freq;
        left = nullptr;
        right = nullptr;
    }
};
struct compare {
    bool operator()(node* a, node* b) {
        return a->freq > b->freq;
    }
};


void gencode(node* root, string code, unordered_map<char, string>& huffmancode){
    if(!root) return;
    if(!root->left && !root->right){
        huffmancode[root->ch] = code;
    }
        gencode(root->left,code + "0",huffmancode);
        gencode(root->right,code + "1",huffmancode);
}
string decoded(node* root,string encoded){
    string decoded = "";
    node* cur = root;
    for(char bit: encoded){
        if(bit == '0'){
            cur = cur->left;
        }
        else{
            cur = cur->right;
        }
        if(!cur->left && !cur->right){
            decoded += cur->ch;
            cur = root;
            
        }
    }
    return decoded;
}
int main()
{
   string text;
    cout << "enter input string: ";
    getline(cin, text);
    unordered_map<char, int> freq;
    for (char ch : text)
        freq[ch]++;

    priority_queue<node*, vector<node*>, compare> pq;
    for (auto pair : freq)
        pq.push(new node(pair.first, pair.second));

    while (pq.size() > 1) {
        node* left = pq.top(); pq.pop();
        node* right = pq.top(); pq.pop();

        node* parent = new node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    node* root = pq.top();
    unordered_map<char, string> huffmancode;
    gencode(root, "", huffmancode);

    cout << "huffman codes:\n";
    for (auto pair : huffmancode)
        cout << pair.first << " : " << pair.second << endl;

    
    string encoded = "";
    for (char ch : text)
        encoded += huffmancode[ch];

    cout << "encoded string:" <<encoded<< endl;
    string decode = decoded(root,encoded);
    cout<< decode;
    return 0;
}
