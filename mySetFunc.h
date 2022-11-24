#pragma once
#include "stdafx.h"
#include "MyMultiSet.h"

void createMstAuto(MyMultiSet &A, MyMultiSet &U);
void createMstManual(MyMultiSet& A, MyMultiSet& U);
void createMst(MyMultiSet& A, MyMultiSet& U);
MyMultiSet unionOfMst(MyMultiSet A, MyMultiSet B);
MyMultiSet intersectionOfMst(MyMultiSet& A, MyMultiSet& B);
MyMultiSet complementOfMst(MyMultiSet& A, MyMultiSet& U);
MyMultiSet differenceOfMst(MyMultiSet& A, MyMultiSet& B, MyMultiSet& U);
MyMultiSet symmetricDiffOfMst(MyMultiSet& A, MyMultiSet& B, MyMultiSet& U);
MyMultiSet ariphSumOfMst(MyMultiSet A, MyMultiSet B,MyMultiSet&U);
MyMultiSet ariphDiffOfMst(MyMultiSet A, MyMultiSet B, MyMultiSet& U);
MyMultiSet ariphMultiplyOfMst(MyMultiSet A, MyMultiSet B, MyMultiSet& U);
MyMultiSet directMultiplyOfMst(MyMultiSet A, MyMultiSet B, MyMultiSet& U);
bool isMstEmpt(MyMultiSet& A);