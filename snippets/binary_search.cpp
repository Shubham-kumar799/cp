#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef float fl;
typedef double dd;
typedef long long ll;
typedef unsigned long long ull;
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
typedef set<int> si;
typedef set<ll> sll;
typedef map<int, int> mi;
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;

#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define fr(i, n) for (int i = 0; i < n; i++)
#define fr1(i, n) for (ll i = 0; i < n; i++)

const int N = 1000000007;

// RETURNS TRUE OR FALSE
bool b_search(ll l, ll r, ll t)
{
  while (l <= r)
  {
    ll mid = l + (r - l) / 2;

    if (mid == t)
      return true;
    else if (mid > t)
    {
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  return false;
}

int main()
{

  return 0;
}
