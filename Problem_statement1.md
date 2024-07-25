
## Find the Middle of a Linked List

### Problem Statement

Given the head of a linked list, the task is to find the middle element. For example:

-   The middle of `1 -> 2 -> 3 -> 4 -> 5` is `3`.
-   If there are two middle nodes (in case of an even number of nodes), return the second middle. For example, the middle of `1 -> 2 -> 3 -> 4 -> 5 -> 6` is `4`.

### Internal Representation

Each test case has two inputs:

1.  `n`: Size of the linked list.
2.  `value[]`: An array of values representing the values of nodes in the linked list.

### Examples

**Input:**

-   `n = 5`
-   `value[] = {1, 2, 3, 4, 5}`

**Output:**

-   `3`

**Explanation:** The linked list is `1 -> 2 -> 3 -> 4 -> 5`, and its middle element is `3`.

**Input:**

-   `n = 6`
-   `value[] = {2, 4, 6, 7, 5, 1}`

**Output:**

-   `7`

**Explanation:** The linked list is `2 -> 4 -> 6 -> 7 -> 5 -> 1`, and its middle element is `7`.

### Constraints

-   `1 <= n <= 5000`

### Expected Time Complexity

-   `O(N)`

### Expected Auxiliary Space

-   `O(1)`
