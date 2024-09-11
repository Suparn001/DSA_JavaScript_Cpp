**Insert Greatest Common Divisors in Linked List**

Given the head of a linked list `head`, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the **greatest common divisor** of them.

Return _the linked list after insertion_.

The **greatest common divisor** of two numbers is the largest positive integer that evenly divides both numbers.

**Example 1:**

![](https://assets.leetcode.com/uploads/2023/07/18/ex1_copy.png)

**Input:** head = [18,6,10,3]
**Output:** [18,6,6,2,10,1,3]
**Explanation:** The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
There are no more adjacent nodes, so we return the linked list.

**Example 2:**

![](https://assets.leetcode.com/uploads/2023/07/18/ex2_copy1.png)

**Input:** head = [7]
**Output:** [7]
**Explanation:** The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes.
There are no pairs of adjacent nodes, so we return the initial linked list.

**Constraints:**

-   The number of nodes in the list is in the range `[1, 5000]`.
-   `1 <= Node.val <= 1000`

**c++**
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int findGCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return findGCD(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // Base case
        if (head->next == nullptr) {
            return head;
        }

        ListNode* cur = head;
        while (cur->next != nullptr) {
            int max = std::max(cur->val, cur->next->val);
            int min = std::min(cur->val, cur->next->val);
            int gcd = findGCD(max,min);

            ListNode* gcdNode = new ListNode(gcd);
            gcdNode->next = cur->next;
            cur->next = gcdNode;
            cur = gcdNode->next;
        }

        return head;
    }
};

```
**javaScript**
```
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val === undefined ? 0 : val);
 *     this.next = (next === undefined ? null : next);
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */

var insertGreatestCommonDivisors = function(head) {
    // Helper function to find the GCD of two numbers
    function findGCD(a, b) {
        if (b === 0) {
            return a;
        }
        return findGCD(b, a % b);
    }

    // Base case: if there's only one node, return the head
    if (head.next === null) {
        return head;
    }

    let cur = head;
    while (cur.next !== null) {
        // Get the GCD of the values of adjacent nodes
        let max = Math.max(cur.val, cur.next.val);
        let min = Math.min(cur.val, cur.next.val);
        let gcd = findGCD(max, min);

        // Create a new node for the GCD
        let gcdNode = new ListNode(gcd);

        // Insert the GCD node between the current node and the next node
        gcdNode.next = cur.next;
        cur.next = gcdNode;

        // Move the pointer to the next node (skip over the newly inserted GCD node)
        cur = gcdNode.next;
    }

    return head;
};

```

**php**
```
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {

    /**
     * Function to find the greatest common divisor (GCD)
     * @param int $a
     * @param int $b
     * @return int
     */
    function findGCD($a, $b) {
        if ($b == 0) {
            return $a;
        }
        return $this->findGCD($b, $a % $b);
    }

    /**
     * Function to insert nodes with the GCD between adjacent nodes
     * @param ListNode $head
     * @return ListNode
     */
    function insertGreatestCommonDivisors($head) {
        // Base case: if there's only one node, return the head
        if ($head->next == null) {
            return $head;
        }

        $cur = $head;
        while ($cur->next != null) {
            // Get the GCD of the values of adjacent nodes
            $max = max($cur->val, $cur->next->val);
            $min = min($cur->val, $cur->next->val);
            $gcd = $this->findGCD($max, $min);

            // Create a new node for the GCD
            $gcdNode = new ListNode($gcd);

            // Insert the GCD node between the current node and the next node
            $gcdNode->next = $cur->next;
            $cur->next = $gcdNode;

            // Move the pointer to the next node (skip over the newly inserted GCD node)
            $cur = $gcdNode->next;
        }

        return $head;
    }
}

```

