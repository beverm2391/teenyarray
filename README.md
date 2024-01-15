# Teenyarray

## The Vision...
### [teenyarray](https://github.com/beverm2391/teenyarray) is to [numpy](https://numpy.org/) as [teenygrad](https://github.com/tinygrad/teenygrad/tree/main) is to [PyTorch](https://pytorch.org/) 

## TODO
[ ] Foundations:
    [ ] - implement basic indexing (with strides)
    [ ] - figure out how to add and access data
    [ ] - decide on a memory layout (row major or column major)
    [ ] - implememnt views
[ ] - figure out how dtypes will work
[ ] - get a testing framework setup
    [ ] - write tests for all the foundational methods
[ ] - Operations:
    [ ] - get a list of [the 28 OPs](https://github.com/tinygrad/teenygrad/blob/main/teenygrad/lazy.py) we will need to plug into teenygrad (basically all the numpy ops it uses
[ ] - get the first end-to-end process setup (expose the bindings to python)

## Goals
- Learn cpp
- Learn about numpy internals
- Learn about lower level systems concepts like memory management, pointers, etc.
- Plug this in to teenygrad and get it working end to end
- Then optimimze it