#include <bits/stdc++.h>

using namespace std;

int main(){
	long long t;
	cin >> t;
	while(t--){
		long long a, b;
		cin >> a >> b;
		if(a % 2 == 1){
			if(b % 2 == 1){
				cout << a * b + 1 << endl;
			}else{
				a *= 2;
				b /= 2;
				if(b % 2 == 1){
					cout << -1 << endl;
				}else{
					a = a * b / 2;
					b = 2;
					cout << a + b << endl;
				}
			}
		}else{
			if(b % 2 == 1){
				cout << -1 << endl;
			}else{
				a = a * b / 2;
				b = 2;
				cout << a + b << endl;
			}
		}
	}
}
