#include "mySetFunc.h"
#include "stdafx.h"
#include "menu.h"

void createMstAuto(MyMultiSet& A, MyMultiSet& U) {
	srand(unsigned int(time(0)));
	// если а-левая граница, b-правая, то:
	//rand() % (b - a + 1) + a;
	vector<bool>flags(U.MultiSet.size(), false);
	int i = 0;
	while (i < A.MultiSet.size()) {
		int rand_idx = rand() % (U.MultiSet.size());
		if (!flags[rand_idx]) {
			A.MultiSet[i].first = U.MultiSet[rand_idx].first;
			A.MultiSet[i].second = rand() % U.MultiSet[rand_idx].second +1;
			flags[rand_idx] = true;
			i++;
		}
		
	}
}

void createMstManual(MyMultiSet& A, MyMultiSet& U)
{

	vector<bool>flags(U.MultiSet.size(), false);
	for (int i = 0; i < A.MultiSet.size(); i++) {
		system("cls");
		for (int i = 0; i < U.MultiSet.size(); i++) {
			if (!flags[i]) {
				cout << "[-] ";
			}
			else {
				cout << "[+] ";
			}
			cout << i << "-> " << U.MultiSet[i].first << '\n';
		}
		printf_s("For index: %d\n", i);
		bool checker = true;

		printf_s("Print index of element from Universum above:\n");
		int n = get_sizeN(U.MultiSet.size() - 1);

		while (flags[n]) {
			printf_s("You have already used this element!\n");
			n = get_sizeN(U.MultiSet.size() - 1);
		}
		A.MultiSet[i].first = U.MultiSet[n].first;
		flags[n] = true;
		printf_s("Print count of element from 1 to %d:\n", U.MultiSet[i].second);
		n = get_sizeN(U.MultiSet[i].second,1);
		A.MultiSet[i].second = n;
		
	}
	system("cls");
}

void createMst(MyMultiSet& A, MyMultiSet& U) {
	printf_s("Type power of multiset:\n");
	int n;
	if (U.MultiSet.size() == 1 && U.MultiSet[0].first == "empty") {
		n = get_sizeN(0);
	}
	else {
		n = get_sizeN(U.MultiSet.size());
	}
	A.MultiSet.clear();
	A.MultiSet.resize(n);

	if (A.MultiSet.empty()) {
		printf_s("You create empty MultiSet.\n");
		A.MultiSet.resize(1);
		A.MultiSet[0].first = "empty";
		A.MultiSet[0].second = 1;
		return;
	}

	printf_s("Choose mode of creating Multiset. (0 to auto. 1 to manual).\n");
	int mode = choose_option();



	if (mode == 0) {
		createMstAuto(A, U);
	}
	else {
		createMstManual(A, U);
	}
	sort(A.MultiSet.begin(), A.MultiSet.end());
}

MyMultiSet unionOfMst(MyMultiSet A, MyMultiSet B)
{
	
	if (isMstEmpt(A)) {
		return B;
	}
	if (isMstEmpt(B)) {
		return A;
	}
	MyMultiSet C;
	int i = 0;
	for (int i = 0; i < A.MultiSet.size(); i++) {
		bool myflag = false;
		for (int j = 0; j < B.MultiSet.size(); j++) {
			if (A.MultiSet[i].first == B.MultiSet[j].first) {
				myflag = true;

				C.MultiSet.push_back(make_pair(A.MultiSet[i].first, max(A.MultiSet[i].second, B.MultiSet[j].second)));
				B.MultiSet[j].first = "empty";
				break;
			}
		}
		if (!myflag) {
			C.MultiSet.push_back(A.MultiSet[i]);
		}
	}
	while (i < B.MultiSet.size()) {
		if (B.MultiSet[i].first != "empty") {
			C.MultiSet.push_back(B.MultiSet[i]);
		}
		i++;
	}
	return C;

}

MyMultiSet intersectionOfMst(MyMultiSet& A, MyMultiSet& B)
{
	if (isMstEmpt(A)) {
		return A;
	}
	if (isMstEmpt(B)) {
		return B;
	}
	MyMultiSet C;
	for (int i = 0; i < A.MultiSet.size(); i++) {
		for (int j = 0; j < B.MultiSet.size(); j++) {
			if (A.MultiSet[i].first == B.MultiSet[j].first) {
				C.MultiSet.push_back(make_pair(A.MultiSet[i].first, min(A.MultiSet[i].second, B.MultiSet[j].second)));
			}
		}
	}
	if (C.MultiSet.empty())C.MultiSet.push_back(make_pair("empty", 1));
	return C;
}

bool isMstEmpt(MyMultiSet& A)
{
	return (A.MultiSet.size() == 1 && A.MultiSet[0].first == "empty");
}

MyMultiSet complementOfMst(MyMultiSet& A,MyMultiSet &U)
{
	if (isMstEmpt(A)) {
		return U;
	}
	if (isMstEmpt(U)) {
		return U; //???
	}
	MyMultiSet C;
	for (int i = 0; i < U.MultiSet.size(); i++) {
		bool flag = false;
		for (int j = 0; j < A.MultiSet.size(); j++) {
			if (U.MultiSet[i].first == A.MultiSet[j].first) {
				C.MultiSet.push_back(make_pair(U.MultiSet[i].first, U.MultiSet[i].second - A.MultiSet[j].second));
				flag = true;
				break;
			}
		}
		if (!flag) {
			C.MultiSet.push_back(U.MultiSet[i]);
		}
	}
	return C;
}

MyMultiSet differenceOfMst(MyMultiSet& A, MyMultiSet& B,MyMultiSet& U)
{
	MyMultiSet C = complementOfMst(B, U);
	return intersectionOfMst(A, C);
}

MyMultiSet symmetricDiffOfMst(MyMultiSet& A, MyMultiSet& B, MyMultiSet& U)
{
	if (isMstEmpt(A)) {
		return B;
	}
	if (isMstEmpt(B)) {
		return A;
	}
	MyMultiSet C;
	for (int i = 0; i < A.MultiSet.size(); i++) {
		for (int j = 0; j < B.MultiSet.size(); j++) {
			if (A.MultiSet[i].first == B.MultiSet[j].first) {
				if (abs(A.MultiSet[i].second - B.MultiSet[j].second) == 0)continue;
				C.MultiSet.push_back(make_pair(A.MultiSet[i].first, abs(A.MultiSet[i].second - B.MultiSet[j].second)));
			}
		}
	}
	
	if (C.MultiSet.empty())C.MultiSet.push_back(make_pair("empty", 1));
	return C;
}
//C.MultiSet.push_back(make_pair(A.MultiSet[i].first, min((A.MultiSet[i].second + B.MultiSet[j].second),U.MultiSet[i].second)));
MyMultiSet ariphSumOfMst(MyMultiSet A, MyMultiSet B,MyMultiSet&U)
{
	if (isMstEmpt(A)) {
		return B;
	}
	if (isMstEmpt(B)) {
		return A;
	}
	MyMultiSet C;
	int i = 0;
	for (int i = 0; i < A.MultiSet.size(); i++) {
		bool myflag = false;
		for (int j = 0; j < B.MultiSet.size(); j++) {
			if (A.MultiSet[i].first == B.MultiSet[j].first) {
				myflag = true;

				C.MultiSet.push_back(make_pair(A.MultiSet[i].first, min((A.MultiSet[i].second + B.MultiSet[j].second), U.MultiSet[i].second)));
				B.MultiSet[j].first = "empty";
				break;
			}
		}
		if (!myflag) {
			C.MultiSet.push_back(A.MultiSet[i]);
		}
	}
	while (i < B.MultiSet.size()) {
		if (B.MultiSet[i].first != "empty") {
			C.MultiSet.push_back(B.MultiSet[i]);
		}
		i++;
	}
	return C;
}

MyMultiSet ariphDiffOfMst(MyMultiSet A, MyMultiSet B, MyMultiSet& U)
{
	if (isMstEmpt(A)) {
		return B;
	}
	if (isMstEmpt(B)) {
		return A;
	}
	MyMultiSet C;
	int i = 0;
	for (int i = 0; i < A.MultiSet.size(); i++) {
		bool myflag = false;
		for (int j = 0; j < B.MultiSet.size(); j++) {
			if (A.MultiSet[i].first == B.MultiSet[j].first) {
				myflag = true;

				C.MultiSet.push_back(make_pair(A.MultiSet[i].first, max((A.MultiSet[i].second - B.MultiSet[j].second), 0)));
				B.MultiSet[j].first = "empty";
				break;
			}
		}
		if (!myflag) {
			C.MultiSet.push_back(A.MultiSet[i]);
		}
	}
	while (i < B.MultiSet.size()) {
		if (B.MultiSet[i].first != "empty") {
			C.MultiSet.push_back(B.MultiSet[i]);
		}
		i++;
	}
	return C;
}

MyMultiSet ariphMultiplyOfMst(MyMultiSet A, MyMultiSet B, MyMultiSet& U)
{
	if (isMstEmpt(A)) {
		return B;
	}
	if (isMstEmpt(B)) {
		return A;
	}
	MyMultiSet C;
	int i = 0;
	for (int i = 0; i < A.MultiSet.size(); i++) {
		bool myflag = false;
		for (int j = 0; j < B.MultiSet.size(); j++) {
			if (A.MultiSet[i].first == B.MultiSet[j].first) {
				myflag = true;

				C.MultiSet.push_back(make_pair(A.MultiSet[i].first, min((A.MultiSet[i].second * B.MultiSet[j].second), U.MultiSet[i].second)));
				B.MultiSet[j].first = "empty";
				break;
			}
		}
		if (!myflag) {
			C.MultiSet.push_back(A.MultiSet[i]);
		}
	}
	while (i < B.MultiSet.size()) {
		if (B.MultiSet[i].first != "empty") {
			C.MultiSet.push_back(B.MultiSet[i]);
		}
		i++;
	}
	return C;
}

MyMultiSet directMultiplyOfMst(MyMultiSet A, MyMultiSet B, MyMultiSet& U)
{
	if (isMstEmpt(A)) {
		return A;
	}
	if (isMstEmpt(B)) {
		return B;
	}
	MyMultiSet C;
	for (int i = 0; i < A.MultiSet.size(); i++) {
		for (int j = 0; j < B.MultiSet.size(); j++) {
			C.MultiSet.push_back(make_pair(A.MultiSet[i].first+"," + B.MultiSet[j].first, min(A.MultiSet[i].second ,B.MultiSet[j].second)));
		}
	}
	if (C.MultiSet.empty())C.MultiSet.push_back(make_pair("empty", 1));
	return C;
}