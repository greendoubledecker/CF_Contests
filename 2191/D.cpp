#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		//cout << "excuse me?!?!" << endl;
		int firstShut = 0;
		for(int i = 0; i < n; ++i){
			if(s[i] == ')'){
				firstShut = i;
				break; //I just needed a *break*.
			}
		}
		
		//cout << "firstshut = " << firstShut << endl;
		
		//cout << "drguih" << endl;
		int pointer = firstShut + 1;
		int dy = -1;
		//cout << "pointerr" << pointer << endl;
		while(dy < 1 && pointer < n){
			//cout << "FW$ETR" << endl;
			if(s[pointer] == '('){
				++dy;
			}else{
				--dy;
			}
			++pointer;
			//cout << "pointer = " << pointer << " dy = " << dy << endl;
		}
		if(pointer == n){
			cout << -1 << endl;
		}else{
			cout << n - (pointer - firstShut) + 1 << endl;
		}
	}
}
