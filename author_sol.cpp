#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		string s[55];
		vector<int> r(2), w(2);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			for (int j = 0; j < m; j++) {
				if (s[i][j] == 'R') {
					// check if 'R' is at an even or odd position
					r[(i + j) & 1] = 1;
				} else if (s[i][j] == 'W') {
					// check if 'W' is at an even or odd position
					w[(i + j) & 1] = 1;
				}
			}
		}
		// 'v' = checks if 'R' is at an even postion and 'W' is at an odd position
		int v = r[1] | w[0];
		// 'vv' = checks if 'R' is at an odd postion and 'W' is at an even position
		int vv = r[0] | w[1];
		// check if both 'v' and 'vv' is both true
		if (v && vv) {
			// if yes, then output NO (because it means that either one of
			// them or both is located in the same position)
			cout << "NO\n";
			// continue the while-loop
			continue;
		}
		// 'cc' contains characters 'R' and 'W'
		char cc[] = {'R', 'W'};
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// by referring to 'cc' array, calculate the index of the character to be printed
				// if the value of 'v' is 1, then character 'R' will be printed in all the even
				// positions while character 'W' will be printed in all the odd positions, however,
				// if the value of 'v' is 0, then vice-versa
				char c = cc[(i + j + v) & 1];
				cout << c;
				if (s[i][j] != '.') {
					assert(s[i][j] == c);
				}
			}
			cout << '\n';
		}
	}
	return 0;
}
