#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> count(n + 1);
		vector<int> v(n);
		vector<vector<int>> locations(n + 1);
		for(int i = 0; i < n; ++i){
			int q;
			cin >> q;
			v[i] = q;
			locations[q].push_back(i);
			++count[q];
		}
		bool x = false;
		for(int i = 1; i <= n; ++i){
			if(count[i] % i != 0){
				cout << -1 << endl;
				x = true;
				break;
			}
		}
		/*
		cout << "locations" << endl;
		for(int i = 1; i <= n; ++i){
			for(int j = 0; j < count[i]; ++j){
				cout << locations[i][j] << " ";
			}
			cout << endl;
		}
		*/
		if(!x){
			vector<int> ans(n);
			int w = 1;
			for(int i = 1; i <= n; ++i){
				for(int j = 0; j < count[i]; ++j){
					//cout << "i = " << i << " j = " << j << " val = " << locations[i][j] << endl;
					ans[locations[i][j]] = w;
					if((j + 1) % i == 0){
						++w;
					}
				}
			}
			for(int i = 0; i < n; ++i){
				cout << ans[i] << " ";
			}
			cout << endl;
		}
	}
}
