#include <iostream>

int CountOfNumbersInRange(int* arr, int min, int max, int size)
{
    int count = 0;
    for(int i = 0; i < size; i++)
        if ((min <= arr[i]) && (arr[i] <= max)) count++;
    return count;
}

int main(int argc, char** argv)
{
    int arr[] = { 5, 6, 9, 4, 4, 2, 2, 9, 5, 3, 4, 0, 1, 8, 5, 3, 8, 7 };
    int size = 18;
    int min = 2;
    int max = 7;
    int output = CountOfNumbersInRange(arr, min, max, size);
    std::cout << "Input: ";
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i < size - 1) std::cout << ",";
        else std::cout << std::endl;
    }
    std::cout << "Numbers between range " << min << " and " << max << ": " << output << std::endl;
    return 0;
}
