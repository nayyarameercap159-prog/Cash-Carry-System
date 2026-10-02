

# 🛒 Cash & Carry System

**A console-based Cash & Carry store management system written in C++ using Object-Oriented Programming.**

Customers can log in, browse products, build a cart and place orders. Staff can manage stock, view inventory reports, check customer order history and see sales reports, all from a colorful terminal interface.

![C++](https://img.shields.io/badge/C%2B%2B-OOP-blue?logo=cplusplus)
![Platform](https://img.shields.io/badge/platform-Windows-lightgrey)

---

## ✨ Features

### 👤 Customer
- Log in with name, email and address
- Add products to a cart and remove them
- Place orders (stock is checked and reduced)
- View order history

### 🧑‍💼 Staff
- Update stock (add or reduce quantity)
- Generate inventory reports (in-stock only, or all products)
- View a customer's order history
- View the sales report: order history, total revenue and most popular product

### 📊 Sales Report
- Stores every placed order
- Calculates total revenue (Rs.)
- Finds the most popular product

---

## 🧱 OOP Concepts Demonstrated

| Concept | Where it is used |
|---|---|
| **Encapsulation** | Private data members with getters/setters in every class |
| **Composition** | `Order` contains a `Customer` and `Product` array; `SalesReport` stores `Order` objects |
| **Operator overloading** | `<<` and `>>` for `Product`, `Customer`, `Order`; `+` for `Product` |
| **Dynamic memory** | Dynamic arrays with `new[]` / `delete[]` (no STL containers) |
| **Rule of Three** | Copy constructor, copy assignment and destructor in `Customer` and `Order` |
| **Friend functions** | Stream operators declared as friends |
| **Default arguments** | Constructors with default values |

---

## 📁 Project Structure

```
cash-and-carry/
├── pCcarry.cpp      # Main program (menus, UI, Customer method definitions)
├── Product.h        # Product class
├── Customer.h       # Customer class (cart + order history)
├── Order.h          # Order class
├── Inventory.h      # Inventory management
├── SalesReport.h    # Sales report and statistics
└── Staff.h          # Staff class
```

### Class Relationships

```
Customer ──has──► Product[] (cart), Order[] (history)
Order ──has──► Customer, Product[]
Inventory ──manages──► Product[]
SalesReport ──stores──► Order[]
Staff ──has──► Product[] (report)
```

---

## 🚀 Getting Started

### Requirements
- A C++ compiler (g++ / MinGW / Dev-C++ / Visual Studio)
- **Windows** (the colored UI uses `<windows.h>`)

### Build and Run

```bash
g++ pCcarry.cpp -o cashandcarry
cashandcarry.exe
```

---

## 🖥️ How to Use

1. Run the program and choose your role (Customer or Staff).
2. **Customer:** enter your details, add products to the cart, then place an order.
3. **Staff:** manage inventory, view reports and customer history.

> The system currently supports 3 customers (index 0-2).

---

## ⚠️ Known Limitations

- Data is kept in memory only and is lost when the program closes
- Fixed number of customers (3)
- Windows-only because of `<windows.h>`
- No login passwords

---

## 🔮 Future Improvements

- Save and load data using file handling
- Cross-platform support
- Dynamic customer registration
- Staff authentication
- Discounts and tax

---

## 👨‍💻 Author

**Muhammad Nayyar Ameer**
GitHub: [@your-username](https://github.com/your-username)

## 📄 License

MIT License. See [LICENSE](LICENSE).
