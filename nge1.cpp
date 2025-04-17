#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
	{
		map<int, int> mpp;
		stack<int> s;
		int n = nums2.size();
		int m = nums1.size();
		for (int i = n - 1; i >= 0; i--)
		{
			while (!s.empty() && nums2[i] > s.top())
			{
				s.pop();
			}
			if (s.empty())
			{
				mpp[nums2[i]] = -1;
			}
			else
			{
				mpp[nums2[i]] = s.top();
			}
			s.push(nums2[i]);
		}
		for (int i = 0; i < m; i++)
		{
			nums1[i] = mpp[nums1[i]];
		}
		return nums1;
	}
};