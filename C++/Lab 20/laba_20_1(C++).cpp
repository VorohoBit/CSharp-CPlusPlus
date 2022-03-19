#include <iostream>
using namespace std;

template<typename T>
class Myclass
{
private:
    T value;
public:
    Myclass(T value)
    {
        this->value = value;
    }
    void Data()
    {
        cout << sizeof
        (value) << endl;
    }
    Myclass<T>& operator+(const Myclass<T>& tmp)
    {
        value =value+ tmp.value;
        return *this;
    }
};
class Point
{
private:
    int x, y, z;
public:
    Point()
    {
        x = y = z = 0;
    }
    Point(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Point& operator+(const Point& tmp)
    {
        x =x+ tmp.x;
        y =y+ tmp.x;
        z =z+ tmp.z;
        return *this;
    }
};

int main()
{
    Point a(10,10,10);
    Myclass<Point> c(a);
    Myclass<Point> d(a);
    Myclass<Point> e(a);
    e = c + d;
    e.Data();
    return 0;
}

