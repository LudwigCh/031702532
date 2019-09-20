#pragma once
#ifndef _READ_H_
#define _READ_H_
#include<string>
using namespace std;
class Read {
public:
	void read_judge(int argc,char* argv[]);
	void read_init(int dimension, int num,string file_in);
	void DFS(int n);
	bool Check(int m, int key);
	int dimension;
	void equal(int dimen);
	void output();
	int temp[9][9];
};
#endif

