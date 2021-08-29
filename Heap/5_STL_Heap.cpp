#include<iostream>
#include<queue>
using namespace std;

int main(){
//   ===================== // MAX HEAP ==============================================================================================

   priority_queue<int> heap;// in cpp priority_queue means heap
   // inserting the element
   heap.push(20);
   heap.push(15);
   heap.push(65);
   heap.push(80);
   heap.push(8);
   heap.push(100);
   heap.push(67);
   
   printf("The size of max heap is %d\n",heap.size());
   // max value of heap is
   printf("The Top most element is %d\n",heap.top());

   printf("After pop max heap is\n\n ");
   // poped top element
   heap.pop();
   printf("The Top most element is %d\n",heap.top());

   printf("The size of max heap is %d\n",heap.size());

   printf("is it max heap is empty? %d\n",heap.empty());

//========================== MIN HEAP:==========================================================================

//    priority_queue<int ,vector<int>,greater<int>> heap;// in cpp priority_queue means heap
//    // inserting the element
//    heap.push(20);
//    heap.push(15);
//    heap.push(65);
//    heap.push(80);
//    heap.push(89);
//    heap.push(100);
//    heap.push(67);
   
//    printf("The size of MIN heap is %d\n",heap.size());
//    // MIN value of heap is
//    printf("The Top most element is %d\n",heap.top());

//    // poped top element
//    printf("After pop min heap is\n\n ");
//    heap.pop();
//    printf("The Top most element is %d\n",heap.top());

//    printf("The size of MIN heap is %d\n",heap.size());

//    printf("is it MIN heap is empty? %d\n",heap.empty());
   
    
    return 0;
}