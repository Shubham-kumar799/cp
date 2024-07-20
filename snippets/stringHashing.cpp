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
void prl(T x)
{
	cout << x << endl;
}
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

const int dx[4] = {
	-1,
	1,
	0,
	0};
const int dy[4] = {
	0,
	0,
	-1,
	1};
const int XX[8] = {
	-1,
	-1,
	-1,
	0,
	0,
	1,
	1,
	1};
const int YY[8] = {
	-1,
	0,
	1,
	-1,
	1,
	-1,
	0,
	1};
const ll INF = 1e9;
const ll NINF = -INF;
const int M = 1e9 + 7;
const int S = 1e5 + 5;
const ll MOD = 998244353;

class strHash
{
public:
	strHash(int modOne, int modTwo, int base, int N) : modOne(modOne), modTwo(modTwo),
													   base(base),
													   N(N)
	{
		pwOne = new int[N];
		pwTwo = new int[N];
		invOne = new int[N];
		invTwo = new int[N];
		hashOne = new int[N];
		hashTwo = new int[N];
	}

	void precalc()
	{
		pwOne[0] = 1;
		pwTwo[0] = 1;
		for (int i = 1; i < N; i++)
		{
			pwOne[i] = mult(pwOne[i - 1], base, modOne);
			pwTwo[i] = mult(pwTwo[i - 1], base, modTwo);
		}
		int pw_inv_one = power(base, modOne - 2, modOne);
		int pw_inv_two = power(base, modTwo - 2, modTwo);
		invOne[0] = 1;
		invTwo[0] = 1;
		for (int i = 1; i < N; i++)
		{
			invOne[i] = mult(invOne[i - 1], pw_inv_one, modOne);
			invTwo[i] = mult(invTwo[i - 1], pw_inv_two, modTwo);
		}
	}

	void build(string &s)
	{
		int n = s.length();
		for (int i = 0; i < n; i++)
		{
			hashOne[i] = add((i == 0) ? 0 : hashOne[i - 1], mult(pwOne[i], s[i] - 'a' + 1, modOne), modOne);
			hashTwo[i] = add((i == 0) ? 0 : hashTwo[i - 1], mult(pwTwo[i], s[i] - 'a' + 1, modTwo), modTwo);
		}
	}

	pair<int, int> getHash(int x, int y)
	{
		int resOne = add(hashOne[y], (x == 0) ? 0 : (-1) * hashOne[x - 1], modOne);
		int resTwo = add(hashTwo[y], (x == 0) ? 0 : (-1) * hashTwo[x - 1], modTwo);
		pair<int, int> res = {mult(resOne, invOne[x], modOne), mult(resTwo, invTwo[x], modTwo)};
		return res;
	}

private:
	const int modOne;
	const int modTwo;
	const int base;
	const int N;
	int *pwOne;
	int *pwTwo;
	int *invOne;
	int *invTwo;
	int *hashOne;
	int *hashTwo;

	int add(int a, int b, int mod)
	{
		int res = (a + b) % mod;
		if (res < 0)
			res += mod;
		return res;
	}

	int mult(int a, int b, int mod)
	{
		int res = (a * 1LL * b) % mod;
		if (res < 0)
			res += mod;
		return res;
	}

	int power(int a, int b, int mod)
	{
		int res = 1;
		while (b)
		{
			if ((b % 2) == 1)
				res = mult(res, a, mod);
			a = mult(a, a, mod);
			b = b / 2;
		}
		return res;
	}
};

int getLCP(string &s, int p, strHash &h)
{
	int n = s.length();
	int low = 0, high = min(n - p, p) - 1;
	int ans = 0;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		pair<int, int> leftHalf = h.getHash(0, mid);
		pair<int, int> rightHalf = h.getHash(p, p + mid);
		if (leftHalf == rightHalf)
		{
			low = mid + 1;
			ans = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return ans;
}

void solve()
{
	
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
	return 0;
}
