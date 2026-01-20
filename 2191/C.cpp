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
		bool sorted = true;
		for(int i = 1; i < n; ++i){
			if(s[i] == '0' && s[i-1] == '1'){
				sorted = false;
				break;
			}
		}
		if(sorted){
			cout << "Bob" << endl;
		}else{
			cout << "Alice" << endl;
			int numzeroes = 0;
			for(char c : s){
				if(c == '0'){
					++numzeroes;
				}
			}
			vector<int> ans;
			for(int i = 0; i < numzeroes; ++i){
				if(s[i] == '1'){
					ans.push_back(i + 1);
				}
			}
			for(int i = numzeroes; i < n; ++i){
				if(s[i] == '0'){
					ans.push_back(i + 1);
				}
			}
			cout << ans.size() << endl;
			for(int i = 0; i < ans.size(); ++i){
				if(i == 0){
					cout << ans[i];
				}else{
					cout << " " << ans[i];
				}
			}
			cout << endl;
		}
	}
}
