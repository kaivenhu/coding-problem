#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;

static vector<int> read_ints(int N);
static void output_ints(const vector<int> &vec);


int ask(const vector<int> &vec)
{
	int ans = -1;
	output_ints(vec);
	cin >> ans;
	for (uint i = 0; i < vec.size(); ++i)
		if (vec[i] == ans)
			return i;
	return -1;
}

vector<int> solve(int N)
{
	vector<int> res = {1, 2};
	for (int i = 3; i <= N; ++i) {
		int l = 0;
		int r = res.size() - 1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			int median = ask({res[mid], res[mid + 1], i});
			if (median == -1) {
				exit(1);
			} else if (median == 2) {
				l = mid + 1;
				break;
			} else if (median == 1) {
				l = mid + 1;
				if (l == r)
					++l;
			} else {
				r = mid;
			}
		}
		res.insert(res.begin() + l, i);
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
	int T, N, Q, response;

	cin >> T;
	cin >> N;
	cin >> Q;
	for (int t = 1; t <= T; t++) {
		auto res = solve(N);
		output_ints(res);
		cin >> response;
		if (response != 1) {
			cout << "Failed on test case " << t << "\n";
			exit(1);
		}
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
	cout << flush;
}
/* ================================ */
