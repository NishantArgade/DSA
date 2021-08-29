#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //  for boolean include this header file

struct Node
{
    int data;
    struct Node *next;
};
//-------------------------------------------------------------------------------------------

//PRO 1.Find Middle Element of Link List ? :
// void middleElement(struct Node *head)
// {
//     struct Node *sp = head, *fp = head;
//     if (head != NULL)
//     {
//         while (fp != NULL && fp->next != NULL)
//         {
//             sp = sp->next;
//             fp = fp->next->next;
//         }
//         printf("The middle element is %d\n", sp->data);
//     }
//     else
//     printf("List is empty\n");
// }
//----------------------------------------------------------------------------------------
//PRO 2.Find Middle Element and delete in Link List ? :

// struct Node* delete_Mid_node(struct Node* head){
//     struct Node* sp = head,*fp=head,*prev = head;
//     while (fp != NULL && fp->next != NULL)
//     {
//         prev =sp;
//         sp =sp->next;
//         fp = fp->next->next;
//     }
//     prev->next = sp->next;
//     free(sp);
//     return head;
// }
//---------------------------------------------------------------------------------------------
// PRO 3.Print Link List Element in reverse order(only print do not reverse actual link list) :

// struct Node * reversely_print(struct Node*head){
//     // struct Node *nhead =head;
//     if (head == NULL)
//     {
//        return 1;
//     }
//      reversely_print(head->next);// Recursion
//      printf("%d\n",head->data);// here Backtract perform
// }
//------------------------------------------------------------------------------------------
// PRO 4.Reverse Actual Link List (reverse actual link list ) :
// struct Node* Reverse_Actual_LL(struct Node *head)
// {
//     struct Node *cur = head, *pre = NULL, *next = head;
//     while (cur != NULL)
//     {
//         next = cur->next;
//         cur->next = pre;
//         pre = cur;
//         cur = next;
//     }
//     return pre;
// }
//----------------------------------------------------------------------------------------
// PRo 4 Check whether the LinkList is  Palindrom or Not :

// bool  Is_Palindrom(struct Node *left, struct Node *right)
// {
//     if (right == NULL)
// //     {
//         return true;
//     }
//     bool first = Is_Palindrom(left, right->next);
//     if (first == false)
//     {
//         return false;
//     }
//     bool second = (left->data == right->data);
//     left = left->next;

//     return second;
// }
//-------------------------------------------------------------------------------------------------
// pro 5 remove dublicate Data-node from sorted LinkList :

// struct Node * remove_dublicate_Sort_LL(struct Node * head){
//     struct Node * cur = head,*temp;
//     while(cur->next != NULL){

//         if (cur->data == cur->next->data)
//         {
//             temp = cur->next;
//             cur->next =temp->next;
//             free(temp);
//         }
//         else
//         cur = cur->next;
//     }
//     return head;
// }
//----------------------------------------------------------------------------------------------
//Pro 6 Remove Dublicate Data-node from unsorted Linklist :

// struct Node * remove_duplicate_unsorted(struct Node * head)
// {
//     set<ll> vis;
//     auto cur = head, pre = cur;
//     while (cur)
//     // {
//     if (vis.count(cur->data))
//     {
//         pre->next = cur->next;
//         delete cur;
//     }
//     else
//     {
//         vis.insert(cur->data);
//         pre = cur;
//     }
//     cur = pre->next;
// }
// return head;
// }
//-------------------------------------------------------------------------------------------------
// pro 7 Detect  Loop :
// bool detectLoop(struct Node *head)
// {
//     struct Node *sp = head, *fp = head;
//     while (fp && fp->next)
//     {
//         sp = sp->next;
//         fp = fp->next->next;
//         if(sp == fp){
//             return true;
//         }
//     }
//     return false;
// }
//---------------------------------------------------------------------------------------------
// pro 8 Detect loop and remove loop :

// struct Node * removeLoop(struct Node *head)
// {   // Detect loop
//     struct Node *sp = head, *fp = head;
//     while (fp && fp->next)
//     {
//         sp = sp->next;
//         fp = fp->next->next;
//         if (sp == fp)
//         {
//             break;
//         }
//     }
//     // remove loop
//     if (sp == fp)
//     {
//        sp = head;
//        while (sp->next != fp->next)
//        {
//            sp = sp->next;
//            fp = fp->next;
//        }
//        fp->next = NULL;
//     }
//     return head;
// }
//-------------------------------------------------------------------------------------------------
// Pro 9 Find intersection point of two link :

// int Find_intersection_Point(struct Node *head1 ,struct Node *head2 ){

//     struct Node * cur1 = head1, *cur2 = head2;
//     while (cur1 != cur2)
//     {
//         if (cur1== NULL)
//         {
//             cur1 = cur2;
//         }
//         else
//         cur1 =cur1->next;

//         if (cur2== NULL)
//         {
//             cur2 = cur1;
//         }
//         else
//         cur2 =cur2->next;
//     }
//     return cur2->data;
// }
//--------------------------------------------------------------------------------------------
// Pro 10 Sort the Linklist :

