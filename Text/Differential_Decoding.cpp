#include<bits/stdc++.h>
using namespace std;
 
int32_t main(){
 
  cout << "Enter the size of the encoded data: ";
  int n; cin >> n;
  cout << "Enter the encoded data: ";
  vector<int> dc_data(n), en_data(n);
  for (int i = 0; i < n; i++) cin >> en_data[i];
  dc_data[0] = en_data[0];
  for (int i = 1; i < n; i++) {
    dc_data[i] = en_data[i] + dc_data[i - 1];
  }
  cout << "Differential decoded data is : ";
  for (auto it : dc_data) cout << it << ' ';
  cout << '\n';
  
  return 0;
}