#pragma once
#ifndef _READ_H_
#define _READ_H_
#include<string>
using namespace std;
class Read {
public:
	void read_judge(int argc,char* argv[]);
	void read_init(int dimension, int num,string file_in);
private:
	string file_name = "input.txt";
};
#endif

