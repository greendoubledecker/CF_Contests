#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		vector<int> v;
		for(int j = 0; j < n; ++j){
			int f;
			cin >> f;
			v.push_back(f);
		}
		if(v[0] == 1 || v[n - 1] == 1){
			cout << "Alice" << endl;
		}else{
			cout << "Bob" << endl;
		}
	}
}
