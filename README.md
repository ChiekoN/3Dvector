# C++ Implementation of a vector class

I implemented my own vector class in C++. While I was learning [Linear Algebra Refresher Course in Udacity](https://www.udacity.com/course/linear-algebra-refresher-course--ud953), I implemented my own vector class in **Python** to learn about vector. This implementation is basically a C++ version of it.

## Explanation
I implemented a 3D vector class called `Evector`. This class can do:
-  \+ operation
-  \- operation
- \* operation
- \/ operation
- get the vector's **magnitude**
- get two vector's **dot product**
- **Normalizing** the vector (to get the unit vector)
- get two vector's **cross product**
- \== operation

Also I overloaded `<<` operator to print elements of the 3D vector.

## Execution
```
$ g++ -std=c++17 3DVector.cpp
$ ./a.out
```
 
