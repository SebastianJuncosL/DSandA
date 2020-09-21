#include <iostream>
using namespace std;

template <typename T>
void displayArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
            std::cout << arr[i] << std::endl;
        else
            std::cout << arr[i] << ", ";
    }
    std::cout << "" << std::endl;
}

template <typename T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T>
void bubbleSort(T arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

template <typename T>
void selectionSort(T arr[], int size)
{
    int small;
    for (int i = 0; i < size - 1; i++)
    {
        small = i;
        for (int j = 1 + i; j < size; j++)
        {
            if (arr[j] < arr[small])
                small = j;
        }
        swap(arr[i], arr[small]);
    }
}

int main(int argc, const char **argv)
{
    int arr[] = {2, 10, 6, 5, 8, 9, 1, 3, 7};
    int size = 9;
    displayArray(arr, size);
    selectionSort<int>(arr, size);
    displayArray(arr, size);
    return 0;
}
