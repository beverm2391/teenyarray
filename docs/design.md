# desining teenyarray

The goal here was to build a minimalist yet performant implementation of numpy. 
When designing the core abstractions / objects, I had to make a few design choices along the way. Initially, it seemes logical to have a core array class (`tarray`) with elementwise operations, thus avoiding a separate `ufunc` class like numpy. The problem here lies with broadcasting. To avoid [1] the user having to reshape manually and [2] broadcasting limited to only smaller dimensions I decided to copy NumPy's core abstractions. They are certainly smarter than me and I hope this will payoff when I go to optimize the C++ API later. Concerning the `ArrayScalar` class, my understanding is that this serves to simplify array * scalar operations, provide combatibilty with C types

# Main Abstractions

## `TArray` (teeny array)
- array creation
- indexing and slicing
- shaping
- operations
  - element wise
  - reduction ops
  - matrix ops/linalg

## `tfunc` (teeny function)
- element wise ops

## `Dtype` (data type)
- int32, float32 for now

## `ArrayScalar`
- same elementwise operations as `tarray`

## Broadcasting
Here are the main broadcasting rules in NumPy:

1. **Same Shape**: If two arrays have exactly the same shape, then these arrays are compatible for broadcasting. For example, if you have two arrays, both of shape (2, 3), they can be directly added, subtracted, multiplied, etc.
2. **Prepend Ones to Smaller Array’s Shape**: If the arrays do not have the same shape, prepend the shape of the smaller array with ones until both shapes have the same length. For example, if you have an array of shape (5, 3) and another array of shape (3,), you can think of the second array as having shape (1, 3).
3. **Dimensions are Compatible**: After ensuring that the arrays have the same number of dimensions, two dimensions are compatible for broadcasting if they are equal or if one of them is 1. Continuing the above example, the array of shape (5, 3) can be broadcasted with the array of shape (1, 3) to result in an output of shape (5, 3).
4. **Broadcasting Operation**: When operating on the two arrays, NumPy treats the array as if its shape were the broadcast shape. It carries out the operation as if the smaller array had been copied along the missing dimensions out to the correct size.