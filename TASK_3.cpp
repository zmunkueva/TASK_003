#include "pch.h"
#include "Arraystat.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ArrayStat a;
	a.readf();
	a.arraystat();
	a.print();
	int max_ = a.get_max();
	cout << "max = " << max_ << endl;
	int min_ = a.get_min();
	cout << "min = " << min_ << endl;
	double mean_ = a.mean();
	cout << "mean = " << mean_ << endl;
	double rms_ = a.rms();
	cout << " rms = " << rms_ << endl;
	
}