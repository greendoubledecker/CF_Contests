#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll t = 1;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll> cnt(11);
		for(ll i = 0; i < n; ++i){
			ll x;
			cin >> x;
			++cnt[x];
		}
		for(ll i = 10; i > 0; --i){
			if(cnt[i]){
				cout << cnt[i] << endl;
				break;
			}
		}
	}
}
