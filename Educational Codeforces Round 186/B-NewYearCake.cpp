#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int w, d;
		cin >> w >> d;
		int pow = 1;
		int w1 = w, d1 = d, w2 = w, d2 = d;
		int count = 0;
		while(w1 >= 0 && d1 >= 0){
			++count;
			if(count % 2 == 0){
				w1 -= pow;
			}else{
				d1 -= pow;
			}
			pow *= 2;
		}
		int count2 = 0;
		pow = 1;
		while(w2 >= 0 && d2 >= 0){
			++count2;
			if(count2 % 2 == 1){
				w2 -= pow;
			}else{
				d2 -= pow;
			}
			pow *= 2;
		}
		//cout << count << " " << count2 << endl;
		cout << max(count, count2) - 1 << endl;
	}
	return 0;
}
