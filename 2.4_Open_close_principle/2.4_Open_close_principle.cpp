#include <iostream>
#include <string>
#include <vector>

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product
{
    std::string name;
    Color color;
    Size size;
};


template <typename T>
struct Specification
{
    virtual bool isSatisfied(T* item) = 0;
};

template <typename T> 
struct Filter
{
    virtual std::vector<T*> filter(std::vector<T*> items, Specification<T>& spec) = 0;
};

struct FilterImpl : Filter<Product>
{
    std::vector<Product*> filter(std::vector<Product*> items, Specification<Product>& spec) override
    {
        std::vector<Product*> result;
        for (auto item : items)
        {
            if (spec.isSatisfied(item))
            {
                result.push_back(item);
            }
        }
        return result;
    }
};

struct ColorSpecification : Specification<Product>
{
    Color color;
    
    ColorSpecification(Color color) : color(color) {}

    bool isSatisfied(Product* item) override
    {
        return item->color == color;
    }
};

struct SizeSpecification : Specification<Product>
{
    Size size;

    SizeSpecification(Size size) : size(size) {}

    bool isSatisfied(Product* item) override
    {
        return item->size == size;
    }
};

struct AndSpecification : Specification <Product>
{
    Specification<Product>& first;
    Specification<Product>& second;

    AndSpecification(Specification<Product>& first, Specification<Product>& second) 
    : first(first), second(second) {}

    bool isSatisfied(Product* item) override
    {
        return first.isSatisfied(item) && second.isSatisfied(item);
    }
};

int main()
{
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    std::vector<Product*> items {&apple, &tree, &house};

    FilterImpl filter;
    ColorSpecification green {Color::green};
    SizeSpecification large {Size::large};
    AndSpecification greenAndLarge {green, large};

    std::vector<Product*> FilteredItems = filter.filter(items, greenAndLarge);

    for (auto item : FilteredItems)
    {
        std::cout << item->name << ", ";
    }
}
