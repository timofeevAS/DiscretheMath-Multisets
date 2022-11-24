#include "Gray.h"
#include <algorithm>
#include <cstdlib>
#include <time.h>

int q(int i ) {
	int q = 1;
	int j = i;

	while (j % 2 == 0) {
		j /= 2;
		q++;
	}

	return q;
}

void create_universum(int n,MyMultiSet& U){
	string tmp = "";
	srand(unsigned int(time(0)));
	if (n == 0) {
		U.MultiSet.push_back(make_pair("empty",0));
		return;
	}
	for (int i = 0; i < n; i++) {
		tmp += '0';
	}
	U.MultiSet.push_back(make_pair(tmp, rand() % 9 + 1));
	for (int i = 1; i <= pow(2, n) - 1; i++) {
		int p = q(i) - 1;
		tmp[p] = (1 - (tmp[p] - '0')) + '0';
		U.MultiSet.push_back(make_pair(tmp, rand() % 9 + 1));
	}
	std::sort(U.MultiSet.begin(), U.MultiSet.end());
}
