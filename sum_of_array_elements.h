#pragma once
#include <vector>
#include <iostream>
#include <thread>
#include <ctime>
#include <algorithm>
using namespace std;

class sum_of_array_elements
{
private:
	int _sizeElementsList; // ��-�� ��������� � ������
	int _numberThreads; //���������� �������

	vector<int> _listElements; // ������ ���������
	vector<int> _listSumElements; // ����� ��������� �������� ������� ������������ �� ������

	void calc_sum_part_vector(int start_index, int stop_index); // ���������� ����� ��������� �������

public:
	sum_of_array_elements(const int& sizeElementsList, const int& numberThreads);
	~sum_of_array_elements() = default;

	vector<int> sum_elements_vector_using_Threads(); // ���������� ����� ��������� ������� � ������

	void get_sum_all_elements_vector(vector<int> sum_elements); //����� ��������� ������� 

};

