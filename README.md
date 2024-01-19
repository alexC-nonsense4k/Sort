# Sort
排序算法 面试有可能问到 写个仓库做记录 
## 排序算法（基础8大类）
冒泡排序  
归并排序  
计数排序  
插入排序  
基数排序  
快速排序  
希尔排序  
选择排序
## 冒泡排序
一个被最多人知道的排序。时间复杂度$`O(n^2)`$。  
像吐出的泡泡慢慢浮上水面一样 对于给定位置$`i`$开始 比较$`i`$及其后面每两个相邻元素是否有序 不有序则交换
这话总结的很抽象 不如直接看代码
```
void BubbleSort(vector<int>& nums)
	{
		for (int i = 0; i < nums.size()-1; i++)
		{
			for (int j = 0; j+1+i < nums.size(); j++)
			{
				if (nums[j+1] < nums[j])
				{
					int tmp = nums[j+1];
					nums[j+1] = nums[j];
					nums[j] = tmp;
				}

			}
		}
	}
```
很慢 但存在两种优化方式
### 优化方式1  
如果一次循环中没有发生交换，则说明数组已经有序，可以结束排序。
### 优化方式2  
记录上一次循环中 最后一次放生交换的下标位置lastIndex lastIndex及其后面的元素必定有序 不许要再遍历
## 快速排序
快速排序 我第二熟悉的排序 虽然也没有很熟悉 但是其他排序是完全不熟悉 并且它的名字就很牛x 快速排序 主打的就是一个快  

快速排序采用的是分治思想，即在一个无序的序列中选取一个任意的基准元素pivot，利用pivot将待排序的序列分成两部分，前面部分元素均小于或等于基准元素，后面部分均大于或等于基准元素，然后采用递归的方法分别对前后两部分重复上述操作，直到将无序序列排列成有序序列。（from baidu baike）

简单来说 选个值作为基准 把序列分成 大于基准的一部分和小于基准的另一部分 然后套娃下去 对分出的这两部分序列再调用快排  

```
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
```
时间复杂度一般为O(nlgn)  但存在一个最坏情况是$`O(n^2)`$  
这个最坏情况是啥 就是 你坏分出的两个数组 一个数组的尺寸是0 另一个是size()-1

## 插入排序
对于给定位置$`i`$之前的元素有序 那么对于$`i`$只要在前面有序的子序列中找到一个插入后有序的位置 将这个元素插入 即可实现排序
```
	void InsertSort(vector<int>& nums)
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
```
插入排序比较简单 时间复杂度也是$`O(n^2)`$
## 归并排序
把一个大序列裂开 然后裂成2个元素一组 再排序 然后再将排序后的2个一组合成4个一组 不断合并和排序  
时间复杂度是$`O(nlgn)`$ 他和快排时间复杂度一样 但是 快排存在最坏情况 归并排序不存在 但同样的归并排序需要额外的空间$`O(n)`$
## 选择排序
最简单粗暴的排序  
遍历 找到最小的 然后排在第一个 然后找到第二小的 排在第二个 听起来很弱智 但这就是选择排序。。。
```
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
```
时间复杂度$`O(n^2)`$
## 希尔排序 extends 插入排序
从步长 size/2 到 1 每次按照当前的步长 将序列分割成多个子序列 然后对子序列做插入排序  
效率比插入排序要高 但具体的时间复杂度还和步长选取方式有关系 （想了解去看维基） 
如果步长采用0.5做乘数衰减的话 感觉只要知道希尔排序效率一般比插入排序高 最坏情况和插入排序一样即可。
## 还剩俩 累了 回来再说吧

