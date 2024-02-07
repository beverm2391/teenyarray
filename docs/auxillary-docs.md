# Auxillary Docs
This document includes excepts from helpful resources that are not directly related to `teenyarray`'s API, but are still relevant in understanding how `teenyarray` works

## Core Auxillary Resources
- [Guide To Numpy](https://web.mit.edu/dvp/Public/numpybook.pdf), *Travis Oilphant*
- [Numpy Docs](https://numpy.org/doc/stable/index.html)
- [mlx](https://github.com/ml-explore/mlx)

## Numpy Internals

### Arrays
There are 6 general mechanisms for creating arrays in Numpy:
- Conversion from other Python structures (i.e. lists and tuples)
- Intrinsic NumPy array creation functions (e.g. arange, ones, zeros, etc.)
- Replicating, joining, or mutating existing arrays
- Reading arrays from disk, either from standard or custom formats
- Creating arrays from raw bytes through the use of strings or buffers
- Use of special library functions (e.g., random)


> There are two modes of creating an array using `__new__`:
If buffer is None, then only shape, dtype, and order are used.
If buffer is an object exposing the buffer interface, then all keywords are interpreted.
No `__init__` method is needed because the array is fully initialized after the `__new__` method [[docs](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.html)]

### Indexing Arrays
![from page 25 of guide to numpy](image.png)

### Broadcasting
Here are the main broadcasting rules in NumPy:
1. **Same Shape**: If two arrays have exactly the same shape, then these arrays are compatible for broadcasting. For example, if you have two arrays, both of shape (2, 3), they can be directly added, subtracted, multiplied, etc.
2. **Prepend Ones to Smaller Array’s Shape**: If the arrays do not have the same shape, prepend the shape of the smaller array with ones until both shapes have the same length. For example, if you have an array of shape (5, 3) and another array of shape (3,), you can think of the second array as having shape (1, 3).
3. **Dimensions are Compatible**: After ensuring that the arrays have the same number of dimensions, two dimensions are compatible for broadcasting if they are equal or if one of them is 1. Continuing the above example, the array of shape (5, 3) can be broadcasted with the array of shape (1, 3) to result in an output of shape (5, 3).
4. **Broadcasting Operation**: When operating on the two arrays, NumPy treats the array as if its shape were the broadcast shape. It carries out the operation as if the smaller array had been copied along the missing dimensions out to the correct size.

### Type Conflicts and Casting
mostly handled in `dtype` object and `astype` (cast) method

## Python Internals

### Magic Methods

>Everyone knows the most basic magic method, `__init__`. It's the way that we can define the initialization behavior of an object. However, when I call x = SomeClass(), `__init__` is not the first thing to get called. Actually, it's a method called `__new__`, which actually creates the instance, then passes any arguments at creation on to the initializer. At the other end of the object's lifespan, there's` __del__`. [[magic methods](https://rszalski.github.io/magicmethods/)]

