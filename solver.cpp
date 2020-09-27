// #pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "utils.h"
#include "mTree.h"
#include "mList.h"
#include "mVector.h"
#include "mString.h"
#include "Solution.h"
using namespace std;

// 循环读取直到遇到非空行
fstream &mGetLine(fstream &f, string &in)
{
	while (getline(f, in))
	{
		if (!in.empty())
		{
			break;
		}
	}
	return f;
}

int main()
{
	Solution solu;
	fstream f("input.txt", ios::in);
	clock_t time_start;
	clock_t time_end;
	string in1;

	while (mGetLine(f, in1))
	{
		cout << in1 << endl;
		// 读取第二行
		string in2;
		if (!mGetLine(f, in2))
		{
			break;
		}
		cout << in2 << endl;

		string str1 = buildString(in1);
		int n = parseInt(in2);

		cout << "--result--" << endl;
		time_start = clock();
		// 执行操作

		cout << solu.convert(str1, n);

		cout << endl;
		//结束
		time_end = clock();
		cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;
		cout << endl;
	}

	return 0;
}
