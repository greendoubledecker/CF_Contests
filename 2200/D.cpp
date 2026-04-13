#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, p1,p2;
		cin >> n >> p1 >> p2;
		vector<ll> v1(p1);
		vector<ll> v2(p2-p1);
		vector<ll> v3(n-p2);
		for(ll i = 0; i < p1; ++i){
			cin >> v1[i];
		}
		for(ll i = 0; i < p2 - p1; ++i){
			cin >> v2[i];
		}
		for(ll i = n - p2 - 1; i >= 0; --i){
			cin >> v3[i];
		}
		
		ll min = LLONG_MAX;
		ll minInd;
		for(ll i = 0; i < p2-p1; ++i){
			if(v2[i] < min){
				min = v2[i];
				minInd = i;
			}
		}
		//cout << "calculated min = " << minInd << endl;
		vector<ll> newv2(p2-p1);
		for(ll i = 0; i < p2-p1; ++i){
			newv2[(i - minInd + p2 - p1) % (p2 - p1)] = v2[i];
			//cout << "shifted i = " << i << endl;
		}
		//cout << "shifted v2" << endl;
		ll v1size = v1.size();
		//while(v1size && newv2[0] < v1[v1size - 1]){
		//	v3.push_back(v1[v1size - 1]);
		//	v1.pop_back();
		//	--v1size;
		//}
		ll inspoint = -1;
		//cout << "v1[0] = " << v1[0] << endl;
		//cout << "v2[0] = " << newv2[0] << endl;
		for(ll i = 0; i < v1.size(); ++i){
			if(v1[i] > newv2[0]){
				inspoint = i;
				break;
			}
		}
		if(inspoint != -1){
			while(v1size > inspoint){
				v3.push_back(v1[v1size - 1]);
				v1.pop_back();
				--v1size;
			}
		}
		ll v3size = v3.size();
		while(v3size && v3[v3size - 1] < newv2[0]){
			v1.push_back(v3[v3size - 1]);
			v3.pop_back();
			--v3size;
		}
		for(ll i = 0; i < v1.size(); ++i){
			cout << v1[i] << ' ';
		}
		for(ll i = 0; i < newv2.size(); ++i){
			cout << newv2[i] << ' ';
		}
		for(ll i = v3.size() - 1; i > 0; --i){
			cout << v3[i] << ' ';
		}
		if(v3.empty()){
			cout << '\n';
			continue;
		}
		cout << v3[0] << '\n';
	}
}
