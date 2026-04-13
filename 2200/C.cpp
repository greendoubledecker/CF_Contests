#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		string s;
		cin >> s;
		string stc;
		for(ll i = 0; i < n; ++i){
			if(stc.size() && stc[stc.size()-1] == s[i]){
				stc.pop_back();
			}else{
				stc.push_back(s[i]);
			}
		}
		if(stc.empty()){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
}
