// YOUR NAME HERE

#include "permutations.h"
#include "randint.h"
#include <cstddef>

// A sequential search function, for your convenience.
// Parameters:
//  array - The array of int's to be searched
//  size - The size of the array
//  target - The target value
// Returns:
//  Array index where target is found, or size if target is not found.
// Example:
//  if (search(array, size, x) < size)
//      cout << "x was found in the array\n";
//  else
//      cout << "x was not found in the array\n";
static size_t search(const int array[], size_t size, int target)
{
    for (size_t i = 0; i < size; i++)
        if (array[i] == target)
            return i;
    return size;
}

void permutations1(int array[], size_t size)
{
    int x, loc;
    for (int i = 0; i < size; i++)
    {
        do
        {
            x = randint(size)+1;
            loc = search(array, size, x);
        } while (loc < size-1);
        array[i] = x;
    }
}

void permutations2(int array[], size_t size)
{
    int ran;
    bool *used = new bool[size]();
    for (int i = 0; i < size; i++)
    {
        do
        {
            ran = randint(size)+1;

        } while (used[ran - 1] == 1);
        array[i] = ran;
        used[ran - 1] = 1;
    }
    delete[] used;
}
void permutations3(int array[], size_t size)
{
    int j, swap;
    for (int i = 0; i < size; i++)
    {
        array[i] = i + 1;
    }
    for (int i = 0; i < size; i++)
    {
        j = randint(size)+1;
        swap = array[i];
        array[i] = array[j];
        array[j] = swap;
    }
}
