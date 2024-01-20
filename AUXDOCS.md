# Auxillary Docs
This document includes excepts from helpful resources that are not directly related to `teenyarray`'s API, but are still relevant in understanding how `teenyarray` works

## Core Auxillary Resources
- [Guide To Numpy](https://web.mit.edu/dvp/Public/numpybook.pdf), *Travis Oilphant*
- [Numpy Docs](https://numpy.org/doc/stable/index.html)
- [mlx](https://github.com/ml-explore/mlx)

## Arrays
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

## Python Internals

### Magic Methods

>Everyone knows the most basic magic method, `__init__`. It's the way that we can define the initialization behavior of an object. However, when I call x = SomeClass(), `__init__` is not the first thing to get called. Actually, it's a method called `__new__`, which actually creates the instance, then passes any arguments at creation on to the initializer. At the other end of the object's lifespan, there's` __del__`. [[magic methods](https://rszalski.github.io/magicmethods/)]

