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



// aho-corasick
struct Trie {

	bool exist;
	unordered_map<char, Trie*> childs;
	Trie* fail;
	int value;

	Trie() : exist(false), fail(nullptr) {}
	~Trie() { for (auto& i : childs) delete i.second; }

	void insert(string s, int value) {
		Trie* now = this;
		for (char c : s) {
			if (!now->childs.count(c)) {
				now->childs[c] = new Trie();
			}
			now = now->childs[c];
		}
		now->exist = 1;
		now->value = value;
	}

	void build() {
		Trie* root = this; fail = this;
		queue<Trie*> q;
		q.push(root);

		while (q.size()) {
			auto now = q.front(); q.pop();

			for (auto& ch : now->childs) {
				Trie* next = ch.second;
				q.push(next);

				if (now == root) {
					next->fail = root;
				}
				else {
					Trie* prev = now->fail;

					while (prev != root && !prev->childs.count(ch.first))
						prev = prev->fail;

					if (prev->childs.count(ch.first))
						prev = prev->childs[ch.first];

					next->fail = prev;
				}

				if (next->fail->exist) now->exist = 1;
			}

		}
	}

	// 어떤 문자열 s가 주어졌을 때, 트라이에 든 패턴이 발견된다면 참 반환
	int kmp(string s) {
		Trie* now = this;
		for (char c : s) {
			while (now != this && !now->childs.count(c)) now = now->fail;
			if (now->childs.count(c)) now = now->childs[c];
			if (now->exist) return now->value;
		}
		return now->value;
	}

};

Trie* root, *rroot;

int main() {
	FAST;

	freopen("input.txt", "rt", stdin);

	root = new Trie();
	rroot = new Trie();

	root->insert("1", 1);
	root->insert("2", 2);
	root->insert("3", 3);
	root->insert("4", 4);
	root->insert("5", 5);
	root->insert("6", 6);
	root->insert("7", 7);
	root->insert("8", 8);
	root->insert("9", 9);

	root->insert("one", 1);
	root->insert("two", 2);
	root->insert("three", 3);
	root->insert("four", 4);
	root->insert("five", 5);
	root->insert("six", 6);
	root->insert("seven", 7);
	root->insert("eight", 8);
	root->insert("nine", 9);

	rroot->insert("1", 1);
	rroot->insert("2", 2);
	rroot->insert("3", 3);
	rroot->insert("4", 4);
	rroot->insert("5", 5);
	rroot->insert("6", 6);
	rroot->insert("7", 7);
	rroot->insert("8", 8);
	rroot->insert("9", 9);

	rroot->insert("eno", 1);
	rroot->insert("owt", 2);
	rroot->insert("eerht", 3);
	rroot->insert("ruof", 4);
	rroot->insert("evif", 5);
	rroot->insert("xis", 6);
	rroot->insert("neves", 7);
	rroot->insert("thgie", 8);
	rroot->insert("enin", 9);

	root->build();
	rroot->build();

	ll res = 0;

	string s;
	while (cin >> s) {
		int now = 0;
		now += root->kmp(s) * 10;
		reverse(all(s));
		now += rroot->kmp(s);
		res += now;
	}

	cout << res;

} // main
