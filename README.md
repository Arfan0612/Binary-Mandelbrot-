# Introduction
Mandelbrot set represented as either 1 or 0. This program was coded using CodeBlocks IDE.

# calcNxNy function

To determine the size of Nx, a for loop is used to loop based on the variables of xMin, xStep, and xMax. The same goes for finding Ny except the variables used are yMin, yStep, and yMax. The value of Nx and Ny will increase as the for loop runs.

![image](https://github.com/Arfan0612/Binary-Mandelbrot-/assets/94776851/fb5e5798-4402-483c-82fd-d4167738d29c)

# setRange function

This function is used to define the values of xMin, xStep, xMax, yMin, yStep, and yMax again if the user wants to explore different ranges to be tested with the Mandelbrot set. The function will take the new values of xMin, xStep, xMax, yMin, yStep, and yMax and assigns them accordingly into the Mandelbrot class. Then a function is used to determine the values of Nx and Ny is called to determine the new Nx and Ny. After that the old memory allocated for the MBS array is freed and new memory is re-allocated into the MBS based on the new values of Nx and Ny. 

![image](https://github.com/Arfan0612/Binary-Mandelbrot-/assets/94776851/e888e280-3399-4306-b969-eec47ced4fe6)

# Determining whether it converges or diverges

Equation used for the iterations is z= z^2+c. It is a known fact that if the absolute of z is ever larger than 2 for a complex c, that complex c is not in the Mandelbrot set. 
While if z converges for a value of complex c, no matter the iterations, the values of absolute z will never be 2 or above. So, for now the number of iterations to determine whether a complex c is in the Mandelbrot set is 20 iterations of z. If the z only converges for a complex c after the 20 iterations, it means that the complex c is in the Mandelbrot set.

# calcMBS function

Object z and object c are created to represent z and c respectively from the equation. Variable ‘absolute’ of type double is used to store the value of absolute z. Variable ‘control’ of type integer is used to keep track the number of iterations that has occurred for when testing a complex c. Variable ‘k’ of type integer is then used for knowing the position of where the complex c is in the MBS array. There were two for loops used to get the complex c based on the ranges determined by the user. The first loop is used to get the imaginary part of the complex number and the second for loop is used for getting the real part of the complex number. Then the obtained real and imaginary part to passed to object c of type Complex. This is followed by setting the initial value z of type Complex to 0.

What determines whether absolute of z diverges or converges is the 3rd nested loop which is the while loop. The condition for this loop to keep looping is that the variable ‘control’ must be less than the variable ‘max_iterations’ and that the absolute of z is less or equals to 2. As mentioned in the previous section, complex c is in the Mandelbrot set if the absolute z never exceeds 2 no matter the number of iterations. Since infinite number of iterations is not practical, the max number of iterations is set to 255. The max iterations is now set to 255 instead of 20 is because with 255 iterations the printing of the Mandelbrot set is more correct compared with 20 iterations.

![image](https://github.com/Arfan0612/Binary-Mandelbrot-/assets/94776851/7396afac-98ed-488a-8444-bf8af5ff6015)

Max iteration of 20:

![image](https://github.com/Arfan0612/Binary-Mandelbrot-/assets/94776851/b693188f-9e3b-4583-ab6f-17b09b1691de)

Max iteration of 255:

![image](https://github.com/Arfan0612/Binary-Mandelbrot-/assets/94776851/fcabfc7f-9f97-4cb2-9384-5ffd7fe5a011)

After the while loop finishes, if the variable ‘control’ values is the same as ‘max_interations’, this means absolute of z converges for that value of complex c. Hence that complex c is in the Mandelbrot set and this point is set to 1 in the MBS array. Otherwise, if the absolute z diverges for that value of complex c, variable ‘control’ will hold less than ‘max_iteration’. Leading to that point set to 0 in MBS array as it is not in the Mandelbrot set. After deciding whether the complex c belongs in the Mandelbrot set or not, the variable ‘control’ and ‘absolute’ is reset back to 0 for the next complex c. In addition, the value of variable ‘k’ increments to indicate the next point in the MBS array. 



