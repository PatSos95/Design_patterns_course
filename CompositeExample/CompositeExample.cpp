#include <iostream>
#include <vector>
#include <functional>

class Product
{
public:
    Product(int price, std::string name) : price_(price), name_(name) {}

    virtual int getPrice()
    {
        return price_;
    }

    virtual std::string getName()
    {
        return name_;
    }

protected:
    int price_;
    std::string name_;
};

class SpecificProduct : public Product
{
public:
    SpecificProduct(std::string name) : Product(10, name) {}
};

class Box : public Product
{
public:
    Box(std::string name) : Product(2, name) {}

    int getPrice()
    {
        for (const auto& product : productsInside_)
        {
            std::string name = product.get().getName();
            int price = product.get().getPrice();
            std::cout << "Product: " << name << "   Price: " << price << "\n";
            price_ += price;
        }
        return price_;
    }

    void addProduct(std::reference_wrapper<Product> product)
    {
        productsInside_.push_back(product);
    }


private:
    std::vector<std::reference_wrapper<Product>> productsInside_;
};

int main()
{
    Box box1("box1");
    Box box1_1("box1_1");
    Box box1_2("box1_2");
    Box box1_3("box1_3");
    Box box1_1_1("box1_1_1");
    Box box1_1_2("box1_1_2");

    SpecificProduct product1("product1");
    SpecificProduct product1_1("product1_1");
    SpecificProduct product1_2("product1_2");
    SpecificProduct product1_3("product1_3");
    SpecificProduct product1_1_1("product1_1_1");
    SpecificProduct product1_1_2("product1_1_2");
    SpecificProduct product1_1_2no2("product1_1_2no2");

    // 1st layer
    box1.addProduct(box1_1);
    box1.addProduct(box1_2);
    box1.addProduct(box1_3);
    box1.addProduct(product1);

    // 2nd layer
    box1_1.addProduct(box1_1_1);
    box1_1.addProduct(box1_1_2);
    box1_1.addProduct(product1_1);
    
    box1_2.addProduct(product1_2);

    box1_3.addProduct(product1_3);

    // 3rd layer
    box1_1_1.addProduct(product1_1_1);

    box1_1_2.addProduct(product1_1_2);
    box1_1_2.addProduct(product1_1_2no2);

    std::cout << "Price: " << box1.getPrice();
}

