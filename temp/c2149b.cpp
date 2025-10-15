#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

typedef pmr::vector<int> vi;
typedef pair<int, int> pi;

void solve();

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}

// problem set
// find pairing [(a,b), (c,d)] with minimax  a-b
// "naive" solution, sort vector
// THIS DOES NOT HANDLE NEGATIVES
// todo solve negatives at home
//
// greedy solution: first pair up
void solve() {
  int n,t;

  cin >> n;
  cin.ignore();
  pmr::vector<signed int> p;
  p.reserve(n);
  string line;
  getline(cin, line);
  stringstream ss(line);
  int num;
  while (ss >> num) {
    p.push_back(num);
  }

  sort(p.begin(), p.end());
  t = 0;
  int m = 0;
  for (int i = 0; i < n / 2; i++) {
    auto l = abs(p[2 * i + 1] - p[2 * i]);
    if (l > t) {
      t = l;
      m = i;
    }
  }
  cout << t;
  int pm = t;
  int pi = m;
  int cm = t;
  int ci = m;
  bool s = false;
  while (true) {
    pm = cm;
    pi = ci;
    for (int i = 0; i < n / 2; i++) {
      if (i == m) {
        continue;
      }
      int a1 = abs(p[2 * i] - p[2 * m]);
      int a2 = abs(p[2 * i + 1] - p[2 * m + 1]);
      int b1 = abs(p[2 * i] - p[2 * m + 1]);
      int b2 = abs(p[2 * i + 1] - p[2 * m]);
      if (a2 <= cm && a1 <= cm) {
        cm = a2 > a1 ? a2 : a1;
        s = false;
        ci = 2 * i;
      }
      if (b2 <= cm && b1 <= cm) {
        cm = b2 > b1 ? b2 : b1;
        s = true;
        ci = 2 * i;
      }
    }
    if (cm == pm) {
      cout << cm << '\n';
      return;
    }
    if (s) {
      int t = p[2 * ci + 1];
      p[2 * ci + 1] = p[2 * m];
      p[2 * m] = t;

    } else {
      int t = p[2 * ci + 1];
      p[2 * ci + 1] = p[2 * m + 1];
      p[2 * m + 1] = t;
    }
  }
}
