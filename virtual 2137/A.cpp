#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int k, x;
		cin >> k >> x;
		int pow = 1;
		while(k--){
			pow *= 2;
		}
		cout << x * pow << endl;
	}
}
