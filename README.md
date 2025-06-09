# Leetcode-1911.-Maximum-Alternating-Subsequence-Sum
# 🔄 Maximum Alternating Subsequence Sum

## 📘 Problem Statement
You are given an array `nums`. Your task is to find the **maximum alternating sum** of any subsequence.

An **alternating sum** is calculated as:
```
nums[i1] - nums[i2] + nums[i3] - nums[i4] + ...
```
where `i1 < i2 < i3 < ...` is a strictly increasing sequence.

---

## 🧠 Approach 1: Recursion + Memoization

### 🔧 Logic:
- Use a recursive function `answer(i, iseven)`:
  - If `iseven == true`, we add `nums[i]`
  - If `iseven == false`, we subtract `nums[i]`
- At every step, choose:
  - Include current element with its respective sign
  - Skip current element
- Memoize results using a 2D table `t[i][iseven]`

### 🧮 Base Case
- When `i >= nums.size()`, return 0

### 🧪 Example
```
Input: nums = [4,2,5,3]
Output: 7
Explanation:
- Choose subsequence [4,2,5]
- Alternating sum = 4 - 2 + 5 = 7
```

### ⏱️ Time Complexity
- **O(N × 2)** = **O(N)**

### 💾 Space Complexity
- **O(N)** for recursion stack + **O(N)** for memoization

---

## 🧠 Approach 2: Iterative Tabulation (Bottom-Up DP)

### 🔧 Logic:
- Use a DP table `t[i][0]` for even sum, `t[i][1]` for odd sum
- At each index:
  - `t[i][0] = max(t[i-1][0], t[i-1][1] - nums[i])`
  - `t[i][1] = max(t[i-1][1], t[i-1][0] + nums[i])`

### 🧪 Example
```
Input: nums = [4,2,5,3]
Output: 7
Same logic as above but in bottom-up manner
```

### ⏱️ Time Complexity
- **O(N)**

### 💾 Space Complexity
- **O(N)** for the DP table

---

## 👨‍💻 Author Info
**🧑‍🎓 Ridham Garg**  
🎓 B.Tech Computer Engineering, Thapar University, Patiala  
📬 *ridhamgarg@example.com*

---

## 🌟 Crafted with ❤️ using dynamic programming, both recursive and iterative!
