#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		string s;
		cin >> s;
		int count = 0;
		if(s[0] == 'u'){
			++count;
			s[0] = 's';
		}
		if(s[s.size() - 1] == 'u'){
			++count;
			s[s.size() - 1] = 's';
		}
		vector<int> uLengths;
		int currentLength = 0;
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == 'u'){
				++currentLength;
			}
			if(s[i] == 's'){
				uLengths.push_back(currentLength);
				currentLength = 0;
			}
		}
		for(int l : uLengths){
			count += l/2;
		}
		cout << count << endl;
	}
}
