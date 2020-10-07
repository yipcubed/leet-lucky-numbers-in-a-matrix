#include <algorithm>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/PrintUtils.hpp"
#include "../utils/VectorUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// https://leetcode.com/problems/check-if-it-is-a-straight-line/
// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() { // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  vector<int> luckyNumbers(vector<vector<int>> &m) {
    vector<int> result;
    if (m.size() == 0)
      return result;
    vector<int> colIndex(m.size());
    int rows = m.size();
    int cols = m[0].size();
    for (int row = 0; row < rows; row++) {
      // minimum in row
      int minIndex = 0;
      for (int col = 1; col < cols; col++) {
        if (m[row][col] < m[row][minIndex])
          minIndex = col;
      }
      colIndex[row] = minIndex;
    }
    // max in its column
    unordered_set<int> seenCol;
    for (int row = 0; row < rows; row++) {
      // check if m[row, colIndex[row]] is maximum
      int checkCol = colIndex[row];
      PV3(row, checkCol, m[row][checkCol]);
      if (seenCol.count(checkCol))
        continue;
      int num = m[row][checkCol];
      int currMax = num;
      for (int r = 0; r < rows; r++) {
        if (m[r][checkCol] > num) {
          currMax = m[r][checkCol];
          break;
        }
      }
      if (num == currMax) {
        result.push_back(num);
        seenCol.emplace(checkCol);
      }
    }
    return result;
  }
};

void test1() {
  return;
  cout << boolalpha;
  vector<int> a{3, 7, 8};
  vector<int> b{9, 11, 13};
  vector<int> c{15, 16, 17};
  vector<vector<int>> m{a, b, c};

  cout << "15 ? " << Solution().luckyNumbers(m) << endl;
}

void test2() {
  cout << boolalpha;
  vector<int> a{1, 10, 4, 2};
  vector<int> b{9, 3, 8, 7};
  vector<int> c{15, 16, 17, 12};
  vector<vector<int>> m{a, b, c};

  cout << "12 ? " << Solution().luckyNumbers(m) << endl;
}

void test3() {}
