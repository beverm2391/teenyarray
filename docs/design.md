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

### Handling Different Dtypes - Templates + Polymorphism
- Base `Dtype` class defines the interface for all data types
  - virtual functions for any operations (like type converion)
- Derived `Dtype` classes
  - for each data type, use a derived class that implementes the Dtype interface. This will be the actual implementation of the ops defined in the `Dtype` interface
- `Tarray` Class
  - instead of hanving a template param for the data type, use a pointer to a `Dtype` object, which would be set to an instance of the appropriate derived class (based on the data type of the array)

## `tfunc` (teeny function)
- broadcasting
- type checking
- buffered coercion
  - use a temporary buffer to hold data while converting (coercing) dytpes
- element wise ops

## `Dtype` (data type)
- int32, float32 for now

### Runtime Type System
This is necessary because we need runtime type information (RTTI) to handle dynamic type behaviors like NumPy's `dtype` abstraction
This includes:
  - a `Dtype` class that encapsulates type info/metadata (name, itemsize, biteorder, etc.) 
  - the Dtype Registry maps identifiers (strings or enums) to `Dtype` instances. This allows for dynamic type resolution at runtime

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