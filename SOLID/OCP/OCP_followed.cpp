#include <iostream>
#include <vector>
using namespace std;

class Products {
    public : 
    string name;
    double price;

    Products(string name, double price){
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart {
    private: 
    vector<Products*> products;

    public:
    void addProduct(Products *p){
        products.push_back(p);
    }

    const vector<Products*> &getProducts(){
        return products;
    }

    double calculateTotal(){
        double total = 0;
        for(auto p: products){
            total += p->price;
        }
        return total;
    }

};

class ShoppingCartPrinter {
    private:
    ShoppingCart* cart;

    public:
    ShoppingCartPrinter(ShoppingCart *cart){
        this->cart = cart;
    }

    void printInvoice(){
        cout << "Shopping cart Invoice :\n";
        for(auto p : cart->getProducts()){
            cout << p->name << "-RS" << p->price;
        }

        cout << "Total :Rs" << cart->calculateTotal() <<endl;
    }
};

class Persistence{
    private:
    ShoppingCart* cart;

    public:
    virtual void save(ShoppingCart* cart) = 0;

};

class SQLPersistence : public Persistence{
    public:
    void save(ShoppingCart* cart) override {
        cout << "saving shopping cart to SQL DB..";
    }
};

class MongoPersistence : public Persistence {
public:
    void save(ShoppingCart* cart) override {
        cout << "Saving shopping cart to MongoDB..." << endl;
    }
};

class FilePersistence : public Persistence {
public:
    void save(ShoppingCart* cart) override {
        cout << "Saving shopping cart to a file..." << endl;
    }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();
    Products* p1 = new Products("lap",50000);
     Products* p2 = new Products("laptop",50001);

    cart->addProduct(p1);
    cart->addProduct(p2);

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

     Persistence* db = new SQLPersistence();
    Persistence* mongo = new MongoPersistence();
    Persistence* file = new FilePersistence();

    db->save(cart);   // Save to SQL database
    mongo->save(cart); // Save to MongoDB
    file->save(cart);  // Save to File

    return 0;


}