#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Templated Node class
// Normal node except that each node can hold a pair <T,int>
// where the first value is templated and the second value is the frequency
// (or quantity) of the first
// For example, if T was a string then it would hold string,int
template <class T>
class Node {
public:
  Node( const T& data ); //Node Constructor - Assume each quan
  pair<T,int>& GetData(); //Node Data Getter
  void SetData( const pair<T,int>& ); //Node Data Setter
  Node<T>* GetNext(); //Node m_next getter
  void SetNext( Node<T>* next ); //Node m_next setter
private:
  pair <T,int> m_data; //Holds templated data
  Node<T>* m_next; //Pointer to next node
};

template <class T>
Node<T>::Node( const T& data ) {
  m_data = make_pair(data,1);
  m_next = nullptr;
}

template <class T>
pair<T,int>& Node<T>::GetData() {
   return m_data;
}

template <class T>
void Node<T>::SetData( const pair<T,int>& data ) {
   m_data = data;
}

template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

//Templated Linked List class
template <class T>
class LL {
 public:
  // Name: LL() (Linked List) - Default Constructor
  // Desc: Used to build a new linked list
  // Preconditions: None
  // Postconditions: Creates a new linked list where m_head points to nullptr
  LL();
  // Name: ~LL() - Destructor
  // Desc: Used to destruct a LL
  // Preconditions: There is an existing LL with at least one node
  // Postconditions: A LL is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks!
 ~LL();
  // Name: LL (Copy Constructor)
  // Desc: Creates a copy of existing LL
  //       Requires a LL - REQUIRED to be implemented even if not used
  // Preconditions: Source LL exists
  // Postconditions: Copy of source LL
  LL(const LL&);
  // Name: operator= (Overloaded Assignment Operator)
  // Desc: Makes two LL of the same type have identical number of nodes and values
  // Preconditions: Requires two linked lists of the same templated type
  //                REQUIRED to be implemented even if not used
  // Postconditions: Two idenetical LL
  LL<T>& operator= (const LL&);
  // Name: Find
  // Desc: Iterates through LL and returns node if data found
  // Preconditions: LL Populated
  // Postconditions: Returns nullptr if not found OR Node pointer if found
  Node<T>* Find(const T& data);
  // Name: Insert
  // Desc: Either inserts a node to the linked list OR increments frequency of first
  //       Takes in data. If "first" (of pair) NOT in list, adds node
  //       If "first" (of pair) is already in list, increments quantity
  //       Inserts "first" in order with no duplicates
  // Preconditions: Requires a LL.
  // Postconditions: Node inserted in LL based on first value (or quantity incremented)
  void Insert(const T&);
  // Name: RemoveAt
  // Desc: Removes a node at a particular position based on data passed (matches first)
  // Preconditions: LL with at least one node.
  // Postconditions: Removes first node with passed value (in first)
  void RemoveAt(const T&);
  // Name: Display
  // Desc: Display all nodes in linked list
  // Preconditions: Outputs the LL
  // Postconditions: Displays the pair in each node of LL
  void Display();
  // Name: GetSize
  // Desc: Returns the size of the LL
  // Preconditions: Requires a LL
  // Postconditions: Returns m_size
  int GetSize();
  // Name: operator<< (Overloaded << operator)
  // Desc: Returns the ostream of the data in each node
  // Preconditions: Requires a LL
  // Postconditions: Returns an ostream with the data from each node on different line
  template <class U>
  friend ostream& operator<<(ostream& output, const LL<U>&);
  // Name: Overloaded [] operator
  // Desc: When passed an integer, returns the data at that location
  // Precondition: Existing LL
  // Postcondition: Returns pair from LL using []
  pair<T,int>& operator[] (int x);//Overloaded [] operator to pull data from LL
private:
  Node <T> *m_head; //Node pointer for the head
  int m_size; //Number of nodes in queue
};
//*****************************************************************
//Implement LL here
template <class T> // default constructor
LL<T>::LL(){

}
template <class T> //destructor
LL<T>::~LL(){

}
template <class T> //copy constructor
LL<T>::LL(const LL& aList){
    Node<T> *p = aList.m_head;
    m_head = p;
    while (p != NULL){
        Node<T> *q = new Node<T>(p->GetData().first);
        pair <T, int> NewData;
        NewData = make_pair (p->GetData().first, (p->GetData()).second);
        q->SetData(NewData);
        p = p->GetNext();

      }
    }

