#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> x(n);
		for(int i = 0; i < n; ++i){
			cin >> x[i];
		}
		sort(x.begin(), x.end());
		int maxStreak = 0;
		int streak = 1;
		for(int i = 1; i <n ; ++i){
			if(x[i] == x[i - 1] + 1){
				++streak;
			}else if(x[i] != x[i - 1]){
				maxStreak = max(maxStreak, streak);
				streak = 1;
			}
			//cout << "max is " << maxStreak << endl;
		}
		maxStreak = max(maxStreak, streak);
		cout << maxStreak << endl;
	}
}
