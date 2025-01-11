# 1769. Minimum Number of Operations to Move All Balls to Each Box
https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/
## 問題描述
You have `n` boxes represented by a binary string `boxes` of length `n`.  
- `boxes[i] = '0'` means the `i`-th box is empty.  
- `boxes[i] = '1'` means the `i`-th box contains one ball.

In one operation, you can move one ball from a box to an adjacent box.  
- Box `i` is adjacent to box `j` if `abs(i - j) == 1`.  

Return an array `answer` of size `n`, where `answer[i]` is the **minimum number of operations** needed to move all the balls to the `i`-th box, considering the initial state of the boxes.

---

## 範例
### 範例 1:
**Input:**  
`boxes = "110"`  
**Output:**  
`[1, 1, 3]`  
**Explanation:**  
- For the first box:  
  Move one ball from the second box to the first box in one operation.  
- For the second box:  
  Move one ball from the first box to the second box in one operation.  
- For the third box:  
  Move one ball from the first box to the third box in two operations.  
  Move one ball from the second box to the third box in one operation.  

---

### 範例 2:
**Input:**  
`boxes = "001011"`  
**Output:**  
`[11, 8, 5, 4, 3, 4]`  

---

## 限制條件
- `n == boxes.length`  
- `1 <= n <= 2000`  
- `boxes[i]` is either `'0'` or `'1'`.  

---

## 解法

本題可以理解為每一個有 1 的地方距離回傳答案中每個 index 的絕對值距離和。

首先針對回傳中答案中每一個 index 拆解為左右兩部分，左半部分的 1 最終都須移動到 index ，距離則是所需的操作次數，所以可以建立一個 prefix sum 去知道每個 index 左側所有的 1 移動到 index 時需要操作多少次，做法很簡單只要暫時紀錄目前有多少個 1 需要同時移動，以及目前累積的操作總數，遍歷一次就能更新完 prefix sum。

右側也是同理，接著就是在遍歷一次把同樣 index 的左右 prefix sum 相加就是答案了。