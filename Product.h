#include<iostream>
#include<cstring>
#ifndef PRODUCT_H
#define PRODUCT_H


using namespace std;

class Product{
private:
    string product_id;
    string product_name;
    string category;
    float price;
    int quantity;
public:
Product(string id="",string name="",string cat="",float pr=0,int qty=0){
    product_id=id;
    product_name=name;
    category=cat;
    quantity=qty;
    price=pr;
}
void setID(string id){
    product_id=id;
}
void setProduct(string id, string name, float pr, int qty){
    product_id=id;
    product_name=name;
    price=pr;
    quantity=qty;
}
void setName(string name){
    product_name=name;
}
void setCat(string cat){
    category=cat;
}
void setPrice(float pr){
    price=pr;
}
void setQty(int qty){
    quantity=qty;
}
string getID(){
    return product_id;
}
string getName(){
    return product_name;
}
string getCat(){
    return category;
}
float getPrice(){
    return price;
}
int getQty(){
    return quantity;
}
bool updateStock(short op,int qty){
    if(op==1){
        quantity+=qty;
    }
    else if(op==2){
        if(quantity>=qty){
            quantity-=qty;
        }
        else{
            return false;
        }
    }
    return true;
}
void displayProduct(){
    cout<<"Product ID: "<<product_id<<endl;
    cout<<"Product Name: "<<product_name<<endl;
    cout<<"Category: "<<category<<endl;
    cout<<"Price: "<<price<<endl;
    cout<<"Quantity: "<<quantity<<endl;
}
    double total(){
        return price * quantity;
    }
    friend ostream& operator<<(ostream& os, const Product& p){
        os << "Product ID: " << p.product_id << endl;
        os << "Product Name: " << p.product_name << endl;
        os << "Category: " << p.category << endl;
        os << "Price: " << p.price << endl;
        os << "Quantity: " << p.quantity << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Product& p){
        cout << "Enter Product ID: "; is >> p.product_id;
        cout << "Enter Product Name: "; is >> p.product_name;
        cout << "Enter Category: "; is >> p.category;
        cout << "Enter Price: "; is >> p.price;
        cout << "Enter Quantity: "; is >> p.quantity;
        return is;
    }
    Product operator+(const Product& other) const {
        Product result = *this;
        result.quantity += other.quantity;
        return result;
    }
};
#endif