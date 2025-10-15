#include <algorithm>
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
  int n;
  int t;

  cin >> n;
  cin.ignore();
  pmr::vector<signed int> p;
  vi r;
  r.reserve(n/2);
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
    auto l = p[2 * i + 1] - p[2 * i];
    r[i] = l
    if (l > t) {
      t = l;
      m = i;
    }
  }

  int prev_max = r[m];
  int prev_idz = m;
  int cur_max = r[m];
  int cur_idx = m;
  for (int i =0; i < n; i++) {
    // forall even i, check if swapping m.x or m.y decreases both sides to be lower than cur_max 
    // forall odd i, check if swapping i with m.x | m.y changes anything, using n-1 as the test
    }
}
