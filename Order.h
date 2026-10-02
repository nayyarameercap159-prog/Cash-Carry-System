#include<iostream>
#include<cstring>
#ifndef ORDER_H
#define ORDER_H
#include"Product.h"
#include"Customer.h"
using namespace std;
class Order{
    private:
    int orderId;
    Customer customerInfo;
    Product* products;
    int size;
    string dateTime;
    string customer_name;
    string email;
    string address;
    public:
    Order(int oid=0,int sz=0,string dt="",string cname="",string em="",string add="",int ct=0){
        orderId=oid;
        size=sz;
        dateTime=dt;
        customerInfo=Customer(cname,em,add,ct);
        if(size > 0) products=new Product[size];
        else products=NULL;
    }
    Order(const Order& other) {
        orderId = other.orderId;
        size = other.size;
        dateTime = other.dateTime;
        customerInfo = other.customerInfo;
        customer_name = other.customer_name;
        email = other.email;
        address = other.address;
        if(size>0){
            products=new Product[size];
            for(int i=0;i<size;i++) products[i]=other.products[i];
        }else products=NULL;
    }
    Order& operator=(const Order& other) {
        if(this!=&other){
            delete[] products;
            orderId = other.orderId;
            size = other.size;
            dateTime = other.dateTime;
            customerInfo = other.customerInfo;
            customer_name = other.customer_name;
            email = other.email;
            address = other.address;
            if(size>0){
                products=new Product[size];
                for(int i=0;i<size;i++) products[i]=other.products[i];
            }else products=NULL;
        }
        return *this;
    }
    void setOrder(int oid,string cname,string em,string add,int ct){
        orderId=oid;
        customerInfo=Customer(cname,em,add,ct);
    }
    int getOrderId(){
        return orderId;
    }
    int getSize(){
        return size;
    }
    Product* getProducts(){
        return products;
    }
    bool addProduct(const Product& prod){
        Product* temp=new Product[size+1];
        for(int i=0;i<size;i++){
            temp[i]=products[i];
        }
        temp[size]=prod;
        delete[] products;
        products=temp;
        size++;
        return true;
    }
    void displayOrder(){
        cout<<"Order ID: "<<orderId<<endl;
        cout<<"Date Time: "<<dateTime<<endl;
        cout<<"Customer Name: "<<customerInfo.getName()<<endl;
        cout<<"Customer Address: "<<customerInfo.getAddress()<<endl;
        cout<<"Customer Email: "<<customerInfo.getEmail()<<endl;
        cout<<"Products: "<<endl;
        for(int i=0;i<size;i++){
            products[i].displayProduct();
        }
    }

    ~Order() {
        delete[] products;
    }
    friend ostream& operator<<(ostream& os, const Order& o){
        os << "Order ID: " << o.orderId << endl;
        os << "DateTime: " << o.dateTime << endl;
        os << "Customer: " << o.customerInfo.getName() << endl;
        os << "Address: " << o.customerInfo.getAddress() << endl;
        os << "Email: " << o.customerInfo.getEmail() << endl;
        os << "Products ordered:" << endl;
        for(int i=0;i<o.size;i++) os << o.products[i];
        os << "Total: Rs. " << o.getAmount() << endl;
        return os;
    }
    float getAmount() const {
        float total=0;
        for(int i=0;i<size;i++){
            total+=products[i].total();
        }
        return total;
    }
};
#endif