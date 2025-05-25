#include<bits/stdc++.h>
using namespace std;
 
int32_t main(){
 
  cout << "Enter your encoded string: ";
  string s, decoded_s; cin >> s;
  for (int i = 1; i < (int)s.size(); i += 2) {
    int cnt = s[i - 1] - '0';
    while (cnt--) {
      decoded_s += s[i];
    }
  }
  cout << "After decoding: " << decoded_s << '\n';
  return 0;
}