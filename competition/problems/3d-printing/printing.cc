#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;

static vector<int> read_ints(int N);
static void output_ints(const vector<int> &vec);

vector<int> solve(const vector<int> &A,
		  const vector<int> &B,
		  const vector<int> &C)
{
	int remain = 1000000;
	vector<int> res(4, 0);
	for (int i = 0; i < 4; ++i) {
		res[i] = std::min({remain, A[i], B[i], C[i]});
		remain -= res[i];
	}
	return (!remain) ? res : vector<int>();
}

int main(void)
{
/* ================================ */
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
/* ================================ */
	int T = 1;

	cin >> T;
	for (int t = 1; t <= T; t++) {
		auto res = solve(read_ints(4), read_ints(4), read_ints(4));
		cout << "Case #" << t << ": ";
		if (res.size())
			output_ints(res);
		else
			cout << "IMPOSSIBLE" << "\n";
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

static void output_ints(const vector<int> &vec)
{
	for (uint i = 0; i < vec.size() - 1; ++i)
		cout << vec[i] << " ";
	cout << vec[vec.size() - 1] << "\n";
}
/* ================================ */
