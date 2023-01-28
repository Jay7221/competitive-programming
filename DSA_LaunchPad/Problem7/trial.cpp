#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}

/*
 * Complete the 'reverseLinkedList' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST root
 *  2. INTEGER K
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
#define ListNode SinglyLinkedListNode
ListNode *reverseLinkedListRec(ListNode *head) // For reversing a block of linked list in O(n)
{

if(head == NULL || head -> next == NULL)
    return head;

ListNode *newhead = reverseLinkedListRec(head -> next);
head -> next -> next = head;
head -> next = NULL;
return newhead;
}
SinglyLinkedListNode* reverseLinkedList(SinglyLinkedListNode* head, int k) {
    // Reverse the linked list with head root
    if(head == NULL || head -> next == NULL)
    return head;
if(k==1 || k==0)
    return head;

int c=1,d=0;
ListNode *temp = head;
ListNode *last = NULL; //for saving the last node of a k-group
ListNode *fhead = NULL; //for saving the head of the linked list
ListNode *newhead = NULL; // for saving the head of every new head
while(temp != NULL){
    if(c==k){
        c=1;
        ListNode *a = temp -> next;
        temp -> next  = NULL;
        newhead = reverseLinkedListRec(head);
        if(last!=NULL)
            last -> next = newhead;
        if(d==0){
            fhead = newhead;
            d=1;
        }
        last = head;
        head = a;
        temp = a;
    } else {
        c++;
        temp = temp -> next;
    }
}
/* If the question has the alteration of reversing the remaining nodes if k is not a multiple of length of list
if(head != NULL){
     newhead = reverseLinkedListRec(head);
     last -> next = newhead;
 }
 */
last -> next = head;
return fhead;
}

int main()
{
	freopen("testcase0.txt", "r", stdin);
	freopen("solution.txt", "w", stdout);

    string i1_temp;
    getline(cin, i1_temp);

    int i1 = stoi(ltrim(rtrim(i1_temp)));

    string i2_temp;
    getline(cin, i2_temp);

    int i2 = stoi(ltrim(rtrim(i2_temp)));

    string i3_temp;
    getline(cin, i3_temp);

    int i3 = stoi(ltrim(rtrim(i3_temp)));

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    SinglyLinkedList* ll = new SinglyLinkedList();

    string ll_count_temp;
    getline(cin, ll_count_temp);

    int ll_count = stoi(ltrim(rtrim(ll_count_temp)));

    for (int i = 0; i < ll_count; i++) {
        string ll_item_temp;
        getline(cin, ll_item_temp);

        int ll_item = stoi(ltrim(rtrim(ll_item_temp)));

        ll->insert_node(ll_item);
    }

    SinglyLinkedListNode* rll = reverseLinkedList(ll->head, k);

    print_singly_linked_list(rll, " ");
    cout << "\n";


    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

