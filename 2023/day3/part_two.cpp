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

vector<vi> grp;
vi numberOf;
int gnumber = 1;

bool isSymbol(char c) {
	return !(isdigit(c) || c == '.');
}

vector<string> m;
void check(vector<ii>&v) {
	string buffer;
	for (auto& i : v) {
		grp[i.first][i.second] = gnumber;
		buffer.push_back(m[i.first][i.second]);
	}
	gnumber++;
	numberOf.push_back(stoi(buffer));
}

int main() {
	FAST;

	INPUT;

	string s;
	while (cin >> s) m.push_back(s);

	R = m.size(), C = m.back().size();

	grp.resize(R, vi(C));
	numberOf.push_back(0);

	For(i, 0, R) {
		vector<ii> buffer;
		For(j, 0, C) {
			if (isdigit(m[i][j])) {
				buffer.emplace_back(i, j);
			}
			else if (buffer.size()) {
				check(buffer); buffer.clear();
			}
		}
		if (buffer.size()) check(buffer);
	}

	int res = 0;

	For(i, 0, R) {
		For(j, 0, C) {
			if (m[i][j] != '*') continue;
			set<int> s;
			For(t, 0, 8) {
				int nx = i + "11020202"[t] - '1';
				int ny = j + "02110220"[t] - '1';
				if (zoutside(nx, ny, R, C) || grp[nx][ny] == 0) continue;
				s.insert(grp[nx][ny]);
			}
			if (s.size() != 2) continue;
			int tmp = 1;
			for (int i : s) {
				tmp *= numberOf[i];
			}
			res += tmp;
		}
	}
	
	cout << res;

} // main
