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

class SGTree {
    public:
        SGTree(int m){
            n = m;
            tree.resize(4*n , 0);
        }
        int query(int l, int r){
            return query(0, 0, n - 1, l, r);
        }

        void update(int tarInd, int tarVal){
            update(0, 0, n - 1, tarInd, tarVal);
        }
    private:
        vector<int> tree;
        int n;

    int query(int ind, int left, int right, int low, int high){
        // NO OVERLAP
        if(high < left || low > right) return INT_MIN;

        // FULL OVERLAP
        if(low <= left && high >= right) return tree[ind];

        int mid = left + (right - left)/2;
        return max({query(2*ind + 1, left, mid, low, high),
        query(2*ind + 2, mid + 1, right, low, high), 0});
    }

    void update(int ind , int left, int right, int tarInd, int tarVal){
        
        if(left == right){
            tree[ind] = tarVal;
            return;
        }

        int mid = left + (right - left)/2;
        if(tarInd <= mid) update(2*ind + 1, left, mid, tarInd, tarVal);
        else update(2*ind + 2, mid + 1, right, tarInd, tarVal);
        tree[ind] = max(tree[2*ind + 1], tree[2*ind + 2]);
    }  
};

int main()
{

  return 0;
}
