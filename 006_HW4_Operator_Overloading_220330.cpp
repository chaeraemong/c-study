#include <iostream>
using namespace std;

class IntCoor
{
    int x, y;
public:
    IntCoor(int cx = 0, int cy = 0) :x(cx), y(cy) {}
    const IntCoor operator++();
    const IntCoor operator++(int);
    friend const IntCoor operator+(const IntCoor& a, const IntCoor& b);
    friend const IntCoor operator-(const IntCoor& a, const IntCoor& b);
    friend bool operator==(const IntCoor& a, const IntCoor& b);
    friend const IntCoor operator-(const IntCoor& a);
    friend ostream& operator<<(ostream& out, const IntCoor& a);
    friend istream& operator>>(istream& in, IntCoor& a);
};

int main()
{
    IntCoor a;
    cout << "Enter two integers for coordinates: ";
    cin >> a;

    IntCoor b = a++;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "a+b: " << a + b << endl << endl;

    a = -a;
    IntCoor c = ++a;
    cout << "a: " << a << endl;
    cout << "c: " << c << endl;
    if (a == c) cout << "same" << endl;
    else cout << "not same" << endl;
    cout << "a-c: " << a - c << endl << endl;

    return 0;
}

const IntCoor IntCoor::operator++()
{
    return IntCoor(++x, ++y);
}

const IntCoor IntCoor::operator++(int)
{
    int temp1 = x;
    int temp2 = y;
    x++;
    y++;

    return IntCoor(temp1, temp2);
}

const IntCoor operator+(const IntCoor& a, const IntCoor& b)
{
    return IntCoor(a.x + b.x, a.y + b.y);
}

const IntCoor operator-(const IntCoor& a, const IntCoor& b)
{
    return IntCoor(a.x - b.x, a.y - b.y);
}

bool operator==(const IntCoor& a, const IntCoor& b)
{
    return a.x == b.x && a.y == b.y;
}

const IntCoor operator-(const IntCoor& a)
{
    return IntCoor(-a.x, -a.y);
}

ostream& operator<<(ostream& out, const IntCoor& a)
{
    out << "(" << a.x << "," << a.y << ")";
    return out;
}

istream& operator>>(istream& in, IntCoor& a)
{
    in >> a.x;
    in >> a.y;

    return in;
}

/*
모두 구현한 후 위 코드를 실행시키면 결과 예는 다음과 같습니다.

Enter two integers for coordinates: 1 2
a : (2, 3)
b : (1, 2)
a + b : (3, 5)

a: (-1, -2)
c : (-1, -2)
same
a - c : (0, 0)
*/
