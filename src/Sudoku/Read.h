#pragma once
#ifndef _READ_H_
#define _READ_H_
#include<string>
using namespace std;
class Read {
public:
	void read_judge(int argc,char* argv[]);
	void DFS(int n);
	bool Check(int m, int key);
	void input(int dimension, int num, string file_in);
	void equal(int dimension);
	void output(string file_out,int num);
	void add();

	int count = 0;
	int dimen;
	int temp[100][9][9];
};
#endif

