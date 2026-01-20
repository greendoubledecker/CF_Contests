#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

long long mex(vector<long long> v){
	unordered_set<long long> appears;
	for(long long n : v){
		appears.insert(n);
	}
	long long i = 0;
	while(appears.count(i)){
		++i;
	}
	return i;
}

int main(){
	long long t;
	cin >> t;
	for(long long i  = 0; i < t; ++i){
		long long n, k;
		cin >> n >> k;
		vector<long long> a;
		for(long long j = 0; j < n; ++j){
			long long d;
			cin >> d;
			a.push_back(d);
		}
		cout << min(mex(a), k - 1) << endl;
	}
}
