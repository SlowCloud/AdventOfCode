#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define FAST cin.tie(0)->sync_with_stdio(0);
#define endl '\n'
#define INPUT freopen("input.txt", "rt", stdin)

using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i,a,b) for(int i=a;i<b;i++)
#define outside(x,y,R,C) (min(x,y) < 1 || R < x || C < y)
#define zoutside(x,y,R,C) (min(x,y) < 0 || R <= x || C <= y)
#define nx(x,i) x + "1102"[i] - '1'
#define ny(y,i) y + "0211"[i] - '1'

int cnt[300];

int main() {
	FAST;
	INPUT;
	vector<string> input;
	string s;
	while (getline(cin, s)) {
		input.push_back(s);
	}

	int N = input.size();
	fill(cnt, cnt + N + 1, 1);

	for (string s : input) {
		stringstream ss; ss.str(s);
		string trash, id; ss >> trash >> id;
		set<int> se;
		For(i, 0, 10) {
			int n; ss >> n;
			se.insert(n);
		}
		ss >> trash;
		int now = 0;
		For(i, 0, 25) {
			int n; ss >> n;
			now += se.count(n);
		}
		id.pop_back();
		int nth = stoi(id);
		For(i, 0, now) {
			cnt[nth + i + 1] += cnt[nth];
		}
	}

	int res = 0;
	For(i, 1, N + 1) res += cnt[i];
	cout << res;

} // main
