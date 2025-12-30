#include <iostream>
#include <string>

using namespace std;

int main(){
	int tc;
	cin >> tc;
	for(int i = 0; i < tc; ++i){
		string s;
		cin >> s;
		int ycount = 0;
		for(char c : s){
			if(c == 'Y'){
				++ycount;
			}
		}
		if(ycount > 1){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
	}
}
