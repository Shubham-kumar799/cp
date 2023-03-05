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
typedef queue<int> qi;
typedef queue<pi> qpi;
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
template <class T>
using vt = vector<T>;

#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define fr(k, start, end) for (int k = start; k < end; k++)
#define frr(k, start, end) for (int k = start; k >= end; k--)
#define prDouble(x) cout << fixed << setprecision(12) << x
int toint(const string &s)
{
  stringstream ss;
  ss << s;
  int x;
  ss >> x;
  return x;
}
void tointV(const string &s, vi &ans)
{
  stringstream ss;
  int x;
  str temp;
  ss << s;

  while (!ss.eof())
  {
    /* extracting word by word from stream */
    ss >> temp;
    /* Checking the given word is integer or not */
    if (stringstream(temp) >> x)
      ans.pb(x);
    /* To save from space at the end of string */
    temp = "";
  }
}

const ll INF = 1e9;
const ll NINF = -INF;
const int M = 1e9 + 7;
const int M2 = 1e9 + 9;
const int N = 1e6 + 1;
const int base = 33;

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

int apw[N];
int bpw[N];
int ainv[N];
int binv[N];
int ahash[N];
int bhash[N];
int arhash[N];
int brhash[N];

int add(int a, int b, int mod)
{
  int res = (a + b) % mod;
  if (res < 0)
    res += mod;
  return res;
}

int mult(int a, int b, int mod)
{
  int res = (a * 1ll * b) % mod;
  if (res < 0)
    res += mod;
  return res;
}

int binpow(int a, int b, int mod)
{
  int res = 1;
  while (b)
  {
    if (b & 1)
    {
      res = mult(res, a, mod);
    }
    a = mult(a, a, mod);
    b >>= 1;
  }
  return res;
}

void precal(int base, int mod, int pw[], int inv[])
{
  pw[0] = 1;
  fr(i, 1, N)
  {
    pw[i] = mult(pw[i - 1], base, mod);
  }
  int pw_inv = binpow(base, mod - 2, mod);

  inv[0] = 1;
  fr(i, 1, N)
  {
    inv[i] = mult(inv[i - 1], pw_inv, mod);
  }
}

void buildHash(str s, int mod, int h[], int pw[])
{
  int n = s.length();
  fr(i, 0, n)
  {
    h[i] = add(i == 0 ? 0 : h[i - 1], mult(pw[i], s[i] - 'a' + 1, mod), mod);
  }
}

int getHash(int x, int y, int mod, int h[], int inv[])
{
  int res = add(h[y], x == 0 ? 0 : (-1) * h[x - 1], mod);
  res = mult(res, inv[x], mod);
  return res;
}

pi getHashPair(int x, int y, int amod, int ahash[], int ainv[], int bmod, int bhash[], int binv[])
{
  return {getHash(x, y, amod, ahash, ainv), getHash(x, y, bmod, bhash, binv)};
}

int main()
{
  str s;
  cin >> s;
  int n = s.length();
  vvi dp(n, vi(n, 0));
  mi mapping;
  int count = n;
  precal(base, M, apw, ainv);
  precal(base, M2, bpw, binv);
  buildHash(s, M, ahash, apw);
  buildHash(s, M2, bhash, bpw);
  reverse(s.begin(), s.end());
  buildHash(s, M, arhash, apw);
  buildHash(s, M2, brhash, bpw);
  fr(i, 0, n)
  {
    dp[i][i] = 1;
    mapping[1]++;
  }
  fr(i, 1, n)
  {
    fr(j, 0, n - i)
    {
      pi h = getHashPair(j, i + j, M, ahash, ainv, M2, bhash, binv);
      pi revH = getHashPair(n - j - i - 1, n - j - 1, M, arhash, ainv, M2, brhash, binv);
      if (h != revH)
        continue;
      if ((i + 1) & 1)
      {
        // odd length
        dp[j][j + i] = min(dp[j][((2 * j + i) >> 1) - 1], dp[((2 * j + i) >> 1) + 1][j + i]) + 1;
      }
      else
      {
        // even length
        dp[j][j + i] = min(dp[j][((2 * j + i) >> 1)], dp[((2 * j + i) >> 1) + 1][j + i]) + 1;
      }
      mapping[dp[j][j + i]]++;
      count++;
    }
  }
  fr(i, 1, n + 1)
  {
    cout << count << " ";
    if (mapping.count(i))
      count -= mapping[i];
  }
  return 0;
}
