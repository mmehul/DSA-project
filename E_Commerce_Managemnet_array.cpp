#include<iostream>
#include<vector>
using namespace std;
class item{
	string brand;
	int price;
	string type;
	string seller;
	public:
		item(string s1,int p1,string t1,string s2){
			brand=s1;
			price=p1;
			type=t1;
			seller=s2;
		}
		string getbrand(){
			return brand;
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
};
class User_demand{
	public:
		void select_brand(item ar[],item new_item_temporary_brand[],string selected_brand,int size,int &k,int r){
			if(r==0){
				cout<<"DEFAULT BRANDS :  "<<endl;
			    for(int i=0;i<size;i++){
				    cout<<ar[i].getbrand()<<"-->"<<ar[i].getprice()<<"-->"<<ar[i].gettype()<<"-->"<<ar[i].getseller()<<endl;
			    }
			}
			else{
				for(int i=0;i<size;i++){
				    if(ar[i].getbrand()==selected_brand){
					    new_item_temporary_brand[k]=ar[i];
					    k++;
				    }
			    }
			    cout<<"SELECTED BRANDS :  "<<endl;
			    for(int i=0;i<k;i++){
				    cout<<new_item_temporary_brand[i].getbrand()<<"-->"<<new_item_temporary_brand[i].getprice()<<"-->"<<new_item_temporary_brand[i].gettype()<<"-->"<<new_item_temporary_brand[i].getseller()<<endl;
			    }
			}
		}
		void select_price(item new_item_temporary_brand[],item new_item_temporary_price[],item ar[],int selected_price_max,int selected_price_min,int size,int option,int r){
			if(r==0){
				cout<<"DEFAULT PRICE RANGE : "<<endl;
				for(int i=0;i<size;i++){
				    cout<<ar[i].getbrand()<<"-->"<<ar[i].getprice()<<"-->"<<ar[i].gettype()<<"-->"<<ar[i].getseller()<<endl;
			    }
			}
			else{
				int k=0;
			    for(int i=0;i<=size-1;i++){
				    if(selected_price_min<=new_item_temporary_brand[k].getprice()){
					    if(selected_price_max>=new_item_temporary_brand[k].getprice()){
						    new_item_temporary_price[k]=new_item_temporary_brand[i];
						    k++;
					    }
				    }
			    }
			    if(option==1){
				    for(int i=0;i<=k-2;i++){
				        for(int j=0;j<=k-i-1;j++){
					        if(new_item_temporary_price[j].getprice()>=new_item_temporary_price[j+1].getprice()){
						        swap(new_item_temporary_price[j],new_item_temporary_price[j+1]);
					        }
				        }
			        }
			        cout<<"LOW TO HIGH IN A GIVEN SEARCH : "<<endl;
			        for(int i=0;i<=k-1;i++){
			    	    cout<<new_item_temporary_price[i].getbrand()<<"-->"<<new_item_temporary_price[i].getprice()<<"-->"<<new_item_temporary_price[i].gettype()<<"-->"<<new_item_temporary_price[i].getseller()<<endl;
				    }
				    cout<<endl;
			    }
			    else if(option==2){
				    for(int i=0;i<=k-2;i++){
				        for(int j=0;j<=k-i-1;j++){
					        if(new_item_temporary_price[j].getprice()<=new_item_temporary_price[j+1].getprice()){
						        swap(new_item_temporary_price[j],new_item_temporary_price[j+1]);
					        }
				        }
			        }
			        cout<<"HIGHT TO LOW IN A GIVEN SEARCH : "<<endl;
			        for(int i=0;i<=k-1;i++){
			    	    cout<<new_item_temporary_price[i].getbrand()<<"-->"<<new_item_temporary_price[i].getprice()<<"-->"<<new_item_temporary_price[i].gettype()<<"-->"<<new_item_temporary_price[i].getseller()<<endl;
				    }
				    cout<<endl;
			    }	
			}
		}
		void select_type(item ar[],item new_item_temporary_price[],item new_item_temporary_type[],string selected_type,int size,int k,int &p,int r){
			if(r==0){
				cout<<"DEFAULT TYPE : "<<endl;
				for(int i=0;i<size;i++){
				    cout<<ar[i].getbrand()<<"-->"<<ar[i].getprice()<<"-->"<<ar[i].gettype()<<"-->"<<ar[i].getseller()<<endl;
			    }
			}
			else{
				for(int i=0;i<=k-1;i++){
					if(new_item_temporary_price[i].gettype()==selected_type){
						new_item_temporary_type[p]=new_item_temporary_price[i];
						p++;
					}
				}
				cout<<"SELECTED TYPE : "<<endl;
				for(int i=0;i<=p-1;i++){
			    	cout<<new_item_temporary_type[i].getbrand()<<"-->"<<new_item_temporary_type[i].getprice()<<"-->"<<new_item_temporary_type[i].gettype()<<"-->"<<new_item_temporary_type[i].getseller()<<endl;
				}
				cout<<endl;
			}
		}
		void select_seller(item ar[],item new_item_temporary_type[],item new_item_temporary_seller[],string selected_seller,int size,int p,int &d,int r){
			if(r==0){
				cout<<"DEFAULT SELLER : "<<endl;
				for(int i=0;i<size;i++){
				    cout<<ar[i].getbrand()<<"-->"<<ar[i].getprice()<<"-->"<<ar[i].gettype()<<"-->"<<ar[i].getseller()<<endl;
			    }
			}
			else{
				for(int i=0;i<=p-1;i++){
					if(new_item_temporary_type[i].getseller()==selected_seller){
						new_item_temporary_seller[d]=new_item_temporary_type[i];
						d++;
					}
				}
				cout<<"SELECTED SELLER : "<<endl;
				for(int i=0;i<=d-1;i++){
			    	cout<<new_item_temporary_seller[i].getbrand()<<"-->"<<new_item_temporary_seller[i].getprice()<<"-->"<<new_item_temporary_seller[i].gettype()<<"-->"<<new_item_temporary_seller[i].getseller()<<endl;
				}
				cout<<endl;
			}
		}
};
int main(){
	
	item item1("Allensolly",100,"Casual","Bigbazzar");
	item item2("Allensolly",200,"Formal","Sadarbazaar");
	item item3("Allensolly",300,"Formal","Bigbazzar");
	item item4("Pantaloon",600,"Casual","Apple");
	item item5("Pantaloon",400,"Casual","Bigbazzar");
	item item6("Pantaloon",500,"Formal","Bigapple");
	
	int r=1;
	item ar[6]={item1,item2,item3,item4,item5,item6};
	item new_item_temporary_brand[6]={item1,item2,item3,item4,item5,item6};
	
	// Brand_Filter
	
	User_demand user;
	string brand="Pantaloon";
	int k=0;
	int size=6;
	user.select_brand(ar,new_item_temporary_brand,brand,size,k,r);
	cout<<endl;
	
	// Price_Filter
	
	User_demand user1;
	int max=600;
	int min=400;
	item new_item_temporary_price[6]={item1,item2,item3,item4,item5,item6};
	int option=1;
	user1.select_price(new_item_temporary_brand,new_item_temporary_price,ar,max,min,k,option,r);
	cout<<endl;
	
	
	// Type_Filter
	
	User_demand user2;
	int p=0;
	string selected_type="Casual";
	item new_item_temporary_type[6]={item1,item2,item3,item4,item5,item6};
	user2.select_type(ar,new_item_temporary_price,new_item_temporary_type,selected_type,size,k,p,r);
	cout<<endl;
	
	
	// Seller_Filter
	
	User_demand user3;
	int d=0;
	string selected_seller="Bigbazzar";
	item new_item_temporary_seller[6]={item1,item2,item3,item4,item5,item6};
	user2.select_seller(ar,new_item_temporary_type,new_item_temporary_seller,selected_seller,size,p,d,r);
	
	return 0;
}
