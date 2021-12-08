#ifndef THAT_WAY_H_INC
#define THAT_WAY_H_INC
#include <iostream>

//bubble sort
template <typename T>
void BubbleSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

//swap function for bubble sort
template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

//display function for arrays
template <typename T>
void display(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << " " << arr[i];
    }
}
#endif
