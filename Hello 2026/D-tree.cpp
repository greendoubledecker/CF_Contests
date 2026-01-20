#include <iostream>
#include <vector>

using namespace std;

void tc(){
	long long n;
	cin >> n;
	vector<long long> degree(n, 0);
	for(int i = 0; i < n - 1; ++i){
		int a, b;
		cin >> a >> b;
		++degree[a - 1];
		++degree[b - 1];
	}
	++degree[0];
	long long max = 0;
	for(long long f : degree){
		if(f > max){
			max = f;
		}
	}
	cout << max << endl;
}

int main(){
	long long t;
	cin >> t;
	for(long long i = 0; i < t; ++i){
		tc();
	}
}
