#include<bits/stdc++.h>
using namespace std;
 
int32_t main(){
 
  cout << "Enter the string: ";
  string s; cin >> s;
  string encoded_s;
  for (int i = 0; i < (int)s.size(); i++) {
    int cnt = 1;
    while (s[i] == s[i + 1] and i + 1 < (int)s.size()) {
      cnt++;
      i++;
    }
    encoded_s += cnt + '0';
    encoded_s += s[i];
  }
  cout << "Encoded string is : " << encoded_s << '\n';
  return 0;
}