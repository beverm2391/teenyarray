# Teenyarray

## The Vision...
### [teenyarray](https://github.com/beverm2391/teenyarray) is to [numpy](https://numpy.org/) as [teenygrad](https://github.com/tinygrad/teenygrad/tree/main) is to [tinygrad](https://github.com/tinygrad/tinygrad) (or [PyTorch](https://pytorch.org/))

I'm building this as a personal project in hopes of producing a distillation of a library like Numpy. Just as teenygrad includes only core deep-learning functionality needed to train the MNIST, my goal is to implement a core array API that I can use to train the MNIST. This means replacing Numpy as a dependency of teenygrad with this library.

- [design](docs/design.md) outlines design choices
- [developer-docs](docs/developer-docs.md) will help get things working
- [python-api](docs/python-api.md) will eventually have the Python API
- [auxillary-docs](docs/auxillary-docs.md) has external resources and documentation that I've found helpful or relied on

## Personal Goals
- build my first "real" cpp project
- build my first "under the hood" project that exposes Python bindings
- Learn about numpy internals
- Practice lower level systems concepts as I write (hopefully clean and efficient) cpp
- (eventually) learn some GPU programming by implementing this on METAL

## TODO
- [ ] get the 4 main classes defined (skeleton) and exposed via bindings
  - [X] Dtype
  - [X] Tarray
    - [ ] add array creation methods
      - [X] static methods (.zeroes() .ones(), etc)
      - [ ] figure out a way to bind fill to python (takes in python type, passes through correct func with C-type (which is manually created from the temlate function))
        - [ ] might need a new typeMap??
      - [ ] from python data (.array())
      - [ ] figure out a default datatype if no argument is provided
    - [ ] __getitem__ and __setitem__
      - [ ] basic indexing
      - [ ] slicing
    - [ ] reshape
    - [ ] tranposing
  - [ ] Tfunc
    - [ ] break the [the 28 OPs](https://github.com/tinygrad/teenygrad/blob/main/teenygrad/lazy.py) into categories: Unary, Binary, Reduce, Ternary, and Load
    - [ ] handle broadcasting
  - [ ] ArrayScalar
      - [ ] get element-wise ops working
- [ ] figure out how iteration will work
- [ ] work on memory management
  - [ ] lazy evaluation
  - [ ] copy on write?
- [ ] get a testing framework setup
    - [ ] write tests for all the foundational methods
- [ ] add an overall line counter (resist the bloat!)

## Long Term
- [ ] do a writeup on why i built this, clearly outlining the process
- [ ] work on optimizations (matmul, etc.)
- [ ] once end to end CPU is working, port to METAL
- [ ] get some sort of benchmark going