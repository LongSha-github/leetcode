# 45. Jump Game II
https://leetcode.com/problems/jump-game-ii/description/

## Problem Description

You are given a **0-indexed array** of integers `nums` of length `n`. You are initially positioned at `nums[0]`.

Each element `nums[i]` represents the **maximum length of a forward jump** from index `i`. In other words, if you are at `nums[i]`, you can jump to any `nums[i + j]` where:

- `0 <= j <= nums[i]` and  
- `i + j < n`

Return the **minimum number of jumps** to reach `nums[n - 1]`.

The test cases are generated such that it is **guaranteed** that you can reach `nums[n - 1]`.

---

## Examples

### Example 1
**Input**:
```
nums = [2,3,1,1,4]
```
**Output**:
```
2
```
**Explanation**:
Jump 1 step from index `0` to `1`, then jump 3 steps to the last index.
The minimum number of jumps to reach the last index is `2`.

### Example 2
**Input**:
```
nums = [2,3,0,1,4]
```
**Output**:
```
2
```
## Constraints:
- `1 <= nums.length <= 10⁴`
- `0 <= nums[i] <= 1000`
- It's guaranteed that you can reach `nums[n - 1]`.


---

## 解法
觀察第一個例子，當我們從 0 開始起跳時，可以到 1, 2，此時已知到達2時若還沒到終點則必定要多增加一次跳躍。

在這之間我們能到達最遠的距離可能被更新，而到達 2 時，則將上一輪跳躍中最遠的距離`canReach`設定成下一次必定跳躍的地方 `mustJump`，並且將 `ret` +1 ，反覆操作直到遍歷到終點就能得到最少的跳躍次數，因為我們總是盡可能地跳去最遠的地方才更新 `ret`。
