#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct poly {	long coef, power; }tpoly1, tpoly2;
long n, xpos, ypos, xlen, ylen;
vector<poly> x, y, res;
inline bool cmp(poly a, poly b) {
	return (a.power > b.power) ? 1 : 0;
}
inline void init(vector<poly> &despoly) {
	poly tpoly;
	despoly.clear();
	while (true) {
		scanf("%ld%ld", &tpoly.coef, &tpoly.power);
		if (tpoly.power < 0) break;
		else despoly.push_back(tpoly);
	}
	sort(despoly.begin(), despoly.end(), cmp);
}
int main() {
	scanf("%ld", &n);
	for (int i = 0; i < n; i++) {
		init(x), init(y);
		res.clear(), xpos = 0, ypos = 0, xlen = x.size(), ylen = y.size();
		tpoly1 = x[0], tpoly2 = y[0];
		while ((xpos < xlen) && (ypos < ylen)) {
			while ((xpos + 1 < xlen) && (x[xpos + 1].power == x[xpos].power))
				tpoly1.coef += x[xpos + 1].coef, xpos++;
			while ((ypos + 1 < ylen) && (y[ypos + 1].power == y[ypos].power))
				tpoly2.coef += y[ypos + 1].coef, ypos++;
			if (tpoly1.power > tpoly2.power) {
				res.push_back(tpoly1), xpos++;
				if (xpos < xlen) tpoly1 = x[xpos];
			}
			else if (tpoly1.power < tpoly2.power) {
				res.push_back(tpoly2), ypos++;
				if (ypos < ylen) tpoly2 = y[ypos];
			}
			else {
				tpoly1.coef += tpoly2.coef, res.push_back(tpoly1), xpos++, ypos++;
				if (xpos < xlen) tpoly1 = x[xpos];
				if (ypos < ylen) tpoly2 = y[ypos];
			}
		}
		while (xpos < xlen) {
			while ((xpos + 1 < xlen) && (x[xpos + 1].power == x[xpos].power))
				tpoly1.coef += x[xpos + 1].coef, xpos++;
			res.push_back(tpoly1), xpos++;
			if (xpos < xlen) tpoly1 = x[xpos];
		}
		while (ypos < ylen) {
			while ((ypos + 1 < ylen) && (y[ypos + 1].power == y[ypos].power))
				tpoly2.coef += y[ypos + 1].coef, ypos++;
			res.push_back(tpoly2), ypos++;
			if (ypos < ylen) tpoly2 = y[ypos];
		}
		for (int j = 0; j < res.size(); j++)
			if (res[j].coef) printf("[ %ld %ld ] ", res[j].coef, res[j].power);
		printf("\n");
	}
}