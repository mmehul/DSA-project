#include<iostream>

#include<string>

#include<queue>

#include<vector>

using namespace std;



class item{

  string brand;

  int id;

  string model;

  int price;

  string type;

  string seller;

  float rating;

  public:

    item(string b,int i,string m,int p,string t,string s,float r){

        brand=b;

        id=i;

        model=m;

        price=p;

        type=t;

        seller=s;

        rating=r;

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

    int getprice(){

        return price;

    }

    string gettype(){

        return type;

    }

    string getseller(){

        return seller;

    }

    float getrating(){

        return rating;

    }

    void Print(){

        cout<<brand<<"-->"<<model<<"-->"<<id<<"-->"<<price<<"-->"<<type<<"-->"<<seller<<"-->"<<rating<<endl;

    }

};



vector<item>desired;

vector<item>undesired;



class node{

    public:

    item data;

    node* left;

    node* right;

    node(item d):data(d),left(NULL),right(NULL){

    }

};



class Minheap{

	vector<item> v;



	void heapify(int i){

		   int min_index = i;

		   int left_child = 2*i;

		   int right_child = left_child + 1;

		   if(left_child<v.size() && v[left_child].getprice()<v[min_index].getprice()){

			      min_index = left_child;

		   }

		   if(right_child<v.size() && v[right_child].getprice()<v[min_index].getprice()){

		 	     min_index = right_child;

		   }



		   if(min_index!=i){

			     swap(v[i],v[min_index]);

			     heapify(min_index);

		   }

	}



    public:

	       Minheap(){

	          item r("NULL",0,"NULL",0,"NULL","NULL",0.0);

		      v.push_back(r);

	 }



	void push(item data){

		  v.push_back(data);

		  int index = v.size()-1;

		  int parent = index/2;

		  while(index>1 && v[index].getprice()<v[parent].getprice()){

			      swap(v[index],v[parent]);

			      index = parent;

			      parent = parent/2;

		  }

	 }



	void pop(){ 

		   int last_index = v.size()-1;

		   swap(v[last_index],v[1]);

		   v.pop_back();

           heapify(1);

	}



	item top(){

		   return v[1];

	}



	bool empty(){

		   return v.size()==1;

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
	exit(1);
}



void Print_desired(vector<item>v){
	

    int size=v.size();

    for(int i=0;i<size;i++){

        v[i].Print();

    }

    cout<<endl;

}



void clean(vector<item>&v){

    int size=v.size();

    for(int i=0;i<size;i++){

        v.pop_back();

    }

    cout<<endl;

}



class Selection{

    vector<item>replica;

    Minheap h;

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

    

    void Select_price(vector<item>original,int n,int max,int min,string choice){

	if(choice=="NO"){

	    for(int i=0;i<n;i++){

		    h.push(original[i]);

	    }

	    while(!h.empty()){

	    	item store=h.top();

		    if(store.getprice()<=max){

			    if(store.getprice()>=min){

				    desired.push_back(store);

			    }

		    }

		    else{

			    undesired.push_back(store);

		    }

		    h.pop();

	    }

	    clean(undesired);

	    cout<<"REQUIRED DATABASE :  "<<endl;

	    cout<<"---------------------"<<endl;

	    Print_desired(desired);

	}

	

	if(choice=="YES"){

	        int size=desired.size();

		    for(int i=0;i<size;i++){

		         h.push(desired[i]);

		    }

		    clean(desired);

		    while(!h.empty()){

			     item store=h.top();

			     if(store.getprice()>=min){

				     if(store.getprice()<=max){

					   desired.push_back(store);

				     }

			     }

			     else{

				     undesired.push_back(store);

			     }

			h.pop();

		    }	

		clean(undesired);

	    cout<<"REQUIRED DATABASE :  "<<endl;

	    cout<<"---------------------------------------------------"<<endl;

	    Print_desired(desired);

	}

    }

    

    

	void Select_type(vector<item>original,int n,string type,string choice){

        if(choice=="NO"){

        	cout<<"REQUIRED : "<<endl;

        	for(int i=0;i<n;i++){

        		original[i].Print();

	        }

	    }

	    if(choice=="YES"){

	        replica=desired;

	        clean(desired);

            int size=replica.size();

		    for(int i=0;i<size;i++){

		        item store=replica[i];

		            if(store.gettype()==type){

		                desired.push_back(store);

		            }

		            else{

		                undesired.push_back(store);

		            }

		     }

		     cout<<"REQUIRED DATABASE : "<<endl;

		     cout<<"--------------------"<<endl;

		     Print_desired(desired);

		     cout<<"DO U HAVE AN ACCOUNT IN OUR SYSTEM : "<<endl;

		     cout<<"---------------"<<endl;

		     string t;

		     cin>>t;

		     if(t=="NO"){

		          cout<<"---------------------------------"<<endl;

		     }

		     else{
			 cout<<endl<<"Your product will be delivered within 2 days...";
			 cout<<endl<<"-------------------------------------";		          

	          }

	    }

    }

    

