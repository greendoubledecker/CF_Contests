#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n, m, h;
		cin >> n >> m >> h;
		vector<int> original(n);
		for(int i = 0; i < n; ++i){
			cin >> original[i];
		}
		vector<int> active = original;
		vector<int> as(m);
		vector<int> bs(m);
		for(int i = 0; i < m; ++i){
			cin >> as[i] >> bs[i];
			--as[i];
			/*
			if(original[a - 1] + b > h){
				as = {};
				bs = {};
			}else{
				as.push_back(a);
				bs.push_back(b);
			}
			*/
		}
		
		int it = m - 1;
		for(; it >= 0; --it){
			if(bs[it] + original[as[it]] > h){
				break;
			}
		}
		++it;
		for(int i = it; i < as.size(); ++i){
			int a = as[i], b = bs[i];
			if(active[a] + b > h){
				active = original;
			}else{
				active[a] += b;
			}
		}
		for(int i = 0; i < n; ++i){
			cout << active[i];
			if(i != n - 1){
				cout << " ";
			}
		}
		cout << endl;
	}
}