template <class T> //overloading =
LL<T>& LL<T>::operator= (const LL& aList){

    Node<T> *p = aList.m_head;
    m_head = p;
    while (p != NULL){
        Node<T> *q = new Node<T>(p->GetData().first);
        pair <T, int> NewData;
        NewData = make_pair (p->GetData().first, (p->GetData()).second);
        q->SetData(NewData);
        p = p->GetNext();

    }
    return *this;
}
template <class T> //Find data
Node<T>* LL<T>::Find(const T& data){
    Node<T>* temp = m_head;
    while (temp != nullptr)
    {
        if (((temp->GetData().first).compare(data)) == 0){
            cout << temp->GetData().first << temp->GetData().second;
            return(temp);
            
        }
        temp = temp->GetNext();
    }
    return nullptr;
}
template <class T> //insert
void LL<T>::Insert(const T& input){
    Node<T> *t = new Node<T>(input);
    Node<T> *temp = m_head;
    
    if (m_head == nullptr){ //if LL is empty
        m_head = t;
        m_size++;
    }
    else{ //handles repeated "first"
        while (temp->GetNext() != nullptr){
            if (((temp->GetData().first).compare(input)) == 0) {
                  pair <T, int> NewData;
                  NewData = make_pair (temp->GetData().first, ((temp->GetData()).second) + 1);
                  temp->SetData(NewData);
                 return;
          }
            temp = temp->GetNext();
        }
        if (((temp->GetData().first).compare(input)) == 0) {
         pair <T, int> NewData;
         NewData = make_pair (temp->GetData().first, ((temp->GetData()).second) + 1);
         temp->SetData(NewData);
        }
        else{
            temp->SetNext(t);
            m_size++;
        }
     }
}
template <class U>
ostream& operator<<(ostream& output, const LL<U>& aList){
    Node<U> *temp = aList.m_head;
    while(temp != nullptr){
    output << temp->GetData().first << ":" << temp->GetData().second << endl;
    temp = temp->GetNext();
        
    }
    return output;
}


template <class T> //Remove LL with
void LL<T>::RemoveAt(const T& input){
       Node<T> * delptr = NULL;
       Node<T> *current = m_head;
       Node<T> *temp = m_head;
    if (m_head->GetData().first == input)//head node removal
       {
         m_head = temp->GetNext();
         free(temp);
         m_size--;
         return;
       }
        while(current != NULL && current->GetData().first != input){
          temp = current;
          current = current-> GetNext();
        }
        if(current == NULL){
            return;
        }
        else {
          if (current->GetNext() == NULL){
            temp->SetNext(NULL);// last node removal
          }
          delptr = current;
          current = current->GetNext();
          temp-> SetNext(current);
          delete delptr;
          m_size--;
        }

    }
              
template <class T> //Display LL
void LL<T>::Display(){
    Node<T> *temp = m_head;
    while(temp != nullptr){
    cout << temp->GetData().first << ":" << temp->GetData().second << endl;
    temp = temp->GetNext();
    }
}

template <class T> //returns size of LL
int LL<T>::GetSize(){
  int count = 0; // Initialize count
        Node<T>* current = m_head; // Initialize current
        while (current != nullptr)
        {
            count++;
            current = current->GetNext();
        }
        return count;
}
template <class T>
pair<T,int>& LL<T>::operator[] (int x){
  pair<T,int> data;
  if(x > m_size){
    cout << "not valid input" << endl;
    data.first = 0;
    data.second = 0;
  }
  else{
    Node<T>* current = m_head;
    int counter = 0;
    while(counter != x){
      counter++;
      current = current->GetNext();
    }
    data.first = current->GetData().first;
    data.second = current->GetData().second;
  }
  return data;
}
//****************************************************************
// To test just LL follow these instructions:
//   1.  Uncomment out int main below
//   2.  make LL
//   3.  ./LL (try valgrind too!)

//
//int main () {
//  //Test 1 - Default Constructor and Push
//  cout << "Test 1 - Default Constructor and Push Running" << endl;
//  //Test Default Constructor
//  LL <string>* newLL1 = new LL<string>();
//  //Push 4 nodes into LL
//  newLL1->Insert("candy");
//  newLL1->Insert("cookies");
//  newLL1->Insert("candy");
//  newLL1->Insert("bananas");
//  newLL1->Insert("dogs");
//  newLL1->Insert("apples");
//  newLL1->Insert("elephants");
//  newLL1->Insert("barf");
//  newLL1->Insert("candy");
//  newLL1->Insert("cookies");
//  newLL1->Insert("candy");
//  newLL1->Insert("bananas");
//  newLL1->Insert("dogs");
//  newLL1->Insert("apples");
//  newLL1->Insert("elephants");
//  newLL1->Insert("barf");
//  newLL1->Display();
//
//  //expectedd output: candy: 4
//  //                  cookies: 2
//  //                  bananas: 2
//  //                  dogs: 2
//  //                  apples: 2
//  //                  elephants: 2
//  //                  barf: 2
//  //  delete newLL1;
//
//  //Test 2 - Copy Constructor and Assignment Operator
//  cout << "Test 2 - Copy Constructor and Assignment Operator Running" << endl;
//  //Test Copy constructor
//  LL <string>* newLL2 = new LL<string>(*newLL1);
//  cout << "*******Original*********" << endl;
//  newLL1->Display();
//  cout << "*******Copy*********" << endl;
//  newLL2->Display();
//
//
//
//
//
//  //Test Overloaded Assignment Operator
//  LL <string>* newLL3 = new LL<string>();
//  *newLL3 = *newLL1;
//  cout << "*******Assignment*********" << endl;
//  newLL3->Display();
//  cout << endl;
//
//  //Test 3 - Test Display and Overloaded <<
//  cout << "Test 3 - Display and Overloaded << Running" << endl;
//  cout << "newLL1 Display Function" << endl;
//  newLL1->Display();
//  cout << "newLL1 Overloaded" << endl;
//  cout << *newLL1;
//  cout << "RemoveAt(candy)" << endl;
//  newLL1->RemoveAt("candy");
//  cout << "newLL1 Display Function" << endl;
//  newLL1->Display();
//
//  return 0;
//}
