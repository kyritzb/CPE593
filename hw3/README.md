# DoubleLinkedList

Implement the hw class DoubleLinkedList2 in either C++ or Java:

Here is a sample C++ file exercising the class


/* Homework 
    Implement Linked List variant "DoubleLinkedList2"
        addEnd()
        addStart()
        removeEnd()
        use cout w/ '<<' operator or printList() if you're lazy
        size()
        
*/

class DoubleLinkedList2 {


   friend ostream& operator <<(ostream& s, const DoubleLinkedList2& list) {


   }
};
int main() {
    DoubleLinkedList2 mylist;

    for (int i = 0; i < 10; i++)
      mylist.addEnd(i); // 0 1 2 3 4 5 6 7 8 9
    for (int i = 0; i < 10; i++)
      mylist.addStart(i); 9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9
    for (int i = 0; i < 5; i++)
      mylist.removeEnd();  // this is the one that needs DoubleLinkedList!
    cout << mylist << '\n'; // print the list!
    cout << mylist.size();         
}
