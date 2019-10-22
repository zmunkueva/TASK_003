#include "pch.h"
#include "Arraystat.h"
#include <iostream>
#include <fstream>
#include <algorithm> //sort
#include <cmath>
#include <numeric>
#include <iterator>

using namespace std;

ArrayStat::ArrayStat() {
	max = min = a = 0;
	m_mean = m_rms = 0.;
}
ArrayStat::ArrayStat(int max, int min, int a, double m_mean, double m_rms) :
	max(max), min(min), a(a), m_mean(m_mean), m_rms(m_rms) {}

void ArrayStat::arraystat() {
	int N = v.size();
	max = v.back();
	min = v.front();
	m_mean = accumulate(v.begin(), v.end(), 0.) / v.size();

	vector <int> squares(v.size());
	auto squarer = [](int a) { return a * a; };
	transform(v.begin(), v.end(), squares.begin(), squarer);

	double mean_sq = accumulate(squares.begin(), squares.end(), 0.) / squares.size();
	m_rms = sqrt(mean_sq - m_mean * m_mean);
}

void ArrayStat::readf()
{
	v.clear();
	fstream file("filename.txt");
	if (!file.good()) {
		cout << "cannot open a file" << endl;
		exit(1);
	}
	else {
		copy(istream_iterator<int>(file), istream_iterator<int>(), back_inserter(v)); //добавление элемента
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
		sort(v.begin(), v.end());
	}
}
void ArrayStat::print() const
{
	cout << "the length is " << v.size() << endl;
	for (auto const &value : v)
	{
		cout << value << ' ';
	}
}