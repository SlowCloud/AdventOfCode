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

	string s, trash;

	int cnt = 0;
	while (getline(cin, s)) {
		stringstream ss; ss.str(s);
		string id;
		ss >> trash >> id; // Game n:
		id.pop_back();
		string number, type;
		bool flag = true;
		while (flag && ss >> number >> type) {
			int n = stoi(number);
			if (!isalpha(type.back())) type.pop_back(); // remove , ;
			if (type == "red") {
				flag = n <= 12;
			}
			if (type == "green") {
				flag = n <= 13;
			}
			if (type == "blue") {
				flag = n <= 14;
			}
		}
		if (flag) {
			cnt += stoi(id);
		}
	}

	cout << cnt;

} // main
