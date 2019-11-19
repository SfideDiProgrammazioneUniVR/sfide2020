#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  vector<pair<int, int>> pos; // (pos, i)
  for (int i = 0; i < N; i++) {
    pos.push_back({A[i], i});
  }

  while (pos.size() > 1) {
    for (auto &x : pos) {
      x.first += B[x.second];
    }
    sort(pos.begin(), pos.end());
    pos.erase(pos.begin(), pos.begin() + pos.size() / 2);
  }

  cout << pos[0].second << endl;
}
