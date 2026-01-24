#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0 ; i< n; ++i){
			int h;
			cin >> h;
			cout << n + 1 - h << " ";
		}
		cout << endl;
	}
}
