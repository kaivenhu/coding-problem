#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;


void output(const string &x)
{
	cout << x << "\n";
	cout << flush;
}

void solve(void)
{
	int x = 8;
	bool state = false;
	bool ans = true;
	for (int i = 0; i < 300; ++i) {
		if (x == -1)
			exit(1);
		if (x == 0) {
			return;
		} else if (x == 8) {
			output("11111111");
		} else if (x >= 5) {
			output("11111111");
		} else if (x == 4) {
			if (ans) {
				output("10101010");
				ans = false;
			} else {
				ans = true;
				if (state) {
					output("10011001");
					state = false;
				} else {
					output("10100101");
					state = true;
				}
			}
		} else if (x == 2 || x == 3) {
			output("00000001");
		} else if (x == 1) {
			output("11110000");
		}
		cin >> x;
	}
}

int main(void)
{
/* ================================ */
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
/* ================================ */
	int T = 1;
	int N;

	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve();
	}
	return 0;
}
