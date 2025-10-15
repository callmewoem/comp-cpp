#include <iostream>
#include <utility>
#include <vector>

typedef long long ll;

typedef std::pmr::vector<int> vi;
typedef std::pair<int, int> pi;


int main() {
  int x;
  int y;
  std::cin >> x >> y;
  // base perfect cases
  if (x % 2 == 0 ) {
    std::cout << ((x/2) * y);
    return 0;
  }
  if (y % 2 == 0) {
    std::cout << ((y/2) * x);
    return 0;
  }
  // x or y aren't de
  int t = x;
  if (y > x) {
    x = y;
    y = t;
  }

  std::cout << (x*y)/2;
  // int sum = (x)*((y - 1)/2) + (y-1)/2;
  // std::cout << sum; 
}
