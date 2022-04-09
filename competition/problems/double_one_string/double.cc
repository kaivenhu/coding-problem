#include <bits/stdc++.h>

using namespace std;

bool IsSmall(const string &res, int pos)
{
	int N = res.length();
	for (int i = pos; i < (N - 1); ++i) {
		if (res[i] == res[i + 1])
			continue;
		else if (res[i] > res[i + 1])
			return false;
		else
			return true;
	}
	return false;
}

string solve(string &s)
{
	int N = s.length();
	string res = s;
	int pos = 0;
	for (int i = 0; i < N - 1; ++i) {
		if (IsSmall(res, pos)) {
			res.insert(pos, 1, res[pos]);
			pos++;
		}
		pos++;
	}
	return res;
}

int main(void)
{
/* ================================ */
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
/* ================================ */
	int T = 1;
	string s;

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> s;
		cout << "Case #" << t << ": ";
		cout << solve(s) << "\n";
	}
	return 0;
}

