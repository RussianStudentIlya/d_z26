#include "sum_of_array_elements.h"

void sum_of_array_elements::calc_sum_part_vector(int start_index, int stop_index)
{
    int result = 0;

    for (start_index; start_index <= stop_index; start_index++)
        result += _listElements[start_index];
    
    _listSumElements.push_back(result);
}

sum_of_array_elements::sum_of_array_elements(const int& sizeElementsList, const int& numberThreads): _sizeElementsList(sizeElementsList), _numberThreads(numberThreads)
{
	srand(time(NULL));
	int countElements = 0; //ко-во элементов в каждом потоке

    countElements = _sizeElementsList / _numberThreads;

    for (size_t i = 0; i < _sizeElementsList; ++i)
    {
        _listElements.push_back(rand() % _sizeElementsList);
    }
}

vector<int> sum_of_array_elements::sum_elements_vector_using_Threads()
{
    vector<thread> _list_Thread; // список потоков
    int start_index = 0; //начальное значение интервала потока
    int stop_index = 0; //конечное значение интервала потока
    int elements_count = _sizeElementsList / _numberThreads;

    for (int i = 0; i < _numberThreads; i++)
    {
        if (i == _numberThreads - 1)
            start_index = _listElements.size();
        else
            start_index += elements_count;

        /*---«апуск потоков и помещение в вектор*/
        _list_Thread.push_back(move(thread(&sum_of_array_elements::calc_sum_part_vector, this, stop_index, start_index - 1)));

        stop_index += elements_count;
    }

    for (auto& t : _list_Thread)
    {
        if (t.joinable())
            t.join();
    }

    return _listSumElements;
}

void sum_of_array_elements::get_sum_all_elements_vector(vector<int> sum_elements)
{
    int sum_element_vector = 0;

    cout << "—умму всех частей массива: ";

    for (int i = 0; i < sum_elements.size(); i++)
    {
        cout << sum_elements[i];

        sum_element_vector += sum_elements[i];

        if ((i + 1) != sum_elements.size())
            cout << " + ";
    }

    cout << " = " << sum_element_vector << endl;
}
