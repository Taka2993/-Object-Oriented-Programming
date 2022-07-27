#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>



using namespace std;

//definition of class Point
class Point {
public:
    //constructor
    Point(double xcoord = 0.0, double ycoord = 0.0);
    // destructor
    virtual ~Point() = default;
    virtual void input(const char* prompt);
    virtual void output() const;
    virtual double area() const;
    void move(double deltax, double deltay);
private:
    double x;
    double y;
};

class Circle : public Point
{
public:
    Circle(double xcoord = 0.0, double ycoord = 0.0, double radius_zero = 0.0);
    virtual void input(const char* prompt) override;
    virtual void output() const override;
    virtual double area() const override;
private:
    double radius;
};

class Square : public Point
{
public:
    Square(double xcoord = 0.0, double ycoord = 0.0, double width_zero = 0.0, double height_zero = 0.0);
    virtual void input(const char* prompt) override;
    virtual void output() const override;
    virtual double area() const override;
private:
    double height;
    double width;
};

shared_ptr <Point> rnd();

int main()
{
    vector<shared_ptr <Point>> vect;
    vect.push_back(make_shared <Point>
                           (1.0, 1.0));

    vect.push_back(make_shared <Circle>
                           (2.0, 2.0, 2.0));

    vect.push_back(make_shared <Square>
                           (5.0, 5.0, 2.0, 2.0));

    Point input_point;
    input_point.input("Point:");
    vect.push_back(make_shared <Point>
                           (input_point));

    Circle input_circle;
    input_circle.input("Circle:");
    vect.push_back(make_shared <Circle>
                           (input_circle));

    Square input_square;
    input_square.input("Square:");
    vect.push_back(make_shared <Square>
                           (input_square));

    printf("\n\nOriginal Vector Values\n\n");
    for (auto element : vect)
    {
        element -> output();
        cout << endl;
    }

    sort(vect.begin(), vect.end(), [](shared_ptr<Point> first, shared_ptr<Point> second) -> bool
         {
             return first -> area() < second -> area();
         }
    );

    printf("\n\nSorted Vector Values\n\n");
    for (auto element : vect)
    {
        element -> output();
        cout << endl;
    }

    vect.clear();

    cout << endl;


    return 0;
}

shared_ptr <Point> rnd()
{
    int o = rand() % 3;

    if (o == 0)
    {
        Point point_col;
        point_col.input("Point:");
        return make_shared <Point> (point_col);

    }
    else if (o == 1)
    {
        Circle circle_col;
        circle_col.input("Circle:");
        return make_shared <Circle> (circle_col);
    }
    else
    {
        Square square_col;
        square_col.input("Square:");
        return make_shared <Square> (square_col);
    }
}

Point::Point(double xcoord, double ycoord) : x(xcoord), y(ycoord) {}

void Point::input(const char* prompt)
{
    cout << prompt << endl;

    printf("Enter x: ");
    cin >> x;

    printf("Enter y: ");
    cin >> y;
}

void Point::output() const
{
    printf("Coordinates: (");
    cout << x;
    printf(",");
    cout << y;
    printf(")");
}

double Point::area() const
{
    return 0.0;
}

void Point::move(double deltax, double deltay)
{
    x += deltax;
    y += deltay;
}

Circle::Circle(double xcoord, double ycoord, double radius_zero) : Point(xcoord, ycoord), radius(radius_zero) {}

void Circle::input(const char* prompt)
{
    Point::input(prompt);

    printf("Enter radius: ");
    cin >> radius;
}

void Circle::output() const
{
    printf("Circle's area: ");
    cout << area();
    printf(" ");
    Point::output();
}

double Circle::area() const
{
    return M_PI * pow(radius, 2);
}

Square::Square(double xcoord, double ycoord, double width_zero, double height_zero) : Point(xcoord, ycoord), width(width_zero), height(height_zero) {}

void Square::input(const char* prompt)
{
    Point::input(prompt);

    printf("Enter height: ");
    cin >> height;

    printf("Enter width: ");
    cin >> width;
}

void Square::output() const
{
    printf("Square's area: ");
    cout << area() << " ";
    Point::output();
}

double Square::area() const
{
    return height * width;
}