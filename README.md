<div align="center">
  <h1> 🌐 Matrix
  </h1>
</div>

---

Matrix is a 42 project where you have to create a library about Vector and Matrix space.

This project is aimed around math and what you can do with Vectors and Matrix in Computer Science.

![Static Badge](https://img.shields.io/badge/language-c%2B%2B17-blue)

## Summary

- [Use the Library](#use-the-library)
- [Run Locally the Tester](#run-locally-the-tester)
- [Functions](#functions)
- [Documentation](#documentation)
  - [Add](#add)
  - [Sub](#sub)
  - [Scl](#scl)
  - [Linear Combination](#linear-combination)
  - [Linear Interpolation](#linear-interpolation)
- [Sources](#sources)


## Use the Library

Clone the project

```bash
  git clone https://github.com/drabiot/matrix.git
```

Include the lib

```bash
  ./matrix/inc/Core/matlib.hpp
```

## Run Locally the Tester

Clone the project

```bash
  git clone https://github.com/drabiot/matrix.git
```

Go to the project directory

```bash
  cd matrix
```

Compile the project

```bash
  make -j
```

Open the project

```bash
  //Run all the Test
  ./matrix

  //Check all the specific Test you can do
  ./matrix help

  //Run specific Test
  ./matrix <name_of_your_function>
```

## Functions

| Function | Description |
| -------- | ----------- |
| Add | Adds two vectors or matrices element-wise |
| Sub | Subtracts two vectors or matrices element-wise |
| Scl | Scales a vector or matrix by a scalar |
| Linear Combination | Returns a linear combination of vectors with given coefficients |

## Documentation

### ADD
Adds two vectors or matrices element-wise. Modifies the object in-place.

```cpp
void    Vector::add(const Vector &v);
void    Matrix::add(const Matrix &m);
```

| | Vector | Matrix |
|---|---|---|
| Time complexity | O(n) | O(n·m) |
| Space complexity | O(1) | O(1) |

```cpp
Vector u({1.0, 2.0, 3.0});
Vector v({4.0, 5.0, 6.0});

u.add(v); // u = {5.0, 7.0, 9.0}
```

---

### SUB
Subtracts two vectors or matrices element-wise. Modifies the object in-place.

```cpp
void    Vector::sub(const Vector &v);
void    Matrix::sub(const Matrix &m);
```

| | Vector | Matrix |
|---|---|---|
| Time complexity | O(n) | O(n·m) |
| Space complexity | O(1) | O(1) |

```cpp
Vector u({1.0, 2.0, 3.0});
Vector v({4.0, 5.0, 6.0});

u.sub(v); // u = {-3.0, -3.0, -3.0}
```

---

### SCL
Multiplies every element by a scalar. Modifies the object in-place.

```cpp
void    Vector::scl(const K &a);
void    Matrix::scl(const K &a);
```

| | Vector | Matrix |
|---|---|---|
| Time complexity | O(n) | O(n·m) |
| Space complexity | O(1) | O(1) |

```cpp
Vector u({1.0, 2.0, 3.0});
Vector v({4.0, 5.0, 6.0});

u.sub(6); // u = {6.0, 12.0, 18.0}
v.sub(2); // u = {8.0, 10.0, 12.0}
```

---

### LINEAR COMBINATION
Returns the linear combination of vectors with given coefficients using `fma` for precision.

```cpp
Vector<K>	linear_combination(initializer_list<Vector<K>> u, initializer_list<K> coefs);
Vector<K>	linear_combination(initializer_list<Vector<K>> u, Vector<K> coefs);
Vector<K>	linear_combination(Matrix<K> u, initializer_list<K> coefs);
Vector<K>	linear_combination(Matrix<K> u, Vector<K> coefs);
```

| Time complexity | Space complexity |
|---|---|
| O(L × D) | O(D) |

> L = number of vectors, D = dimension of vectors

```cpp
Vector<float> v1({1.0, 0.0, 0.0});
Vector<float> v2({0.0, 1.0, 0.0});
Vector<float> v3({0.0, 0.0, 1.0});

auto res = linear_combination({v1, v2, v3}, {10.0, -2.0, 0.5}); // res = {10.0, 2.0, 0.5}
```

```math
\begin{bmatrix}
1 & 0 & 0 \\
0 & 1 & 0 \\ 
0 & 0 & 1 
\end{bmatrix}
\mathbin{\&}
\begin{bmatrix}
10 \\
-2 \\
0.5
\end{bmatrix}
\Rightarrow
\begin{bmatrix}
1^{\times 10} & 0^{\times 10} & 0^{\times 10} \\
0^{\times -2} & 1^{\times -2} & 0^{\times -2} \\
0^{\times 0.5} & 0^{\times 0.5} & 1^{\times 0.5}
\end{bmatrix}
\Rightarrow
\begin{bmatrix}
10 & 0 & 0 \\
+ & + & + \\
0 & -2 & 0 \\
+ & + & + \\
0 & 0 & 0.5
\end{bmatrix}
\Rightarrow
\begin{bmatrix}
10 & -2 & 0.5
\end{bmatrix}
```

### LINEAR INTERPOLATION
Returns the linear interpolation between two values using `fma` for precision.

```cpp
V       lerp(V u, V v, float t);
Vector<V> lerp(Vector<V> u, Vector<V> v, float t);
Matrix<V> lerp(Matrix<V> u, Matrix<V> v, float t);
```

| Overload | Time complexity | Space complexity |
|---|---|---|
| Scalar | O(1) | O(1) |
| Vector | O(D) | O(D) |
| Matrix | O(R × C) | O(R × C) |

> D = dimension of vectors, R = rows, C = cols

```cpp
lerp(0., 1., 0.5);								// 0.5
lerp(21., 42., 0.3);							// 27.3

Vector<double> u({2., 1.});
Vector<double> v({4., 2.});
lerp(u, v, 0.3);								// {2.6, 1.3}

Matrix<double> m1({{2., 1.}, {3., 4.}});
Matrix<double> m2({{20., 10.}, {30., 40.}});
lerp(m1, m2, 0.5);								// {{11., 5.5}, {16.5, 22.}}
```

```math
\begin{bmatrix}
C_x \\
C_y 
\end{bmatrix}
\mathbin{=}
\begin{bmatrix}
A_x {\times 1 - t} + B_x {\times t} \\
A_Y {\times 1 - t} + B_y {\times t}
\end{bmatrix}
\mathbin{=}
\begin{bmatrix}
A_x - A_x {\times t} + B_x {\times t} \\
A_Y - A_y {\times t} + B_y {\times t}
\end{bmatrix}
\mathbin{=}
\begin{bmatrix}
A_x + (B_x - A_x) {\times t} \\
A_Y + (B_y - A_y) {\times t}
\end{bmatrix}
```
```math
\Rightarrow
\begin{bmatrix}
2 + (4 - 2) {\times 0.3} \\
1 + (2 - 1) {\times 0.3}
\end{bmatrix}
\mathbin{=}
\begin{bmatrix}
2 + 2 {\times 0.3} \\
1 + 1 {\times 0.3}
\end{bmatrix}
\mathbin{=}
\begin{bmatrix}
2 + 0.6 \\
1 + 0.3
\end{bmatrix}
\mathbin{=}
\begin{bmatrix}
2.6 \\
1.3
\end{bmatrix}
```

## Sources
- Math explications https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab

