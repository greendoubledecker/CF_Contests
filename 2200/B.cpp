#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		bool nondecreasing = true;
		vector<ll> a(n);
		for(ll i = 0; i < n; ++i){
			cin >> a[i];
		}
		for(ll i = 1; i < n; ++i){
			if(a[i] < a[i - 1]){
				nondecreasing = false;
				break;
			}
		}
		if(nondecreasing){
			cout << n << endl;
		}else{
			cout << "1\n";
		}
	}
}
