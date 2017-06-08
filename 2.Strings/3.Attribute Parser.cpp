#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	map<string, string> hrml;
	vector<string> tags;

	int N, Q;
	cin >> N >> Q;

	for (int i = 0; i < N; i++) {
		string s;
		getline(cin >> ws, s);
		stringstream ss(s);

		string tag, attribute, value;
		char ch;
		ss >> ch >> tag;

		if (tag[0] == '/') {
			tags.pop_back();
		}
		else {
			if (tag.back() == '>') {
				tag = tag.substr(0, tag.length() - 1);
			}
			tags.push_back(tag);

			while (!ss.eof()) {
				ss >> attribute >> ch >> ch >> value;

				if (value.back() == '>') {
					value = value.substr(0, value.length() - 2);
				}
				else {
					value = value.substr(0, value.length() - 1);
				}

				s = "";
				for (int j = 0; j < tags.size(); j++) {
					s += tags.at(j) + '.';
				}
				s = s.substr(0, s.length() - 1);
				s += '~' + attribute;

				hrml[s] = value;
			}
		}
	}

	for (int i = 0; i < Q; i++) {
		string s;
		cin >> s;

		if (hrml.find(s) != hrml.end()) {
			cout << hrml[s] << endl;
		}
		else {
			cout << "Not Found!" << endl;
		}
	}

	return 0;
}