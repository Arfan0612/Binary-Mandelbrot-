#include "CW4.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//testing functions
//used for testing the complex class complex math operations
void testComplexClass(){
    cout << "////////////////////////////////////////////////////////////////////////\n";
    Complex c1(4,5);
    cout << "c1 = " << c1.get_coord_x() << " + j(" << c1.get_coord_y() << ")\n";

    Complex c2(2,3);
    cout << "c2 = " << c2.get_coord_x() << " + j(" << c2.get_coord_y() << ")\n";
    cout << "////////////////////////////////////////////////////////////////////////\n";

    Complex c3;

    //Complex mathematics testings
    ////////////////addition
    c3 = c1+c2;
    cout << "c1 + c2 = " << c3.get_coord_x() << " + j(" << c3.get_coord_y() << ")\n";

    //////////////////subtraction
    c3 = c1-c2;
    cout << "c1 - c2 = " << c3.get_coord_x() << " + j(" << c3.get_coord_y() << ")\n";

    //////////////////multiplication
    c3 = c1*c2;
    cout << "c1*c2 = " << c3.get_coord_x() << " + j(" << c3.get_coord_y() << ")\n";

    //////////////////division
    c3 = c1/c2;
    cout << "c1/c2 = " << c3.get_coord_x() << " + j(" << c3.get_coord_y() << ")\n";

    //////////////////power operation by n
    c3 = c2^2;
    cout << "c2^2 = " << c3.get_coord_x() << " + j(" << c3.get_coord_y() << ")\n";

    //////////////////inverse
    c2.invert();
    cout << "c2^-1 = " << c2.get_coord_x() << " + j(" << c2.get_coord_y() << ")\n";

    //////////////////square
    c1.square();
    cout << "c1^2 = " << c1.get_coord_x() << " + j(" << c1.get_coord_y() << ")\n";

    //////////////////absolute
    double absolute = c1.abs();
    cout << "abs(c1) = " << absolute << endl;

}

//used for testing the print out of the MBS class
void testMBSClass(){
    int input = 0;
    int retry = 1;

    double xMin = -2, xStep = 0.02, xMax = 1; //the x-values to be tested
    double yMin = -1, yStep = 0.02, yMax = 1; //the y-values to be tested

    //usage of parameterized constructor
    Mandelbrot mbs(xMin, xStep, xMax, yMin, yStep, yMax);

    while(retry==1){
        cout << "Default Range (Enter 1) | specified Range (Enter any other integer)\n";
        cin >> input;

        if(input!=1){
            //process what mode user want to do
            //ask user for x parameters
            cout << "Enter parameters of the x and y ranges below:\n";
            cout << "xMin = ";
            cin >> xMin;
            cout << "xStep = ";
            cin >> xStep;
            cout << "xMax = ";
            cin >> xMax;

            //ask user for y parameters
            cout << "yMin = ";
            cin >> yMin;
            cout << "yStep = ";
            cin >> yStep;
            cout << "yMax = ";
            cin >> yMax;

            //re-allocate memory accordingly
            mbs.setRange(xMin, xStep, xMax, yMin, yStep, yMax);
        }

        //print the range chosen by the user
        mbs.printRange();

        //calculate whether a complex number is in the Mandelbrot set or not
        //print out the complex number being tested as well
        mbs.calcMBS();

        //print out the MBS
        mbs.printMBS();

        //ask user they want to retry
        cout << "Do you want to try with a different range? Yes(Enter 1) | No (Enter any other number)\n";
        cin >> retry;
    }
}

