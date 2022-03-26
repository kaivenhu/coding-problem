#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;

static vector<int> read_ints(int N);
static void output_ints(const vector<int> &vec);



void solve(void)
{
	// solution.
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
		cout << "Case #" << t << ": ";
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
