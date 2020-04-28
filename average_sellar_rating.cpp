#include<iostream>
#include<vector>
using namespace std;

class seller_rating{
	string type;
	string model;
	float rating;
	public:
		seller_rating(string t,string m, float r){
			rating=r;
			model=m;
			type=t;
		}
		float getrating(){
			return rating;
		}
		string gettype(){
			return type;
		}
		string getmodel(){
			return model;
		} 
};

void search(string type,string model,vector<seller_rating>s,int n){
	int x=1;
	for(int i=0;i<n;i++){
		if(type==s[i].gettype() && model==s[i].getmodel()){
			cout<<endl<<type<<" WITH MODEL : "<<model<<" HAS AN AVERAGE RATING OF :"<<s[i].getrating();
			x=0;
			break;
		}
		
	}
	if(x==1){
		cout<<endl<<"PRODUCT NOT FOUND..";
	}
}

int main(){
	
	//data
	seller_rating s1("cloth","peterenglandmodel1",3.3);
	seller_rating s2("watch","titanmodel1",4.4);
	seller_rating s3("watch","peterenglandmodel2",4.3);
	seller_rating s4("cloth","peterenglandnmodel3",4.0);
	seller_rating s5("watch","fatsrackmodel1",3.4);
	seller_rating s6("watch","timexmodel1",1.4);
	seller_rating s7("watch","titanmodel2",4.4);
	seller_rating s8("watch","titanmodel3",4.8);
	seller_rating s9("watch","timexmodel2",3.0);
	seller_rating s10("watch","fastrackmodel2",4.0);
	
	vector<seller_rating>original;
	original.push_back(s1);
	original.push_back(s2);
	original.push_back(s3);
	original.push_back(s4);
	original.push_back(s5);
	original.push_back(s6);
	original.push_back(s7);
	original.push_back(s8);
	original.push_back(s9);
	original.push_back(s10);
    
	//inputs
	string type,model;
	cout<<"************************************************************";
	cout<<endl<<"Enter the type of material you want(watch/clothe):";
	cout<<endl<<"-------- Warning Case Sensitive--------"<<endl;
	cin>>type;
	cout<<endl<<"Enter the complany along with the model:"<<endl;
	cin>>model;
	cout<<endl<<"-------------------------------------------------------";
	
	//searching
	search(type,model,original,10);
	return 0;
}
