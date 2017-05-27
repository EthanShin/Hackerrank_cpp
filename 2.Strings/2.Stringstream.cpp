#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    vector<int> integers;
    char ch;
    int i;
    stringstream ss(str);
    
    while(!ss.eof()) {
        ss >> i >> ch;
        integers.push_back(i);
    }
    return integers;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}