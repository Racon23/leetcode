// #pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "utils.h"
#include "mTree.h"
#include "mList.h"
#include "mVector.h"
#include "Solution.h"
using namespace std;

// ѭ����ȡֱ�������ǿ���
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
		// ��ȡ�ڶ���
		string in2;
		if (!mGetLine(f, in2))
		{
			break;
		}
		cout << in2 << endl;

		time_start = clock();
		// ִ�в���
		vector<int> vec1 = buildVector(in1);
		vector<int> vec2 = buildVector(in2);
		cout<<solu.findMedianSortedArrays(vec1,vec2);

		cout<<endl;
		//����
		time_end = clock();
		cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;
		cout << endl;
	}

	return 0;
}
