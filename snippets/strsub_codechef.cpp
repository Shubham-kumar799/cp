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
#define pb push_back
#define fr(k, start, end) for (int k = start; k < end; k++)
#define frr(k, start, end) for (int k = start; k >= end; k--)

const int N = 1000000007;
const int M = 1e9 + 7;
const int S = 1e6 + 1;

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

// bool answer(int lim, int left, int right, int k, str &s)
// {
//   int count = 0;
//   int zero = 0;
//   int one = 0;
//   int prev = left;
//   fr(i, left, right + 1)
//   {
//     zero += s[i] == '0';
//     one += s[i] == '1';

//     if (zero > k || one > k)
//     {
//       while (zero > k || one > k)
//       {
//         zero -= s[prev] == '0';
//         one -= s[prev] == '1';
//         prev++;
//       }
//     }
//     count += i - prev + 1;
//     if (count >= lim)
//       return true;
//   }
//   return false;
// }

vi preprocess(int left, int right, int k, str &s)
{
  int zero = 0;
  int one = 0;
  vi far(s.length(), right);
  int prev = left;
  fr(i, left, right)
  {
    zero += s[i] == '0';
    one += s[i] == '1';
    while (zero > k || one > k)
    {
      far[prev] = i;
      zero -= s[prev] == '0';
      one -= s[prev] == '1';
      prev++;
    }
  }
  return far;
}

int main()
{

  int t;
  cin >> t;

  while (t--)
  {
    int n, k, q;
    cin >> n >> k >> q;
    str s;
    cin >> s;
    vpi queries;

    fr(i, 0, q)
    {
      int l, r;
      cin >> l >> r;
      queries.pb({l - 1, r - 1});
    }
    vi far = preprocess(0, s.length(), k, s);
    // cout << endl;
    // fr(i, 0, s.length()) cout << i << " " << far[i] << endl;
    fr(i, 0, q)
    {
      int left = queries[i].first;
      int right = queries[i].second;
      ll count = 0;
      fr(i, left, right + 1)
      {
        int j = min(far[i], right + 1);
        count += j - i;
      }
      cout << count << endl;
    }
    return 0;
  }
}