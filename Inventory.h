#include<iostream>
#include<cstring>
#include"Product.h"
#ifndef INVENTORY_H
#define INVENTORY_H
using namespace std;
class Inventory{
    private:
    Product* productList;
    int size;
    public:
    Inventory(int sz=0){
        size=sz;
        if(size>0) productList=new Product[size];
        else productList=NULL;
    }
    bool add(const Product& product){
        Product* temp = new Product[size+1];
        for(int i=0; i<size; i++){
            temp[i] = productList[i];
        }
        temp[size] = product;           
        delete[] productList;
        productList = temp;
        size++;
        return true;
    }
    bool update(string pid, short op, int qty){
        if(op==1){
            for(int i=0;i<size;i++){
                if(productList[i].getID()==pid){
                    productList[i].setQty(productList[i].getQty() + qty);
                }
            }
            return true;  
        }
        else if(op==2){
            for(int i=0;i<size;i++){
                if(productList[i].getID()==pid){
                    if(productList[i].getQty() >= qty) {
                        productList[i].setQty(productList[i].getQty() - qty);
                    } else {
                        return false;
                    }
                }
            }  
            return true;  
        }
        return false;
    }
    void generateReport(short type){
        if(type==1){
            for(int i=0;i<size/2;i++){
               productList[i].displayProduct();
            }
        }
        else if(type==2){
            for(int i=0;i<size;i++){
                if(productList[i].getQty()!=0){
                    productList[i].displayProduct();
                }
            }
        }
    }
    ~Inventory() {
        delete[] productList;
    }
};
#endif