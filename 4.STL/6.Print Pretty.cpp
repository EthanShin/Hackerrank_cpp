#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while (T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		cout << setw(0) << nouppercase << "0x" << hex << (long long)A << endl;

		cout << fixed << setprecision(2) << setw(15) << setfill('_') << right << showpos << B << endl;

		cout << scientific << uppercase << setprecision(9) << noshowpos << C << endl;
	}
	return 0;

}