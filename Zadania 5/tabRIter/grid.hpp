#ifndef GRID_HPP_INCLUDED
#define GRID_HPP_INCLUDED

class Grid
{
    private:
        int x_, y_;

    public:
        Grid(int x=0, int y=0) : x_(x), y_(y) {}

        int X(void) const
        {
            return x_;
        }

        int Y(void) const
        {
            return y_;
        }
};

bool operator==(Grid g1, Grid g2)
{
    return (g1.X()==g2.X())&&(g1.Y()==g2.Y());
}

std::ostream& operator<<(std::ostream& wy, Grid g)
{
    return wy<<'('<<g.X()<<','<<g.Y()<<')';
}

#endif // GRID_HPP_INCLUDED
