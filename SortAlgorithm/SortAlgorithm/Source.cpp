#include <iostream>
#include <vector>
using namespace std;


void insertSort(vector<int>& list)// Done and good 
{
	int sort, unSorted, key;

	for (sort = 1; sort < list.size(); sort++)
	{
		key = list.at(sort);
		unSorted = sort - 1;
		while (unSorted >= 0 && list.at(unSorted) > key)
		{
			list.at(unSorted + 1) = list.at(unSorted);
			unSorted = unSorted - 1;
		}
		list.at(unSorted + 1) = key;
	}


}

void selectionSort(vector<int>& list)//Done 
{
	int i, j, min;
	for (i = 0; i < list.size() - 1; i++)
	{
		min = i;
		for (j = i + 1; j < list.size(); j++)
		{
			if (list.at(j) < list.at(min))
			{
				min = j;
			}
		}
		int temp = list.at(i);
		list.at(i) = list.at(min);
		list.at(min) = temp;
	}
}

int partition(vector<int>& list, int start, int end)// GOOD
{
	int midpoint = start + (end - start) / 2;
	int lowIter = start;
	int highIter= end;
	bool done =false;
	int pivot = list.at(midpoint);

	while (!done)
	{
		while (list.at(lowIter) < pivot)
		{
			++lowIter;
		}
		while (list.at(highIter) > pivot)
		{
			--highIter;
		}
		if (lowIter >= highIter)
		{
			done = true;
		}
		else
		{
			int temp = list.at(lowIter);
			list.at(lowIter) = list.at(highIter);
			list.at(highIter) = temp;	
			++lowIter;
			--highIter;
		}
	}
	return highIter;
}
void quickSort(vector<int>& list, int start, int end)// Good
{
	int midstart;

	if (start >= end)
	{
		return;
	}

	midstart = partition(list, start, end);

	quickSort(list, start, midstart);
	quickSort(list, midstart + 1, end);
}

template <typename T>
void Merge(vector<T>& leftHalf, vector<T>& rightHalf, vector<T>& splits)
{
	int newLeft = leftHalf.size();
	int newRight = rightHalf.size();
	int iteratorLeft = 0;
	int iteratorMid = 0;
	int iteratorRight = 0;

	while (iteratorMid < newLeft && iteratorRight < newRight) //Based off the one in zybooks
	{
		if (leftHalf.at(iteratorMid) < rightHalf.at(iteratorRight))
		{
			splits.at(iteratorLeft) = leftHalf.at(iteratorMid);
			iteratorMid++;
		}
		else
		{
			splits.at(iteratorLeft) = rightHalf.at(iteratorRight);
			iteratorRight++;
		}
		iteratorLeft++;
	}

	while (iteratorMid < newLeft)//check if left half is empty
	{
		splits.at(iteratorLeft) = leftHalf.at(iteratorMid);
		iteratorMid++;
		iteratorLeft++;
	}

	while (iteratorRight < newRight)//check if right half is empty
	{
		splits.at(iteratorLeft) = rightHalf.at(iteratorRight);
		iteratorRight++;
		iteratorLeft++;
	}
}

template <typename T>
vector<T> MergeSort(vector<T>& items) // Make it recurse as planned or it will not work 
{
	if (items.size() <= 1)
	{
		return items;
	}

	int mid = items.size() / 2;
	vector<int> left;
	vector<int> right;
	vector<T> sortedVec;

	for (int leftIter = 0; leftIter < mid; leftIter++) //Fill the left 
	{
		left.push_back(items.at(leftIter));
	}

	for (int rightIter = 0; rightIter < items.size() - mid; rightIter++) //Fill the right 
	{
		right.push_back(items.at(mid + rightIter));
	}

	MergeSort(left);
	MergeSort(right);
	Merge(left, right, items);

	return items;

}


int main()
{

	vector<int> list{5,4,9,7,8,2,3,34,56,1,2,6,9};
	int begin = 0;
	int end = list.size() - 1;
	//insertSort(list);
	//selectionSort(list);
	//quickSort(list,begin,end);
	//MergeSort(list);

	for (int i = 0; i < list.size(); i++)
	{
		cout << list.at(i) << '\n';
	}


	return 0;
}


// All my sorting algoritms 