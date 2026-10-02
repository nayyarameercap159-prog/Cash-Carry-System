#include<iostream>
#include<cstring>
#ifndef STAFF_H
#define STAFF_H
#include"Product.h"
using namespace std;
class Staff{
    private:
    string staff_name;
    string email;
    string address;
    short rank;
    Product* prodReport;
    int size;
    public:
    Staff(string nm="",string em="",string add="",short r=0,int sz=0){
        staff_name=nm;
        email=em;
        address=add;
        rank=r;
        size=sz;
        if (size > 0)
            prodReport=new Product[size];
        else
            prodReport=NULL;
    }
    void setStaff(string nm,string em,string add,short r){
        staff_name=nm;
        email=em;
        address=add;
        rank=r;
        
    }
    string getName(){
        return staff_name;
    }
    string getAddress(){
        return address;
    }
    string getEmail(){
        return email;
    }
    short getRank(){
        return rank;
    }
    void displayStaff(){
        cout<<"Staff Name: "<<staff_name<<endl;
        cout<<"Staff Address: "<<address<<endl;
        cout<<"Staff Email: "<<email<<endl;
        cout<<"Staff Rank: "<<rank<<endl;
    }
    void getSalesRpt(short type){
        if(type==1){
            cout<<"Daily Sales Report"<<endl;
            for(int j=0;j<1;j++){
                for(int i=0;i<size;i++){
                    prodReport[i].displayProduct();
                }
            }
        }
        else if(type==2){
            cout<<"Weekly Sales Report"<<endl;
            for(int j=0;j<7;j++){
                for(int i=0;i<size;i++){
                    prodReport[i].displayProduct();
                }
            }
        }
        else{
            cout<<"Invalid Report Type"<<endl;
        }
    }
    ~Staff() {
        delete[] prodReport;
    }
};
#endif
