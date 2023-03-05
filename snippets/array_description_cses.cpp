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
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;
typedef stack<int> sti;
typedef stack<pi> stpi;
typedef set<int> si;
typedef set<ll> sll;
typedef set<pair<int, int>> spi;
typedef set<pair<ll, ll>> spll;
typedef multiset<int> msi;
typedef map<int, int> mi;
typedef map<pair<int, int>, int> mpi;
typedef map<ll, ll> mll;
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;

template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl "\n"
#define ff first
#define ss second
// #define p push
#define pb push_back
#define fr(k, start, end) for (int k = start; k < end; k++)
#define fr1(k, start, end) for (ll k = start; k < end; k++)

const int N = 1000000007;
const int M = 1e9 + 7;

// CUSTOM COMPARATOR FOR SETS
// struct comp
// {
//   bool operator()(const pi &a, const pi &b)
//   {
//     int diff1 = a.second - a.first;
//     int diff2 = b.second - b.first;
//     return diff1 <= diff2;
//   }
// };

bool comp(pi &a, pi &b)
{
  if (a.first == b.first)
    return a.second > b.second;
  return a.first < b.first;
}

int main()
{
  int n, m;
  vi arr;
  arr.pb(0);
  cin >> n >> m;
  vvi dp(n + 1, vi(m + 1));
  fr(i, 0, n)
  {
    int a;
    cin >> a;
    arr.pb(a);
  }
  fr(i, 1, n + 1)
  {
    fr(x, 1, m + 1)
    {
      if (i == 1)
      {
        if (arr[i] == 0 || arr[i] == x)
          dp[i][x] = 1;
        else
          dp[i][x] = 0;
      }
      else
      {
        if (arr[i] == 0 || arr[i] == x)
        {
          dp[i][x] = ((dp[i - 1][x - 1] + dp[i - 1][x]) % M + dp[i - 1][x + 1]) % M;
        }
        else
          dp[i][x] = 0;
      }
    }
  }

  int ans = 0;
  fr(i, 1, m + 1)
  {
    ans = (ans + dp[n][i]) % M;
  }

  cout << ans;
  return 0;
}
