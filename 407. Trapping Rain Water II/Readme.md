# 407. Trapping Rain Water II
https://leetcode.com/problems/trapping-rain-water-ii/description/

## Problem Description

Given an `m x n` integer matrix `heightMap` representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

## Example 1:
![alt text](image-1.png)
```
Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: 
After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.
```

## Example 2:
![alt text](image.png)
```
Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10
```

## Constraints:

- `m == heightMap.length`
- `n == heightMap[i].length`
- `1 <= m, n <= 200`
- `0 <= heightMap[i][j] <= 2 * 104`

---

## 解法
本題是之前 2D 的 3D 版本，思路也是差不多的，我們必須找出"短板"的地方，而之前可以透過雙指標帶這裡我們必須透過 BFS 加上 min heap 去找出短板所在。

先觀察一下題目，可以看出周圍一圈是不可能積水的，我們可以把他們先加進 `pq` 中，並標記在 `visited` 中接著把 `pq` 中最短的板找出來，找出來後，若短板的高度高於目前的水平面則更新水平面，接著搜索附近合法的未探索地區，若高度低於目前的水平面就代表這裡是可以裝水的，此時把差距加入 res 中累積。並把合法的未探索地區也加入到`pq`中等待之後搜索。 
