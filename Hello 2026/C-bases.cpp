#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long calcTime(long long d1, long long d2){
	return 2 * max(d1, d2) + min(d1, d2) - 1;
}

void tc(){
	long long numBases, days, home;
	cin >> numBases >> days >> home;
	--home;
	long long l = home;
	long long r = home;
	while(calcTime(home - l, r - home) <= days){
		//cout << "l is " << l << " and r is " << r << endl;
		if(l == 0 && r == numBases - 1){
			cout << numBases << endl;
			return;
		}
		if(l > 0){
			--l;
		}
		if(calcTime(home - l, r - home) > days){
			break;
		}
		if(r < numBases - 1){
			++r;
		}
	}
	cout << r - l << endl;
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		tc();
	}
}
