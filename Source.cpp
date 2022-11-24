#include "stdafx.h"
#include "Gray.h"
#include "mySetFunc.h"
#include "menu.h"
#include "MyMultiSet.h"

using namespace std;

void cleaner(vector<MyMultiSet>& multiSets) {
	for (int i = 0; i < multiSets.size(); i++) {
		for (int j = 0; j < multiSets[i].MultiSet.size(); j++) {
			if (multiSets[i].MultiSet[j].second == 0) {
				multiSets[i].MultiSet.erase(multiSets[i].MultiSet.begin() + j);
			}
		}
		
	}
}


int main() {
	int n = 3;

	MyMultiSet U;

	vector<MyMultiSet>multiSets(3);
	bool flag_stop = true;
	bool newU = false;
	while (flag_stop) {

		print_menu(U.MultiSet.empty(), multiSets[1].MultiSet.empty());
		switch (get_option(U.MultiSet.empty(), multiSets[1].MultiSet.empty())) {
		case 0: {
			printf_s("Good bye!\n");
			flag_stop = false;

			system("pause");
			break;
		}
		case 1: {
			printf_s("Put N of Universum.\n");
			int n = get_sizeN();
			U.MultiSet.clear();
			create_universum(n, U);
			printf_s("Universum for %d was created\n", n);
			if (!newU) {
				newU = true;
			}
			else {
				for (int i = 0; i < multiSets.size(); i++) {
					multiSets[i].MultiSet.resize(0);
				}
				printf_s("You need to create your Multisets again :(\n");
			}
			system("pause");
			break;
		}
		case 2: {
			printf_s("Your universum:\n");
			outMS(U);
			system("pause");
			break;
		}
		case 3: {
			for (int i = 1; i < multiSets.size(); i++) {
				printf_s("Now is %d :\n", i);
				createMst(multiSets[i], U);
			}
			for (int i = 1; i < multiSets.size(); i++) {
				printf_s("Your %d:\n", i);
				outMS(multiSets[i]);
			}
			system("pause");
			break;
		}
		case 4: {
			int n1 = 1, n2 = 2;
			multiSets[0] = unionOfMst(multiSets[n1], multiSets[n2]);
			outMS(multiSets[0]);
			system("pause");
			break;
		}
		case 5: {
			int n1 = 1, n2 = 2;
			multiSets[0] = intersectionOfMst(multiSets[n1], multiSets[n2]);
			outMS(multiSets[0]);
			system("pause");
			break;
		}
		case 6: {

			printf_s("Put Number of Multiset. (Now you can choose: from 1 to %d)\n", multiSets.size() - 1);
			int n = get_sizeN(2, 1);

			multiSets[0] = complementOfMst(multiSets[n], U);
			outMS(multiSets[0]);
			system("pause");
			break;
		}
		case 7: {
			int n1 = 1, n2 = 2;

			multiSets[0] = differenceOfMst(multiSets[n1], multiSets[n2], U);
			outMS(multiSets[0]);
			system("pause");
			break;
		}
		case 8: {
			int n1 = 1, n2 = 2;

			multiSets[0] = symmetricDiffOfMst(multiSets[n1], multiSets[n2], U);
			outMS(multiSets[0]);
			system("pause");
			break;
		}
		case 9: {
			int n1 = 1, n2 = 2;
			multiSets[0] = ariphSumOfMst(multiSets[n1], multiSets[n2], U);
			outMS(multiSets[0]);
			system("pause");
			break;
		}
		case 10: {
			int n1 = 1, n2 = 2;
			multiSets[0] = ariphDiffOfMst(multiSets[n1], multiSets[n2], U);
			outMS(multiSets[0]);
			system("pause");
			break;
		}
		case 11: {
			int n1 = 1, n2 = 2;
			multiSets[0] = ariphMultiplyOfMst(multiSets[n1], multiSets[n2], U);
			outMS(multiSets[0]);
			system("pause");
			break;
		}
		case 12: {
			int n1 = 1, n2 = 2;
			multiSets[0] = directMultiplyOfMst(multiSets[n1], multiSets[n2], U);
			outMS(multiSets[0]);
			system("pause");
			break;
		}
		case 13: {
			if (!multiSets.empty()) {
				printf_s("Your last operation is: \n");
				outMS(multiSets[0]);
			}
			for (int i = 1; i < multiSets.size(); i++) {
				printf_s("Your %d multiset is: \n",i);
				outMS(multiSets[i]);
			}

			system("pause");
			break;
		}
		}
		cleaner(multiSets);
	}


	return 0;
}