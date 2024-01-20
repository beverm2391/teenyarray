# Python API Docs

- This is going to hold the API for the main teenyarray object
- I'll define here exactly what methods I'll need to expose to plug into teenygrad
- currently copying the structure of the [numpy docs](https://numpy.org/doc/stable/reference/index.html)

## The n-dimensional Array (tarray)
- `teenyarray.tarray`

```python
class teenyarray.tarray(shape, dtype=float, buffer=None, offset=0, strides=None, order=None
)
```
  
### Attributes
- shape
- size
- strides
- isContigous
- view

### Methods





## The ufunc (universal function)

## Scalars

## Data Type Objects

## Indexing Routines

## Iteration

## Subclasses?