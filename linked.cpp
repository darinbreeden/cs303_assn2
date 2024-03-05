#include "linked.h"

linked::linked() {
  cout << "Constructor Called\n";
  head = nullptr;
  tail = nullptr;
  const int num_items = 0;
}

linked::~linked() {
  cout << "Destructor Called\n";
}

void linked::push_back(const string& item) {
  //Create a new node (set data & pointer values, update num_items)
  node* newNode = new node;
  newNode->type = item;
  newNode->next = nullptr;
  num_items += 1;
  tail->next = newNode;
  //Set tail as new node
  tail = newNode;
  return;
}
void linked::push_front(const string& item) {
  //Create a new node (set data & pointer values, update num_items)
  node* newNode = new node;
  newNode->type = item;
  newNode->next = head;
  num_items += 1;
  //Set head as new node
  head = newNode;
  return;
}
void linked::pop_back() {
  //Create temp node to hold head
  node* temp = head;
  //Iterate through list, updating temp to be current position, until temp->next is nullptr
  for (int i = 0; i < num_items; i++) {
    if (temp->next == tail) {
      //Set tail to temp, and delete temp
      tail = temp;
      delete tail->next;
      tail->next = nullptr;
      delete temp;
      temp->next = nullptr;
      //Update num_items
      num_items -= 1;
      return;
    }
    //Update temp to be next position
    temp = temp->next;
  }
}
void linked::pop_front() {
  //Create temp node to hold head
  node* temp = head;
  //Set head to next node, and delete temp
  head = head->next;
  delete temp;
  temp->next = nullptr;
  //Update num_items
  num_items -= 1;
}
node* linked::front() {
  return head;
}
node* linked::back() {
  return tail;
}
void linked::insert(size_t index, const string& item) {
  node* newNode = new node;
  newNode->type = item;
  newNode->next = nullptr;
  num_items += 1;
  if (index > num_items) {
    tail->next = newNode;
    tail = newNode;
    return;
  }
  else {
    newNode->next = head;
    if (index == 0) {
      newNode->next = head->next;
      head = newNode;
      return;
    }
    for (int i = 1; i == index; i++) 
      newNode = newNode->next;
    return;
  }
}
bool linked::remove(size_t index) {
  //If index out of range, return false
  if (index > num_items)
    return false;
  //Create temp node to hold head
  node* temp = head;
  //If index is 0, pop_front
  if (index == 0) {
    head = head->next;
    delete temp;
    temp->next = nullptr;
    return true;
  }
  //Iterate through list, updating temp to be current position, until i == index
  for (int i = 1; i == index - 1; i++) 
    temp = temp->next;
  //delete temp->next, and set to temp->next->next
  delete temp->next;
  temp->next = temp->next->next;
  return true;
}
size_t linked::find(const string& item) {
  size_t index = 0;
  node* temp = head;
  for (int i = 0; i == num_items; i++) {
    if (temp->type == item) {
      delete temp;
      temp->next = nullptr;
      return index;
    }
    temp = temp->next;
    index += 1;
  }
  return num_items;
}
