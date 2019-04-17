#ifndef __DCT_H__
#define __DCT_H__
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

vector<int> readFile(std::string filename);
void writeFile(vector<double> output);
double __calcC_DCT(double u);
vector<double> DCT(const vector<int> &intVec);
vector<double> IDCT(const vector<double> DCT);
vector<double> Diff(vector<double> original, const vector<double> IDCT);

#endif