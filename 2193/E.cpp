#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll> count(n + 1, 0);
		for(ll i = 0; i < n; ++i){
			ll m;
			cin >> m;
			++count[m];
		}
		vector<ll> ans(n + 1);
		for(ll i = 1; i <= n; ++i){
			if(count[i]){
				//cout << i << "appears" << endl;
				ans[i] = 1;
			}else{
				ll cur = i;
				bool works = false;
				for(ll j = i / 2; j > 1; --j){
					if(cur % j == 0){
						if(ans[j] != -1 && count[cur / j]){
							ans[i] = ans[j] + 1;
							works = true;
							break;
						}
					}
				}
				if(!works){
					ans[i] = -1;
				}
			}
		}
		for(ll i = 1; i <= n; ++i){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}
