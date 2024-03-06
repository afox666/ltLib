#include <iostream>
#include <string>
#include <vector>

using namespace std;

void BackTrack(vector<string> &res, const vector<string> &num_mapping, string &digits, int index, string &candidate) {
  if(candidate.size() == digits.size()) {
    res.push_back(candidate);
  } else {
    int num_mapping_index = digits[index] - '1';
    string num_map = num_mapping[num_mapping_index];
    for(auto &c : num_map) {
      candidate.push_back(c);
      BackTrack(res, num_mapping, digits, index + 1, candidate);
      candidate.pop_back();
    }
  }
}

vector<string> letterCombinations(string digits) {
  vector<string> res;
  if(digits.empty()) {
    return res;
  }
  vector<string> num_mapping = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  string candidate;
  
  BackTrack(res, num_mapping, digits, 0, candidate);
  
  return res;
}




int main() {
  string s = "2222223";
  auto res = letterCombinations(s);
  for(auto &ss : res) {
    std::cout << ss << " ";
  }
  std::cout << std::endl;
  return 0;
}

