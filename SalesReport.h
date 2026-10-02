#include<iostream>
#include<cstring>
#ifndef SALESREPORT_H
#define SALESREPORT_H
#include"Product.h"
#include"Customer.h"
#include"Order.h"
using namespace std;
class SalesReport{
    private:
    Order* salesData;
    int size;
    public:
    SalesReport(int sz=0){
        size=sz;
        if(size>0) salesData=new Order[size];
        else salesData=NULL;
    }
    bool addOrder(const Order& order){
        Order* temp = new Order[size+1];
        for(int i=0;i<size;i++) temp[i]=salesData[i];
        temp[size]=order;
        delete[] salesData;
        salesData=temp;
        size++;
        return true;
    }
    float getTotalSales(){
        float total=0;
        for(int i=0;i<size;i++){
            total+=salesData[i].getAmount();
        }
        return total;
    }
    void popularProducts(){
        int maxQty=0;
        string popularId = "None";
        for(int i=0;i<size;i++){
            Product* products = salesData[i].getProducts();
            int orderSize = salesData[i].getSize();
            for(int j=0;j<orderSize;j++){
                if(products[j].getQty() > maxQty){
                    maxQty = products[j].getQty();
                    popularId = products[j].getID();
                }
            }
        }
        if(maxQty > 0){
            cout<<"Popular Product ID: "<<popularId<<" with quantity: "<<maxQty<<endl;
        } else {
            cout<<"No sales yet."<<endl;
        }
    }
    void display(){
        cout<< "Total Sales: "<<getTotalSales()<<endl;
        popularProducts();
    }
    ~SalesReport(){
        delete[] salesData;
    }
    void printReport(){
        cout<<"****SALES REPORT****\n";
        cout<< "Total Sales: "<<getTotalSales()<<endl;
        cout<<"\nORDER HISTORY:\n";
        for(int i=0;i<size;i++){
            salesData[i].displayOrder();
        }
    }
};
#endif