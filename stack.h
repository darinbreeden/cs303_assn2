#pragma once
#include "linked.h"

class stack : public linked{
public:
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
    node* temp = head;
    for (int i = 0; i < num_items; i++) {
      sum += stof(temp->type);
      temp = temp->next;
    }
    delete temp;
    temp->next = nullptr;
    return sum / num_items;
  }
};
