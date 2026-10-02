#include<iostream>
#include<cstring>
#include"Product.h"
#ifndef CUSTOMER_H
#define CUSTOMER_H
using namespace std;
class Order;
class Customer{
private:
    string customer_name;
    string email;
    string address;
    Order* orderHistory;
    int orderCount;
    Product* prod;
    int size;
    int idx;
public:
    Customer(string name="",string em="",string add="",int ct=0,int sz=0,int idx=0);
    Customer(const Customer& other);
    Customer& operator=(const Customer& other);
    bool placeOrder(Order& order);
    void viewOrderHistory();
void setIdx(int index){
    idx=index;
}
int getIdx(){
    return idx;
}
void setName(string name){
    customer_name=name;
}
void setAddress(string address){
    this->address=address;
}
void setEmail(string em){
    email=em;
}
string getName() const {
    return customer_name;
}
string getAddress() const {
    return address;
}
string getEmail() const {
    return email;
}
void displayCustomer(){
    cout<<"Customer Name: "<<customer_name<<endl;
    cout<<"Customer Address: "<<address<<endl;
}
bool add(const Product& product){
    Product* temp = new Product[size+1];
    for(int i=0; i<size; i++){
        temp[i] = prod[i];
    }
    temp[size] = product;           
    delete[] prod;
    prod = temp;
    size++;
    return true;
}
void showCart(){
    for(int i=0;i<size;i++){
        prod[i].displayProduct();
        cout<<endl;
    }
}
int getCartSize(){
    return size;
}
Product* getCartProducts(){
    return prod;
}
// RESPECTED Sir! i placed this function in main becayse the the ORDER class was not initialised 
   ~Customer();
   friend ostream& operator<<(ostream& os, const Customer& c){
       os << "Customer Name: " << c.customer_name << endl;
       os << "Customer Email: " << c.email << endl;
       os << "Customer Address: " << c.address << endl;
       return os;
   }
   friend istream& operator>>(istream& is, Customer& c){
       cout << "Enter Name: "; is >> c.customer_name;
       cout << "Enter Email: "; is >> c.email;
       cout << "Enter Address: "; is >> c.address;
       return is;
   }
};  
#endif