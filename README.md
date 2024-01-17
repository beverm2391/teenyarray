# Teenyarray

## The Vision...
### [teenyarray](https://github.com/beverm2391/teenyarray) is to [numpy](https://numpy.org/) as [teenygrad](https://github.com/tinygrad/teenygrad/tree/main) is to [PyTorch](https://pytorch.org/) 

## TODO
- [ ] get end-to-end [bindings](https://pybind11.readthedocs.io/en/stable/basics.html) going so I can figure out how i need to abstract this cpp API
  - [ ] do it in this repo and get everything CMAKE/setuptools configured
    - [ ] figure out how to use `make check -j 4`
  - [ ] [mlx binding to python docs](https://ml-explore.github.io/mlx/build/html/dev/extensions.html#binding-to-python)
- [ ] make an API doc [like this](https://ml-explore.github.io/mlx/build/html/python/array.html) for the python API, then go backards from there (think about what teenygrad needs)
- [ ] foundations:
    - [ ] implement basic indexing (with strides)
      - [X] - decide on a memory layout (row major or column major)
        - [ ] figure out if strides should repepresent num bytes or num elements
        - [ ] implement calcualteSize() function
    - [ ] figure out how to add and access data
    - [ ] implememnt views
- [ ] figure out how dtypes will work
- [ ] figure out how iteration will work
- [ ] get a testing framework setup
    - [ ] write tests for all the foundational methods
- [ ] Operations:
    - [ ] get a list of [the 28 OPs](https://github.com/tinygrad/teenygrad/blob/main/teenygrad/lazy.py) we will need to plug into teenygrad (basically all the numpy ops it uses)
- [ ] get the first end-to-end process setup (expose the bindings to python)
    - [ ] using float32 dtype, hardcoded for now

## Long Term
- [ ] once end to end CPU is working, port to METAL

## Goals
- Learn cpp
- Learn about numpy internals
- Practice lower level systems concepts like memory management, pointers, etc.
- Plug this in to teenygrad and get it working end to end'
- train MNIST
- Optimimze