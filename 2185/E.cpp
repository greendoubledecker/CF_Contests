#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, m, k;
		cin >> n >> m >> k;
		vector<ll> leftRange(n);
		vector<ll> rightRange(n);
		vector<ll> robots(n);
		for(ll i = 0; i < n; ++i){
			cin >> robots[i];
		}
		vector<ll> spikes(m);
		for(ll i = 0; i < m; ++i){
			cin >> spikes[i];
		}
		sort(spikes.begin(), spikes.end());
		for(ll i = 0; i < n; ++i){
			auto right = lower_bound(spikes.begin(), spikes.end(), robots[i]);
			if(right == spikes.end()){
				rightRange[i] = LLONG_MAX;
			}else{
				ll r = *right;
				rightRange[i] = r - i - 1;
			}
			if(right == spikes.begin()){
				leftRange[i] = LLONG_MAX;
			}else{
				ll l = spikes[right - spikes.begin() - 1];
				leftRange[i] = i - l - 1;
			}
		}
		ll rightMove = 0;
		ll leftMove = 0;
		ll cur = 0;
		for(int i = 0; i < k; ++i){
			char c;
			cin >> c;
			if(c == 'L'){
				--cur;
				if(-cur > leftMove){
					leftMove = -cur;
				}
			}else{
				++cur;
				if(cur > rightMove){
					rightMove = cur;
				}
			}
		}
		ll killed = 0;
		for(int i = 0; i < n; ++i){
			if(leftRange[i] < leftMove){
				++killed;
			}
		}
		for(int i = 0; i < n; ++i){
			if(rightRange[i] < rightMove && leftRange[i] >= leftMove){
				++killed;
			}
		}
		cout << n - killed << endl;
	}
}
