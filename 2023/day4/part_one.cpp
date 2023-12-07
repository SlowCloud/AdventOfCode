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


int main() {
	FAST;

	INPUT;
	string s, trash;

	int res = 0;
	while (getline(cin, s)) {
		stringstream ss; ss.str(s);
		ss >> trash >> trash;
		set<int> se;
		string buffer;
		while (1) {
			ss >> buffer;
			if (buffer == "|") break;
			se.insert(stoi(buffer));
		}
		int cnt = 0;
		while (ss >> buffer) {
			if (se.count(stoi(buffer))) {
				if (cnt == 0) cnt++;
				else cnt <<= 1;
			}
		}
		res += cnt;
	}
	cout << res;

} // main
