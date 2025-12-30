#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		string s;
		cin >> n >> s;
		bool has25 = false;
		bool has26 = false;
		for(int i = 0; i < s.size() - 3; ++i){
			if(s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2'){
				if(s[i + 3] == '5'){
					has25 = true;
				}
				if(s[i + 3] == '6'){
					has26 = true;
				}
			}
		}
		if(has25 && !has26){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;
		}
	}
}
