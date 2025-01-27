https://leetcode.com/problems/course-schedule-iv/

## 解法
拓譜排序題目，先建立鄰接表，計算入度後把為0的放入 queue 中。

接著透過 BFS 搜索一層層往下傳遞之前的 `preSet`，若入度為0則繼續加入到 queue 中。

最後把遍歷 `preSet` 看看題目要的 prerequisite 是否在裡面，沒有就是 false。 


