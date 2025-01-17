# 2683. Neighboring Bitwise XOR
https://leetcode.com/problems/neighboring-bitwise-xor/description/
## Problem Description

A 0-indexed array `derived` with length `n` is created by computing the bitwise XOR (⊕) of adjacent values in a binary array `original` of length `n`. Specifically:

- If `i = n - 1`, then `derived[i] = original[i] ⊕ original[0]`.
- Otherwise, `derived[i] = original[i] ⊕ original[i + 1]`.

Given an array `derived`, determine whether there exists a valid binary array `original` that could have formed `derived`.

Return `true` if such an array exists, otherwise return `false`.

---

## Examples

### Example 1:
**Input:**  
`derived = [1, 1, 0]`  
**Output:**  
`true`  
**Explanation:**  
A valid `original` array that produces `derived` is `[0, 1, 0]`.  
- `derived[0] = original[0] ⊕ original[1] = 0 ⊕ 1 = 1`.  
- `derived[1] = original[1] ⊕ original[2] = 1 ⊕ 0 = 1`.  
- `derived[2] = original[2] ⊕ original[0] = 0 ⊕ 0 = 0`.  

### Example 2:
**Input:**  
`derived = [1, 1]`  
**Output:**  
`true`  
**Explanation:**  
A valid `original` array that produces `derived` is `[0, 1]`.  
- `derived[0] = original[0] ⊕ original[1] = 1`.  
- `derived[1] = original[1] ⊕ original[0] = 1`.  

### Example 3:
**Input:**  
`derived = [1, 0]`  
**Output:**  
`false`  
**Explanation:**  
There is no valid `original` array that satisfies the conditions.  

---

## Constraints

- `n == derived.length`
- `1 <= n <= 10^5`
- The values in `derived` are either `0` or `1`.

---

## 解法
這題可以用反向的方法思考，先考慮各種 `original` 的排列方式會產生怎麼樣的 `derived`。

試著排列長度3個與4個的 `original` 會發現只會產生偶數個 1 的`derived`，因為每次出現變化時 0->1 或是 1->0 ，都會產生2次作用(考慮到循環)生成2個1。
