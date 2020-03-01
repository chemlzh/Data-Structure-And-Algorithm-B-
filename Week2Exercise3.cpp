#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	long exp, coef;
	struct node* next;
};
struct prop { long exp, coef; };
typedef node* poly;
poly x, y;
inline void init(poly& A) {
	long c, e;
	poly tmp = nullptr;
	while (true) {
		scanf("%ld%ld", &c, &e);
		if ((c == 0) && (e == 0)) break;
		else {
			poly npoly = new node;
			npoly->coef = c, npoly->exp = e, npoly->next = nullptr;
			if (A == nullptr) A = npoly, tmp = npoly;
			else tmp->next = npoly, tmp = npoly;
		}
	}
}
inline poly add(const poly& A, const poly& B) {
	poly res = nullptr, tmp = nullptr; 
	poly tmp1 = A, tmp2 = B, npoly1 = new node, npoly2 = new node;
	npoly1->coef = A->coef, npoly1->exp = A->exp, npoly1->next = nullptr;
	npoly2->coef = B->coef, npoly2->exp = B->exp, npoly2->next = nullptr;
	while ((tmp1 != nullptr) && (tmp2 != nullptr)) {
		while ((tmp1->next != nullptr) && (tmp1->next->exp == tmp1->exp))
			npoly1->coef += tmp1->next->coef, tmp1 = tmp1->next;
		while ((tmp2->next != nullptr) && (tmp2->next->exp == tmp2->exp))
			npoly2->coef += tmp2->next->coef, tmp2=tmp2->next;
		if (npoly1->exp > npoly2->exp) {
			if (res == nullptr) res = npoly1, tmp = npoly1;
			else tmp->next = npoly1, tmp = npoly1;
			tmp1 = tmp1->next;
			if (tmp1 != nullptr) {
				npoly1 = new node, npoly1->coef = tmp1->coef, npoly1->exp = tmp1->exp, npoly1->next = nullptr;
			}
		}
		else if (npoly1->exp < npoly2->exp) {
			if (res == nullptr) res = npoly2, tmp = npoly2;
			else tmp->next = npoly2, tmp = npoly2;
			tmp2 = tmp2->next;
			if (tmp2 != nullptr) {
				npoly2 = new node, npoly2->coef = tmp2->coef, npoly2->exp = tmp2->exp, npoly2->next = nullptr;
			}
		}
		else {
			npoly1->coef += npoly2->coef;
			if (res == nullptr) res = npoly1, tmp = npoly1;
			else tmp->next = npoly1, tmp = npoly1;
			tmp1 = tmp1->next, tmp2 = tmp2->next;
			if (tmp1 != nullptr) {
				npoly1 = new node, npoly1->coef = tmp1->coef, npoly1->exp = tmp1->exp, npoly1->next = nullptr;
			}
			if (tmp2 != nullptr) {
				npoly2 = new node, npoly2->coef = tmp2->coef, npoly2->exp = tmp2->exp;
			}
		}
	}
	while (tmp1 != nullptr) {
		while ((tmp1->next != nullptr) && (tmp1->next->exp == tmp1->exp))
			npoly1->coef += tmp1->next->coef, tmp1 = tmp1->next;
		if (res == nullptr) res = npoly1, tmp = npoly1;
		else tmp->next = npoly1, tmp = npoly1;
		tmp1 = tmp1->next;
		if (tmp1 != nullptr) {
			npoly1 = new node, npoly1->coef = tmp1->coef, npoly1->exp = tmp1->exp, npoly1->next = nullptr;
		}
	}
	while (tmp2 != nullptr) {
		while ((tmp2->next != nullptr) && (tmp2->next->exp == tmp2->exp))
			npoly2->coef += tmp2->next->coef, tmp2 = tmp2->next;
		if (res == nullptr) res = npoly2, tmp = npoly2;
		else tmp->next = npoly2, tmp = npoly2;
		tmp2 = tmp2->next;
		if (tmp2 != nullptr) {
			npoly2 = new node, npoly2->coef = tmp2->coef, npoly2->exp = tmp2->exp, npoly2->next = nullptr;
		}
	}
	return res;
}
inline bool cmp(const prop A, const prop B) {
	return (A.exp > B.exp) ? 1 : 0;
}
inline poly mul(const poly& A, const poly& B) {
	poly res = nullptr, tmp=nullptr, npoly;
	vector<prop> v;
	prop p;
	long pos = 0;
	for (poly tmp1 = A; tmp1 != nullptr; tmp1 = tmp1->next) {
		for (poly tmp2 = B; tmp2 != nullptr; tmp2 = tmp2->next) {
			p.coef = tmp1->coef * tmp2->coef, p.exp = tmp1->exp + tmp2->exp;
			v.push_back(p);
		}
	}
	sort(v.begin(), v.end(), cmp);
	while (pos < v.size()) {
		p = v[pos];
		while ((pos + 1 < v.size()) && (v[pos + 1].exp == v[pos].exp)) p.coef += v[++pos].coef;
		npoly = new node, npoly->coef = p.coef, npoly->exp = p.exp, npoly->next = nullptr;
		if (res == nullptr) res = npoly, tmp = npoly;
		else tmp->next = npoly, tmp = npoly;
		pos++;
	}
	return res;
}
inline void printPolynomial(const poly& A) {
	poly tmp = A;
	int flag = 0;
	while (tmp != nullptr) {
		if (tmp->coef == 0) { tmp = tmp->next; continue; }
		else {
			if (tmp->coef == -1) printf("%c", '-');
			else if (tmp->coef < 0) printf("%ld", tmp->coef);
			else {
				if (flag) printf("%c", '+');
				if ((tmp->coef > 1) || (tmp->exp == 0)) printf("%ld", tmp->coef);
			}
			if (tmp->exp == 0);
			else if (tmp->exp == 1) printf("%c", 'x');
			else if (tmp->exp) printf("x^%ld", tmp->exp);
			tmp = tmp->next, flag = 1;
		}
	}
	printf("\n");
}
int main() {
	init(x), init(y);
	printPolynomial(add(x, y));
	printPolynomial(mul(x, y));
}