#pragma once
#include <iostream>
#include <string>
using namespace std;

struct node {
  node * next;
  string type;
};

class linked {

public: 
  node* head;
  node* tail;
  int num_items;

  linked();
  ~linked();

  void addNode(const string& item);
  void push_front(const string& item);
  void push_back(const string& item);
  void pop_front();
  void pop_back();
  node* front();
  node* back();
  void empty();
  void insert(size_t index, const string& item);
  bool remove(size_t index);
  size_t find(const string& item);
};
