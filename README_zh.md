# 使用AVL树的集合抽象数据类型（ADT）

该项目实现了一个使用平衡AVL树的集合抽象数据类型（ADT），展示了标准集合操作的实现，并具有高效的时间复杂度。

## 功能

1. **基本集合操作**：
   - **SetInsert**：向集合中添加元素。
   - **SetContains**：检查集合中是否存在某个元素。
   - **SetSize**：返回集合中元素的数量。
   - **SetShow**：以排序的顺序打印集合元素。

2. **集合操作**：
   - **SetUnion**：返回两个集合的并集。
   - **SetIntersection**：返回两个集合的交集。
   - **SetDifference**：返回两个集合的差集（集合1中的元素不在集合2中）。
   - **SetEquals**：判断两个集合是否相等。
   - **SetSubset**：判断一个集合是否是另一个集合的子集。

3. **高级操作**：
   - **SetFloor**：找到小于或等于给定数字的最大元素。
   - **SetCeiling**：找到大于或等于给定数字的最小元素。

4. **游标操作**：
   - 允许通过集合元素进行顺序遍历（开发中）。

## 时间复杂度分析

| 操作                | 时间复杂度   | 描述                                     |
|---------------------|--------------|-----------------------------------------|
| **SetInsert**       | O(log n)     | 在AVL树中插入时进行平衡调整。            |
| **SetContains**     | O(log n)     | 在AVL树中查找元素。                      |
| **SetUnion**        | O(n + m)     | 遍历两个集合并合并元素。                 |
| **SetIntersection** | O(n + m)     | 遍历并匹配元素。                         |
| **SetDifference**   | O(n + m)     | 遍历并查找集合1中独有的元素。            |
| **SetEquals**       | O(n + m)     | 比较两个集合是否相等。                   |
| **SetSubset**       | O(n + m)     | 验证集合1的所有元素是否都在集合2中。     |
| **SetFloor**        | O(log n)     | 查找最大的符合条件的元素。               |
| **SetCeiling**      | O(log n)     | 查找最小的符合条件的元素。               |

## 文件结构

- **`Set.c`**：集合ADT的实现。
- **`Set.h`**：集合ADT的接口。
- **`SetStructs.h`**：内部数据结构（例如AVL树节点）。
- **`test.c`**：基本集合操作的测试。
- **`testSet.c`**：所有函数的综合测试。
- **`analysis.txt`**：复杂度分析和文档。
- **`Makefile`**：自动化编译。

## 编译与执行

1. **编译**：
   使用提供的`Makefile`编译所有文件：
   ```bash
   make
   ```

2. **执行**:
   运行测试以验证功能：
   ```bash
   ./test       # 基本测试
   ./testSet    # 综合测试
   ```

## 安装

1. 克隆该仓库：
   ```bash
   git clone https://github.com/PeterZG/Set-ADT-AVL.git
   ```

2. 进入项目目录：
   ```bash
   cd Set-ADT
   ```

3. 编译并测试项目：
   ```bash
   make
   ./test
   ./testSet
   ```

## 致谢

此项目是UNSW COMP2521课程的一部分，重点学习数据结构和算法。特别感谢讲师和课程资料为学习提供了全面的框架。
