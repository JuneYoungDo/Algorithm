#include<iostream>
#include<vector>
using namespace std;

class Minheap
{
private:
	vector<int> data;
	int heapsize;
	int rootindex;
public:
	Minheap()
	{
		data.push_back(-1);
		heapsize = 0;
		rootindex = 1;
	}

	void swap(vector<int>& arr, int num, int num2)
	{
		int tmp = arr[num];
		arr[num] = arr[num2];
		arr[num2] = tmp;
	}

	int empty()
	{
		if (heapsize == 0)
			return 1;
		else
			return 0;
	}

	void insert(int input)
	{
		data.push_back(input);
		heapsize++;

		int index = heapsize;
		while (index > rootindex)
		{
			if (abs(data[index]) < abs(data[index / 2]))
			{
				swap(data, index, index / 2);
			}
			else if (abs(data[index]) == abs(data[index / 2]))
			{
				if (data[index] < data[index / 2])
					swap(data, index, index / 2);
				else
					break;
			}
			else
				break;
			index = index / 2;
		}
	}
	void remove()
	{
		if (empty() != 1)
		{
			data[1] = data[heapsize];
			data.pop_back();
			heapsize--;

			int index = rootindex;
			while (index * 2 <= heapsize)
			{
				int left = index * 2;
				int right = index * 2 + 1;
				int minindex;
				if (right <= heapsize)
				{
					if (abs(data[left]) < abs(data[right]))
					{
						minindex = left;
					}
					else if (abs(data[left]) == abs(data[right]))
					{
						if (data[left] < data[right])
							minindex = left;
						else
							minindex = right;
					}
					else
						minindex = right;
				}
				else
					minindex = left;

				if (abs(data[index]) > abs(data[minindex]))
				{
					swap(data, index, minindex);
					index = minindex;
				}
				else if (abs(data[index]) == abs(data[minindex]))
				{
					if (data[index] > data[minindex])
					{
						swap(data, index, minindex);
						index = minindex;
					}
					else
						break;
				}
				else
					break;
			}
		}
	}
	int returnMin()
	{
		if (empty() == 1)
			return 0;
		else
			return data[1];
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	Minheap min;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (input != 0)
		{
			min.insert(input);
		}
		else
		{
			cout << min.returnMin() << '\n';
			min.remove();
		}
	}

	return 0;
}