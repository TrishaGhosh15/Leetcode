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
    ListNode* oddEvenList(ListNode* head) {

       ListNode* temp = head;
       ListNode* oddpos = NULL;
       ListNode* evenposs = NULL;
         ListNode* temp2 = NULL;
       int count=1;
        ListNode*  evenposshead = NULL;

    
    while(temp!=NULL){
       temp2 = temp->next;
            if(count%2!=0){
              if(oddpos == NULL){
                oddpos=temp;
                temp->next =NULL;
              }
              else{     
                temp->next =NULL;
                oddpos->next = temp;
                oddpos = oddpos->next ;
              }
            }
            else{
              if( evenposs == NULL){
                evenposshead = temp;
                 evenposs = temp;
                 temp->next =NULL;
              }
              else{
                 temp->next =NULL;
                 evenposs->next = temp;
                 evenposs = evenposs->next;
              }
            }
          count++;
          temp = temp2;
       }
       if(oddpos!=NULL){
         oddpos->next = evenposshead;
       }
       
       return head;
    }
};