#include <iostream>
#include <cmath>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////
//testing functions
void testComplexClass();
void testMBSClass();
void evalMBS();

//////////////////////////////////////////////////////////////////////////////////////////////////////
//Complex class
class Complex{
private:
    //complex number
    double x; //real part
    double y; //imaginary part

public:
    //accessors
    double get_coord_x();
    double get_coord_y();

    //mutators
    void setCoordinates(double x, double y);
    void setcoord_x(double x);
    void setcoord_y(double y);

    //complex class default constructor
    Complex(){x=0; y=0;}

    //parameterized constructors
    Complex(double x, double y){setCoordinates(x,y);}

    //destructor
    ~Complex(){}

    //////////////////////////////////////////////////////////////////////////////////////////////////////
    //complex mathematics
    void add(Complex c); //add coordinate c to the internal coordinate
    void sub(Complex c); //subtract coordinate c from the internal coordinate
    void mult(Complex c); //multiplies the complex number c with the internal complex number
    void div(Complex c); //multiplies the inverse of complex number c with the internal complex number
    void invert(); //inverts the internal complex number.
    void square(); //squares the internal complex number
    double abs(); //returns the absolute value of the internal complex number

    //////////////////////////////////////////////////////////////////////////////////////////////////////
    //overloading of math operators to work with complex numbers
    Complex operator + (Complex comInput);
    Complex operator - (Complex comInput);
    Complex operator * (Complex comInput);
    Complex operator / (Complex comInput);
    Complex operator ^ (int n);

};


//////////////////////////////////////////////////////////////////////////////////////////////////////
//Complex Derived Mandelbrot class
class Mandelbrot:public Complex{
private:
    double xMin, xStep, xMax; //the x-values to be tested
    double yMin, yStep, yMax; //the y-values to be tested

    //number of x and y elements in each dimension of the Mandelbrot Set
    int Nx=0, Ny=0;

    //1D array representing a 2D array for the MBS
    int *MBS;
public:
    //default constructor
    Mandelbrot();

    //parameterized constructor to initialize the x and y values according to user demand
    Mandelbrot(double xMin, double xStep, double xMax, double yMin, double yStep, double yMax);

    //destructor
    ~Mandelbrot(){delete[] MBS;}

    //compute the values of Nx and Ny from the x and y values
    void calcNxNy();

    //prints out values of x, y, Nx, and Ny for the user to validate its correctness
    void printRange();

    //to determine whether the point is in Mandelbrot Set or not
    void calcMBS();

    //overload the calcMBS() just for testing the class
    //this version prints out the complex numbers
    void calcMBS(int input);

    //this function called if user wants to explore different ranges in a continuous session
    void setRange(double xMin, double xStep, double xMax, double yMin, double yStep, double yMax);

    //print out the determined Mandelbrot set
    void printMBS();
};
