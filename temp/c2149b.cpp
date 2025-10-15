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
  pmr::vector<pi> pairs;

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
  for (int i = 0; i < n / 2; i++) {
    pairs.push_back(pair(2*i+1,2*i));
    auto l = p[2 * i + 1] - p[2 * i];
    if (l > t) {
      t = l;
    }
  }
}



// 5
// 2
// 1 2
// 4
// 10 1 2 9
// 6
// 3 8 9 3 3 2
// 8
// 5 5 5 5 5 5 5 5
// 4
// -5 -1 2 6



// 1
// 1
// 1
// 0
// 4
