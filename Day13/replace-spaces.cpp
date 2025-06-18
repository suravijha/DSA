// You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.

#include <bits/stdc++.h> 
using namespace std;
string replaceSpaces(string &str){
	string ans;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') ans += "@40";
		else ans += str[i];
	}
	return ans;
}