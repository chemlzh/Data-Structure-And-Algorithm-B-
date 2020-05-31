#include <cstdio>
#include <vector>
using namespace std;
char str[150];
long pos;
int main() {
	while ((str[pos] = getchar()) != EOF) pos++;
	for (long i = 0; i < pos; i++) {
		if ((str[i] >= 'A') && (str[i] <= 'Z')) printf("%c", str[i] - 'A' + 'a');
		else if ((str[i] >= 'a') && (str[i] <= 'z')) printf("%c", str[i] - 'a' + 'A');
		else printf("%c", str[i]);
	}
}