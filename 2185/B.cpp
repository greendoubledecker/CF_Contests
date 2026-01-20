#include <iostream>

using namespace std;

int main(){	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int max = 0;
		for(int i = 0; i < n; ++i){
			int g;
			cin >> g;
			if(g > max){
				max = g;
			}
		}
		cout << max * n << endl;
	}
}
