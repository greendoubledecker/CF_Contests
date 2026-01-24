#include <bits/stdc++.h>

using namespace std;

void tc(){
	int n, m, h;
	cin >> n >> m >> h;
	vector<int> original(n);
	vector<pair<int, int>> updates;
	for(int i = 0; i < n; ++i){
		cin >> original[i];
	}
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		--a;
		updates.push_back({a, b});
	}
	vector<int> active = original;
	int lastReset = 0; //first operation after reset
	for(int i = 0; i < m; ++i){
		auto [idx, val] = updates[i];
		active[idx] += val;
		if(active[idx] > h){
			for(int j = i; j >= lastReset; --j){
				active[updates[j].first] -= updates[j].second;
			}
			lastReset = i + 1; //since i is the reset
		}
	}
	for(int i = 0; i < n; ++i){
		cout << active[i] << " ";
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		tc();
	}
}
