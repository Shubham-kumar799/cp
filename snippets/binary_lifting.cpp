#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <climits>

using namespace std;
typedef string str;
typedef float fl;
typedef double dd;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<pair<int, int>, int> ppi;
typedef tuple<int, int, int> ti;
typedef tuple<ll, ll, ll> tll;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<dd> vd;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pi> vpi;
typedef vector<ti> vti;
typedef vector<tll> vtll;
typedef vector<pll> vpll;
typedef vector<vc> vvc;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef vector<vd> vvd;
typedef stack<int> sti;
typedef stack<pi> stpi;
typedef stack<char> stc;
typedef queue<int> qi;
typedef queue<ll> qll;
typedef queue<pi> qpi;
typedef set<int> si;
typedef set<char> sc;
typedef set<ll> sll;
typedef set<pi> spi;
typedef set<pll> spll;
typedef multiset<int> msi;
typedef multiset<ll> msll;
typedef map<int, int> mi;
typedef map<pi, int> mpi;
typedef map<ll, ll> mll;
typedef map<int, vi> mivi;
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
template <class T>
using minq = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using maxq = priority_queue<T>;
template <class T>
using vt = vector<T>;

#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define fr(k, start, end) for (int k = start; k < end; k++)
#define frr(k, start, end) for (int k = start; k >= end; k--)
#define prDouble(x) cout << fixed << setprecision(6) << x
#define all(x) x.begin(), x.end()

template <class T>
void pr(T x)
{
	cout << x;
}
template <class T>
void prs(T x)
{
	cout << x << " ";
}
template <class T>
void prl(T x) { cout << x << endl; }
template <class T>
void prV(vector<T> &v)
{
	for (auto i : v)
		cout << i << " ";
	cout << endl;
}
template <class T>
void prV1(vector<T> &v)
{
	int n = v.size();
	fr(i, 1, n) pr(v[i]);
	cout << endl;
}

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int XX[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int YY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const ll INF = 1e9;
const ll NINF = -INF;
const int M = 1e9 + 7;
const int S = 1e5 + 5;
const int N = 3 * 1e5;
const ll MOD = 998244353;

int up[N + 1][30];
int lvl[N + 1];

void binary_lifting(int node, int par, mivi &tree)
{
	up[node][0] = par;
	fr(i, 1, 30)
	{
		if (up[node][i - 1] != -1)
			up[node][i] = up[up[node][i - 1]][i - 1];
		else
			up[node][i] = -1;
	}
	for (auto child : tree[node])
	{
		if (child == par)
			continue;
		binary_lifting(child, node, tree);
	}
}

int lift(int node, int jumps)
{
	if (node == -1 || jumps == 0)
		return node;
	frr(i, 29, 0)
	{
		if (jumps >= (1 << i))
			return lift(up[node][i], jumps - (1 << i));
	}
	return -1;
}

void getLvl(int root, int level, mivi &tree)
{
	lvl[root] = level;
	for (auto child : tree[root])
	{
		getLvl(child, level + 1, tree);
	}
}

void solve()
{
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}