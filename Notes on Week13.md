#### 第十一周编程解析 ####
**T1**：本题即为0-1背包问题，状态方程为$f[i][j]=\begin{cases} f[i-1][j] \quad (j<\mathrm{cost}[i]) \\ max \{ f[i-1][j],f[i-1][j-\mathrm{cost}[i]]+\mathrm{value}[i] \} \quad (j \geq \mathrm{cost}[i]) \end{cases}$，其中$i$表示取前$i$个物品，$j$表示背包容量还剩$j$。如果改成一维数组，则由于计算$f[i][j]$时要用到$f[i-1][j]$和$f[i-1][j-\mathrm{cost}[i]]$的数据，因此$j$要从大到小循环。
**T2**：本题要求在$O(n \log{n})$的时间复杂度下求逆序对（因为$O(n^2)$的穷举法会超时），解决方法是归并排序，在合并时，设合并的左半边数组为$a[\mathrm{left},\mathrm{left}+1,\dots,\mathrm{mid}]$，下标为$\mathrm{p1}$；右半边数组为$a[\mathrm{mid}+1,\mathrm{mid}+2,\dots,\mathrm{right}]$，下标为$p2$，则当$a[\mathrm{p1}]>a[\mathrm{p2}]$时，我们发现$a[\mathrm{p1}+1],a[\mathrm{p1}+2],\dots,a[\mathrm{mid}]$均大于$a[\mathrm{p2}]$，因此逆序对个数为$\mathrm{mid}+1-\mathrm{p1}$，从而累加即可得到答案。