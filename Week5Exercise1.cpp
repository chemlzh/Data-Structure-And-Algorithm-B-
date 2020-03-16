#include <cstdio>
#include <cstring>
using namespace std;
struct userDeque {
	const long initLength = 128;
	long head, len, dequeSize;
	long* element = nullptr;
	inline void newDeque() {
		if (element != nullptr) delete[] element;
		element = new long[initLength];
		head = 0, len = 0, dequeSize = initLength;
	}
	inline void insertDeque(long num) {
		if (head+len == dequeSize) {
			dequeSize <<= 1;
			long* tmp = new long[dequeSize];
			memcpy(tmp, element + head, sizeof(long) * len);
			delete[] element;
			element = tmp, head = 0;
		}
		element[head + len] = num, len++;
	}
	inline long deleteDeque(long flag) {
		if (len == 0) return -1;
		else {
			(flag) ? (len--) : (head++, len--); return 1;
		}
	}
	inline void printDeque() {
		if (!len) printf("%s\n", "NULL");
		else {
			for (long i = head; i < head + len; i++) printf("%ld ", element[i]);
			printf("\n");
		}
	}
};
long t, n, op, num;
userDeque deq;
int main() {
	scanf("%ld", &t);
	for (long i = 0; i < t; i++) {
		deq.newDeque();
		scanf("%ld", &n);
		for (long j = 0; j < n; j++) {
			scanf("%ld%ld", &op, &num);
			if (op == 1) deq.insertDeque(num);
			else if (op == 2) deq.deleteDeque(num);
			else;
		}
		deq.printDeque();
	}
}