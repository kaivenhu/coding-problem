#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;

static vector<int> read_ints(int N);


int solve(vector<int> &vec)
{
	int count = 1;
	std::sort(vec.begin(), vec.end());
	for (const int &n : vec) {
		if (n >= count)
			++count;
	}
	return count - 1;
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
		cin >> N;
		auto x = read_ints(N);
		cout << "Case #" << t << ": " << solve(x) << "\n";
	}
	return 0;
}

/* ================================ */
static vector<int> read_ints(int N)
{
	vector<int> input(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> input[i];
	return input;
}
/* ================================ */
