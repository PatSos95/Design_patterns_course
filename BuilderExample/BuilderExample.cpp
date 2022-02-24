#include <iostream>
#include <memory>

/* Car parts */
class Wheel
{
public:
    int size;
};

class Engine
{
public:
    int horsepower;
};

class Body
{
public:
    std::string shape;
};

/* Final product -- a car */
class Car
{
public:
    Wheel wheels[4];
    Engine engine;
    Body body;

    void specifications()
    {
        std::cout << "body:" << body.shape << std::endl;
        std::cout << "engine horsepower:" << engine.horsepower << std::endl;
        std::cout << "tire size:" << wheels[0].size << "'" << std::endl;
    }
};

class CarBuilderInterface
{
public:
    virtual std::unique_ptr<Car> createCar() = 0;
};

class JeepBuilder : public CarBuilderInterface
{
public:
    std::unique_ptr<Car> createCar()
    {
        std::unique_ptr<Car> car = std::make_unique<Car>();
        car->body
    }
    
};



int main()
{
    std::cout << "Hello World!\n";
}

