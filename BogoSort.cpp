/* Created by Doug Wagner
 * 5/26/2015
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

#define SIZE 10 //array size

/* Function Declarations */
void shuffle(int[], int);
void swap(int*, int*);
bool isSorted(int[], int);
void printarray(int[], int);

int main()
{
	int nums[SIZE];
	long long count = 0;
	srand(time(NULL));
	/* Randomly generate values into array */
	for (int i = 0; i < SIZE; i++)
		nums[i] = rand() % 100 + 1;
	printarray(nums, SIZE);
	/* Start timer */
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	/* Begin Bogosort */
	while (!isSorted(nums, SIZE))
	{
		shuffle(nums, SIZE);
		count++;
	}
	/* End timer */
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	printarray(nums, SIZE);
	std::cout << std::endl;
	std::chrono::duration<double> runtime = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
	/* Display Results */
	std::cout << runtime.count() << " seconds" << std::endl;
	std::cout << count << " loops" << std::endl;
}

void shuffle(int numarray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		/* Two different shuffling methods. Uncomment one and comment the other to switch.
		 * There is not really any significant performance boost from either one because of
		 * the randomness of this algorithm.
		 */
		int j = i + (rand() % (size - i));
//		int j = rand() % size;
		if (i != j)
			swap(&numarray[i], &numarray[j]);
	}
}
void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
bool isSorted(int numarray[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (numarray[i] > numarray[i + 1])
			return false;
	}
	return true;
}
void printarray(int numarray[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << numarray[i] << ", ";
	std::cout << std::endl;
}
