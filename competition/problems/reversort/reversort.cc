#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;

static vector<int> read_ints(int N);
static void output_ints(const vector<int> &vec);

void revertsort(vector<int> &vec)
{
	int cost = 0;
	for (int i = 0; i < (int) vec.size() - 1; ++i) {
		auto iter = std::min_element(vec.begin() + i, vec.end());
		cost += iter - vec.begin() - i + 1;
		std::reverse(vec.begin() + i, std::next(iter));
	}
	cout << cost << "\n";
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
		auto vec = read_ints(N);
		cout << "Case #" << t << ": ";
		revertsort(vec);
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
