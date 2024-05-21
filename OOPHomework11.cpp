#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Task1

//class Equation 
//{
//public:
//    virtual double solve() = 0;
//};
//class LinearEquation : public Equation 
//{
//private:
//    double a, b;
//public:
//    LinearEquation(double a1, double b1) : a(a1), b(b1) {}
//    double solve() override
//    {
//        if (a == 0)
//        {
//            if (b == 0) 
//            {
//                cout << "The equation has an infinite number of roots" << endl;
//            }
//            else
//            {
//                cout << "The equation has no roots" << endl;
//            }
//        }
//        else 
//        {
//            return -b / a;
//        }
//    }
//};
//class QuadraticEquation : public Equation
//{
//private:
//    double a, b, c;
//public:
//    QuadraticEquation(double a1, double b1, double c1) : a(a1), b(b1), c(c1) {}
//    double solve() override 
//    {
//        double discriminant = b * b - 4 * a * c;
//        if (discriminant > 0) 
//        {
//            double root1 = (-b + sqrt(discriminant)) / (2 * a);
//            double root2 = (-b - sqrt(discriminant)) / (2 * a);
//            cout << "Root: " << root1 << ", " << root2 << endl;
//        }
//        else if (discriminant == 0)
//        {
//            double root = -b / (2 * a);
//            cout << "Root: " << root << endl;
//        }
//        else 
//        {
//            cout << "The equation has no real roots" << endl;
//            return -1;
//        }
//    }
//};

//Task2
class Shape 
{
public:
    virtual ~Shape() {}
    virtual void Show() const = 0;
    virtual void Save(ofstream& out) const = 0;
    virtual void Load(ifstream& in) = 0;
};
class Rectangle : public Shape 
{
private:
    int x, y;
    int width, height;
public:
    Rectangle() : x(0), y(0), width(0), height(0) {}
    Rectangle(int x, int y, int width, int height): x(x), y(y), width(width), height(height) {}
    void Show() const override 
    {
        cout << "Rectangle at (" << x << ", " << y << ") with width "
            << width << " and height " << height << endl;
    }
    void Save(ofstream& out) const override
    {
        out << "Rectangle " << x << " " << y << " " << width << " " << height << endl;
    }
    void Load(ifstream& in) override 
    {
        in >> x >> y >> width >> height;
    }
};
int main()
{
    //Task1

   /* LinearEquation linearEquation(2, 5);
    cout << "Linear equation: 2x + 5 = 0" << endl;
    double linearRoot = linearEquation.solve();
    if (linearRoot != -1) 
    {
        cout << "Root: " << linearRoot << endl;
    }

    QuadraticEquation quadraticEquation(1, 4, 4);
    cout << "Quadratic equation: x^2 + 4x + 4 = 0" << endl;
    double quadraticRoot = quadraticEquation.solve();*/

    //Task2
    const int numShapes = 2;
    Shape* shapes[numShapes];
    shapes[0] = new Rectangle(10, 20, 30, 40);
    shapes[1] = new Rectangle(50, 60, 70, 80);

    ofstream outFile("shapes.txt");
    if (outFile.is_open()) 
    {
        for (int i = 0; i < numShapes; ++i)
        {
            shapes[i]->Save(outFile);
        }
        outFile.close();
    }
    else {
        cerr << "Error opening file for writing" << endl;
    }
    for (int i = 0; i < numShapes; ++i) 
    {
        delete shapes[i];
    }
    ifstream inFile("shapes.txt");
    if (inFile.is_open()) 
    {
        string shapeType;
        for (int i = 0; i < numShapes; ++i)
        {
            inFile >> shapeType;
            if (shapeType == "Rectangle")
            {
                Rectangle* rect = new Rectangle();
                rect->Load(inFile);
                shapes[i] = rect;
            }
        }
        inFile.close();
    }
    else
    {
        cerr << "Error opening file for reading" << endl;
    }
    for (int i = 0; i < numShapes; ++i) 
    {
        shapes[i]->Show();
        delete shapes[i];
    }

}