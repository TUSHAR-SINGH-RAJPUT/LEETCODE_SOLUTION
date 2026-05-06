#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//sooch --> node by node add krunga fir new node me value store krega fir temp ko temp->next ko point krega , aagr carry bacha toh usko bhi add krega using (while (l1 != NULL || l2 != NULL || carry)) which means jb tk l1 ya l2 ya carry 0 se greater ho 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);    // ek naya node banaya jisme 0 value h isko dummy head kehte h 
        ListNode* temp = dummy;             // ek naya pointer banaya jo dummy head ko point krega 
        int carry = 0;                      // ek naya variable banaya jisme 0 value h isko carry kehte h 

        while (l1 != NULL || l2 != NULL || carry) {     // jb tk l1 ya l2 ya carry 0 se greater ho 
            int sum = carry;                        // sum me carry ko add krege 

            if (l1 != NULL) {                       // jb tk l1 0 se greater ho 
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {                   // jb tk l2 0 se greater ho 
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;                   // carry me sum / 10 ko store krege 
            temp->next = new ListNode(sum % 10);  // new node me sum % 10 ko store krege 
            temp = temp->next;                  // temp ko temp->next ko point krega 
        }

        return dummy->next;
    }
};


int main() {
    Solution sol;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = sol.addTwoNumbers(l1, l2);

    while (result != NULL) {
        cout << result->val << " -> ";
        result = result->next;
    }
    cout << "NULL" << endl;

    return 0;
}
