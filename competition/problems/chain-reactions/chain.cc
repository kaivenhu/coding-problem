#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;

static vector<int> read_ints(int N);

static inline int get_parent(const vector<int> &parents, int i)
{
	return (parents[i] - 1 >= i) ? -1 : parents[i] - 1;
}

long long solve(vector<int> factors, const vector<int> parents)
{
	long long total = 0;
	int N = factors.size();
	vector<int> mins(N, 0);
	vector<int> degrees(N, 0);
	queue<int> bfs_q;
	for (int i = 0; i < N; ++i) {
		int p = get_parent(parents, i);
		if (p == -1)
			continue;
		degrees[p]++;
	}
	for (int i = 0; i < N; ++i) {
		if (!degrees[i])
			bfs_q.push(i);
	}

	while (!bfs_q.empty()) {
		int size = bfs_q.size();
		for (int i = 0; i < size; ++i) {
			int idx = bfs_q.front();
			int p = get_parent(parents, idx);
			bfs_q.pop();
			if (p == -1) {
				total += static_cast<long long>(factors[idx]);
				continue;
			}
			degrees[p]--;
			if (!mins[p] || factors[idx] < mins[p]) {
				total += static_cast<long long>(mins[p]);
				mins[p] = factors[idx];
			} else {
				total += static_cast<long long>(factors[idx]);
			}
			if (!degrees[p]) {
				factors[p] = std::max(factors[p], mins[p]);
				bfs_q.push(p);
			}
		}
	}
	return total;
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
		auto factors = read_ints(N);
		cout << "Case #" << t << ": " << solve(factors, read_ints(N)) << "\n";
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
