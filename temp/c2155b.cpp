#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

typedef std::pmr::vector<int> vi;
typedef std::pair<int, int> pi;



void solve();
int count(char (*a)[100][100],bool (*b)[100][100], int n);

int main() {
  int t;
  cin >> t;
  for(int i =0; i < t; i++) {
    solve();
  }
}


void solve() {
  char a[100][100];
  bool b[100][100];
  int n,k;
  cin >> n;
  cin >> k;
  int r = k*k;
  for (int i=0; i < n; i++) {
    for (int j = 0; i < n; i++) {
      a[i][j] = 'U';
      if (i == 0) {
        b[i][j] = true;
      }
    }
  }

  cout << count(&a,&b,n);

  
}


// p sure this is unneccesary because in actual logic i would just set this switch to true in the "calculatorics"
int count(char (*a)[100][100],bool (*b)[100][100],int n) {
  int k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; i < n; j++) {
      switch (*a[i][j]) {
        case 'U':
          if (i == 0 ||(i > 0 && *b[i-1][j] == true))
            *b[i][j] = true; k+=1;
          break;
        case 'D':
          if (i == n-1 || (i < n-1 && *b[i+1][j] == true))
            *b[i][j] = true; k+=1;
          break;
        case 'L':
          if(j == 0 || (j > 0 && *b[i][j-1] == true))
            *b[i][j] = true; k+=1;
          break;
        case 'R':
          if(j == 0 || (j > 0 && *b[i][j-1] == true))
            *b[i][j] = true; k+=1;
          break;
      }
    }
  }
}
