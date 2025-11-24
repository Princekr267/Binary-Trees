# Binary Trees in C++

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Trees](https://img.shields.io/badge/Data_Structure-Binary_Trees-green?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/DSA-Interview_Ready-orange?style=for-the-badge)

Complete implementation of Binary Tree algorithms in C++. From basic traversals to advanced problems like LCA and tree transformations.

---

## 🌳 Example Tree Structure

```
           1
         /   \
        2     3
       / \     \
      4   5     6

Preorder:   1 → 2 → 4 → 5 → 3 → 6  (Root → Left → Right)
Inorder:    4 → 2 → 5 → 1 → 3 → 6  (Left → Root → Right)
Postorder:  4 → 5 → 2 → 6 → 3 → 1  (Left → Right → Root)
Level Order: 1 → 2 → 3 → 4 → 5 → 6 (Level by level)
```

---

## 📚 What's Implemented

| 🎯 Category | 📝 Operations | 📄 File |
|------------|--------------|---------|
| **🏗️ Basics** | Build, All Traversals | `creation.cpp` |
| **📏 Measurements** | Height, Count, Sum | `height.cpp`, `commonProblems.cpp` |
| **🎨 Views** | Top View, Kth Level | `kthLevel.cpp` |
| **🔍 Search** | LCA, Min Distance, Kth Ancestor | `lowestCommAncess.cpp` |
| **🔄 Transform** | Sum Tree, Subtree Check | `sumOfTree.cpp`, `commonProblems.cpp` |
| **💎 Advanced** | Diameter (Optimized) | `commonProblems.cpp` |

---

## 🚀 Quick Start

```bash
g++ -std=c++11 creation.cpp -o tree && ./tree
```

**Input Format:** Use `-1` for NULL nodes
```cpp
vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
```

---

## 📖 Core Algorithms Explained

### 1️⃣ Tree Traversals (`creation.cpp`)

```
        1
       / \
      2   3
     / \   \
    4   5   6

Preorder:  1 → 2 → 4 → 5 → 3 → 6  (Copy tree, Prefix notation)
Inorder:   4 → 2 → 5 → 1 → 3 → 6  (BST sorted, Infix notation)
Postorder: 4 → 5 → 2 → 6 → 3 → 1  (Delete tree, Postfix notation)
Level:     1 → 2 → 3 → 4 → 5 → 6  (Level-wise operations)
```

---

### 2️⃣ Diameter (`commonProblems.cpp`)

**Longest path between any two nodes**

```
        1
       / \
      2   3         Diameter = 5 nodes
     / \   \        Path: 4 → 2 → 1 → 3 → 6
    4   5   6       
```

| Approach | Time | Method |
|----------|------|--------|
| Naive | O(n²) | Calculate height at each node |
| **Optimized** | **O(n)** | Calculate diameter & height together ✓ |

---

### 3️⃣ Top View (`kthLevel.cpp`)

Nodes visible from top

```
        1             Top View: 4 → 2 → 1 → 3 → 6
       / \            
      2   3           Horizontal Distance (HD):
     / \   \          Left: HD-1, Right: HD+1
    4   5   6         Keep first node at each HD
```

---

### 4️⃣ Lowest Common Ancestor (`lowestCommAncess.cpp`)

Deepest ancestor of both nodes

```
        1
       / \
      2   3         LCA(4, 5) = 2
     / \   \        LCA(4, 6) = 1
    4   5   6       
```

**Optimal Approach (O(n)):**
- If node is n1 or n2, return it
- Recursively find in left and right
- If both return non-null → current is LCA

---

### 5️⃣ Minimum Distance (`lowestCommAncess.cpp`)

```
        1
       / \
      2   3         Distance(4, 5) = 2
     / \   \        Distance(4, 6) = 4
    4   5   6       

Formula: distance(n1, n2) = dist(LCA, n1) + dist(LCA, n2)
```

---

### 6️⃣ Sum Tree (`sumOfTree.cpp`)

Transform nodes to sum of descendants

```
Before:              After:
    1                  27
   / \                /  \
  2   3              9   13
 / \   \            0    0
4   5   6          (leaves → 0)
```

---

## 📊 Complexity Reference

| Operation | Time | Space | Notes |
|-----------|------|-------|-------|
| Traversals | O(n) | O(h) | h = height |
| Height/Count/Sum | O(n) | O(h) | Single pass |
| Diameter (Optimized) | O(n) | O(h) | Height + diameter together |
| Top View | O(n) | O(n) | BFS + Map |
| LCA (Optimal) | O(n) | O(h) | Single traversal |
| Min Distance | O(n) | O(h) | LCA + 2 distances |
| Sum Tree | O(n) | O(h) | Postorder |

---

## 🎯 Common Patterns

### Pattern 1: Recursive Template
```cpp
returnType solve(Node* root) {
    if(!root) return baseCase;
    
    auto left = solve(root->left);
    auto right = solve(root->right);
    
    return combine(left, right, root->data);
}
```

### Pattern 2: Optimization with Pairs
```cpp
// Return multiple values to avoid recalculation
pair<diameter, height> optimized(Node* root) {
    // Calculate both in one pass
}
```

### Pattern 3: Path Finding
```cpp
bool findPath(Node* root, int target, vector<int>& path) {
    if(!root) return false;
    path.push_back(root->data);
    if(root->data == target) return true;
    if(findPath(left) || findPath(right)) return true;
    path.pop_back();  // Backtrack
    return false;
}
```

---

## 📁 File Guide

```
📂 Binary-Trees/
│
├─ 🏗️  creation.cpp ............... Build tree & all traversals
├─ 📏 height.cpp .................. Height calculation
├─ 💎 commonProblems.cpp .......... Diameter, subtree, count
├─ 🎨 kthLevel.cpp ................ Top view, Kth level nodes
├─ 🔍 lowestCommAncess.cpp ........ LCA, distance, ancestors
└─ 🔄 sumOfTree.cpp ............... Tree transformations
```

---

## 🎓 Learning Path

```
1. START     →  creation.cpp (Traversals)
      ↓
2. MEASURE   →  height.cpp (Basic recursion)
      ↓
3. PROBLEMS  →  commonProblems.cpp (Core algorithms)
      ↓
4. VIEWS     →  kthLevel.cpp (BFS applications)
      ↓
5. ADVANCED  →  lowestCommAncess.cpp (LCA problems)
      ↓
6. TRANSFORM →  sumOfTree.cpp (Modifications)
```

---

## 🔥 Problem Solving Guide

```
┌─────────────────────┬────────────────────────────────┐
│ Need                │ Use                            │
├─────────────────────┼────────────────────────────────┤
│ Shortest path       │ BFS (Level Order)              │
│ All paths           │ DFS (Any traversal)            │
│ Work with subtrees  │ Postorder (bottom-up)          │
│ Distance problems   │ Find LCA first                 │
│ Optimize            │ Combine operations (pairs)     │
└─────────────────────┴────────────────────────────────┘
```

---

## 💡 When to Use Each Traversal?

```
Preorder   → Create copy, Prefix expressions
Inorder    → BST sorted order, Infix expressions  
Postorder  → Delete tree, work from leaves up
Level      → Level-wise operations, shortest path
```

---

## 🎮 LeetCode Mapping

| Problem | # | File | Level |
|---------|---|------|-------|
| Binary Tree Traversals | 144, 94, 145 | `creation.cpp` | Easy |
| Maximum Depth | 104 | `height.cpp` | Easy |
| Diameter of Tree | 543 | `commonProblems.cpp` | Easy |
| Subtree Check | 572 | `commonProblems.cpp` | Easy |
| LCA | 236 | `lowestCommAncess.cpp` | Medium |

---

## 💪 Best Practices

```
✅ Always check for NULL
✅ Use recursion (most elegant)
✅ Optimize by combining operations
✅ Handle empty tree cases
✅ Consider both recursive & iterative
```

---

## 🐛 Common Pitfalls

```
❌ Forgetting NULL checks
❌ Wrong base cases
❌ Not resetting global variables
❌ Memory leaks (not deleting)
```

---

## 📚 Resources

- 🎥 [Visualgo](https://visualgo.net/en/bst) - Interactive visualization
- 💻 [LeetCode Trees](https://leetcode.com/tag/tree/) - Practice problems
- 📖 [CP-Algorithms](https://cp-algorithms.com/) - Advanced topics

---

## 🎯 Next Steps

**Master First:** Traversals → Height → Diameter → LCA

**Then Learn:** BST → AVL Trees → Segment Trees → Trie

---

## ⭐ Support

If this helped you, give it a star! 🌟

---

**Built with 💚 for technical interviews and competitive programming**
