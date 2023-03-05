#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef set<int> si;
typedef set<ll> sll;
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;

#define endl "\n"
#define ff first
#define ss second
#define pb push_back

const int N = 10000007;

const vi sieve(N, 1);
sieve[0] = sieve[1] = 0;

// SEIVE OF EARTHOTHOENESS
void createSieve(int n)
{
  for (int i = 2; i * i <= n; i++)
  {
    if (sieve[i])
    {
      for (int j = i * i; j <= n; j += i)
      {
        sieve[j] = 0;
      }
    }
  }
}

int main()
{

  return 0;
}