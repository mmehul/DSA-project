#include<iostream>
#include<string>
#include<queue>
#include<vector>
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

int key(string s){
    int ts=s.length();
    int mul_factor=1;
    int ans=0;
    for(int i=0;s[i]!='\0';i++){
        ans=mul_factor*int(s[i]);
        mul_factor*=37;
        ans%=ts;
        mul_factor%=ts;
    }
    return ans%ts;
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


void database(vector<item>&unknown,string brand,vector<item>v){
    int size=v.size();
    for(int i=0;i<size;i++){
        if(v[i].getbrand()==brand){
            unknown.push_back(v[i]);
        }
    }
    cout<<"REQUIRED DATABASE FOR "<<brand<<" : "<<endl;
    cout<<"------------------------------------"<<endl;
    int p=unknown.size();
    for(int i=0;i<p;i++){
        unknown[i].Print();
    }
    cout<<endl;
}

void Search(vector<item>unknown,string brandmodelno){
    node* root=CreateTree(unknown);
    int r=key(brandmodelno);
    node* ans=SearchInBst(root,r);
    cout<<"REQUIRED MODEL : "<<endl;
    cout<<"-----------------"<<endl;
    item sample=ans->data;
    sample.Print();
}

class Selection{
    vector<item>desired;
    vector<item>undesired;
    public:
    void Select_Brand(vector<item>original,int size,string brand_model_no,string brand,string choice){
        if(choice=="NO"){
            cout<<"NO FILTER APPLIED : "<<endl;
            cout<<"--------------------"<<endl;
            for(int i=0;i<size;i++){
                original[i].Print();
            }
        }
        if(choice=="YES"){
            database(desired,brand,original);
            cout<<"WANT TO GIVE MODEL NUMBER : "<<endl;
            string t;
            cin>>t;
            if(t=="NO"){
                cout<<"----------------------------"<<endl;
            }
            else{
                Search(desired,brand_model_no);
            }
        } 
    }
};

int main(){
    item i1("titan",key("titanmodel1"),"titanmodel1");
    item i2("timex",key("timexmodel1"),"timexmodel1");
    item i3("fastrack",key("fastrackmodel1"),"fastrackmodel1");
    item i4("gshock",key("gshockmodel1"),"gshockmodel1");
    item i5("titan",key("titanmodel2"),"titanmodel2");
    item i6("titan",key("titanmodel3"),"titanmodel3");
    item i7("titan",key("titanmodel4"),"titanmodel4");
    item i8("titan",key("titanmodel5"),"titanmodel5");
    item i9("titan",key("titanmodel6"),"titanmodel6");
    item i10("timex",key("timexmodel2"),"timexmodel2");
    item i11("fastrack",key("fastrackmodel2"),"fastrackmodel2");
    item i12("gshock",key("gshockmodel2"),"gshockmodel2");
    item i13("timex",key("timexmodel3"),"timexmodel3");
    
    vector<item>original;
	original.push_back(i1);
	original.push_back(i2);
	original.push_back(i3);
	original.push_back(i4);
	original.push_back(i5);
	original.push_back(i6);
	original.push_back(i7);
	original.push_back(i8);
	original.push_back(i9);
	original.push_back(i10);
	original.push_back(i11);
	original.push_back(i12);
	original.push_back(i13);
	
    Selection s;
    string brandb,modelm,reply;
    cout<<"Enter brand name: ";
    cin>>brandb;
    cout<<endl<<"---------------------";
    cout<<endl<<"Enter model name: ";
    cin>>modelm;
    cout<<endl<<"--------------------";
    cout<<endl<<"Do you want to see the whole data or just the values that you have given? (YES/NO)";
    cout<<endl<<"********( Case sensitive: HAVE TO GIVE THE REPLY AS PER THE OPTION GIVEN )***********"<<endl;
    cin>>reply;
    s.Select_Brand(original,13,modelm,brandb,reply);
}
