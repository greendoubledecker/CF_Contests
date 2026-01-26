#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n, s, x;
		cin >> n >> s >> x;
		ll sum = 0;
		for(ll i = 0; i < n; ++i){
			ll c;
			cin >> c;
			sum += c;
		}
		if(sum % x == s % x && sum <= s){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}
