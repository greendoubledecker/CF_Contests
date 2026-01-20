#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool zero = false, one = false;
		int zerocount = 0;
		for(int i = 0; i < n; ++i){
			int x;
			cin >> x;
			if(x == 0){
				zero = true;
				++zerocount;
			}
			if(x == 1){
				one = true;
			}
		}
		if((zero && one) || zerocount == 1){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	}
}
