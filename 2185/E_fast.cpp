#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, m, k;
		cin >> n >> m >> k;
		vector<ll> leftRange(n); //bool is whether it died
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
				//cout << "next spike for " << i << " is " << r << ", index " << right - spikes.begin() << endl;
				rightRange[i] = r - robots[i];
			}
			if(right == spikes.begin()){
				leftRange[i] = LLONG_MAX;
			}else{
				ll l = spikes[right - spikes.begin() - 1];
				//cout << "prev spike for " << i << " is " << l << ", index " << right - spikes.begin() - 1 << endl;
				leftRange[i] = robots[i] - l;
			}
		}
		/*
		for(int i = 0; i < n; ++i){
			cout << robots[i] << " left: " << leftRange[i].first << endl;
			cout << robots[i] << " right: " << rightRange[i].first << endl;
		}
		*/
		
		string s;
		cin >> s;
		vector<ll> step(2 * k + 1, LLONG_MAX); //the step at which each value of movement is first found
		ll cur = 0;
		for(ll i = 0; i < k; ++i){
			if(s[i] == 'L'){
				--cur;
			}else{
				++cur;
			}
			step[cur + k] = min(step[cur + k], i);
		}
		//cout << "calculated step" << endl;
		vector<ll> count(k); //the number of robots that die at each step
		for(ll i = 0; i < n; ++i){
			ll left = leftRange[i];
			ll right = rightRange[i];
			if(left > k){
				if(right > k){
					continue;
				}else{
					++count[step[right + k]];
				}
			}else{
				if(right > k){
					++count[step[-left + k]];
				}else{
					++count[min(step[right + k], step[-left + k])];
				}
			}
		}
		
		ll surviving = n;
		for(ll i = 0; i < k; ++i){
			surviving -= count[i];
			cout << surviving << " ";
		}
		cout << endl;
	}
}
