#include<iostream>
#include<iomanip>
#include<string>
#include"Product.h"
#include"Customer.h"
#include"Order.h"
#include"SalesReport.h"
#include"Inventory.h"
#include"Staff.h"
#ifdef _WIN32
#include<windows.h>
#endif
using namespace std;

namespace ui {
    const string RESET = "\033[0m";
    const string BOLD = "\033[1m";
    const string GOLD = "\033[38;5;220m";
    const string HOT_PINK = "\033[38;5;205m";
    const string CYAN = "\033[38;5;51m";
    const string GREEN = "\033[38;5;82m";
    const string RED = "\033[38;5;196m";
    const string DIM = "\033[2m";

#ifdef _WIN32
    void enableAnsiColors() {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut == INVALID_HANDLE_VALUE) return;
        DWORD mode = 0;
        if (!GetConsoleMode(hOut, &mode)) return;
        SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    }
#else
    void enableAnsiColors() {}
#endif

    void line(char ch = '=', int width = 70) {
        cout << DIM;
        for (int i = 0; i < width; i++) cout << ch;
        cout << RESET << '\n';
    }

    void title(const string& text) {
        line('=');
        cout << BOLD << HOT_PINK << "   " << text << RESET << '\n';
        line('=');
    }

    void section(const string& text) {
        cout << '\n' << BOLD << GOLD << "[ " << text << " ]" << RESET << '\n';
        line('-');
    }

    void menuOption(int id, const string& label) {
        cout << CYAN << "  " << id << "." << RESET << " " << BOLD << label << RESET << '\n';
    }

    void prompt(const string& text) {
        cout << GOLD << text << RESET;
    }

    void success(const string& text) {
        cout << GREEN << BOLD << text << RESET << '\n';
    }

    void error(const string& text) {
        cout << RED << BOLD << text << RESET << '\n';
    }

    void info(const string& text) {
        cout << HOT_PINK << text << RESET << '\n';
    }
}

Customer::Customer(string name,string em,string add,int ct,int sz,int idx){
    customer_name=name;
    email=em;
    address=add;
    orderCount=ct;
    if(orderCount>0) orderHistory=new Order[orderCount];
    else orderHistory=NULL;
    size=sz;
    if(size>0) prod=new Product[size];
    else prod=NULL;
    this->idx=idx;
}

Customer::~Customer(){
    delete[] prod;
    delete[] orderHistory;
}

Customer::Customer(const Customer& other) {
    customer_name = other.customer_name;
    email = other.email;
    address = other.address;
    orderCount = other.orderCount;
    size = other.size;
    idx = other.idx;
    if (orderCount > 0) {
        orderHistory = new Order[orderCount];
        for(int i=0; i<orderCount; i++) orderHistory[i] = other.orderHistory[i];
    } else orderHistory = NULL;
    if (size > 0) {
        prod = new Product[size];
        for(int i=0; i<size; i++) prod[i] = other.prod[i];
    } else prod = NULL;
}

Customer& Customer::operator=(const Customer& other) {
    if (this != &other) {
        delete[] prod;
        delete[] orderHistory;
        customer_name = other.customer_name;
        email = other.email;
        address = other.address;
        orderCount = other.orderCount;
        size = other.size;
        idx = other.idx;
        if (orderCount > 0) {
            orderHistory = new Order[orderCount];
            for(int i=0; i<orderCount; i++) orderHistory[i] = other.orderHistory[i];
        } else orderHistory = NULL;
        if (size > 0) {
            prod = new Product[size];
            for(int i=0; i<size; i++) prod[i] = other.prod[i];
        } else prod = NULL;
    }
    return *this;
}

bool Customer::placeOrder(Order& order){
    for(int i=0;i<size;i++){
        order.addProduct(prod[i]);
    }
    Order* temp=new Order[orderCount+1];
    for(int i=0;i<orderCount;i++){
        temp[i]=orderHistory[i];
    }
    temp[orderCount]=order;
    delete[] orderHistory;
    orderHistory=temp;
    orderCount++;
    cout<<"ORDER PLACED SUCCESSFULLY\n";
    return true;
}

void Customer::viewOrderHistory(){
    if(orderCount==0){
        cout<<"No orders placed yet." <<endl;
        return;
    }
    cout<<"Order History:"<<endl;
    for(int i=0;i<orderCount;i++){
        cout << orderHistory[i]; 
    }
}

