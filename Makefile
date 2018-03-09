# all: Longest-Palindromic-Substring
# all: Roman-Conversion
# all: Longest-Common-Prefix
# all: Remove-Nth-Node
# all: Swap-Nodes-in-Pairs
# all: Pow-x-n
# all: Knapsack-01
# all: Jump-Game
# all: Spiral-matrix
# all: Reverse-LL-II
# all: Search-Rotated-Sorted-Array
# all: Word-Search
# all: Binary-Tree-Inorder-Traversal
# all: Validate-Binary-Search-Tree
# all: Flatten-Binary-Tree-to-Linked-List
# all: Linked-List-Cycle-II
# all: Min-Stack
# all: House-Robber
# all: Kth-largest-element-in-array
# all: Valid-Parentheses
# all: Merge-Two-Sorted-Lists
# all: Climbing-Stairs
# all: Symetric-Tree
# all: Maximum-Depth-of-Binary-Tree
# all: Hamming-Distance
# all: Island-Perimeter
# all: Majority-Element
# all: Intersection-of-Two-Linked-Lists
# all: Move-Zeroes
# all: Sort-Colors
# all: Invert-Binary-Tree
# all: Unique-Paths
# all: Product-of-Array-Except-Self
# all: Rotate-Image
# all: Construct-Binary-Tree
# all: Search-2D-Matrix-II
# all: Number-of-Islands
# all: Maximal-Square
# all: Longest-Increasing-Subsequence
# all: Perfect-Squares
# all: Unique-Binary-Search-Trees
# all: Counting-Bits
# all: Decode-String
# all: Balanced-Binary-Tree
# all: Reverse-Linked-List
# all: Subsets
# all: Combination-Sum
# all: Letter-Combinations-of-a-Phone-Number
# all: Lowest-Common-Ancestor-of-a-Binary-Tree
# all: Maximum-Binary-Tree
# all: Bulb-Switcher
# all: Minesweeper
# all: Restore-IP-Addresses
# all: Single-Element-in-a-Sorted-Array
# all: Multiply-Strings
# all: Remove-Duplicates-from-SortedArray
# all: Count-and-Say
# all: Binary-Tree-Level-Order-Traversal-II
# all: ZigZag-Conversion
# all: Binary-Search-Tree-Iterator
# all: Isomorphic-Strings
# all: Maximum-Subarray
# all: Add-Binary
# all: Length-of-Last-Word
# all: Trie-Test
# all: Container-With-Most-Water
# all: Heap-Test
# all: Gray-Code
# all: Test
# all: 3Sum
# all: Valid-Palindrome
# all: Valid-Palindrome-II
# all: Palindrome-Linked-List
# all: Group-Anagrams
# all: Remove-Duplicates-from-Sorted-List
# all: Implement-Trie
# all: Kth-Smallest-Element-BST
# all: Binary-Tree-Paths
# all: Path-Sum-II
# all: Course-Schedule
# all: Subarray-Sum-Equals-K
# all: Shortest-Unsorted-Continuous-Subarray
# all: Find-All-Numbers-Disappeared-in-an-Array
# all: Best-Time-to-Buy-and-Sell-Stock
# all: Best-Time-to-Buy-and-Sell-Stock-II
# all: Path-Sum-III
# all: Increasing-Triplet-Subsequence
# all: Battleships-in-a-Board
# all: Convert-BST-to-Greater-Tree
# all: Diameter-of-Binary-Tree
# all: Find-All-Anagrams-in-a-String
# all: Subtree-of-Another-Tree
# all: Coin-Change
# all: Edit-Distance
# all: Search-for-a-Range
# all: Merge-Intervals
# all: Reverse-Integer
# all: Best-Time-to-Buy-and-Sell-Stock-with-Cooldown
# all: Generate-Parentheses
# all: Find-the-Duplicate-Number
# all: Simplify-Path
# all: Merge-Two-Binary-Trees
# all: House-Robber-III
# all: Min-Cost-Climbing-Stairs
# all: Rotate-List
# all: Unique-Paths-II
# all: Remove-Duplicates-from-Sorted-Array-II
# all: Remove-Duplicates-from-Sorted-List-II
# all: Plus-One
# all: Convert-Sorted-List-to-Binary-Search-Tree
# all: Minimum-Depth-of-Binary-Tree
# all: Populating-Next-Right-Pointers
# all: Maximum-Product-Subarray
# all: Repeated-DNA-Sequences
# all: Minimum-Size-Subarray-Sum
# all: Count-Primes
# all: House-Robber-II
# all: Binary-Tree-Right-Side-View
# all: Contains-Duplicate-III
# all: Word-Pattern
# all: N-Queens
# all: Binary-Tree-Maximum-Path-Sum
# all: Task-Scheduler
# all: Course-Schedule-II
# all: Longest-Palindromic-Subsequence
# all: Palindromic-Substrings
# all: Sort-List
# all: Top-K-Frequent-Elements
# all: Reverse-Nodes-in-k-Group
# all: Binary-Tree-Preorder-Traversal
# all: Binary-Tree-Postorder-Traversal
# all: Palindrome-Partitioning
# all: Find-Peak-Element
# all: Sort-Characters-By-Frequency
# all: Kth-Smallest-Element-in-a-Sorted-Matrix
# all: Find-Duplicate-Subtrees
# all: Repeated-String-Match
# all: Copy-List-with-Random-Pointer
# all: Word-Break
# all: Regular-Expression-Matching
# all: Wildcard-Matching
# all: Complex-Number-Multiplication
# all: Merge-k-Sorted-Lists
# all: 3Sum-Closest
# all: Valid-Sudoku
# all: Queue-Reconstruction-by-Height
# all: Permutations
# all: Permutations-II
# all: Next-Permutation
# all: Burst-Balloons
# all: Minimum-Window-Substring
# all: Longest-Substring-with-At-Least-K-Repeating-Characters
# all: Longest-Substring-Without-Repeating-Characters
# all: Longest-Consecutive-Sequence
# all: Reorganize-String
# all: Delete-and-Earn
# all: Top-K-Frequent-Words
# all: Friend-Circles
# all: Maximum-Width-of-Binary-Tree
# all: Find-K-Closest-Elements



# all: Implement-strStr
# all: Count-of-Smaller-Numbers-After-Self
# all: Target-Sum
# all: Partition-Equal-Subset-Sum

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@
