#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



namespace StableSort 
{
	void BubbleSort(vector<int>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[j] < nums[i])
				{
					int tmp = nums[i];
					nums[i] = nums[j];
					nums[j] = tmp;
				}

			}
		}
	}

	vector<int> Merge(vector<int> v1, vector<int> v2)
	{
		vector<int> res;
		int i = 0;
		int j = 0;
		while (i < v1.size() || j < v2.size())
		{
			if (i == v1.size())
			{
				while (j < v2.size())
				{
					res.push_back(v2[j]);
					j++;
				}
				return res;
			}

			if (j == v2.size())
			{
				while (i < v1.size())
				{
					res.push_back(v1[i]);
					i++;
				}
				return res;
			}

			if (v1[i] < v2[j])
			{
				res.push_back(v1[i]);
				i++;
			}
			else
			{
				res.push_back(v2[j]);
				j++;
			}
		}
		return res;
	}


	void MergeSort(vector<int>& nums)
	{
		vector<vector<int>> tmp;
		for (int i = 0; i < nums.size(); i++)
		{
			vector<int> t;
			t.push_back(nums[i]);
			tmp.push_back(t);
		}

		while (tmp.size() != 1)
		{
			vector<vector<int>> bak;
			for (int j = 0; (j + 1) < tmp.size(); j += 2)
			{
				bak.push_back(Merge(tmp[j], tmp[j + 1]));
			}
			if (tmp.size() % 2 == 1)
				bak.push_back(tmp[tmp.size() - 1]);
			tmp.swap(bak);
		}

		nums = tmp[0];
	}

	void CountSort(vector<int>& nums)
	{
		vector<int> tmp = nums;
		sort(tmp.begin(), tmp.end());

		int lower = tmp[0];
		int upper = tmp[nums.size() - 1];

		vector<int> count(upper + 1);

		for (int i = 0; i < nums.size(); i++)
		{
			count[nums[i]]++;
		}

		for (int i = 1; i < count.size(); i++)
		{
			count[i] += count[i - 1];
		}

		for (int i = 0; i < nums.size(); i++)
		{
			tmp[count[nums[i]] - 1] = nums[i];
			count[nums[i]]--;
		}


		nums.swap(tmp);
	}

	void InserSort(vector<int>& nums)
	{
		for (int i = 1; i < nums.size(); i++)
		{
			int insertval = nums[i];
			for (int j = i; (j > 0 && nums[j] < nums[j - 1]); j--)
			{

				int tmp = nums[j];
				nums[j] = nums[j - 1];
				nums[j - 1] = tmp;

			}
		}
	}
	void RadixSort(vector<int>& nums)
	{
		int d = 1;
		int p = 10;
		for (int i = 0; i < nums.size(); i++)
		{
			while (p <= nums[i])
			{
				p *= 10;
				d++;
			}
		}

		vector<int> count(10, 0);

		int radix = 1;

		for (int i = 1; i <= d; i++)
		{
			for (int j = 0; j < nums.size(); j++)
			{
				int remain = (nums[j] / radix) % 10;
				count[remain]++;
			}

			for (int j = 1; j < count.size(); j++)
			{
				count[j] += count[j - 1];
			}

			vector<int> tmp(nums.size());

			for (int j = nums.size() - 1; j >= 0; j--)
			{
				int remain = (nums[j] / radix) % 10;
				tmp[count[remain] - 1] = nums[j];
				count[remain]--;
			}

			nums.swap(tmp);

			for (int j = 0; j < count.size(); j++)
				count[j] = 0;
			radix *= 10;
		}
	}
}



namespace UnstableSort {

	void QuickSort(vector<int>& nums,int lower,int upper)
	{

		int i = lower;
		int j = upper;

		if (i >= j)
			return;

		int pivot = nums[i];
		
		while (i < j)
		{
			while (i<j&&nums[j] > pivot)
			{
				j--;
			}
			int tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;

			while (i<j && nums[i] < pivot)
			{
				i++;
			}

			tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		}
		QuickSort(nums, lower, i - 1);
		QuickSort(nums, i + 1, upper);
	}

	void ShellSort(vector<int>& nums)
	{
		int gap = nums.size() / 2;

		while (gap >= 1)
		{
			for (int i = gap; i<nums.size(); i++)
			{
				for (int j = i; (j -gap)>=0 ; j -= gap)
				{
					if ((nums[j - gap] > nums[j]))
					{
						int tmp = nums[j];
						nums[j] = nums[j - gap];
						nums[j - gap] = tmp;
					}
				}
			}
			gap /= 2;
		}
	}

	void SelectSort(vector<int>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			int minval = INT_MAX;
			int minidx=i;
			for (int j = i; j < nums.size(); j++)
			{
				if (nums[j] < minval)
				{
					minidx = j;
					minval = nums[j];
				}
			}

			int tmp = nums[i];
			nums[i] = nums[minidx];
			nums[minidx] = tmp;
		}
	}

}





void main()
{
	vector<int> v = { 3,56,2,7,13,10,36 };

	UnstableSort::SelectSort(v);

	cout << 1;


}