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
void solve_test() {
  ll ans = 0;
  ll n, k;
  cin >> n >> k;
  a.clear();
  for (int i = 0; i < n; i++)
  {
    ll x, y;
    cin >> x >> y;
    a.push_back({x, y});
  }
  sort(all(a));
  ll now = a[0].second - a[0].first;
  ll remain = 0;
  if (now % k != 0)
    remain = k - ( now % k);
  ans += ((now + k - 1) / k);

  for (int i = 1; i < n; i++)
  {
    remain -= (a[i].first - a[i - 1].second);
    now = a[i].second - a[i].first;
    if (remain < 0) remain = 0;
    if (remain >= now) {
      remain -= now;
      continue;
    }
    now -= remain;
    ans += ((now + k - 1) / k);
    if (now % k != 0)
      remain = k - (now % k);
    //  trace(i, a[i].first, a[i].second, ans);
  }

  cout << ans << "\n";
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
