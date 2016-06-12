class Solution {
public:
	/**
	* @param nums: a vector of integers
	* @return: the maximum difference
	*/
	struct Bucket{
		int max;
		int min;
		bool flag;//判断该桶是否被使用
	};
	int maximumGap(vector<int> nums) {
		//给定n个实数x1,x2,...,xn,求这n个实数在实轴上相邻2个数之间的最大差值,要求设计线性的时间算法
		//由于要求要线性时间，所以不能使用排序，于是使用了一种类似桶排序的变形

		//由于
		// write your code here
		int MAXLINE = 100;
		int n = nums.size();

        if(n<2) return 0;
		//桶的定义和初始化
		Bucket b[100000], bp[100000];//前者为临时使用的桶，后者为精简过后的桶
		for (int i = 0; i<100; i++)
		{
			b[i].flag = false;
		}

		// 到数组的最大值和最小值
		int maxA = -1000000, minA = 1000000;
		for (int i = 0; i<n; i++)
		{
			if (nums[i]>maxA)
				maxA = nums[i];
			if (nums[i]<minA)
				minA = nums[i];
		}

		if(maxA==minA) return 0;
		int offset = ceil((double)(maxA - minA) / (n - 1));//该距离一定小于maxOffset,同时将其作为桶的大小，则maxoffset不会再桶的内部出现

		//将数据放入桶中
		for (int i = 0; i<n; i++)
		{
			int pose = (int)((nums[i] - minA) / offset);//！！！！！！
			if (!b[pose].flag)//该桶之前没有使用过
			{
				b[pose].min = b[pose].max = nums[i];
				b[pose].flag = true;
			}
			else
			{
				if (nums[i]>b[pose].max)
					b[pose].max = nums[i];
				else if (nums[i]<b[pose].min)
					b[pose].min = nums[i];
			}
		}


		int count = 0;
		//删除无用的桶
		for (int i = 0; i<100000; i++)
		{
			if (b[i].flag)
				bp[count++] = b[i];
		}


		int maxOffset = 1;
		for (int i = 1; i<count; i++)
		{
			if (bp[i].min - bp[i - 1].max>maxOffset)
				maxOffset = bp[i].min - bp[i - 1].max;
		}

		return maxOffset;
	}
};