//used for evaluating the calcMBS()
void evalMBS(){
    int input = 0;
    int retry = 1;

    double xMin, xStep, xMax; //the x-values to be tested
    double yMin, yStep, yMax; //the y-values to be tested

    //default constructor so later on can use setRange()
    Mandelbrot mbs;

    while(retry==1){
        cout << "Default Range (Enter 1) | specified Range (Enter any other integer)\n";
        cin >> input;

        //let the user choose the range if chose not to use default range
        if(input!=1){
            //process what mode user want to do
            //ask user for x parameters
            cout << "Enter parameters of the x and y ranges below:\n";
            cout << "xMin = ";
            cin >> xMin;
            cout << "xStep = ";
            cin >> xStep;
            cout << "xMax = ";
            cin >> xMax;

            //ask user for y parameters
            cout << "yMin = ";
            cin >> yMin;
            cout << "yStep = ";
            cin >> yStep;
            cout << "yMax = ";
            cin >> yMax;

            //re-allocate memory accordingly
            mbs.setRange(xMin, xStep, xMax, yMin, yStep, yMax);
        }

        //print the range chosen by the user
        mbs.printRange();

        //calculate whether a complex number is in the Mandelbrot set or not
        //print out the complex number being tested as well
        mbs.calcMBS(input);

        //ask user they want to retry
        cout << "Do you want to try with a different range? Yes(Enter 1) | No (Enter any other number)\n";
        cin >> retry;
    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//Complex class
double Complex::get_coord_x(){
    return x;
}

double Complex::get_coord_y(){
    return y;
}

void Complex::setCoordinates(double x, double y){
    this -> x = x;
    this -> y = y;
}

void Complex::setcoord_x(double x){
    this -> x = x;
}

void Complex::setcoord_y(double y){
    this -> y = y;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//complex mathematics
void Complex::add(Complex c){
    //c.x represents x1 from the equation
    //c.y represents y1 from the equation
    //adding the x values
    x = x + c.x;

    //adding the y values
    y = y + c.y;
}

void Complex::sub(Complex c){
    //c.x represents x1 from the equation
    //c.y represents y1 from the equation
    //subtracting the x values
    x = x - c.x;

    //subtracting the y values
    y = y - c.y;
}

void Complex::mult(Complex c){
    //c.x represents x1 from the equation
    //c.y represents y1 from the equation
    double previous_x = 0;

    //store previous values of x before operation
    previous_x = x;

    //real part
    x = (x*c.x)-(y*c.y);

    //imaginary part
    y = (previous_x*c.y)+(c.x*y);
}

void Complex::div(Complex c){
    //c.x represents x1 from the equation
    //c.y represents y1 from the equation
    double previous_x = 0;

    //store previous values of x before operation
    previous_x = x;

    //computing multiplication for real part
    x = ((x*c.x)+(y*c.y))/(pow(c.x,2)+pow(c.y,2));

    //computing multiplication for imaginary part
    y = ((c.x*y)-(previous_x*c.y))/(pow(c.x,2)+pow(c.y,2));
}

void Complex::invert(){
    double previous_x = 0;

    //store previous values of x before operation
    previous_x = x;

    //real part
    x = x / (pow(x,2)+pow(y,2));

    //imaginary part
    y = (-1*y) / (pow(previous_x,2)+pow(y,2));
}

void Complex::square(){
    double previous_x;

    //store value of x before operation
    previous_x = x;

    //real part
    x = (x*x)-(y*y);

    //imaginary part
    y = (previous_x*y)+(previous_x*y);
}

double Complex::abs(){
    double absolute = 0.0;
    absolute = sqrt(pow(x,2)+pow(y,2));
    return absolute;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//overloading of math operators to work with complex numbers
Complex Complex::operator+(Complex comInput){
    Complex comOutput(x,y);
    comOutput.add(comInput);
    return comOutput;
}

Complex Complex::operator-(Complex comInput){
    Complex comOutput(x,y);
    comOutput.sub(comInput);
    return comOutput;
}

Complex Complex::operator*(Complex comInput){
    Complex comOutput(x,y);
    comOutput.mult(comInput);
    return comOutput;
}

Complex Complex::operator/(Complex comInput){
    Complex comOutput(x,y);
    comOutput.div(comInput);
    return comOutput;
}

Complex Complex::operator ^(int n){
    //object that will store the output
    Complex comOutput(x,y);

    //object that will be used to store the original complex
    Complex previous(x,y);

    //repeat multiplication by n number of times
    for(int i=1; i<n; i++){
        //pass the original complex each time
        comOutput.mult(previous);
    }

    return comOutput;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//Complex Derived Mandelbrot class

//default constructor definition
Mandelbrot::Mandelbrot(){
    //assigning values to x
    xMin = -2;
    xStep = 0.02;
    xMax = 1;

    //assigning values to y
    yMin = -1;
    yStep = 0.02;
    yMax = 1;

    //calculate value of Nx and Ny
    calcNxNy();

    //dynamically allocate memory for array
    MBS = new int[Nx*Ny];
}

//parameterized constructor definition
Mandelbrot::Mandelbrot(double xMin, double xStep, double xMax, double yMin, double yStep, double yMax){
    //set the range for the x values
    this ->xMin = xMin;
    this ->xStep = xStep;
    this ->xMax = xMax;

    //set the range for the y values
    this ->yMin = yMin;
    this ->yStep = yStep;
    this ->yMax = yMax;

    //calculate value of Nx and Ny
    calcNxNy();

    //dynamically allocate memory for array
    MBS = new int[Nx*Ny];
}

//to calculate Nx and Ny based on the range given
void Mandelbrot::calcNxNy(){
    //calculating value for Nx
    for(double i=xMin; i<=xMax; i+=xStep){
        //increment value of Nx
        Nx++;
    }

    //calculating value for Ny
    for(double j=yMin; j<=yMax; j+=yStep){
        //increment value of Ny
        Ny++;
    }
}

//prints out values of x, y, Nx, and Ny for the user to validate its correctness
void Mandelbrot::printRange(){
    cout << "Mandelbrot set range:\n";
    cout << "x:[" << xMin << ":" << xStep << ":" << xMax << "], Nx = " << Nx << endl;
    cout << "y:[" << yMin << ":" << yStep << ":" << yMax << "], Ny = " << Ny << endl;
}

//to determine whether the point is in Mandelbrot Set or not
void Mandelbrot::calcMBS(){
    cout << "In function calcMBS()\n";

    Complex z;
    Complex c;

    //store the absolute value of z
    double absolute = 0.0;

    //control the while loop
    int control = 0;

    //max iteration to determine whether z diverges or converges
    int max_iterations = 255;

    //for position of 0 or 1 in the MBS array
    int k = 0;

    //access column
    for(double i=yMin; i<=yMax; i+=yStep){
        //access row by row for that colomn
        for(double j=xMin; j<=xMax; j+=xStep){
            //c part of the equation
            c.setCoordinates(j,i);

            //set z to initial conditions which is 0+j0
            z.setCoordinates(0,0);

            //determining if c is in the Mandelbrot set or not
            //if z diverges, c is not in Mandelbrot set
            //if z converges, c is in Mandelbrot set
            while(control < max_iterations && absolute <=2){
                //z^2 part of the equation
                z.square();

                //result = z^2 + c equation
                z = z + c;

                //take the absolute of the result
                absolute = z.abs();

                //increment the counter
                control++;
            }

            //if the while goes until 20 times, that means c causes the z to converge
            //hence this c is in the Mandelbrot set
            if(control==max_iterations){
                MBS[k] = 1;
            }
            else{
                MBS[k] = 0;
            }

            //reset variables controlling the while loop above
            control = 0;
            absolute = 0.0;

            //keep track of the position in the MBS array
            k++;
        }
    }
}

//overload the calcMBS() just for testing the class
//this version prints out the complex numbers
void Mandelbrot::calcMBS(int input){
    cout << "In function calcMBS()\n";

    Complex z;
    Complex c;

    //store the absolute value of z
    double absolute = 0.0;

    //control the while loop
    int control = 0;

    //max iteration to determine whether z diverges or converges
    int max_iterations = 20;

    //for position of 0 or 1 in the MBS array
    int k = 0;

    //access column
    for(double i=yMin; i<=yMax; i+=yStep){
        //access row by row for that colomn
        for(double j=xMin; j<=xMax; j+=xStep){
            //testing to see if this one complex number diverges or converges
            //c part of the equation
            c.setCoordinates(j,i);
            cout << "/////////////////////////////////////\n";
            cout << "c = " << c.get_coord_x() << " + j(" << c.get_coord_y() << ")\n";
            cout << "/////////////////////////////////////\n";

            //set z to initial conditions which is 0+j0
            z.setCoordinates(0,0);

            //determining if c is in the Mandelbrot set or not
            //if z diverges, c is not in Mandelbrot set
            //if z converges, c is in Mandelbrot set
            while(control < max_iterations && absolute <=2){
                //z^2 part of the equation
                z.square();
                cout << "z^2 = " << z.get_coord_x() << " + j(" << z.get_coord_y() << ")\n";

                //result = z^2 + c equation
                z = z + c;
                cout << "new z = " << z.get_coord_x() << " + j(" << z.get_coord_y() << ")\n";

                //take the absolute of the result
                absolute = z.abs();
                cout << "abs = " << absolute << endl << endl;

                //increment the counter
                control++;
            }

            //if the while goes until 20 times, that means c causes the z to converge
            //hence this c is in the Mandelbrot set
            if(control==max_iterations){
                cout << "This c is in Mandelbrot set.\n";
                MBS[k] = 1;
            }
            else{
                cout << "This c is NOT in Mandelbrot set.\n";
                MBS[k] = 0;
            }

            //reset variables controlling the while loop above
            control = 0;
            absolute = 0.0;

            //keep track of the position in the MBS array
            k++;
        }
    }
}

//this function called if user wants to explore different ranges in one continuous session
void Mandelbrot::setRange(double xMin, double xStep, double xMax, double yMin, double yStep, double yMax){
    //set the range for the x values
    this ->xMin = xMin;
    this ->xStep = xStep;
    this ->xMax = xMax;

    //set the range for the y values
    this ->yMin = yMin;
    this ->yStep = yStep;
    this ->yMax = yMax;

    //recomputes the values for Nx and Ny
    calcNxNy();

    //frees the old memory
    delete[] MBS;

    //reallocates new memory for MBS array
    MBS = new int [Nx*Ny];
}

//print out the determined Mandelbrot set
void Mandelbrot::printMBS(){
    cout << "In function printMBS()\n";
    int k =0;

    //just for intializing everything in the array to be zero for testing printing
//    for(int i=0; i<(Nx*Ny); i++){
//        MBS[i]=0;
//    }

    //printing a 1D array as a 2D array
    //accessing each row
    for(int i=0; i<Ny; i++){
        //accessing each colomn in that row
        for(int j=0; j<Nx; j++){
            cout << MBS[k];
            k++;
        }
        //make sure next row is printed below the current row
        cout << "\n";
    }
}



