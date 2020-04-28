#include<iostream>
#include<string>
#include<queue>
using namespace std;

class item{
  string brand;
  int id;
  string model;
  public:
    item(string b,int i,string m){
        brand=b;
        id=i;
        model=m;
    }
    string getbrand(){
        return brand;
    }
    int getid(){
        return id;
    }
    string getmodel(){
        return model;
    }
    void Print(){
        cout<<brand<<"-->"<<model<<"-->"<<id<<endl;
    }
};

class node{
    public:
    item data;
    node* left;
    node* right;
    node(item d):data(d),left(NULL),right(NULL){
    }
};

node* InsertInBst(node* root,item sample){
    if(root==NULL){
        root=new node(sample);
        return root;
    }
    item object=root->data;
    if(object.getid()<sample.getid()){
        root->right=InsertInBst(root->right,sample);
    }
    else{
        root->left=InsertInBst(root->left,sample);
    }
    return root;
}

node* CreateTree(vector<item>v){
    node* root=NULL;
    int size=v.size();
    for(int i=0;i<size;i++){
        root=InsertInBst(root,v[i]);
    }
    return root;
}

node* SearchInBst(node* root,int model_no){
    if(root==NULL){
        return NULL;
    }
    item object=root->data;
    if(model_no==object.getid()){
        return root;
    }
    else if(model_no<object.getid()){
        return SearchInBst(root->left,model_no);
    }
    else if(model_no>object.getid()){
        return SearchInBst(root->right,model_no);
    }
}

int main(){
	//----
	
}
