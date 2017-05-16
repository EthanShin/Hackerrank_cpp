#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
	map<string, int> m;
	int Q;

	cin >> Q;

	for (int i = 0; i < Q; i++) {
		int type;
		string x;
		cin >> type >> x;
		if (type == 1) {
			int y;
			cin >> y;
			if (m.find(x) != m.end()) {
				y += m[x];
				m.erase(x);
			}
			m.insert(make_pair(x, y));
		}
		else if (type == 2) {
			m.erase(x);
		}
		else if (type == 3) {
			if (m.find(x) != m.end()) {
				cout << m[x] << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
	}

	return 0;
}
