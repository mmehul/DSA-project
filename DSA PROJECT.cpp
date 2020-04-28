#include <iostream>
#include <vector>
using namespace std;

class Minheap{
	vector<int> v;

	void heapify(int i){
		int min_index = i;
		int left_child = 2*i;
		int right_child = left_child + 1;
		if(left_child<v.size() && v[left_child]<v[min_index]){
			min_index = left_child;
		}
		if(right_child<v.size() && v[right_child]<v[min_index]){
			min_index = right_child;
		}

		if(min_index!=i){
			swap(v[i],v[min_index]);
			heapify(min_index);
		}
	}

public:
	Minheap(){
		v.push_back(-1);
	}

	void push(int data){
		v.push_back(data);
		int index = v.size()-1;
		int parent = index/2;
		while(index>1 && v[index]<v[parent]){
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

	int top(){
		return v[1];
	}

	bool empty(){
		return v.size()==1;
	}

};

class Brands{
	Minheap h;
	string gender_products[100][2];
	int number_of_products;
	public:
		void Ranges(int n,int r){
			for(int i=0;i<n;i++){
				int amount_ranges;
				cout<<"ENTER THE RANGE FOR THE AMOUNT OF THE PRODUCT : "<<endl;
				cin>>amount_ranges;
				h.push(amount_ranges);
			}
			number_of_products=r;
		}
		void Price(int max,int min){
			gender_products[0][0]="MALE";
			gender_products[0][1]="FEMALE";
			if(min==h.top()){
				h.pop();
				if(max==h.top()){
					h.pop();
					    for(int j=1;j<=number_of_products;j++){
						    string products;
					        cout<<"ENTER THE PRODUCT FOR MALE WHOSE COST IS IN THE RANGE OF THE MAX AND THE MIN : "<<endl;
					        cin.ignore();
					        getline(cin,products);
					        gender_products[j][0]=products;
					    }
					    for(int j=1;j<=number_of_products;j++){
						    string products;
					        cout<<"ENTER THE PRODUCT FOR MALE WHOSE COST IS IN THE RANGE OF THE MAX AND THE MIN : "<<endl;
					        cin.ignore();
							getline(cin,products);
					        gender_products[j][1]=products;
					    }
				    }
				}
			else if(min==h.top()){
				h.pop();
				if(max==h.top()){
					h.pop();
					    for(int j=1;j<=number_of_products;j++){
						    string products;
					        cout<<"ENTER THE PRODUCT FOR MALE WHOSE COST IS IN THE RANGE OF THE MAX AND THE MIN : "<<endl;
					        cin.ignore();
					        getline(cin,products);
					        gender_products[j][0]=products;
					    }
					    for(int j=1;j<=number_of_products;j++){
						    string products;
					        cout<<"ENTER THE PRODUCT FOR MALE WHOSE COST IS IN THE RANGE OF THE MAX AND THE MIN : "<<endl;
					        cin.ignore();
							getline(cin,products);
					        gender_products[j][1]=products;
					    }
				    }
			}
			else if(min==h.top()){
				h.pop();
				if(max==h.top()){
					h.pop();
					    for(int j=1;j<=number_of_products;j++){
						    string products;
					        cout<<"ENTER THE PRODUCT FOR MALE WHOSE COST IS IN THE RANGE OF THE MAX AND THE MIN : "<<endl;
					        cin.ignore();
					        getline(cin,products);
					        gender_products[j][0]=products;
					    }
					    for(int j=1;j<=number_of_products;j++){
						    string products;
					        cout<<"ENTER THE PRODUCT FOR MALE WHOSE COST IS IN THE RANGE OF THE MAX AND THE MIN : "<<endl;
					        cin.ignore();
							getline(cin,products);
					        gender_products[j][1]=products;
					    }
				    }
			}
        }
        void Print(string gender){
        	for(int i=0;i<2;i++){
        		if(gender_products[0][i]==gender){
        			for(int j=1;j<=number_of_products;j++){
        				cout<<gender_products[j][i]<<", ";
					}
				}
			}
			cout<<endl;
		}
};
int main(){
	Brands b;
	int n;
	cout<<"ENTER THE NUMBER OF THE RANGES : "<<endl;
	cin>>n;
	int r;
	cout<<"ENTER THE NUMBER OF PRODUCTS : "<<endl;
	cin>>r;
	b.Ranges(n,r);
	int max,min;
	cout<<"ENTER THE MAX AND MIN RANGE OF YOUR PRICE : "<<endl;
	cin>>max;
	cout<<endl;
	cin>>min;
	b.Price(max,min);
	string gender;
	cout<<"ENTER THE GENDER : "<<endl;
	cin>>gender;
	b.Print(gender);
}
