#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll N, Q;
string S;
vl rpos, bpos;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N >> Q >> S;

  for (auto i = 0; i < N; ++i) {
    if (S[i] == 'R') rpos.push_back(i);
    if (S[i] == 'B') bpos.push_back(i);
  }

  for (auto q = 0; q < Q; ++q) {
    ll l, r;
    cin >> l >> r;

    const auto& a_idx = lower_bound(rpos.begin(), rpos.end(), l);
    if (a_idx == rpos.end() || a_idx + 1 == rpos.end()) {
      cout << -1 << '\n';
      continue;
    }
    const auto& a = *a_idx;
    const auto& b = *(a_idx + 1);
    if (b > r) {
      cout << -1 << '\n';
      continue;
    }

    const auto& c_idx = lower_bound(bpos.begin(), bpos.end(), b + 1);
    if (c_idx == bpos.end() || c_idx + 1 == bpos.end()) {
      cout << -1 << '\n';
      continue;
    }
    const auto& c = *c_idx;
    const auto& d = *(c_idx + 1);
    if (d > r) {
      cout << -1 << '\n';
      continue;
    }

    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
  }

  return 0;
}