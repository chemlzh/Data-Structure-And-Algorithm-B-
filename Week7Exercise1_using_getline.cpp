#include <iostream>
#include <sstream>
#include <string>
// #include <map>
#include <unordered_map>
using namespace std;
unordered_map<string, string> dict;
string meaning, words, tmp;
long flag = 0;
int main() {
	std::ios::sync_with_stdio(false);
	while (getline(cin, tmp)) {
		if (tmp == "") {	flag = 1; continue; }
		if (!flag) {
			stringstream ss(tmp);
			ss >> meaning >> words;
			dict[string(words)] = string(meaning);
		}
		else {
			if (dict.count(tmp)) cout << dict[tmp] << endl;
			else cout << "eh" << endl;
		}
	}
}
// More beautiful, but much slower. We'd better use getchar().