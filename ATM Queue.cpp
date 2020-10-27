#include<bits/stdc++.h>
using namespace std;
typedef long long           ll;
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " = " << arg1 << " | "; __f(comma + 1, args...);
}

ll max(ll a, ll b) {return (a > b ? a : b);}
ll min(ll a, ll b) {return (a < b ? a : b);}
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};
void yes_or_no(ll x) {
  if (x) cout << "YES\n"; else cout << "NO\n";
}
vector<pair<ll, ll>> a;
/*
bool comp(pair<ll, ll> &x, pair<ll, ll> &y) {
  if (x.first == y.first) {
    return x.first < y.first;
  }
  return x.second < y.second;
}
*/
void solve_test() {
  ll ans = 0;
  ll n, x;
  cin >> n >> x;
  a.clear();
// trace(n);
  vector<ll> original(n);
  for (int i = 0; i < n; i++)
  {
    ll y;
    cin >> y;
    // original[i] = y;
    a.push_back({y / x, i});
    if (y % x == 0) a[i].first--;
  }
  sort(all(a));

  for (int i = 0; i < n; i++) cout << a[i].second + 1 << " "; cout << "\n";
//  cout << ans << "\n";
}
int main()
{
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve_test();
  }
  return 0;
}
