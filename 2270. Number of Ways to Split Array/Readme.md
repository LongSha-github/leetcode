# 2270. Number of Ways to Split Array
https://leetcode.com/problems/number-of-ways-to-split-array/description/
## Problem Description
You are given a 0-indexed integer array `nums` of length `n`.

`nums` contains a valid split at index `i` if the following are true:
1. The sum of the first `i + 1` elements is greater than or equal to the sum of the last `n - i - 1` elements.
2. There is at least one element to the right of `i`. That is, `0 <= i < n - 1`.

Return the number of valid splits in `nums`.

---

## Examples
### Example 1:
**Input:**  
`nums = [10,4,-8,7]`  
**Output:**  
`2`  
**Explanation:**  
There are three ways of splitting `nums` into two non-empty parts:
- Split `nums` at index `0`:  
  The first part is `[10]`, and its sum is `10`. The second part is `[4,-8,7]`, and its sum is `3`. Since `10 >= 3`, `i = 0` is a valid split.  
- Split `nums` at index `1`:  
  The first part is `[10,4]`, and its sum is `14`. The second part is `[-8,7]`, and its sum is `-1`. Since `14 >= -1`, `i = 1` is a valid split.  
- Split `nums` at index `2`:  
  The first part is `[10,4,-8]`, and its sum is `6`. The second part is `[7]`, and its sum is `7`. Since `6 < 7`, `i = 2` is not a valid split.

Thus, the number of valid splits in `nums` is `2`.

---

### Example 2:
**Input:**  
`nums = [2,3,1,0]`  
**Output:**  
`2`  
**Explanation:**  
There are two valid splits in `nums`:
- Split `nums` at index `1`:  
  The first part is `[2,3]`, and its sum is `5`. The second part is `[1,0]`, and its sum is `1`. Since `5 >= 1`, `i = 1` is a valid split.  
- Split `nums` at index `2`:  
  The first part is `[2,3,1]`, and its sum is `6`. The second part is `[0]`, and its sum is `0`. Since `6 >= 0`, `i = 2` is a valid split.

Thus, the number of valid splits in `nums` is `2`.

---

## Constraints
- `2 <= nums.length <= 10^5`
- `-10^5 <= nums[i] <= 10^5`

---

## 解法 
要求切出左右半邊，兩邊最少要有一個元素，當左邊總和大於或等於右邊則為答案之一。

本題與區間總和有關，基本上就是 prefix sum 的題目。

作法只需要算出每個 index 上的累積和，並且在最後遍歷一次，每次比較 index 上的累積和與總和扣掉累積和的結果，若大於或等於則答案累加1。
須注意 10^5 * 10^5 會大於 int32 需要用 long 。 