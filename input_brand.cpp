// inputs
#include<iostream>
#include<string>
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
}