// struct Node *merge(struct Node *h1, struct Node *h2)
// {
//     if (h1 == NULL || h2 == NULL)
//     {
//         if (h1 == NULL)
//         {
//             return h2;
//         }
//         else if (h2 == NULL)
//         {
//             return h1;
//         }
//     }
//     if (h1->data < h2->data)
//     {
//         h1->next = merge(h1->next, h2);
//         return h1;
//     }
//     else
//     {
//         h2->next = merge(h1, h2->next);
//         return h2;
//     }
// }
// struct Node *Mergsort(struct Node *head)
// {
//     if (head == NULL || head->next == NULL)
//         return head;

//     struct Node *sp = head, *fp = head, *pre = head;
//     while (fp && fp->next)
//     {
//         pre = sp;
//         sp = sp->next;
//         fp = fp->next->next;
//     }
//     pre->next = NULL;
//     struct Node *h1 = Mergsort(head);
//     struct Node *h2 = Mergsort(sp);
//     return merge(h1, h2);
// }
//----------------------------------------------------------------------------------------------------
// Pro 11 Find sum and odd position node and create new LL which contain seperatly sum position node and odd position

// struct Node *SumOddNodes(struct Node *head)
// {
//     struct Node *o = head, *e = head->next, *even_node_head = e;
//     while ( e && e->next)// or e != NULL && e->next != NULL
//     {
//         o->next = e->next;
//         o = o->next;
//         e->next = o->next;
//         e = e->next;
//     }
//     o->next = even_node_head;
//     return head;
// }
//-------------------------------------------------------------------------------------------------------
// Pro.12 find Kth or nth term from the last of Link List

// void Nth_TermFrom_Last(struct Node *head,int n){

//     struct Node *ptr1 =head,*ptr2 = head;
//     int i = 1;

//     while(i < n){

//      ptr2 = ptr2->next;
//      i++;
//     }

//     while (ptr2 && ptr2->next)// give two condition or considering both odd or even numbers of node
//     {
//         ptr1 =ptr1->next;
//         ptr2 =ptr2->next;
//     }
//     printf("The %d th term from the last is : %d ",n,ptr1->data);
// }

//=========================================================================================================
// Dispaling Nodes Data:

struct Node *Traverse_Nodes(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return head;
}
//====================================================================================================================
int main()
{ // Create pointer;
    struct Node *head = NULL, *second, *third, *forth, *fifth, *sixth;
    // struct Node *head2 = NULL, *second2, *third2, *forth2;

    // point pointers to nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));

    // head2 = (struct Node *)malloc(sizeof(struct Node));
    // second2 = (struct Node *)malloc(sizeof(struct Node));
    // third2 = (struct Node *)malloc(sizeof(struct Node));
    // forth2 = (struct Node *)malloc(sizeof(struct Node));

    // link nodes :
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = forth;

    forth->data = 4;
    forth->next = fifth;

    fifth->data = 5;
    fifth->next = sixth;

    sixth->data = 6;
    sixth->next = NULL;

    // For detect intersection point in two loop for that make another loop:

    // head2->data = 36;
    // head2->next = second2;

    // second2->data = 48;
    // second2->next = third2;

    // third2->data = 12;
    // third2->next = forth2;

    // forth2->data = 77;
    // forth2->next = third;

    //---------------------------------------------------------------------------------------------

    // struct Node *nhead;
    // Traverse_Nodes(head);// actual traversing

    // pro 1;
    // middleElement(head);

    // pro 2:
    // nhead = delete_Mid_node(head);

    // Pro 3 :
    //  printf("Reverse Element is :\n");
    // nhead = reversely_print(head);

    // Pro 4 :
    // nhead = Reverse_Actual_LL(head,head);
    // Traverse_Nodes(nhead);

    // Pro 5 :
    // struct Node *left = head;
    // struct Node *right = head;
    // int nhead = Is_Palindrom(left, right);
    // printf("The given node is paleandrom if 1 otherwise 0 for not paleandrom :%d",nhead);

    // Pro 6 :
    // nhead = remove_dublicate_Sort_LL(head);
    // Traverse_Nodes(nhead);

    // Pro 8:
    // struct Node * node = removeLoop(head);

    // Pro 7:
    // bool nhead = detectLoop(head);
    // printf("if 1 then loop present if 0 loop is not present : %d\n",nhead);

    // Pro 9:
    //  int intersection = Find_intersection_Point(head,head2);
    //  printf("The intersection node value is : %d\n",intersection);

    // Pro 10:
    // nhead = Mergsort(head);
    // Traverse_Nodes(nhead);

    // Pro 11:
    // nhead = SumOddNodes(head);
    // Traverse_Nodes(nhead);

    // Pro 12:
    // Traverse_Nodes(head);
    // Nth_TermFrom_Last(head,3);


    return 0;
}
