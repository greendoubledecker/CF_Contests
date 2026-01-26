#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll> swords(n);
		vector<ll> levels(n);
		for(ll i = 0; i < n; ++i){
			cin >> swords[i];
		}
		sort(swords.begin(), swords.end());
		
		for(ll i = 0; i < n ;++i){
			cin >> levels[i];
		}
		
		vector<ll> swordsNeeded(1, 0);
		for(ll i = 0; i < n; ++i){
			swordsNeeded.push_back(swordsNeeded[i] + levels[i]);
		}
		
		vector<ll> levelFor(n + 1);
		levelFor[0] = 0;
		for(ll i = 1; i <= n; ++i){
			if(swordsNeeded[levelFor[i - 1] + 1] <= i){
				levelFor[i] = levelFor[i - 1] + 1;
			}else{
				levelFor[i] = levelFor[i - 1];
			}
		}
		
		vector<ll> numSwords(n); // if you set difficulty = swords[i];
		for(ll i = 0; i < n; ++i){
			numSwords[i] = n - i;
		}
		
		ll maxx = 0;
		for(ll i = 0; i < n; ++i){
			ll difficulty = swords[i];
			ll swords = numSwords[i];
			ll level = levelFor[swords];
			maxx = max(maxx, difficulty * level);
		}
		cout << maxx << endl;
	}
}
