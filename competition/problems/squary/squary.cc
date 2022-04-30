#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;

static vector<long long> read_ints(int N);
static void output_ints(const vector<long long> &vec);



int solve(vector<long long> &vec, long long *ans)
{
	int ret = -1;
	int N = vec.size();;
	long long B = std::accumulate(vec.begin(), vec.end(), 0LL);
	long long C = 0;

	for (int i = 0; i < N; ++i)
		C += vec[i] * vec[i];

	if (B == 0)
		*ans = 0;
	else
		*ans = (C - B * B) / (2 * B);


	if ((*ans * 2 * B) == (C - B * B))
		return 0;
	return -1;
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
	int K;

	cin >> T;
	for (int t = 1; t <= T; t++) {
		int res;
		long long ans = 0;
		cin >> N >> K;
		vector<long long> vec = read_ints(N);
		cout << "Case #" << t << ": ";
		res = solve(vec, &ans);
		if (res)
			cout << "IMPOSSIBLE\n";
		else
			cout << ans << "\n";
	}
	return 0;
}

/* ================================ */
static vector<long long> read_ints(int N)
{
	vector<long long> input(N, 0);
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
