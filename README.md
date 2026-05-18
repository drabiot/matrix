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
Vector<K> linear_combination(initializer_list<Vector<K>> u, initializer_list<K> coefs);
Vector<K> linear_combination(initializer_list<Vector<K>> u, Vector<K> coefs);
Vector<K> linear_combination(Matrix<K> u, initializer_list<K> coefs);
Vector<K> linear_combination(Matrix<K> u, Vector<K> coefs);
```

| Time complexity | Space complexity |
|---|---|
| O(L × D) | O(D) |

> L = number of vectors, D = dimension of vectors

```cpp
Vector<float> e1({1.0, 0.0, 0.0});
Vector<float> e2({0.0, 1.0, 0.0});

auto res = linear_combination({e1, e2}, {2.0f, 3.0f}); // res = {2.0, 3.0, 0.0}
```

## Sources
- Math explications https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab

