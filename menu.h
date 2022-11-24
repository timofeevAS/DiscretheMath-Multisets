#pragma once
#include "MyMultiSet.h"
void print_menu(bool flag,bool flagAB);
int get_option(bool flag1,bool flag2);
int get_sizeN(int n=6,int left = 0);
int choose_option();
void outS(vector<string>& vec, bool flag=false);
void outMS(MyMultiSet& A);