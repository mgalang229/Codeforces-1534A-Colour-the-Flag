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
		vector<vector<char>> a(n, vector<char>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		// to solve this, you must create two valid 'n' x 'm' grid matrix, either it starts 
		// with 'W' or 'R' and check if the 2D grid 'a' matches one of these valid grids
		// start by making a valid grid that starts with 'W'
		vector<vector<char>> start_w(n, vector<char>(m, ' '));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// check if the current element in 'start_w' is equal to a space
				if (start_w[i][j] == ' ') {
					// if yes, then set the current element to 'W'
					start_w[i][j] = 'W';
					if (i > 0) {
						// set the ('i' - 1') (up) element to 'R' (if possible)
						start_w[i - 1][j] = 'R';
					}
					if (i < n - 1) {
						// set the ('i' + 1') (down) element to 'R' (if possible)
						start_w[i + 1][j] = 'R';
					}
					if (j > 0) {
						// set the ('j'- 1') (left) element to 'R' (if possible)
						start_w[i][j - 1] = 'R';
					}
					if (j < m - 1) {
						// set the ('j' + 1') (right) element to 'R' (if possible)
						start_w[i][j + 1] = 'R';
					}
				}
			}
		}
		// next is to create a valid grid that starts with 'R'
		vector<vector<char>> start_r = start_w;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// use the 'start_w' grid and reverse all the values, for example, 
				// if the current element is 'R' then change it to 'W' and vice-versa
				start_r[i][j] = (start_r[i][j] == 'R' ? 'W' : 'R');
			}
		}
		// then, check the already provided elements (not the dot symbol) from 'a'
		// if it matches the elements in the 'start_w'
		bool w_checker = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// check if the already provided elements in grid 'a' (not the dot symbol)
				// does not match the corresponding element in 'start_w'
				if (a[i][j] != '.' && a[i][j] != start_w[i][j]) {
					// if yes, then set 'w_checker' to false and break the inner for-loop
					w_checker = false;
					break;
				}
			}
			if (!w_checker) {
				// if 'w_checker' is false, then break the outer for-loop
				break;
			}
		}
		// also, check the already provided elements (not the dot symbol) from 'a'
		// if it matches the elements in the 'start_r'
		bool r_checker = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// check if the already provided elements in grid 'a' (not the dot symbol)
				// does not match the corresponding element in 'start_r'
				if (a[i][j] != '.' && a[i][j] != start_r[i][j]) {
					// if yes, then set 'r_checker' to false and break the inner for-loop
					r_checker = false;
					break;
				}
			}
			if (!r_checker) {
				// if 'r_checker' is false, then break the outer for-loop
				break;
			}
		}
		// check if grid 'a' matches one of the correct provided grids by the program
		if (r_checker || w_checker) {
			// create 'res' grid to store the correct grid
			vector<vector<char>> res;
			// check if the 'r_checker' is true and set the value of 'res' to 'start_r'
			// otherwise, if the 'w_checker' is true, then set the value of 'res' to 'start_w'
			res = (r_checker ? start_r : start_w);
			// output the needed results (based from the problem statement)
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << res[i][j];
				}
				cout << '\n';
			}
		} else {
			// if grid 'a' does not match any of the provided grids, then output NO
			cout << "NO\n";
		}
	}
	return 0;
}
