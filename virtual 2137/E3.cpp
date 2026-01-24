#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> step(vector<int> v, int mex, vector<int> count){
	vector<int> ans(v.size());
	for(int i = 0; i < v.size(); ++i){
		if(v[i] > mex || count[v[i]] > 1){
			ans[i] = mex;
		}else{
			ans[i] = v[i];
		}
	}
	return ans;
}

vector<int> calcCount(vector<int> v){
	vector<int> count(v.size() + 2);
	for(int i : v){
		if(i <= v.size()){
			++count[i];
		}
	}
	return count;
}

int MEX(vector<int> count){
	for(int i = 0; i < count.size(); ++i){
		if(!count[i]){
			return i;
		}
	}
}

signed main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		
		vector<int> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i];
		}
		
		//count occurences
		vector<int> count = calcCount(v);
		
		//calculate mex
		int totalMex = MEX(count);
		
		//do first step manually
		vector<int> step1 = step(v, totalMex, count);
		
		//find mex and count after first step
		vector<int> count1 = calcCount(step1);
		int mex1 = MEX(count1);
		
		//do second step manually
		vector<int> step2 = step(step1, mex1, count1);
		
		//find mex and count after second step
		vector<int> count2 = calcCount(step2);
		int mex2 = MEX(count2);
		
		//do third step manually
		vector<int> step3 = step(step2, mex2, count2);
		
		//find mex and count after third step
		vector<int> count3 = calcCount(step3);
		int mex3 = MEX(count3);
		
		//can exit if there is 1 step
		if(k == 1){
			int sum = 0;
			for(int i = 0; i < n; ++i){
				sum += step1[i];
			}
			cout << sum << endl;
		}else{
			//based on parity
			if(k % 2 == 0){
				int sum = 0;
				for(int i = 0; i < n; ++i){
					sum += step2[i];
				}
				cout << sum << endl;
			}else{
				int sum = 0;
				for(int i = 0; i < n; ++i){
					sum += step3[i];
				}
				cout << sum << endl;
			}
		}
	}
}
