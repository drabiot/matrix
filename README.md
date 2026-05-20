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
  - [Dot Product](#dot-product)
  - [Norm](#norm)
  - [Cosine](#cosine)
  - [Cross Product](#cross-product)
  - [Matrix Multiplication](#matrix-multiplication)
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
| Linear Interpolation | Returns the linear interpolation between two values |
| Dot Product | Returns the sum of the element-wise products of two vectors |
| Norm | Returns different kinds of norms of a vector |
| Cosine | Returns the cosine of the angle between two vectors |
| Cross Product | Returns the cross product of two 3D vectors |
| Matrix Multiplication | Returns the result of the product of two matrix or a matrix with a vector |

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
V       	lerp(V u, V v, float t);
Vector<V>	lerp(Vector<V> u, Vector<V> v, float t);
Matrix<V>	lerp(Matrix<V> u, Matrix<V> v, float t);
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

### DOT PRODUCT
Returns the sum of the element-wise products of two vectors using `fma` for precision.

```cpp
K   dot(Vector<K> &v);
K   dot(const Vector<K> &v) const;
```

| Overload | Time complexity | Space complexity |
|---|---|---|
| Vector | O(n) | O(1) |

> n = size of both vectors (must be equal)

```cpp
Vector<float>	u({1., 0.});
Vector<float>	v({0., 1.});
u.dot(v);						// 0.

Vector<float>	u({1., 1.});
Vector<float>	v({1., 1.});
u.dot(v);						// 2.

Vector<float>	u({-1., 6.});
Vector<float>	v({3., 2.});
u.dot(v);						// 9.  =>  (-1 × 3) + (6 × 2)
```

```math
\begin{bmatrix}
A_x \\
A_y \\
A_z
\end{bmatrix}
\cdot
\begin{bmatrix}
B_x \\
B_y \\
B_z
\end{bmatrix}
\mathbin{=}
A_x {\cdot B_x} + A_y {\cdot B_y} + A_z {\cdot B_z}
```

### NORM
Returns different kinds of norms of a vector.

```cpp
float   norm_1(void);
float   norm(void);
float   norm_inf(void);

float   norm_1(void) const;
float   norm(void) const;
float   norm_inf(void) const;
```

| Overload | Time complexity | Space complexity |
|---|---|---|
| norm_1 (Manhattan / Taxicab) | O(n) | O(1) |
| norm (Euclidean) | O(n) | O(1) |
| norm_inf (Supremum) | O(n) | O(1) |

> n = size of the vector

```cpp
Vector<float>	u({0., 0., 0.});
u.norm_1();		// 0.0
u.norm();		// 0.0
u.norm_inf();	// 0.0

Vector<float>	u({1., 2., 3.});
u.norm_1();		// 6.0
u.norm();		// 3.74166
u.norm_inf();	// 3.0

Vector<float>	u({-1., -2.});
u.norm_1();		// 3.0
u.norm();		// 2.23607
u.norm_inf();	// 2.0
```
<div align="center">
<ins>Manhattan / Taxicab Norm:</ins>
<br>

```math
\|v\|_1 = |v_x| + |v_y| + ... + |v_n| 
```

<br>
<ins>Euclidean Norm:</ins>
<br>

```math
\|v\|_2 = \sqrt{v^2_x + v^2_y + ... + v^2_n}
```
<br>
<ins>Supremum Norm:</ins>
<br>

```math
\|v\|_∞ = max(|v_x|, |v_y|, ..., |v_n|)
```
</div>

### COSINE
Returns the cosine of the angle between two vectors.

```cpp
float	angle_cos(Vector<K> &u, Vector<K> &v);
float	angle_cos(const Vector<K> &u, const Vector<K> &v);
```

| Overload | Time complexity | Space complexity |
|---|---|---|
| angle_cos | O(n) | O(1) |

> n = size of both vectors

```cpp
Vector<float>	u({1., 0.});
Vector<float>	v({0., 1.});
angle_cos(u, v);			// 0.0

Vector<float>	u({1., 0.});
Vector<float>	v({1., 0.});
angle_cos(u, v);			// 1.0

Vector<float>	u({1., 2., 3.});
Vector<float>	v({4., 5., 6.});
angle_cos(u, v);			// 0.974632
```

```math
cos(\vec{u}, \vec{v}) = \frac{\vec{u} \cdot \vec{v}}{\|\vec{u}\|_2 \times{\|\vec{v}\|_2}}
```

So we use [Dot Product](#dot-product) & [Norm](#norm) to compute our cosine

### CROSS PRODUCT
Returns the cross product of two 3D vectors.

```cpp
Vector<K>	cross_product(std::initializer_list<K> u, std::initializer_list<K> v);
Vector<K>	cross_product(Vector<K> u, Vector<K> v);
```

| Overload | Time complexity | Space complexity |
|---|---|---|
| cross_product | O(1) | O(1) |

> Cross product is strictly defined for 3D vectors, input size is always fixed.

```cpp
Vector<int>	e1({0, 0, 1});
Vector<int>	e2({1, 0, 0});
cross_product(e1, e2);					// [0, 1, 0]

Vector<int>	e1({1, 0, 0});
Vector<int>	e2({0, 1, 0});
cross_product(e1, e2);					// [0, 0, 1]

cross_product({1, 2, 3}, {4, 5, 6});	// [-3, 6, -3]
```

```math
\vec{u}
=
\begin{bmatrix}
u_1 \\
u_2 \\
u_3
\end{bmatrix}

\vec{v}
=
\begin{bmatrix}
v_1 \\
v_2 \\
v_3
\end{bmatrix}
```

```math
\vec{u} \times{\vec{v}}
=
\begin{bmatrix}
u_2v_3 - u_3v_2 \\
u_3v_1 - u_1v_3 \\
u_1v_2 - u_2v_1
\end{bmatrix}
```

### MATRIX MULTIPLICATION
Returns the product of a matrix with a vector or another matrix.

```cpp
Vector<K>	mul_vec(std::initializer_list<K> vec);
Vector<K>	mul_vec(Vector<K> vec);

Matrix<K>	mul_mat(Matrix<K> mat);
```

| Overload | Time complexity | Space complexity |
|---|---|---|
| mul_vec | O(nm) | O(m) |
| mul_mat | O(nmp) | O(mp) |

> For `mul_vec`: A ∈ R^(m×n), u ∈ R^n => result ∈ R^m  
> For `mul_mat`: A ∈ R^(m×n), B ∈ R^(n×p) => result ∈ R^(m×p)

```cpp
Matrix<double> m1({{1., 0.}, {0., 1.}});
Matrix<double> m2({{2., 1.}, {4., 2.}});

m1.mul_vec({4., 2.});		// [4., 2.]
m1.mul_vec({4., 2.});		// [4., 2.]
m2.mul_vec({4., 2.});		// [10., 20.]

m1.mul_mat(m1);				// [[1., 0.], [0., 1.]]
m1.mul_mat(m2);				// [[2., 1.], [4., 2.]]
m2.mul_mat(m1);				// [[2., 1.], [4., 2.]]
m2.mul_mat(m2);				// [[8., 4.], [16., 8.]]
```

<div align="center">
<ins>Matrix with Vector Multiplication:</ins>
<br>
</div>

```math
A =
\begin{bmatrix}
A_{11} & A_{12} \\
A_{21} & A_{22}
\end{bmatrix}
B =
\begin{bmatrix}
B_1 \\
B_2 \\
\end{bmatrix}
```

```math
A \times{B} =
\begin{bmatrix}
A_{11} \times{B_1} + A_{12} \times{B_1} \\
A_{21} \times{B_2} + A_{22} \times{B_2}
\end{bmatrix}

```

<div align="center">
<ins>Two Matrix Multiplication:</ins>
<br>
</div>

```math
A =
\begin{bmatrix}
A_{11} & A_{12} \\
A_{21} & A_{22} \\
A_{31} & A_{32}
\end{bmatrix}
B =
\begin{bmatrix}
B_{11} & B_{12} & B_{13} \\
B_{21} & B_{22} & B_{23} \\
\end{bmatrix}
```

```math
A \times B =
\begin{bmatrix}
A_{11} \times B_{11} + A_{12} \times B_{21} & A_{11} \times B_{12} + A_{12} \times B_{22} & A_{11} \times B_{13} + A_{12} \times B_{23} \\
A_{21} \times B_{11} + A_{22} \times B_{21} & A_{21} \times B_{12} + A_{22} \times B_{22} & A_{21} \times B_{13} + A_{22} \times B_{23} \\
\end{bmatrix}
```

To multiply two matrices, the number of columns of the first matrix must equal the number of rows of the second matrix.

If A is a matrix of dimension n × p and B is a matrix of dimension p × m,
the product of A by B, denoted A × B or AB, is a matrix of dimension n × m
whose coefficient at row i and column j is obtained by multiplying the i-th row of A by the j-th column of B.

## Sources
- Math explications https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab
- Compute Cos of two vectors https://www.youtube.com/watch?v=2pIlGSu6Ta4
- Compute Cross Product https://www.khanacademy.org/math/multivariable-calculus/thinking-about-multivariable-function/x786f2022:vectors-and-matrices/a/cross-products-mvc
- Compute the product between two Matrix https://youtu.be/OC90E-fnQ7g
