#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, m, k;
		cin >> n >> m >> k;
		vector<pair<ll, bool>> leftRange(n); //bool is whether it died
		vector<pair<ll, bool>> rightRange(n);
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
				rightRange[i].first = LLONG_MAX;
			}else{
				ll r = *right;
				//cout << "next spike for " << i << " is " << r << ", index " << right - spikes.begin() << endl;
				rightRange[i].first = r - robots[i] - 1;
			}
			if(right == spikes.begin()){
				leftRange[i].first = LLONG_MAX;
			}else{
				ll l = spikes[right - spikes.begin() - 1];
				//cout << "prev spike for " << i << " is " << l << ", index " << right - spikes.begin() - 1 << endl;
				leftRange[i].first = robots[i] - l - 1;
			}
		}
		/*
		for(int i = 0; i < n; ++i){
			cout << robots[i] << " left: " << leftRange[i].first << endl;
			cout << robots[i] << " right: " << rightRange[i].first << endl;
		}
		*/
		ll rightMove = 0;
		ll leftMove = 0;
		ll cur = 0;
		ll killed = 0;
		string s;
		cin >> s;
		for(int i = 0; i < k; ++i){
			//cout << "looping " << i << endl;
			char c = s[i];
			if(c == 'L'){
				--cur;
				if(-cur > leftMove){
					leftMove = -cur;
					for(int j = 0; j < n; ++j){
						if(!leftRange[j].second){
							//cout << "robot " << j << " can move " << rightRange[j].first << " steps left." << endl;
							if(leftRange[j].first < leftMove){
								++killed;
								leftRange[j].second = true;
								rightRange[j].second = true;
							}
						}
					}
				}
			}else{
				++cur;
				if(cur > rightMove){
					rightMove = cur;
					for(int j = 0; j < n; ++j){
						if(!rightRange[j].second){
							//cout << "robot " << j << " can move " << rightRange[j].first << " steps right." << endl;
							if(rightRange[j].first < rightMove){
								++killed;
								rightRange[j].second = true;
								leftRange[j].second = true;
							}
						}
					}
				}
			}
			//cout << "moved " << cur << endl;
			cout << n - killed;
			if(i < k - 1){
				cout << " ";
			}
		}
		cout << endl;
	}
}