int main(){
    ui::enableAnsiColors();

    ui::title("PUNJAB CASH&CARRY :: LUXE EDITION");
    cout << ui::DIM << "Muhammad Nayyar Ameer || 2530087" << ui::RESET << "\n\n";
    Customer cust[3];
    cust[0].setName("Customer1");
    cust[0].setEmail("email");
    cust[0].setAddress("address");
    cust[0].setIdx(0);
    cust[1].setName("Customer2");
    cust[1].setEmail("email");
    cust[1].setAddress("address");
    cust[1].setIdx(1);
    cust[2].setName("Customer3");
    cust[2].setEmail("email");
    cust[2].setAddress("address");
    cust[2].setIdx(2);
    
    

    int size=7;
    Product products[size];
    
    products[0].setProduct("P001","Apple",100,10);
    products[1].setProduct("P002","Banana",200,20);
    products[2].setProduct("P003","Orange",300,30);
    products[3].setProduct("P004","Grapes",400,40);
    products[4].setProduct("P005","Mango",500,50);
    products[5].setProduct("P006","Pineapple",600,60);
    products[6].setProduct("P007","Watermelon",700,70);
    Inventory inventory[size];
    for(int i=0;i<size;i++){
        inventory[i].add(products[i]);
    }

    SalesReport salesReport;

    Staff staff[3];
    staff[0].setStaff("Manager","email","123islamabad",0);
    staff[1].setStaff("Cashier","email","456karachi",1);
    staff[2].setStaff("Helper","email","789peshawar",2);

    ui::section("Welcome to PUNJAB CASH&CARRY Supermarket");
    ui::menuOption(1, "Customer");
    ui::menuOption(2, "Staff");
    ui::menuOption(3, "Exit");
    int choice = 0;
    ui::prompt("Select portal: ");
    cin>>choice;
    while(choice!=3){
        if(choice==1){
            int choice1 = 0;
            while(choice1 != 3) {
                ui::section("Customer Access");
                ui::menuOption(1, "Login");
                ui::menuOption(2, "Signup");
                ui::menuOption(3, "Exit");
                ui::prompt("Choose option: ");
                if(!(cin >> choice1)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    ui::error("Invalid input. Please enter a number.");
                    continue;
                }
                string username;
                string email;
                string address;
                int idx;
                if(choice1==1){
                    cout<<"Enter your username: ";
                    cin>>username;
                    cout<<"Enter your address: ";
                    cin>>address;
                    cout<<"Enter your email: ";
                    cin>>email;
                    cout<<"INDEX plz \n";
                    cin>>idx;
                    if(idx >=0 && idx < 3 && cust[idx].getName()==username && cust[idx].getEmail()==email && cust[idx].getAddress()==address){
                        ui::success("Login successful.");
                        ui::section("Customer Order Menu");
                        int choice2 = 0;
                        while(choice2!=5){
                            ui::menuOption(1, "View History");
                            ui::menuOption(2, "Add products to Cart");
                            ui::menuOption(3, "Show Cart");
                            ui::menuOption(4, "Place Order");
                            ui::menuOption(5, "Exit");
                            ui::prompt("Select action: ");
                            if(!(cin >> choice2)) {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                continue;
                            }
                            
                            if(choice2==1){
                                cout<<"ORDER HISTORY\n";
                                cust[idx].viewOrderHistory();
                            }
                            else if(choice2==2){
                                cout<<"ADD products to Cart"<<endl;
                                string id;
                                cout<<"product ID please\n";
                                cin>>id;
                                for(int i=0;i<size;i++){
                                    if(id==products[i].getID()){
                                        cout<<cust[idx].add(products[i]);
                                        cout<<"ADDED SUCCESSFULLY\n";
                                        break;
                                    }
                                    else if(i == size - 1){
                                        cout<<"NOT AVAILABLE\n";
                                    }
                                }
                            }
                            else if(choice2==3){
                                cout<<"SHOW CART\n";
                                cust[idx].showCart();
                            }
                            else if(choice2==4){
                                cout<<"Place ORDER\n";
                                float cartTotal = 0;
                                for(int i=0;i<cust[idx].getCartSize();i++){
                                    cartTotal += cust[idx].getCartProducts()[i].total();
                                }
                                Order order(cust[idx].getIdx()+1, 0, "",
                                    cust[idx].getName(),
                                    cust[idx].getEmail(),
                                    cust[idx].getAddress(), 0);
                                cust[idx].placeOrder(order);
                                salesReport.addOrder(order);
                                cout << "Cart Total: Rs. " << cartTotal << endl;
                            }
                            else if (choice2 == 5) {
                                cout << "Exiting Order Menu\n";
                            }
                            else {
                                ui::error("Invalid input.");
                            }
                        }
                    }
                    else{
                        ui::error("Invalid login details or index out of bounds.");
                        ui::info("Try signing up as a new customer or check your index.");
                    }
                }
                else if(choice1==2){
                    ui::section("New Customer Signup");
                    cout<<"Enter your username: ";
                    cin>>username;
                    cout<<"Enter your address: ";
                    cin>>address;
                    cout<<"Enter your email: ";
                    cin>>email;
                    cout<<"INDEX plz (0-2): \n";
                    cin>>idx;
                    if(idx >= 0 && idx < 3) {
                        cust[idx].setName(username);
                        cust[idx].setAddress(address);
                        cust[idx].setEmail(email);
                        cust[idx].setIdx(idx);
                        ui::success("Signup complete.");
                    } else {
                        ui::error("Invalid index. Must be 0, 1, or 2.");
                    }
                }
                else if(choice1==3){
                    ui::info("Exited.");
                }
            }
        }
        else if(choice==2){
            ui::section("Staff Access");
            ui::menuOption(1, "Login");
            ui::menuOption(2, "Exit");
            ui::prompt("Choose option: ");
            int staffChoice = 0;
            cin>>staffChoice;
            while(staffChoice!=2){
                if(staffChoice==1){
                    string sname;
                    string semail;
                    string sadd;
                    short rank;
                cout<<"Enter your username: ";
                cin>>sname;;
                cout<<"Enter your email: ";
                cin>>semail;
                cout<<"Enter your address: ";
                cin>>sadd;
                cout<<"RANK/n";
                
                cin>>rank;
               
            
            if(staff[rank].getName()==sname && staff[rank].getEmail()==semail && staff[rank].getAddress()==sadd){
                    ui::success("Login successful.");
                    staff[rank].displayStaff();
                    int choice3 = 0;
                    ui::section("Staff Menu");
                    ui::menuOption(1, "Add Stock to Inventory");
                    ui::menuOption(2, "Remove Stock from Inventory");
                    ui::menuOption(3, "Generate Inventory Report");
                    ui::menuOption(4, "View Customer Order History");
                    ui::menuOption(5, "View Sales Report");
                    ui::menuOption(6, "Exit");
                    ui::prompt("Select action: ");
                    cin>>choice3;
                    while(choice3!=6){
                        
                        if(choice3==1){
                            cout<<"ADD PRODUCT\n";
                            string id;
                            cout<<"product ID please\n";
                            cin>>id;
                            for(int i=0;i<size;i++){
                            if(id==products[i].getID()){
                                if(inventory[i].update(products[i].getID(),1,1)){
                                cout<<"Product added successfully\n";
                                }
                                break;
                            }
                            else if(i == size - 1){
                                cout<<"Product not available\n";
                            }
                            }
                        }
                        if(choice3==2){
                            cout<<"REMOVE PRODUCT\n";
                            string id;
                            cout<<"product ID please\n";
                            cin>>id;
                            for(int i=0;i<size;i++){
                                if(id==products[i].getID()){
                                    if(inventory[i].update(products[i].getID(),2,1)){
                                        cout<<"Product removed successfully\n";
                                    }
                                    break;
                                }
                                else if(i == size - 1){
                                    cout<<"Product not available\n";
                                }
                            }
                        }
                        if(choice3==3){
                            cout<<"Generate Inventory Report:\n";
                            int op=0;
                            cout<<"1. In-Stock Products Only\n";
                            cout<<"2. All Products \n";
                            cin>>op;
                            cout<<"--- INVENTORY REPORT ---\n";
                            for(int i=0;i<size;i++){
                                inventory[i].generateReport(op);
                            }
                            cout<<"--- END OF REPORT ---\n";
                        }
                        if(choice3==4){
                            cout<<"VIEW Customer History\n";
                            int cIdx=0;
                            cout<<"Enter Customer Index (0-2): ";
                            cin>>cIdx;
                            if (cIdx >= 0 && cIdx < 3) {
                                cust[cIdx].displayCustomer();
                                cust[cIdx].viewOrderHistory();
                            } else {
                                cout<<"Invalid Customer Index.\n";
                            }
                            cout<<endl;
                        }
                        if(choice3==5){
                            cout<<"\n*** SALES REPORT ***\n";
                            salesReport.printReport();
                            cout<<"Most Popular: "; salesReport.popularProducts();
                            cout<<"Total Revenue: Rs. "<<salesReport.getTotalSales()<<endl;
                        }
                        if(choice3==6){
                            cout<<"EXITTED\n";
                            break;
                        }
                        else if (choice3 < 1 || choice3 > 6){
                            cout<<"INVALID INPUT\n";
                            break;
                        }
                        cout << "Enter choice: ";
                        cin >> choice3;
                    }

                }
            
                else{
                    ui::error("Invalid username or password.");
                }
                ui::section("Staff Access");
                ui::menuOption(1, "Login");
                ui::menuOption(2, "Exit");
                ui::prompt("Choose option: ");
                cin >> staffChoice;
            }
            

            }


        }
        else{
            ui::error("Invalid choice.");
        }
        ui::prompt("Return to main menu (1/2/3): ");
        if(!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
    }
    ui::title("Thank you for visiting our store");
    cout << ui::DIM << "Muhammad Nayyar Ameer || 2530087" << ui::RESET << '\n';
    return 0;
}