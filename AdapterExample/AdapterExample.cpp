// This example of the Adapter pattern is based on the classic conflict between square pegs and round holes.

#include <iostream>

class RoundPeg
{
public:
	RoundPeg(float radius) : radius_(radius) {}

	float getRadius()
	{
		return radius_;
	}

private:
	float radius_;
};

class SquarePeg
{
public:
	SquarePeg(float width) : width_(width) {}

	float getWidth()
	{
		return width_;
	}

private:
	float width_;
};

class SquarePegAdapter : public RoundPeg
{
public:
	SquarePegAdapter(const SquarePeg& square_peg) : RoundPeg(0), square_peg_(square_peg) {}

	double getRadius()
	{
		return square_peg_.getWidth() * 2 / sqrt(2);
	}

private:
	SquarePeg square_peg_;
};

class RoundHole
{
public:
	RoundHole(float radius) : radius_(radius) {}

	bool if_fits(RoundPeg round_peg)
	{
		return round_peg.getRadius() < radius_;
	}

private:
	float radius_;
};



int main()
{
	RoundHole(10);
	SquarePeg(5);
	SquarePegAdapter(SquarePeg);

    std::cout << "Hello World!\n";
}

