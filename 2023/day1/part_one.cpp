#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define FAST cin.tie(0)->sync_with_stdio(0);
#define endl '\n'

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
#define nx(x,i) x + "1102"[i] - '1'
#define ny(y,i) y + "0211"[i] - '1'


int main() {
	FAST;

	freopen("input.txt", "rt", stdin);

	ll res = 0;

	string s;
	while (cin >> s) {
		int now = 0;
		for (auto i = s.begin(); i != s.end(); i++) {
			if (isdigit(*i)) {
				now += (*i) - '0'; break;
			}
		}
		now *= 10;
		for (auto i = s.rbegin(); i != s.rend(); i++) {
			if (isdigit(*i)) {
				now += (*i) - '0'; break;
			}
		}
		res += now;
	}

	cout << res;

} // main
