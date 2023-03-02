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
using mipq = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using maxq = priority_queue<T>;
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
#define prDouble(x) cout << fixed << setprecision(6) << x
#define all(x) x.begin(), x.end()

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

void prV(vi &v)
{
  for (auto i : v)
    cout << i << " ";
  cout << endl;
}

const ll INF = 1e9;
const ll NINF = -INF;
const int M = 1e9 + 7;
const int S = 1e5 + 5;
const ll MOD = 998244353;

// custom comparator  for sets
// Declaration -> set<int, cmp> s;
// auto cmp = [](pi const &x, pi const &y)
// {
//   return x > y;
// };

// CUSTOM COMPARATOR FOR SETS
// struct comp
// {
//   bool operator()(const pi &u, const pi &vertices)
//   {
//     int diff1 = u.second - u.first;
//     int diff2 = vertices.second - vertices.first;
//     return diff1 <= diff2;
//   }
// };
ll add(ll a, ll b, ll mod)
{
  return (a + b) % mod;
}

ll mul(ll a, ll b, ll mod) { return (a * b) % mod; }

int gcd(int a, int b)
{
  return b ? gcd(b, a % b) : a;
}

ll pow(ll a, ll b, ll m)
{
  ll ans = 1;
  while (b)
  {
    if (b & 1)
    {
      ans = mul(a, ans, m);
    }
    a = mul(a, a, m);
    b = b >> 1;
  }
  return ans;
}

// PERMUTATION AND COMBINATION

// Using pascal
// const int MAXN = 30;

// ll pascal[MAXN + 1][MAXN + 1] = {0};
// void computePascal()
// {
//   pascal[0][0] = 1;
//   fr(i, 1, MAXN + 1)
//   {
//     pascal[i][0] = pascal[i][i] = 1;
//     fr(k, 1, i)
//     {
//       pascal[i][k] = pascal[i - 1][k - 1] + pascal[i - 1][k];
//     }
//   }
// }

// const int MAXN = 1e6 + 1;
// int factorial[MAXN];
// int inv_fact[MAXN];

// int inverse(int a, int m)
// {
//   return pow(a, m - 2, m);
// }

// void computeFactorialAndInverse(int m)
// {
//   factorial[0] = inv_fact[0] = 1;
//   fr(i, 1, MAXN)
//   {
//     factorial[i] = mul(factorial[i - 1], i, M);
//     inv_fact[i] = inverse(factorial[i], m);
//   }
// }

// int nCr(int n, int r, int m)
// {
//   if (n < 0 || r < 0 || r > n)
//     return 0;
//   int numerator = factorial[n];
//   int denominator = mul(inv_fact[r], inv_fact[n - r], m);
//   return mul(numerator, demominator, m);
// }

void decToBinary(int n)
{
  // counter for binary array
  str s = "0000";
  int i = 0;
  int d = n;
  while (n > 0)
  {
    s[i] = ((n % 2) + '0');
    n = n / 2;
    i++;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--)
  {

    continue;
  end:
    cout << endl;
    continue;
  }
  return 0;
}
