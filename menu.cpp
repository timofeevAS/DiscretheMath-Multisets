#include "stdafx.h"
#include "menu.h"
#include "mySetFunc.h"
void outS(vector<string>& vec, bool flag) {
	if (flag) {
		return;
	}
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << '\n';
	}
	cout << '\n';
}

void outMS(MyMultiSet &A) {
	if (isMstEmpt(A)) {
		printf_s("empty\n");
		return;
	}
	for (int i = 0; i < A.MultiSet.size(); i++) {
		cout << A.MultiSet[i].first << '^' <<A.MultiSet[i].second << '\n';
	}
	cout << '\n';
}

void print_menu(bool flag, bool flagAB) {
	system("cls");
	printf_s("Multisets operation testing is welcoming you!\n");
	printf_s("1. Create Universum N by Gray's Code || Old U. will be erase.\n");
	if (!flag)
	{
		printf_s("2. Output your Universum.\n");
		printf_s("3. Create two multisets.\n");
		if (!flagAB) {
			printf_s("4. Union two multisets. [+]\n");
			printf_s("5. Intersection two multisets. [*]\n");
			printf_s("6. Complement of your multiset. [~]\n");
			printf_s("7. Difference of your multisets. [\\]\n");
			printf_s("8. Symmetric Difference of your multisets. [/\\]\n");
			printf_s("9. Ariphmetical sum of ypur multisets.\n");
			printf_s("10. Ariphmetical difference of your multisets.\n");
			printf_s("11. Ariphmetical multiply of your multisets.\n");
			printf_s("12. Direct multiply of your multisets.\n");
			printf_s("13. Output your Multisets.\n");
		}
	}
	printf_s("0. Exit :(\n");
	fflush(stdin);
}

int get_option(bool flag1,bool flag2)
{	
	int right = 1;
	if (!flag1) {
		right = 3;
	}
	if (!flag2) {
		right = 13;
	}
	int variable;
	char s[10]={0};
	scanf_s("%9s", s, (unsigned)sizeof(s));
	while (sscanf_s(s, "%d", &variable) != 1 || variable < 0 || variable > right) {
		printf_s("Incorrect operation. Write from 0 to %d.\n",right);
		scanf_s("%s", s, (unsigned)sizeof(s));
	}
	fflush(stdin);
	return variable;
}

int get_sizeN(int n,int left)
{
	
	int variable;
	char s[10]={0};
	scanf_s("%9s", s, (unsigned)sizeof(s));
	while (sscanf_s(s, "%d", &variable)!= 1 || variable < left || variable > n) {
		printf_s("Incorrect parametr size. Write from %d to %d.\n",left,n);
		scanf_s("%s", s, (unsigned)sizeof(s));
	}
	fflush(stdin);
	return variable;
}

int choose_option()
{
	int variable;
	char s[10]={0};
	scanf_s("%9s", s, (unsigned)sizeof(s));
	while (sscanf_s(s, "%d", &variable) != 1 || variable < 0 || variable > 1) {
		printf_s("Incorrect parametr of mode. Write 1 for auto, 0 for manual.\n");
		scanf_s("%s", s, (unsigned)sizeof(s));
	}
	fflush(stdin);
	return variable;
}
