#include <Windows.h>
#include <conio.h>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

template<template <typename> class P = std::less >
struct sortMapByValue {
	template<class T1, class T2> bool operator()(const std::pair<T1, T2>&left, const std::pair<T1, T2>&right) {
		return P<T2>()(left.second, right.second);
	}
};

void main()
{
	map<char, DWORD> my_map;
	my_map['A'] = 200;
	my_map['B'] = 100;
	my_map['C'] = 300;
	my_map['D'] = 120;

	vector<pair<char, DWORD>> my_vector(my_map.begin(), my_map.end());
	
	cout << "Before" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << my_vector[i].first << " : " << my_vector[i].second << endl;
	}

	sort(my_vector.begin(), my_vector.end(), sortMapByValue<less>());

	cout << "After" << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << my_vector[i].first << " : " <<  my_vector[i].second << endl;
	}
	getch();
}
