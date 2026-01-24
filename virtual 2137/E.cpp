#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> count(n + 1);
		for(int i = 0; i < n; ++i){
			int f;
			cin >> f;
			++count[f];
		}
		if(k == 1){
			int sum = 0;
			for(int i = 0; i < n; ++i){
				int w = 0;
				for(; w <= n; ++w){
					if(count[w] == 0 || (w == i && count[w] == 1)){
						break;
					}
				}
				sum += w;
			}
			cout << sum << endl;
		}
		if(count[0] > 1){
			if(k % 2 == 0){
				cout << 0 << endl;
			}else{
				cout << n << endl;
			}
		}else{
			int gap = 0;
			for(; gap <= n + 1; ++gap){
				if(count[gap] == 0){
					break;
				}
			}
			int greaterThan = 0;
			for(int i = gap + 1; i <= n; ++i){
				greaterThan += count[i];
			}
			int lessSum = 0;
			for(int i = 0; i < gap; ++i){
				lessSum += count[i] * i;
			}
			cout << "gap = " << gap << " greater = " << greaterThan << " less = " << lessSum << endl;
			if(k % 2 == 0){
				int ans = lessSum + greaterThan * gap;
				cout << ans << endl;
			}else{
				int ans = lessSum + greaterThan * (gap + 1);
				cout << ans << endl; 
			}
		}
	}
}
