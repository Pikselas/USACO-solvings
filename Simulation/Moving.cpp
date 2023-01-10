/*
    Alice and Bob are standing on a 2D plane. Alice starts at the point (0, 0), and Bob
    starts at the point (R, S) (1 ≤ R, S ≤ 1000). Every second, Alice moves M units to the
    right, and N units up. Every second, Bob moves P units to the left, and Q units down.
    (1 ≤ M, N, P, Q ≤ 10). Determine if Alice and Bob will ever meet (be at the same point at
the same time), and if so, when
*/

#include<iostream>
class Position
{
    private:
        int x , y;
    public:
        Position(int x , int y) : x(x) , y(y) {}
        bool operator == (const Position p)
        {
            return (p.x == x) && (p.y == y);
        }
        bool operator< (const Position p)
        {
           return (x < p.x) && (y < p.y);
        }
        Position operator+= (const Position p)
        {
            x += p.x;
            y += p.y;
            return *this;
        }
};

int main()
{
    unsigned int time = 0;
    auto Alice = Position{0 , 0};
    auto Bob = Position {15 , 15};
    auto AliceVelocity = Position{3,3};
    
    //Bob moves backwards (i.e left and down)
    auto BobVelocity = Position{-3,-3};

    //Loop until Alice/Bob crosses/meets each other
    while(Alice < Bob)
    {
        Alice += AliceVelocity;
        Bob += BobVelocity;
        time++;
    }
    if(Alice == Bob)
    {
        std::cout << "WILL MEET IN time:" << time;
    }
    return 0;
}
