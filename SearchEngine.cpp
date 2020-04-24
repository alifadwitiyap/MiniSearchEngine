#include "SearchEngine.h"

address create(string inObj,string inDes){
    address temp = new node;
    temp->object=inObj;
    temp->deskripsi=inDes;
    temp->right=temp->left=NULL;
    return temp;
}

void insert(address &root,string inobject,string indeskripsi){
    if (root==NULL){
        root=create(inobject,indeskripsi);
    }else if(root->object>inobject){
        insert(root->left,inobject,indeskripsi);
    }else{
        insert(root->right,inobject,indeskripsi);
    }
}

void search(address root,address &newroot, string x ){
if (root != NULL){
    if(root->object==x){
        newroot=root;
    }else if (root->object > x && root->left!=NULL ){
        search(root->left,newroot,x);
    }else if (root -> object<x && root ->right!=NULL){
        search(root->right,newroot,x);
        
}
}
}

vector<string> getsub(string a){
vector<string> b; 
int found; 
if(&a.back()!="?"){
    a=a+"?";
    }


while(a != ""){
    found=a.find(" ");
    b.push_back(a.substr(0,found));
    a= a.erase(0, found+1);
      if (found==-1){
     found=a.find("?");
     b.push_back(a.substr(0,found));
     a=a.erase(0,found+1);   
    }
    
}
return b;
}

void PrintDatabase(address root){
    if(root !=NULL){
    cout<<endl<<"object : "<<root->object<<endl;
    cout<<"deskripsi : "<<root->deskripsi<<endl;
    cout<<"--------------------------------------"<<endl;
    PrintDatabase(root->left);
    PrintDatabase(root->right);
    }
}

