#include <bits/stdc++.h>

using namespace std;

void solve(int R, int C)
{
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (!i && !j)
				cout << "..";
			else
				cout << "+-";
		}
		cout << "+" << "\n";
		for (int j = 0; j < C; ++j) {
			if (!i && !j)
				cout << "..";
			else
				cout << "|.";
		}
		cout << "|" << "\n";
	}
	for (int j = 0; j < C; ++j)
		cout << "+-";
	cout << "+" << "\n";
}

int main(void)
{
/* ================================ */
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
/* ================================ */
	int T = 1;
	int R;
	int C;

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> R >> C;
		cout << "Case #" << t << ":\n";
		solve(R, C);
	}
	return 0;
}
