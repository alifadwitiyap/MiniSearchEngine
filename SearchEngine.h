#ifndef SEARCHENGINE_H_INCLUDED
#define SEARCHENGINE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

typedef struct node *address;
 
struct node{
    string object;
    string deskripsi;
    address left;
    address right;  
  };

address create(string inObj,string inDes);
void insert(address &root,string object,string deskripsi);
vector<string> getsub(string a);
void search(address root,address &newroot, string x );
#endif