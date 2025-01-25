# 2948. Make Lexicographically Smallest Array by Swapping Elements
https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/

## Problem Description

You are given a 0-indexed array of positive integers `nums` and a positive integer `limit`.

In one operation, you can choose any two indices `i` and `j` and swap `nums[i]` and `nums[j]` if `|nums[i] - nums[j]| <= limit`.

Return the lexicographically smallest array that can be obtained by performing the operation any number of times.

An array `a` is lexicographically smaller than an array `b` if in the first position where `a` and `b` differ, array `a` has an element that is less than the corresponding element in `b`. For example, the array `[2,10,3]` is lexicographically smaller than the array `[10,2,3]` because they differ at index `0` and `2 < 10`.

## Example 1:

```
Input: nums = [1,5,3,9,8], limit = 2
Output: [1,3,5,8,9]
Explanation: Apply the operation 2 times:
- Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
- Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
We cannot obtain a lexicographically smaller array by applying any more operations.
Note that it may be possible to get the same result by doing different operations.
```

## Example 2:

```
Input: nums = [1,7,6,18,2,1], limit = 3
Output: [1,6,7,18,1,2]
Explanation: Apply the operation 3 times:
- Swap nums[1] with nums[2]. The array becomes [1,6,7,18,2,1]
- Swap nums[0] with nums[4]. The array becomes [2,6,7,18,1,1]
- Swap nums[0] with nums[5]. The array becomes [1,6,7,18,1,2]
We cannot obtain a lexicographically smaller array by applying any more operations.
```

## Example 3:

```
Input: nums = [1,7,28,19,10], limit = 3
Output: [1,7,28,19,10]
Explanation: [1,7,28,19,10] is the lexicographically smallest array we can obtain because we cannot apply the operation on any two indices.
```

## Constraints:

- `1 <= nums.length <= 105`
- `1 <= nums[i] <= 109`
- `1 <= limit <= 109`

---

## 解法
先假設有一個陣列是由 1, 2, 3, 4, 5 這5個數字隨機排列的並且 `limit` 是 1 情況，透過觀察可以發現不管他們怎麼排列最後依照題目都可以變成`[1, 2, 3, 4, 5]`。

故只要是數字重新排序後數字間差距在 limit 範圍內的同一組數字，都可以變成這種 sorted 的形式。

觀察範例1可以發現它是由 1, 3, 5 與 8, 9 兩組數字組成的，在這2組之中數字是可以任意排列。

所以我們要做的事就是找出總共有多少組數字，並且在遍歷原本的 `nums` 時去將每組數字中當前最小的數值拿出來，放到對應的 index 上。
