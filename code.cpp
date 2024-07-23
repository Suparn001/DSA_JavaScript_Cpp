#Middle of a Linked List-

Given head of a linked list, the task is to find the middle. For example, the middle of 1-> 2->3->4->5 is 3. If there are two middle nodes (even count), return the second middle. For example, middle of 1->2->3->4->5->6 is 4.
The following is internal representation of every test case (two inputs).
n : Size of the linked list
value[] : An array of values that represents values of nodes.
Examples:
Input: n = 5, value[] = {1,2,3,4,5}
Output: 3
Explanation: The given linked list is 1->2->3->4->5 and its middle is 3.
Input: n = 6, value[] = {2,4,6,7,5,1}
Output: 7
Explanation: The given linked list is 2->4->6->7->5->1 and its middle is 7.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
Constraints:
1 <= n <= 5000

Solution is:-
  
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head) {
        if(head == NULL){
            return -1;
        }
        
        
        
        struct Node *s;//created node to store the address of head
        struct Node *q;//created node to store the address of head

        s = head;
        q=head;
        int c =0; // c is the total length
        while(s!=NULL){
            s=s->next;
            c=c+1;
        }
        
        c=(c/2)+1;
        
        while(c!=1){
            q=q->next;
            c=c-1;
            
        }
        
        return q->data;
      
    }
};
