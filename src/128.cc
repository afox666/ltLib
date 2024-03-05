#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int> &nums) {
  std::unordered_map<int, int> m;
  int size = nums.size();
  for(int i = 0; i < size; ++ i) {
    ++ m[nums[i]];
  }

  int res = 0;
  for(int i = 0; i < size; ++ i) {
    if(!m.count(nums[i] - 1)) {
      int num = nums[i];
      int max_len = 1;
      while(max_len < size) {
	if(!m.count(nums[i] + max_len)) {
	  break;
	}
	++ max_len;
      }
      res = std::max(res, max_len);
     
    }
  }
  return res;
}

int main() {
  vector<int> nums = {1, 2, 3, 8, 0, 11, 34, 33, 56, 67,35};
  std::cout << longestConsecutive(nums) << std::endl;
  return 0;
}
