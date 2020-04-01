#include <cstdio>
#include <cstring>
#include <string>
// #include <map>
#include <unordered_map>
using namespace std;
unordered_map<string, string> dict;
char meaning[15], words[15], tmp[15], c;
long flag = 0, len = 0;
int main() {
	for (c = getchar(); (c != '\n') || (flag); c = getchar()) {
		if (c == ' ') { flag = 1, len = 0; continue; }
		else if (c == '\n') { 
			flag = 0, len = 0; 
			dict[string(words)] = string(meaning);
			memset(words, 0, sizeof(words));
			memset(meaning, 0, sizeof(meaning));
			continue;
		}
		(!flag) ? (meaning[len++] = c) : (words[len++] = c);
	}
	len = 0;
	while ((c=getchar()) != EOF) {
		if (c != '\n') tmp[len++] = c;
		else {
			if (dict.count(string(tmp))) printf("%s\n", dict[string(tmp)].c_str());
			else printf("%s\n", "eh");
			memset(tmp, 0, sizeof(tmp)), len = 0;
		}
	}	
}