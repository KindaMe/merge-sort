#include <iostream>
#include <vector>

std::vector<int> mergeSort(std::vector<int> array);
std::vector<int> merge(std::vector<int> left, std::vector<int> right);

void printArray(std::vector<int> array);

int main()
{
	std::vector<int> data = { 38,27,43,3,9,82,10 };

	std::cout << "Unsorted array: \n";
	printArray(data);

	data = mergeSort(data);

	std::cout << "Sorted array in ascending order: \n";
	printArray(data);
}

std::vector<int> mergeSort(std::vector<int> array)
{
	std::vector<int> left;
	std::vector<int> right;

	if (array.size() == 1)
	{
		return array;
	}
	else
	{
		for (int i = 0; i < array.size(); i++)
		{
			if (i < array.size() / 2)
			{
				left.push_back(array[i]);
			}
			else
			{
				right.push_back(array[i]);
			}
		}

		return merge(mergeSort(left), mergeSort(right));
	}
}

std::vector<int> merge(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> temp;

	while (left.empty() != true && right.empty() != true)
	{
		if (left[0] < right[0])
		{
			temp.push_back(left[0]);
			left.erase(left.begin());
		}
		else
		{
			temp.push_back(right[0]);
			right.erase(right.begin());
		}
	}
	while (left.empty() != true)
	{
		temp.push_back(left[0]);
		left.erase(left.begin());
	}
	while (right.empty() != true)
	{
		temp.push_back(right[0]);
		right.erase(right.begin());
	}

	return temp;
}

void printArray(std::vector<int> array)
{
	for (int i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}