    void Select_seller(vector<item>original,int n,string seller,string choice){

        replica=desired;

	    clean(desired);

	    if(choice=="NO"){

        	 cout<<"REQUIRED DATABASE : "<<endl;

        	 for(int i=0;i<n;i++){

        		 original[i].Print();

	         }

	     }

	    if(choice=="YES"){

	        int size=replica.size();

	        for(int i=0;i<size;i++){

		        item store=replica[i];

		        if(store.getseller()==seller){

		            desired.push_back(store);

		        }

		        else{

		            undesired.push_back(store);

		        }

		    }

		    clean(undesired);

		    cout<<" REQUIRED DATABASE : "<<endl;

		    cout<<" ------------------ "<<endl;

		    Print_desired(desired);

	    }

	}

	

	void Select_Rating(string type,string model,vector<item>original,int n){

	int x=1;

	for(int i=0;i<n;i++){

		if(type==original[i].gettype() && model==original[i].getmodel()){

			cout<<endl<<type<<" WITH MODEL : "<<model<<" HAS AN AVERAGE RATING OF :"<<original[i].getrating();

			x=0;

			break;

		}

		

	}

	if(x==1){

		cout<<endl<<"PRODUCT NOT FOUND..";

	}

}

};



int main(){

    item i1("titan",key("titanmodel1"),"titanmodel1",500,"formal","AmazonIndia",3.3);

    item i2("timex",key("timexmodel1"),"timexmodel1",700,"kidwear","Over2India",4.4);

    item i3("fastrack",key("fastrackmodel1"),"fastrackmodel1",300,"informal","Titan.co.in",4.3);

    item i4("gshock",key("gshockmodel1"),"gshockmodel1",800,"malewear","ETHOS",4.0);

    item i5("titan",key("titanmodel2"),"titanmodel2",200,"femalwear","HELIOS",3.4);

    item i6("titan",key("titanmodel3"),"titanmodel3",600,"formal","AmazonIndia",1.4);

    item i7("titan",key("titanmodel4"),"titanmodel4",100,"kidwear","Over2India",4.4);

    item i8("titan",key("titanmodel5"),"titanmodel5",400,"informal","Titan.co.in",4.8);

    item i9("titan",key("titanmodel6"),"titanmodel6",900,"malewear","ETHOS",3.0);

    item i10("timex",key("timexmodel2"),"timexmodel2",1100,"femalewear","HELIOS",4.2);

    item i11("fastrack",key("fastrackmodel2"),"fastrackmodel2",1200,"malewear","AmazonIndia",4.5);

    item i12("gshock",key("gshockmodel2"),"gshockmodel2",1000,"formal","HELIOS",4.7);

    item i13("timex",key("timexmodel3"),"timexmodel3",1300,"formal","Over2India",4.9);

    

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

	

	//brand FILTER

    Selection s1;

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

    s1.Select_Brand(original,13,modelm,brandb,reply);
    

    // Price FILTER

    Selection s2;

    int max,min;

    cout<<"Enter the min limit : "<<endl;

    cin>>min;

    cout<<"---------------------  "<<endl;

    cout<<"Enter the max limit  : "<<endl;

    cin>>max;

    cout<<"-----------------------"<<endl;

    string choice;

    cout<<"Enter your choice : "<<endl;

    cin>>choice;

    cout<<"----------------------------"<<endl;

    s1.Select_price(original,13,max,min,choice);

    

    //type FILTER

    Selection s3;

    string type,option;

    cout<<"ENTER THE TYPE :  "<<endl;

    cout<<"----------------- "<<endl;

    cin>>type;

    cout<<"ENTER THE CHOICE : "<<endl;

    cout<<"-------------------"<<endl;

    cin>>option;

    s1.Select_type(original,13,type,option);

    

    // seller FILTER

    Selection s4;

    string seller,need;

    cout<<endl<<"ENTER THE SELLER : "<<endl;

    cout<<"-----------------"<<endl;

    cin>>seller;

    cout<<"ENTER THE CHOICE :"<<endl;

    cout<<"------------------"<<endl;

    cin>>need;

    s1.Select_seller(original,13,seller,need);

    

    // rating FILTER

    Selection s5;

	cout<<endl<<"-------------------------------------------------------";

	s1.Select_Rating(type,modelm,original,10);

}
