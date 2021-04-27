// m阶B树
// 1.根结点的子树树∈[2,m],关键字数∈[1,m-1]
// 其他结点的子树树∈[m/2,m],关键字数∈[[m/2]-1,m-1]
// 2.对任一结点,其所有子树高度都相同
// 3.关键字的值:子树0<关键字1<子树1<关键字2<子树2<...

// log[m](n + 1) <= h <= log[m / 2]((n + 1) / 2 + 1)
