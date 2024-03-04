#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  vector<vector<string>> res;

  // may be use map to store sorted str is better.
  vector<string> compare_str;
  for(int i = 0; i < strs.size(); ++ i) {
    string str = strs[i];
    std::sort(str.begin(), str.end());
    std::cout << "sort: " << str << std::endl;
    int index = 0;
    while(index < compare_str.size()) {
      if(compare_str[index] == str) {
	break;
      }
      ++ index;
    }

    if(index == compare_str.size()) {
      vector<string> tmp;
      tmp.push_back(strs[i]);
      res.push_back(tmp);
      compare_str.push_back(str);
    } else {
      res[index].push_back(strs[i]);
    }
  }
  
  return res;
}

int main() {
  vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<string> a = {"a"};
  auto res = groupAnagrams(a);
  for(int i = 0; i < res.size(); ++ i) {
    for(int j = 0; j < res[i].size(); ++ j) {
      std::cout << res[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
