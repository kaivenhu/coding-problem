#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ull = unsigned long long;

static vector<int> read_ints(int N);
static void output_ints(const vector<ull> &vec);

ull solve(int N, int P)
{
	vector<vector<int>> products;
	vector<ull> dp(P, 0ULL);
	vector<ull> prev = dp;
	for (int i = 0; i < N; ++i) {
		products.push_back(read_ints(P));
	}

	for (int i = 0; i < N; ++i) {
		const auto &vec = products[i];
		int max_val = *std::max_element(vec.begin(), vec.end());
		int min_val = *std::min_element(vec.begin(), vec.end());
		std::swap(prev, dp);

		for (int j = 0; j < P; ++j) {
			ull min_cnt = ULLONG_MAX;
			if (!i) {
				min_cnt = max_val + max_val - vec[j];
			} else {
				const auto &prev_vec = products[i - 1];
				ull max_first = std::abs(max_val - min_val) +
						std::abs(min_val - vec[j]);
				ull min_first = std::abs(max_val - min_val) +
						std::abs(max_val - vec[j]);
				for (int x = 0; x < P; ++x) {
					int start = prev_vec[x];
					min_cnt = std::min({min_cnt,
						prev[x] + max_first + (ull) std::abs(start - max_val),
						prev[x] + min_first + (ull) std::abs(start - min_val)});
				}
			}
			dp[j] = min_cnt;
		}
	}
	return *std::min_element(dp.begin(), dp.end());
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
	int P;

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> P;
		cout << "Case #" << t << ": ";
		cout << solve(N, P) << "\n";
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

static void output_ints(const vector<ull> &vec)
{
	for (uint i = 0; i < vec.size() - 1; ++i)
		cout << vec[i] << " ";
	cout << vec[vec.size() - 1] << "\n";
}
/* ================================ */
