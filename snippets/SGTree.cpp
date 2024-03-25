#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;
typedef string str;
typedef float fl;
typedef double dd;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<pair<int, int>, int> ppi;
typedef tuple<int, int, int> ti;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<dd> vd;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pi> vpi;
typedef vector<ti> vti;
typedef vector<pll> vpll;
typedef vector<vc> vvc;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef vector<vd> vvd;
typedef stack<int> sti;
typedef stack<pi> stpi;
typedef set<int> si;
typedef set<ll> sll;
typedef set<pi> spi;
typedef set<pll> spll;
typedef multiset<int> msi;
typedef map<int, int> mi;
typedef map<pi, int> mpi;
typedef map<ll, ll> mll;
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
template <class T>
using mipq = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define fr(k, start, end) for (int k = start; k < end; k++)
#define frr(k, start, end) for (int k = start; k >= end; k--)
#define prDouble(x) cout << fixed << setprecision(1) << x
int toint(const string &s)
{
  stringstream ss;
  ss << s;
  int x;
  ss >> x;
  return x;
}

const ll INF = 1e17;
const ll NINF = -INF;
const int N = 1000000007;
const int M = 1e9 + 7;
const int S = 1e6 + 1;

// CUSTOM COMPARATOR FOR SETS
// struct comp
// {
//   bool operator()(const pi &u, const pi &v)
//   {
//     int diff1 = u.second - u.first;
//     int diff2 = v.second - v.first;
//     return diff1 <= diff2;
//   }
// };

class SGTree
{
public:
	SGTree(int n)
	{
		this->n = n;
		tree.resize(4 * n + 1, 0);
		lazy.resize(4 * n + 1, 0);
	}

	void build(vector<int> &v)
	{
		build(0, 0, n - 1, v);
	}

	void range_update(int l, int r, int val)
	{
		range_update(0, 0, n - 1, l, r, val);
	}

	int query(int l, int r)
	{
		return query(0, 0, n - 1, l, r);
	}

private:
	int n;
	vector<int> tree;
	vector<int> lazy;

	void build(int node, int start, int end, vector<int> &v)
	{
		if (start == end)
		{
			tree[node] = v[start];
			return;
		}

		int mid = start + (end - start) / 2;
		int left = 2 * node + 1;
		int right = 2 * node + 2;
		build(left, start, mid, v);
		build(right, mid + 1, end, v);
		tree[node] = max(tree[left], tree[right]);
	}

	void range_update(int node, int start, int end, int l, int r, int val)
	{
		pushdown(start, end, node);

		// NO OVERLAP
		if (r < start || l > end)
			return;

		// FULL OVERLAP
		if (l <= start && r >= end)
		{
			lazy[node] = val;
			pushdown(start, end, node);
			return;
		}

		int mid = start + (end - start) / 2;
		int left = 2 * node + 1;
		int right = 2 * node + 2;
		range_update(left, start, mid, l, r, val);
		range_update(right, mid + 1, end, l, r, val);
		tree[node] = max(tree[left], tree[right]);
	}

	int query(int node, int start, int end, int l, int r)
	{
		pushdown(start, end, node);

		// NO OVERLAP
		if (r < start || l > end)
			return 0;

		// FULL OVERLAP
		if (l <= start && r >= end)
			return tree[node];

		int mid = start + (end - start) / 2;
		int left = 2 * node + 1;
		int right = 2 * node + 2;
		int leftVal = query(left, start, mid, l, r);
		int rightVal = query(right, mid + 1, end, l, r);
		return max(leftVal, rightVal);
	}

	void pushdown(int start, int end, int node)
	{
		if (lazy[node] != 0)
		{
			tree[node] = lazy[node];
			if (start != end)
			{
				lazy[2 * node + 1] = lazy[node];
				lazy[2 * node + 2] = lazy[node];
			}
			lazy[node] = 0;
		}
	}
};


int main()
{

  return 0;
}
