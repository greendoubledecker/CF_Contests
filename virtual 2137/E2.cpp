#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		
		//count occurences
		vector<int> v(n);
		vector<int> count(n + 1);
		int zeroes = 0;
		for(int i = 0; i < n; ++i){
			cin >> v[i];
			if(v[i] <= n){
				++count[v[i]];
			}
			if(v[i] == 0){
				++zeroes;
			}
		}
		
		//calculate mex
		int totalMex = 0;
		for(int i = 0; i <= n; ++i){
			if(!count[i]){
				totalMex = i;
				break;
			}
		}
		
		//do first step manually
		vector<int> step1(n);
		for(int i = 0; i < n; ++i){
			if(v[i] > totalMex){
				step1[i] = totalMex;
				continue;
			}
			if(count[v[i]] == 1){
				step1[i] = v[i];
			}else{
				step1[i] = totalMex;
			}
		}
		
		//can exit if there is only one step
		if(k == 1){
			int sum = 0;
			for(int i = 0; i < n; ++i){
				sum += step1[i];
			}
			cout << sum << endl;
			continue;
		}
		
		//find mex after first step
		int newMex = 0;
		vector<int> newCount(n + 1);
		for(int i : step1){
			++newCount[i];
		}
		for(int i = 0; i <= n; ++i){
			if(!newCount[i]){
				newMex = i;
				break;
			}
		}
		
		int oddSum, evenSum;
		//calculate sum at even steps
		int lessSum = 0;
		int lessCount = 0;
		for(int i = 0; i < newMex; ++i){
			lessCount += newCount[i];
			lessSum += newCount[i] * i;
		}
		int greaterCount = n - lessCount;
		evenSum = lessSum + greaterCount * newMex;
		
		//now calculate for odd steps
		oddSum = evenSum + greaterCount;
		
		//output answer
		if(k % 2 == 0){
			cout << evenSum << endl;
		}else{
			cout << oddSum << endl;
		}
	}
}
