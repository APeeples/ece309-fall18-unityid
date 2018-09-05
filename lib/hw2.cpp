#include <stdio.h>

class Item {
public:
  const char * str;
  Item(const char *as = "") 
  { 
    str = as; 
  }
};


class List {
private:

// ListNode represents each 
// node of the list
  class ListNode {
  private:
    Item item; // data in the list
    ListNode *next;	
  public:
    ListNode(Item a) 
    { 
      item = a; 
      next=NULL; // automatically serves as a list tail
    }
    ListNode* getNext() 
    { 
      return next; 
    }
    void setNext(ListNode *n) 
    { 
      next = n; 
    }
    Item getItem() 
    { 
      return item; 
    }
  };

  // add head and tail pointer
  ListNode *head;
  ListNode *tail;


  
public:
  List();
  ~List();
  void append(Item a);    
  bool remove(Item &a);    
  bool empty(); 
  void push_back(const char * a);
  Item get(int n);
  int length();
  Item remove_front();
};

List::List()
{
  // start with an empty list
  head = NULL;
  tail = NULL;
}

List::~List()
{
  // Free all of the ListNodes in the list
  Item a;
  while(!empty()) // while not empty
  {
     remove(a);   // remove the next node.
	 printf("Destroyed: %s \n",a.str);
  }
}

void List::push_back(const char * a){
	Item b(a);
	ListNode *node = new ListNode(b);
	if (head == NULL)
    {
      // list is empty
      head = node;
      tail = node;
    }
  else 
    {
      tail->setNext(node);
      tail = node;
    }
}

Item List::get(int n){
	
	if(n <= 0) return Item("Integer invalid");
	
	ListNode *k = head->getNext();
	
	if(k == NULL) return Item("Not enough items"); //No items
	if(n == 1) return Item(head->getItem()); //First item on the list
	
	for(int i = 2; i < n ; i++){
		k = k->getNext();
		if(k == NULL) return Item("Not enough items");
	}
	return Item(k->getItem()); //Returns the item of n on the list
}

int List::length(){
	int counter;
	if(empty()) return 0;
	ListNode *n = head->getNext();
	if(n == NULL){
		return 1;
	} 
	else{
		counter++; //list had at least 1 item
		while (n != NULL){ // while list is not empty
			counter++;
			n = n->getNext();
		}
		return counter; //Returns the # of items in the list
	}
}

Item List::remove_front(){
	Item copy;
	if (!empty()) // if list is not empty
    {
      copy = head->getItem(); // return copy
      ListNode *tmp = head->getNext();
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp==NULL) // removed last element 
	tail = NULL;
      return copy;
    }
}

void List::append(Item a)
{
  ListNode *node = new ListNode(a);
  if (head == NULL)
    {
      // list is empty
      head = node;
      tail = node;
    }
  else 
    {
      tail->setNext(node);
      tail = node;
    }
}

bool List::remove(Item &copy) 
{
  if (!empty()) // if list is not empty
    {
      copy = head->getItem(); // return copy
      ListNode *tmp = head->getNext();
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp==NULL) // removed last element 
	tail = NULL;
      return true;
    }
  return false; // nothing in list
}

bool List::empty()
{
  return head==NULL;
}
