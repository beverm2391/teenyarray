# Teenyarray

## The Vision...
### [teenyarray](https://github.com/beverm2391/teenyarray) is to [numpy](https://numpy.org/) as [teenygrad](https://github.com/tinygrad/teenygrad/tree/main) is to [tinygrad](https://github.com/tinygrad/tinygrad) (or [PyTorch](https://pytorch.org/))

I'm building this as a personal project in hopes of producing a distillation of a library like Numpy. Just as teenygrad includes only core deep-learning functionality needed to train the MNIST, my goal is to implement a core array API that I can use to train the MNIST. This means replacing Numpy as a dependency of teenygrad with this library.

## Personal Goals
- build my first "real" cpp project
- build my first "under the hood" project that exposes Python bindings
- Learn about numpy internals
- Practice lower level systems concepts as I write (hopefully clean and efficient) cpp
- (eventually) learn some GPU programming by implementing this on METAL

## Completed
- [X] get end-to-end [bindings](https://pybind11.readthedocs.io/en/stable/basics.html) going so I can figure out how i need to abstract this cpp API
  - [X] do it in this repo and get everything CMAKE/setuptools configured

## TODO
- [ ] get the 4 main classes defined (skeleton) and exposed via bindings
  - [ ] dtype
  - [ ] Tarray
  - [ ] ArrayScalar
  - [ ] tfunc
- [ ] get the skeleton broadcasting logic
  - [ ] figure out how ufuncs work in numpy (check the *Guide To Numpy* book)
- [ ] work on array init methods [see here](/AUXDOCS.md):
    - [ ] write the `calculateStrides()` method for the constructor
      - [ ] do some manual written examples on paper of the 1-dim memory layout vs the 2-dim layout (can add more dims later)
    - [ ] figure out if strides should repepresent num bytes or num elements
    - [ ] implement basic indexing (with strides)
      - [X] - decide on a memory layout (row major or column major)
        - [X] implement calcualteSize() function
    - [ ] implememnt views
- [ ] figure out how iteration will work
- [ ] figure out how allocatoin will work (custom memory allocator)?
- [ ] get a testing framework setup
    - [ ] write tests for all the foundational methods
- [ ] Operations:
    - [ ] get a list of [the 28 OPs](https://github.com/tinygrad/teenygrad/blob/main/teenygrad/lazy.py) we will need to plug into teenygrad (basically all the numpy ops it uses)
- [ ] get the first end-to-end process setup (expose the bindings to python)
    - [ ] using float32 dtype, hardcoded for now
- [ ] add an overall line counter (resist the bloat!)

## Long Term
- [ ] do a writeup on why i built this, clearly outlining the process
- [ ] work on optimizations (matmul, etc.)
- [ ] once end to end CPU is working, port to METAL
- [ ] get some sort of benchmark going