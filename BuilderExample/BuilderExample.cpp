#include <iostream>
#include <memory>
#include <vector>

class Product
{
public:
	std::vector<std::string> elements_;
	void display_product_specification()
	{
		for (const auto& el : elements_)
		{
			std::cout << el << ", ";
		}
	}
};

class Builder
{
public:
	virtual void buildElement1() = 0;
	virtual void buildElement2() = 0;
	virtual void buildElement3() = 0;

	virtual const Product& getProduct() = 0;
	
	virtual ~Builder() {}
};

class ConcreteBuilder1 : public Builder
{
public:
	ConcreteBuilder1()
	{
		product1_ = std::make_unique<Product>();
	}

	void buildElement1()
	{
		product1_->elements_.push_back("Element1Builder1");
	}

	void buildElement2()
	{
		product1_->elements_.push_back("Element2Builder1");
	}

	void buildElement3()
	{
		product1_->elements_.push_back("Element3Builder1");
	}

	const Product& getProduct()
	{
		return *product1_;
	}

private:
	std::unique_ptr<Product> product1_;
};

class BuilderDirector
{
public:
	BuilderDirector(std::shared_ptr<Builder> builder)
	{
		builder_ = builder;
	}

	void buildMinimalFeaturedProduct()
	{
		builder_->buildElement1();
	}

	void buildFullFeaturedProduct()
	{
		builder_->buildElement1();
		builder_->buildElement2();
		builder_->buildElement3();
	}

private:
	std::shared_ptr<Builder> builder_;
};


int main()
{
	std::shared_ptr<Builder> builder = std::make_shared<ConcreteBuilder1>();
	BuilderDirector director(builder);
	director.buildMinimalFeaturedProduct();

	Product my_product = builder->getProduct();
	my_product.display_product_specification();
}

