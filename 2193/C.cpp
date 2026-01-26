#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, q;
		cin >> n >> q;
		vector<ll> a(n);
		vector<ll> b(n);
		for(ll i = 0;  i< n; ++i){
			cin >> a[i];
		}
		for(ll i = 0;  i< n; ++i){
			cin >> b[i];
		}
		for(ll i =0; i < n; ++i){
			a[i] = max(a[i], b[i]);
		}
		for(ll i = n - 2; i >= 0; --i){
			a[i] = max(a[i], a[i + 1]);
		}
		
		vector<ll> ps(1, 0);
		for(ll i = 0; i < n; ++i){
			ps.push_back(ps[i] + a[i]);
		}
		for(int i = 0; i < q; ++i){
			ll l, r;
			cin >> l >> r;
			--l;
			--r;
			cout << ps[r + 1] - ps[l] << " ";
		}
		cout << endl;
	}
}
