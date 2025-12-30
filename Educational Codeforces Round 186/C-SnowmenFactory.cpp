#include <vector>
#include <iostream>

using namespace std;

long long twoConveyors(vector<long long> a, vector<long long> b){
	long long count = 0;
	for(long long j = 0; j < b.size(); ++j){
		long long x = 0;
		long long y = j;
		bool works = true;
		for(long long q = 0; q < a.size(); ++q){
			if(a[x] >= b[y]){
				works = false;
				break;
			}
			++x;
			++y;
			if(x == a.size()){
				x = 0;
			}
			if(y == b.size()){
				y = 0;
			}
		}
		if(works){
			++count;
		}
	}
	return count;
}

int main(){
	long long t;
	cin >> t;
	for(long long i = 0; i < t; ++i){
		long long n;
		cin >> n;
		vector<long long> a(n);
		vector<long long> b(n);
		vector<long long> c(n);
		for(long long j = 0; j < n; ++j){
			cin >> a[j];
		}
		for(long long j = 0; j < n; ++j){
			cin >> b[j];
		}
		for(long long j = 0; j < n; ++j){
			cin >> c[j];
		}
		long long x = twoConveyors(a, b);
		long long y = twoConveyors(b, c);
		cout << x * y * n << endl;
	}
	return 0;
}
