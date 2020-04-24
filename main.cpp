#include "SearchEngine.cpp"


int main(){
    bool ulang=true;
    address root=NULL;
    cout <<"\033[2J\033[1;1H";
while(ulang){

cout<<"                             --Program Mini Search Engine--";
cout<<endl<<"1. lakukan pencarian"<<endl;
cout<<"2. tambah database"<<endl;
cout<<"3. keluarkan semua database"<<endl;
cout<<"4. update data"<<endl;
cout<<"5. keluar"<<endl<<endl;
cout<<"masukkan pilihan : ";
int input;
cin>>input;
if(cin.fail()){
cin.clear();
cin.ignore(INT_MAX,'\n');
cout<<"\033[2J\033[1;1H";
}
switch(input) {
case 1 :
  {  
     cout <<"\033[2J\033[1;1H";
     string cari;
     vector <string> hasil;
     cout<<"                            --Melakukan Pencarian--";
     cout<<endl<<"Search : ";
     cin.ignore();
     getline(cin,cari,'\n');
     hasil =  getsub(cari);
     int i =0;
     int count=0;
     while (i<hasil.size()){
         address temp= NULL;
         search(root,temp,hasil[i]);
          if (temp != NULL){
            cout<<temp->object<<": "<<temp->deskripsi<<endl<<endl;
            count++;
        }
         i++;
     }   
     if(count==0){
         cout<<endl<<"--Maaf data tidak ditemukan--"<<endl<<endl;
     }

      break;
  }

case 2 :
{
    string obj;
    string desk;        
    address cari=NULL;
    cout <<"\033[2J\033[1;1H";
    cout<<"                             --Masukan Kedalam Database--";                  
    cout<<endl<<"Input Object : ";
    cin>>obj;
    search(root,cari,obj);
    if(cari==NULL){
        cout<<"Input Deskripsi : ";
        cin.ignore();
        getline(cin,desk,'\n');
        insert(root,obj,desk);
        cout<<endl<<endl;
    }else{
        cout<<endl<<"-objek sudah ada-"<<endl;
        cout<<"objek : "<<cari->object<<endl;
        cout<<"deskripsi : "<<cari->deskripsi;
        cout<<endl<<endl;
    }
    break;
}
case 3 :
   { 
       cout <<"\033[2J\033[1;1H";
       cout<<"                              --Inside Database--"<<endl;
       PrintDatabase(root);
       if(root==NULL){
           cout<<"<Database kosong>"<<endl<<endl;
       }
       break;
   }

case 4:
{
  cout <<"\033[2J\033[1;1H";
  cout<<"                                    --Update Data--"<<endl;
  cout<<"object yang ingin di update : ";
  string input;
  cin>>input;
  address hasil=NULL;
  search(root,hasil,input);
  if (hasil == NULL){
      cout<<endl<<"Object tidak ditemukan"<<endl;
  }else{
      cout<<"Masukan Deskripsi : ";
      cin.ignore();
      getline(cin,input,'\n');
      hasil->deskripsi=input;
  }
  break;
}
case 5:
{
  ulang=false;
    break;
}

default :
{
   cout<<"\033[2J\033[1;1H";
   cout<<endl<<"                              -masukkan anda tidak valid -"<<endl<<endl;
}
}
}

}