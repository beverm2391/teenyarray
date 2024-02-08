# desining teenyarray
This holds design decisions for teenyarray

The goal here was to build a minimalist yet performant implementation of numpy. 
When designing the core abstractions / objects, I had to make a few design choices along the way. Initially, it seemes logical to have a core array class (`tarray`) with elementwise operations, thus avoiding a separate `ufunc` class like numpy. The problem here lies with broadcasting. To avoid [1] the user having to reshape manually and [2] broadcasting limited to only smaller dimensions I decided to copy NumPy's core abstractions. They are certainly smarter than me and I hope this will payoff when I go to optimize the C++ API later. Concerning the `ArrayScalar` class, my understanding is that this serves to simplify array * scalar operations, provide combatibilty with C types

avoid the bloat at all costs. aggresivly refactor down. add line counter. test driven. core lib small, encompasing lib can be bigger. like tinygrad

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
- broadcasting
- type checking
- buffered coercion
  - use a temporary buffer to hold data while converting (coercing) dytpes
- element wise ops

## `Dtype` (data type)
- int32, float32 for now

## `ArrayScalar`
think of this as a 0 dimensional array
- same elementwise operations as `tarray`
  - these aren't performed on the arrayscalar object itself, but the underlying data
- make sure to handle ops between this and tarray (broadcasting could be tricky here)

# Secondary Abstractions
not exactly sure what I'll need yet

## `Allocator`
For memory allocation

## `Iterator`
For multidimensional iteration - figure out how NumPy handles this
see the beautiful code chapter on NumPy
This will be interesting because just like slicing/indexing, you need to operate on a contiguous buffer