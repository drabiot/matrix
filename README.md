<div align="center">
  <h1> 🌐 Matrix
  </h1>
</div>

---

Matrix is a 42 project where you have to create a library about Vector and Matrix space.

This project is aimed around math and what you can do with Vectors and Matrix in Computer Science & the first step into Linear ALgebra.

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
  - [Trace](#trace)
  - [Transpose](#transpose)
  - [Row-Echelon Form](#row-echelon-form)
  - [Determinant](#determinant)
  - [Inverse](#inverse)
  - [Rank](#rank)
  - [Projection](#projection)
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

| Function | Description | Work for<br>Complex Nb | Vector<br>Mem. Func | Matrix<br>Mem. Func. |
| -------- | ----------- | :-----------------: | :----: | :----: |
| [Add](#add) | Adds two vectors or matrices element-wise | ✅ | ✅ | ✅ |
| [Sub](#sub) | Subtracts two vectors or matrices element-wise | ✅ | ✅ | ✅ |
| [Scl](#scl) | Scales a vector or matrix by a scalar | ✅ | ✅ | ✅ |
| [Linear Combination](#linear-combination) | Returns a linear combination of vectors with given coefficients | ✅ |❌ | ❌ 
| [Linear Interpolation](#linear-interpolation) | Returns the linear interpolation between two values | ✅ |❌ | ❌ 
| [Dot Product](#dot-product) | Returns the sum of the element-wise products of two vectors | ✅ | ✅ | ❌ |
| [Norm](#norm) | Returns different kinds of norms of a vector | ✅ | ✅ | ❌ |
| [Cosine](#cosine) | Returns the cosine of the angle between two vectors | ✅ |❌ | ❌ 
| [Cross Product](#cross-product) | Returns the cross product of two 3D vectors | ✅ |❌ | ❌ 
| [Matrix Multiplication](#matrix-multiplication) | Returns the result of the product of two matrix or a matrix with a vector | ✅ | ❌ | ✅ |
| [Trace](#trace) | Returns the Trace of the Square Matrix | ✅ | ❌ | ✅ |
| [Transpose](#transpose) | Returns the Transpose of a Matrix | ✅ | ❌ | ✅ |
| [Row-Echelon Form](#row-echelon-form) | Returns the Row-Echelon Form of the Matrix | ✅ | ❌ | ✅ |
| [Determinant](#determinant) | Returns the Deterninant of the Matrix | ✅ | ❌ | ✅ |
| [Inverse](#inverse) | Returns the Inverse Matrix of a Matrix if it's possible | ✅ | ❌ | ✅ |
| [Rank](#rank) | Returns the Rank of a Matrix | ❌ | ❌ | ✅ |
| [Projection](#projection) | Returns a Projection Matrix | ❌ | ❌ | ✅ |

## Documentation

### ADD
Adds two vectors or matrices element-wise. Modifies the object in-place.

```cpp
void    Vector<K>::add(Vector &v);
void    Vector<K>::add(const Vector &v);

void    Matrix<K>::add(Matrix &m);
void    Matrix<K>::add(const Matrix &m);
```

| | Vector | Matrix |
|---|---|---|
| Time complexity | O(n) | O(n·m) |
| Space complexity | O(1) | O(1) |

```cpp
Vector u({1.0, 2.0, 3.0});
Vector v({4.0, 5.0, 6.0});

u.add(v); // u = [5.0, 7.0, 9.0]
```

---

### SUB
Subtracts two vectors or matrices element-wise. Modifies the object in-place.

```cpp
void    Vector<K>::sub(Vector &v);
void    Vector<K>::sub(const Vector &v);

void    Matrix<K>::sub(Matrix &m);
void    Matrix<K>::sub(const Matrix &m);
```

| | Vector | Matrix |
|---|---|---|
| Time complexity | O(n) | O(n·m) |
| Space complexity | O(1) | O(1) |

```cpp
Vector u({1.0, 2.0, 3.0});
Vector v({4.0, 5.0, 6.0});

u.sub(v); // u = [-3.0, -3.0, -3.0]
```

---

### SCL
Multiplies every element by a scalar. Modifies the object in-place.

```cpp
void    Vector<K>::scl(const K &a);
void    Matrix<K>::scl(const K &a);
```

| | Vector | Matrix |
|---|---|---|
| Time complexity | O(n) | O(n·m) |
| Space complexity | O(1) | O(1) |

```cpp
Vector u({1.0, 2.0, 3.0});
Vector v({4.0, 5.0, 6.0});

u.sub(6); // u = [6.0, 12.0, 18.0]
v.sub(2); // u = [8.0, 10.0, 12.0]
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

auto res = linear_combination({v1, v2, v3}, {10.0, -2.0, 0.5}); // res = [10.0, 2.0, 0.5]
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

---

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
lerp(u, v, 0.3);								// [2.6, 1.3]

Matrix<double> m1({{2., 1.}, {3., 4.}});
Matrix<double> m2({{20., 10.}, {30., 40.}});
lerp(m1, m2, 0.5);								// [11.   5.5]
												// [16.5, 22.]
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

---

### DOT PRODUCT
Returns the sum of the element-wise products of two vectors using `fma` for precision.

```cpp
K   Vector<K>::dot(Vector<K> &v);
K   Vector<K>::dot(const Vector<K> &v) const;
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

---

### NORM
Returns different kinds of norms of a vector.

```cpp
float   Vector<K>::norm_1(void);
float   Vector<K>::norm(void);
float   Vector<K>::norm_inf(void);

float   Vector<K>::norm_1(void) const;
float   Vector<K>::norm(void) const;
float   Vector<K>::norm_inf(void) const;
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

---

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

---

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

---

### MATRIX MULTIPLICATION
Returns the product of a matrix with a vector or another matrix.

```cpp
Vector<K>	Matrix<K>::mul_vec(std::initializer_list<K> vec);
Vector<K>	Matrix<K>::mul_vec(Vector<K> vec);

Matrix<K>	Matrix<K>::mul_mat(Matrix<K> mat);
```

| Overload | Time complexity | Space complexity |
|---|---|---|
| mul_vec | O(nm) | O(m) |
| mul_mat | O(nmp) | O(mp) |

> For `mul_vec`: A ∈ R^(m×n), u ∈ R^n => result ∈ R^m  
> For `mul_mat`: A ∈ R^(m×n), B ∈ R^(n×p) => result ∈ R^(m×p)

```cpp
Matrix<double>	m1({{1., 0.}, {0., 1.}});
Matrix<double>	m2({{2., 1.}, {4., 2.}});

m1.mul_vec({4., 2.});		// [4., 2.]
m1.mul_vec({4., 2.});		// [4., 2.]
m2.mul_vec({4., 2.});		// [10., 20.]

m1.mul_mat(m1);				// [1., 0.]
							// [0., 1.]

m1.mul_mat(m2);				// [2., 1.]
							// [4., 2.]

m2.mul_mat(m1);				// [2., 1.]
							// [4., 2.]

m2.mul_mat(m2);				// [8.,  4.]
							// [16., 8.]
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

---

### TRACE
Returns the trace of a square matrix.

```cpp
K	Matrix<K>::trace(void);
```

| Overload | Time complexity | Space complexity |
|---|---|---|
| trace | O(n) | O(1) |

```cpp
Matrix<double>	m1({{1., 0.}, {0., 1.}});
Matrix<double>	m2({{-2, -8, 4}, {1, -23, 4}, {0, 6, 4}});

m1.trace();		// 2
m2.trace();		//-21
```

The trace of a matrix is only defined for square matrices and is the sum of all diagonal values.

```math
A =
\begin{bmatrix}
A_{11} & A_{12} & A_{13} \\
A_{21} & A_{22} & A_{23} \\
A_{31} & A_{32} & A_{33}
\end{bmatrix}
\Rightarrow
A_{11} + A_{22} + A_{33}
```
```math
A =
\begin{bmatrix}
-2 & -8 & 4 \\
1 & -23 & 4 \\
0 & 6 & 4
\end{bmatrix}
\Rightarrow
-2 + -23 + 4 = -21
```

---

### TRANSPOSE
Returns the transpose of a matrix.

```cpp
Matrix<K>	Matrix<K>::transpose(void);
```

| Overload | Time complexity | Space complexity |
|---|---|---|
| transpose | O(n*m) | O(n*m) |

```cpp
Matrix<double>	m1({{1., 0.}, {0., 1.}});
Matrix<double>	m2({{-2, -8, 4}, {1, -23, 4}, {0, 6, 4}});
Matrix<double>	m3({{-2, -8, 4}, {1, -23, 4}});

m1.transpose();		// [1., 0.]
					// [0., 1.]

m2.transpose();		// [-2.,  1.,  0.]
					// [-8., -23., 6.]
					// [4.,   4.,  4.]

m3.transpose();		// [-2.,   1.]
					// [-8., -23.]
					// [ 4.,   4.]
```

```math
A =
\begin{bmatrix}
A_{11} & A_{12} & \cdots & A_{1n} \\
A_{21} & A_{22} & \cdots & A_{2n} \\
A_{31} & A_{32} & \cdots & A_{3n} \\
\vdots & \vdots & & \vdots \\
A_{m1} & A_{m2} & \cdots & A_{mn}
\end{bmatrix}
\Rightarrow
A^T =
\begin{bmatrix}
A_{11} & A_{21} & \cdots & A_{m1} \\
A_{12} & A_{22} & \cdots & A_{m2} \\
A_{13} & A_{23} & \cdots & A_{m3} \\
\vdots & \vdots & & \vdots \\
A_{1n} & A_{2n} & \cdots & A_{mn}
\end{bmatrix}
```
```math
A =
\begin{bmatrix}
-2 & -8 & 4 \\
1 & -23 & 4 \\
0 & 6 & 4
\end{bmatrix}
\Rightarrow
A^T =
\begin{bmatrix}
-2 & 1 & 0 \\
-8 & -23 & 6 \\
4 & 4 & 4
\end{bmatrix}
```

---

### ROW-ECHELON FORM
Returns the row-echelon form of a matrix.

```cpp
Matrix<K>	Matrix<K>::row_echelon(void);
```

| Overload | Time complexity | Space complexity |
|---|---|---|
| row_echelon | O(n*m²) | O(n*m) |

```cpp
Matrix<double>	m1({{1., 0.}, {0., 1.}});
Matrix<double>	m2({{2, 3, 4}, {4, 6, 8}, {1, 3, 1}});
Matrix<double>	m3({{8, 5, -2, 4, 28}, {4, 2.5, 20, 4, -4}, {8, 5, 1, 4, 17}});

m1.row_echelon();	// [1., 0.]
					// [0., 1.]

m2.row_echelon();	// [1., 0.,     3.]
					// [0., 1., -0.67.]
					// [0., 0.,     0.]

m3.row_echelon();	// [1., 0.628, 0., 0., -12.167]
					// [0.,  0.,   1., 0.,  -3.667]
					// [0.,  0.,   0., 1.,    29.5]
```

To be in row-echelon form, a matrix must have the following properties:

1. If a row does'nt consist entirely of zeros, then the first non-zero number in the row is a 1.

2. All zero rows are at the bottom of the matrix.

3. In any two successice rows that do no consist entirely of zeros, the leading 1 in the lower row occurs farther to the right than the leading 1 in the higher row.

Every matrix can be transformed into **reduced row echelon form (RREF)** through a sequence of elementary row operations, a process called **Gauss-Jordan elimination**.

The algorithm works column by column, maintaining a `pivot_row` counter that advances only when a valid pivot is found.

### Step 1: Find a non-zero pivot and move it into position

Scan downward from `pivot_row` in the current column. If a non-zero entry is found, swap that row with `pivot_row`. If the column is all zeros, skip it, no pivot exists here, `pivot_row` stays unchanged.

```math
\begin{bmatrix}
2 & 3 & 4 \\
4 & 6 & 8 \\
1 & 3 & 1
\end{bmatrix}
\xrightarrow{R_0 \leftrightarrow R_0}
\begin{bmatrix}
2 & 3 & 4 \\
4 & 6 & 8 \\
1 & 3 & 1
\end{bmatrix}
```

Here the pivot is already in place (2 ≠ 0), so no swap is needed.


### Step 2: Normalize `pivot_row` so the pivot equals 1

Divide every entry in `pivot_row` by the pivot value. This guarantees a leading 1, which is required for RREF.

```math
\begin{bmatrix}
2 & 3 & 4 \\
4 & 6 & 8 \\
1 & 3 & 1
\end{bmatrix}
\xrightarrow{R_0 = \frac{1}{2}R_0}
\begin{bmatrix}
1 & \frac{3}{2} & 2 \\
4 & 6 & 8 \\
1 & 3 & 1
\end{bmatrix}
```

### Step 3: Eliminate every other entry in that column

For each row `i ≠ pivot_row`, subtract the right multiple of `pivot_row` to zero out `A[i][col]` :

```math
R_i \leftarrow R_i - A[i][\text{col}] \times R_{\text{pivot}}
```

```math
\begin{bmatrix}
1 & \frac{3}{2} & 2 \\
4 & 6 & 8 \\
1 & 3 & 1
\end{bmatrix}
\xrightarrow[R_2 = R_2 - 1 \cdot R_0]{R_1 = R_1 - 4 \cdot R_0}
\begin{bmatrix}
1 & \frac{3}{2} & 2 \\
0 & 0 & 0 \\
0 & \frac{3}{2} & -1 \end{bmatrix}
```

Column 0 is done. `pivot_row` advances to 1.

---

### Column 1: the pivot slot is zero, swap with the first non-zero below

`A[1][1] = 0` so we scan downward and swap with R2 :

```math
\begin{bmatrix}
1 & \frac{3}{2} & 2 \\
0 & 0 & 0 \\
0 & \frac{3}{2} & -1
\end{bmatrix}
\xrightarrow{R_1 \leftrightarrow R_2}
\begin{bmatrix}
1 & \frac{3}{2} & 2 \\
0 & \frac{3}{2} & -1 \\
0 & 0 & 0
\end{bmatrix}
```

Normalize R1 :

```math
\xrightarrow{R_1 = \frac{2}{3}R_1}
\begin{bmatrix}
1 & \frac{3}{2} & 2 \\
0 & 1 & -\frac{2}{3} \\
0 & 0 & 0
\end{bmatrix}
```

Eliminate upward into R0 (RREF requires zeros **above** the pivot too) :

```math
\xrightarrow{R_0 = R_0 - \frac{3}{2}R_1}
\begin{bmatrix}
1 & 0 & 3 \\
0 & 1 & -\frac{2}{3} \\
0 & 0 & 0
\end{bmatrix}
```

Column 1 is done. `pivot_row` advances to 2. No more non-zero entries remain — the matrix is in **RREF**.

---

### DETERMINANT
Returns the determinant of a matrix.

```cpp
Matrix<K>	Matrix<K>::determinant(void);
```

| Overload | Time complexity | Space complexity |
|---|---|---|
| determinant | O(nn³) | O(nn²) |

```cpp
Matrix<double>	m1({{1., 0.}, {0., 1.}});
Matrix<double>	m2({{2, 0, 0}, {0, 2, 0}, {0, 0, 2}});
Matrix<double>	m3({{8, 5, -2}, {4, 7, 20}, {7, 6, 1}});
Matrix<double>	m4({{8, 5, -2, 4}, {4, 2.5, 20, 4}, {8, 5, 1, 4}, {28, -4, 17, 1}});

m1.determinant();	// 0.0
m2.determinant();	// 8.0
m3.determinant();	// -174.0
m4.determinant();	// 1032.0
```

```math
A = 
\begin{bmatrix}
a & b & c & d \\
e & f & g & h \\
i & j & k & l \\
m & n & o & p
\end{bmatrix}
```

To determine how to compute the determinant of a given matrix we need to remember the sign behaviour:

```math 
\begin{bmatrix}
+ & - & + & \cdots \\
- & + &  &  \\
+ &  & \ddots &  \\
\vdots &  &  & \ddots 
\end{bmatrix}
```

And to determine a 2×2 matrix we only need to do:

```math
A =
\begin{bmatrix}
a & b \\
c & d
\end{bmatrix}
```

```math
det(A) = ad - bc
```

To compute the determinant, take a row or a column and iterate through it. For each value, eliminate every other value sharing its row or column.

```math
det(A) =
+ a
\begin{bmatrix}
f & g & h \\
j & k & l \\
n & o & p
\end{bmatrix}
- b
\begin{bmatrix}
e & g & h \\
i & k & l \\
m & o & p
\end{bmatrix}
+ c
\begin{bmatrix}
e & f & h \\
i & j & l \\
m & n & p
\end{bmatrix}
- d
\begin{bmatrix}
e & f & g \\
i & j & k \\
m & n & o
\end{bmatrix}
```

Until only 2×2 matrix remains.

```math
det(A) = +a (
+ f
\begin{bmatrix}
k & l \\
o & p
\end{bmatrix}
- g
\begin{bmatrix}
j & l \\
n & p
\end{bmatrix}
+ h
\begin{bmatrix}
j & k \\
n & o
\end{bmatrix}
)
- b (
+ e
\begin{bmatrix}
k & l \\
o & p
\end{bmatrix}
- g
\begin{bmatrix}
i & l \\
m & p
\end{bmatrix}
+ h
\begin{bmatrix}
i & k \\
m & o
\end{bmatrix}
)
\cdots
```

```math
det(A) = +a(+f(kp - lo) -g(jp - ln) +h(jo - kn)) -b(+e(kp - lo) -g(ip - lm) +h(io - km)) \cdots
```

The determinant represents how a linear transformation scales volumes in space.
If the determinant equals 0, the transformation collapses the space onto a lower dimension. A plane becomes a line, or a line becomes a point.

**Example with a 3×3 matrix:**

```math
A = 
\begin{bmatrix}
1 & 2 & 3 \\
4 & 5 & 6 \\
7 & 8 & 9
\end{bmatrix}
```
```math
det(A) =
1
\begin{bmatrix}
5 & 6 \\
8 & 9
\end{bmatrix}
-2
\begin{bmatrix}
4 & 6 \\
7 & 9
\end{bmatrix}
+ 3
\begin{bmatrix}
4 & 5 \\
7 & 8
\end{bmatrix}
```
```math
det(A) =
1 \times{(5 \times{9} - 6 \times{8})} - 2 \times{(4 \times{9} - 6 \times{7})} + 3 \times{(4 \times{8} - 5 \times{7})}
```
```math
det(A) =
1 \times{(45 - 48)} - 2 \times{(36 - 42)} + 3 \times{(32 - 35)}
```
```math
det(A) =
1 \times{-3} - 2 \times{-6} + 3 \times{-3}
```
```math
det(A) =
- 3 + 12 - 9
```
```math
det(A) = 0
```

---

### INVERSE
Returns the inverse matrix of a given matrix if it's possible.

```cpp
Matrix<K>	Matrix<K>::inverse(void);
```

| Overload | Time complexity | Space complexity |
|---|---|---|
| inverse | O(nn³) | O(nn²) |

```cpp
Matrix<double>	m1({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}});
Matrix<double>	m2({{2, 0, 0}, {0, 2, 0}, {0, 0, 2}});
Matrix<double>	m3({{8, 5, -2}, {4, 7, 20}, {7, 6, 1}});

m1.inverse();	// [1.0, 0.0, 0.0]
				// [0.0, 1.0, 0.0]
				// [0.0, 0.0, 1.0]

m2.inverse();	// [0.5, 0.0, 0.0]
				// [0.0, 0.5, 0.0]
				// [0.0, 0.0, 0.5]

m3.inverse();	// [ 0.64,  0.09, -0.65]
				// [-0.78, -0.12,  0.96]
				// [ 0.14,  0.07, -0.20]
```

An n-by-n square matrix A is called invertible if there exists an n-by-n square matrix B such that:
```math
AB = BA = I_n
```
where I is an identity matrix.

To compute the inverse of a matrix we need to apply the Gaussian Elimination to reduce our matrix to the identy matrix.

```math
A = 
\begin{bmatrix}
0 & 2 & 3 & 5 \\
2 & 4 & 4 & 2 \\
0 & 1 & 2 & 4 \\
3 & 7 & 9 & 11
\end{bmatrix}
```

### Init: Create an augmented matrix

```math
\left[\begin{array}{cccc|cccc}
0 & 2 & 3 & 5  & 1 & 0 & 0 & 0 \\
2 & 4 & 4 & 2  & 0 & 1 & 0 & 0 \\
0 & 1 & 2 & 4  & 0 & 0 & 1 & 0 \\
3 & 7 & 9 & 11 & 0 & 0 & 0 & 1
\end{array}\right]
```

### Step 1: Find a non-zero pivot and move it into position

```math
\left[\begin{array}{cccc|cccc}
0 & 2 & 3 & 5  & 1 & 0 & 0 & 0 \\
2 & 4 & 4 & 2  & 0 & 1 & 0 & 0 \\
0 & 1 & 2 & 4  & 0 & 0 & 1 & 0 \\
3 & 7 & 9 & 11 & 0 & 0 & 0 & 1
\end{array}\right]
\xrightarrow{R_1 \leftrightarrow R_2}
\left[\begin{array}{cccc|cccc}
2 & 4 & 4 & 2  & 0 & 1 & 0 & 0 \\
0 & 2 & 3 & 5  & 1 & 0 & 0 & 0 \\
0 & 1 & 2 & 4  & 0 & 0 & 1 & 0 \\
3 & 7 & 9 & 11 & 0 & 0 & 0 & 1
\end{array}\right]
```

### Step 2: Create the pivot

To create a pivot you need to divide every value of your pivot's line by the value of your pivot.

```math
\left[\begin{array}{cccc|cccc}
2 & 4 & 4 & 2  & 0 & 1 & 0 & 0 \\
0 & 2 & 3 & 5  & 1 & 0 & 0 & 0 \\
0 & 1 & 2 & 4  & 0 & 0 & 1 & 0 \\
3 & 7 & 9 & 11 & 0 & 0 & 0 & 1
\end{array}\right]
\xrightarrow{R_1 \div{2}}
\left[\begin{array}{cccc|cccc}
1 & 2 & 2 & 1  & 0 & \frac{1}{2} & 0 & 0 \\
0 & 2 & 3 & 5  & 1 & 0 & 0 & 0 \\
0 & 1 & 2 & 4  & 0 & 0 & 1 & 0 \\
3 & 7 & 9 & 11 & 0 & 0 & 0 & 1
\end{array}\right]
```

### Step 3: Delete value that isn't 0 in your pivot column

```math
\left[\begin{array}{cccc|cccc}
1 & 2 & 2 & 1  & 0 & \frac{1}{2} & 0 & 0 \\
0 & 2 & 3 & 5  & 1 & 0 & 0 & 0 \\
0 & 1 & 2 & 4  & 0 & 0 & 1 & 0 \\
3 & 7 & 9 & 11 & 0 & 0 & 0 & 1
\end{array}\right]
\xrightarrow{R_3 = R_3 - 3R_1}
\left[\begin{array}{cccc|cccc}
1 & 2 & 2 & 1 & 0 & \frac{1}{2} & 0 & 0 \\
0 & 2 & 3 & 5 & 1 & 0 & 0 & 0 \\
0 & 1 & 2 & 4 & 0 & 0 & 1 & 0 \\
0 & 1 & 3 & 8 & 0 & -\frac{3}{2} & 0 & 1
\end{array}\right]
```

### Step 4: Repeat with your second pivot & more until it's finish

```math
\left[\begin{array}{cccc|cccc}
1 & 2 & 2 & 1 & 0 & \frac{1}{2} & 0 & 0 \\
0 & 2 & 3 & 5 & 1 & 0 & 0 & 0 \\
0 & 1 & 2 & 4 & 0 & 0 & 1 & 0 \\
0 & 1 & 3 & 8 & 0 & -\frac{3}{2} & 0 & 1
\end{array}\right]
\xrightarrow{R_2 \div{2}}
\left[\begin{array}{cccc|cccc}
1 & 2 & 2 & 1 & 0 & \frac{1}{2} & 0 & 0 \\
0 & 1 & \frac{3}{2} & \frac{5}{2}  & \frac{1}{2} & 0 & 0 & 0 \\
0 & 1 & 2 & 4  & 0 & 0 & 1 & 0 \\
0 & 1 & 3 & 8 & 0 & -\frac{3}{2} & 0 & 1
\end{array}\right]
```

```math
\left[\begin{array}{cccc|cccc}
1 & 2 & 2 & 1 & 0 & \frac{1}{2} & 0 & 0 \\
0 & 1 & \frac{3}{2} & \frac{5}{2}  & \frac{1}{2} & 0 & 0 & 0 \\
0 & 1 & 2 & 4  & 0 & 0 & 1 & 0 \\
0 & 1 & 3 & 8 & 0 & -\frac{3}{2} & 0 & 1
\end{array}\right]
\xrightarrow{R_1 = R_1 - 2R_2}
\left[\begin{array}{cccc|cccc}
1 & 0 & -1 & -4  & -1 & \frac{1}{2} & 0 & 0 \\
0 & 1 & \frac{3}{2} & \frac{5}{2}  & \frac{1}{2} & 0 & 0 & 0 \\
0 & 1 & 2 & 4  & 0 & 0 & 1 & 0 \\
0 & 1 & 3 & 8 & 0 & -\frac{3}{2} & 0 & 1
\end{array}\right]
```
```math
\left[\begin{array}{cccc|cccc}
1 & 0 & -1 & -4  & -1 & \frac{1}{2} & 0 & 0 \\
0 & 1 & \frac{3}{2} & \frac{5}{2}  & \frac{1}{2} & 0 & 0 & 0 \\
0 & 1 & 2 & 4  & 0 & 0 & 1 & 0 \\
0 & 1 & 3 & 8 & 0 & -\frac{3}{2} & 0 & 1
\end{array}\right]
\xrightarrow{R_3 = R_3 - R_2}
\left[\begin{array}{cccc|cccc}
1 & 0 & -1 & -4  & -1 & \frac{1}{2} & 0 & 0 \\
0 & 1 & \frac{3}{2} & \frac{5}{2}  & \frac{1}{2} & 0 & 0 & 0 \\
0 & 0 & \frac{1}{2} & \frac{3}{2}  & -\frac{1}{2} & 0 & 1 & 0 \\
0 & 1 & 3 & 8 & 0 & -\frac{3}{2} & 0 & 1
\end{array}\right]
```

```math
\left[\begin{array}{cccc|cccc}
1 & 0 & -1 & -4  & -1 & \frac{1}{2} & 0 & 0 \\
0 & 1 & \frac{3}{2} & \frac{5}{2}  & \frac{1}{2} & 0 & 0 & 0 \\
0 & 0 & \frac{1}{2} & \frac{3}{2}  & -\frac{1}{2} & 0 & 1 & 0 \\
0 & 1 & 3 & 8 & 0 & -\frac{3}{2} & 0 & 1
\end{array}\right]
\xrightarrow{R_4 = R_4 - R_2}
\left[\begin{array}{cccc|cccc}
1 & 0 & -1 & -4  & -1 & \frac{1}{2} & 0 & 0 \\
0 & 1 & \frac{3}{2} & \frac{5}{2}  & \frac{1}{2} & 0 & 0 & 0 \\
0 & 0 & \frac{1}{2} & \frac{3}{2}  & -\frac{1}{2} & 0 & 1 & 0 \\
0 & 0 & \frac{3}{2} & \frac{11}{2} & -\frac{1}{2} & -\frac{3}{2} & 0 & 1
\end{array}\right]
```

```math
\cdots
```
```math
\left[\begin{array}{cccc|cccc}
1 & 0 & 0 & 0  & -1 & -1 & -1 & 1 \\
0 & 1 & 0 & 0  & 4 & -3 & -9 & 2 \\
0 & 0 & 1 & 0  & -4 & \frac{9}{2} & 11 & -3 \\
0 & 0 & 0 & 1 & 1 & -\frac{3}{2} & -3 & 1
\end{array}\right]
```

### Step 5: Interpret the result & end

When you have your identity matrix as the far left of your augmented matrix, you're now finished. The iverse of your matrix is what you have on the far right of your augmented matrix.

```math
A^{-1} =
\begin{bmatrix}
-1 & -1 & -1 & 1 \\
4 & -3 & -9 & 2 \\
-4 & \frac{9}{2} & 11 & -3 \\
1 & -\frac{3}{2} & -3 & 1
\end{bmatrix}
```

---

### RANK
Returns the rank of a matrix.

```cpp
size_t	Matrix<K>::rank(void);
```

| Overload | Time complexity | Space complexity |
|---|---|---|
| rank | O(n*m²) | O(n*m) |

```cpp
Matrix<double>	m1({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}});
Matrix<double>	m2({{1., 2., 0., 0.}, {2., 4., 0., 0.}, {-1., 2., 1., 1.}});
Matrix<double>	m3({{8, 5, -2}, {4, 7, 20}, {7, 6, 1}, {21., 18., 7.}});

m1.rank();	// 3
m2.rank();	// 2
m3.rank();	// 3
```
The rank is the number of dimensions in the output.

To compute the rank of a matrix, you will need to transform your matrix in a Row-Echelon Form & return the sum of all the non-zero line.

```math
A =
\begin{bmatrix}
2 & -1 &  0 \\
1 &  3 &  4 \\
4 &  1 & -3
\end{bmatrix}
\xrightarrow{\text{Row-Echelon Form}}
\begin{bmatrix}
2 & -1 &  0 \\
0 &  \frac{7}{2} &  4 \\
0 &  0 & -\frac{45}{7}
\end{bmatrix}
\text{rank(A) = 3}
```


```math
B =
\begin{bmatrix}
 1 &  2 & 1 \\
-2 & -3 & 1 \\
 3 &  5 & 0 \\
 2 &  4 & 2
\end{bmatrix}
\xrightarrow{\text{Row-Echelon Form}}
\begin{bmatrix}
1 & 2 & 1 \\
0 & 1 & 3 \\
0 & 0 & 0 \\
0 & 0 & 0
\end{bmatrix}
\text{rank(B) = 2}
```

### PROJECTION
Returns a projection matrix.

```cpp
Matrix<K>	projection(float fov, float ratio, float near, float far);
```

| Overload | Time complexity | Space complexity |
|---|---|---|
| projection | O(1) | O(1) |

```cpp
projection(90, 1, 0.1, 100);	// [1, 0,    0,    0]
								// [0, 1,    0,    0]
								// [0, 0, -1.001, -1]
								// [0, 0, -0.1001, 0]

projection(45, 1, 0.1, 100);	// [2.41421, 0, 0, 0]
								// [0, 2.41421, 0, 0]
								// [0, 0, -1.001, -1]
								// [0, 0, -0.1001, 0]

projection(120, 1, 0.1, 100);	// [0.57735, 0, 0, 0]
								// [0, 0.57735, 0, 0]
								// [0, 0, -1.001, -1]
								// [0, 0, -0.1001, 0]
```

## Sources
- Math explications https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab
- Compute Cos of two vectors https://www.youtube.com/watch?v=2pIlGSu6Ta4
- Compute Cross Product https://www.khanacademy.org/math/multivariable-calculus/thinking-about-multivariable-function/x786f2022:vectors-and-matrices/a/cross-products-mvc
- Compute the product between two Matrix https://youtu.be/OC90E-fnQ7g
- Compute the Trace of a Matrix https://youtu.be/OuDA54fWk2o
- Transpose a Matrix https://youtu.be/jG9Swa-wCwg
- Better understand Row-Echelon Form Matrix & how to Transform a Matrix into one https://youtu.be/oXMPQ-6YnGA
- Gaussian Elimination algorythm & explication https://fr.wikipedia.org/wiki/%C3%89limination_de_Gauss-Jordan
- Find the Determinant of a Matrix https://youtu.be/CcbyMH3Noow
- Create the Inverse Matrix https://youtu.be/kWorj5BBy9k
- Singular Matrix https://www.datacamp.com/fr/tutorial/singular-matrix
- Inverse a matrix https://youtu.be/95dYWsZEXmM
- Gaussian Elimination to create identity matrix https://youtu.be/PTii4TBh9kQ
- Compute the rank of a matrix https://youtu.be/cSj82GG6MX4
- Compute the matrix projection https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/building-basic-perspective-projection-matrix.html
- How to do a dot product between two complex numbers vector https://math.stackexchange.com/questions/2459814/what-is-the-dot-product-of-complex-vectors
- How to do an Hermitian dot product https://fr.wikipedia.org/wiki/Hermitien
- Complex Numbers in Cosine https://www.physicsforums.com/threads/angles-between-complex-vectors.864707/
