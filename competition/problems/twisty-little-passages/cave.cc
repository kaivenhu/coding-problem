#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;

long long solve(int N, int K)
{
	long long edges = 0;
	int end = std::min(N, K);
	int room;
	int start;
	bool skip = false;
	long long edge;
	vector<int> vec(N, 0);
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	long long ans;

	std::iota(vec.begin(), vec.end(), 1);
	std::shuffle(vec.begin(), vec.end(), default_random_engine(seed));

	cin >> start >> edge;
	edges += edge;

	for (int i = 0; i < end; ++i) {
		if (vec[i] == start) {
			skip = true;
			continue;
		}
		cout << "T " << vec[i] << "\n" << flush;
		cin >> room;
		if (room == -1LL)
			exit(1);
		cin >> edge;
		edges += edge;
	}
	if (skip && N > end) {
		cout << "T " << vec[end] << "\n" << flush;
		cin >> room;
		if (room == -1LL)
			exit(1);
		cin >> edge;
		edges += edge;
	}
	if (N > end)
		++end;
	ans = (edges * static_cast<long long>(N)) / static_cast<long long>(2 * end);

	if (N > end) {
		long long remain = N - end;
		long long out = (remain * (remain - 1));
		long long exceed = std::max(0LL, edges - ((long long) end * (long long)(end - 1)));
		out += edges + exceed;
		if (end > remain)
			ans = std::min(ans, out / 2LL);
	}

	return ans;
}

int main(void)
{
/* ================================ */
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
/* ================================ */
	int T = 1;
	int N, K;
	long long ans;
	int room, edge;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		ans = solve(N, K);
		cout << "E " << ans << "\n" << flush;
	}
	return 0;
}

