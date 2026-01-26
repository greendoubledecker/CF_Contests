#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll> p(n);
		ll start = n;
		for(ll i = 0; i < n; ++i){
			cin >> p[i];
			if(p[i] != n - i && start == n){
				start = i;
			}
		}
		if(start == n){
			for(ll i : p){
				cout << i << " ";
			}
			cout << endl;
			continue;
		}
		ll end;
		ll maxAfterStart = n - start;
		for(int i = 0; i < n; ++i){
			if(p[i] == maxAfterStart){
				end = i;
			}
		}
		vector<ll> next = p;
		for(int i = start; i <= end; ++i){
			next[i] = p[end - (i - start)];
		}
		for(ll i : next){
			cout << i << " "; 
		}
		cout << endl;
	}
}
