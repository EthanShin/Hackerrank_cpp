#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
	set<int> s;
	int Q;

	cin >> Q;

	for (int i = 0; i < Q; i++) {
		int x, y;
		cin >> y >> x;
		if (y == 1) {
			s.insert(x);
		}
		else if (y == 2) {
			s.erase(x);
		}
		else if (y == 3) {
			if (s.find(x) != s.end()) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}

	return 0;
}