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

int R, C;

bool isSymbol(char c) {
	return !(isdigit(c) || c == '.');
}

vector<string> m;
int check(vector<ii>&v) {
	bool flag = false;
	string buffer;
	for (auto& i : v) {
		buffer.push_back(m[i.first][i.second]);
		For(t, 0, 8) {
			int nx = i.first +  "11020202"[t] - '1';
			int ny = i.second + "02112002"[t] - '1';
			if (zoutside(nx, ny, R, C)) continue;
			flag |= isSymbol(m[nx][ny]);
		}
	}
	if (flag) return stoi(buffer);
	return 0;
}

int main() {
	FAST;

	INPUT;

	string s;
	while (cin >> s) m.push_back(s);

	R = m.size(), C = m.back().size();

	int res = 0;
	For(i, 0, R) {
		vector<ii> buffer;
		For(j, 0, C) {
			if (isdigit(m[i][j])) {
				buffer.emplace_back(i, j);
			}
			else {
				res += check(buffer); buffer.clear();
			}
		}
		if (buffer.size()) res += check(buffer);
	}
	
	cout << res;

} // main
