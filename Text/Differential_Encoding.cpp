#include<bits/stdc++.h>
using namespace std;
 
int32_t main(){
 
  cout << "Enter the size of the data: ";
  int n; cin >> n;
  cout << "Enter the data: ";
  vector<int> data(n), en_data(n);
  for (int i = 0; i < n; i++) cin >> data[i];
  en_data[0] = data[0];
  for (int i = 1; i < n; i++) {
    en_data[i] = data[i] - data[i - 1];
  }
  cout << "Differential encoded data is : ";
  for (auto it : en_data) cout << it << ' ';
  cout << '\n';
  
  return 0;
}