# Python API Docs
This will eventually be the exposed python API. right now its just random crap

- This is going to hold the API for the main teenyarray object
- I'll define here exactly what methods I'll need to expose to plug into teenygrad
- currently copying the structure of the [numpy docs](https://numpy.org/doc/stable/reference/index.html)

## The n-dimensional Array (tarray)
- `teenyarray.tarray`

```python
class teenyarray.tarray(
    shape: List[int],
    dtype=float,
    buffer = None,
    offset=0,
    strides=None,
    order='C')
```
**Attributes**

- `data`
  - the buffer
- `shape`
  - the shape
- `size`
  - the number of elements in the buffer
- `strides`

**Methods**
- `print`
  - prints out attributes for debugging

## The ufunc (universal function)

## Scalars

## Data Type Objects

## Indexing Routines

## Iteration

## Subclasses?