#include <iostream>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;

typedef long long ll;

typedef std::pmr::vector<int> vi;
typedef std::pair<int, int> pi;


template <typename T>
pmr::vector<T> ltot() {
  pmr::vector<T> r;
  string line;
  getline(cin,line);
  stringstream ss(line);
  T n;
  while (ss >> n) {
    r.push_back(n);
  }
  return r;
}

void solve();


int main() {
  int t;
  cin >> t;
  for(int i =0; i < t; i++) {
    solve();
  }
}


void solve() {
  
}
