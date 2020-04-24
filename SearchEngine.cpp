#include "SearchEngine.h"

address create(string inObj,string inDes){
    time_t get_time ;
    time(&get_time);
    address temp = new node;
    tm * templocaltime=localtime(&get_time);
    char tempwaktu[250];
    strftime (tempwaktu,250," %c",templocaltime);
  
    
    temp->object=inObj;
    temp->deskripsi=inDes;
    temp->right=temp->left=NULL;
    temp->deleted=false;
    temp->waktu=tempwaktu;
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
if (root != NULL ){
    if(root->object==x && root->deleted==false){
        newroot=root;
    }else if (root->object > x){
        search(root->left,newroot,x);
    }else if (root -> object<= x ){
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
    if(root !=NULL ){
    if(root->deleted==false){
    cout<<endl<<"object : "<<root->object<<endl;
    cout<<"deskripsi : "<<root->deskripsi<<endl;
    cout<<"ditambahkan pada : "<<root->waktu<<endl;
    cout<<"---------------------------------------------------"<<endl;
    }
    PrintDatabase(root->left);
    PrintDatabase(root->right);
    }
}

