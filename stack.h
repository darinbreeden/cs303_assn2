#pragma once
#include "linked.h"

class stack : public linked{
public:
  //Create stack from linked
  stack() : linked(){}
  void addNode(string d){
    node* newNode = new node;
    newNode->type = d;
    newNode->next = head;
    head = newNode;
  }

  void delNode(){
    if (head != nullptr){
      node* delPtr = head;
      head = head->next;
      delete delPtr;
      delPtr = nullptr;
    }
  }

  node* findTop() {
    return head;
  }

  float avg() {
    float sum = 0;
    //Create temp to hold head
    node* temp = head;
    //Iterate through stack, updating temp and adding its "type" to sum
    for (int i = 0; i < num_items; i++) {
      sum += stof(temp->type);
      temp = temp->next;
    }
    //Delete temp and return avg (sum / num_items)
    delete temp;
    temp->next = nullptr;
    return sum / num_items;
  }
};
