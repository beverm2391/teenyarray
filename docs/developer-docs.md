# Devloper Docs
These are the developer docs (how to get things working)

## Building With Cmake

*from the build directory:*
```bash
cmake ..
make
```

check `CMakeLists.txt` for options

## Using the Build in A Python Environment
- Add the module dir path `build/` to the environment (sys.path.append or `.pth` file in site-packages)
- cd to `/python` and run `pip install .` which will run the `setup.py` file

## Updating the Python Package on Rebuild
- just rebuild with Cmake

## Adding A New Source File
- update the source files argument in `setup.py`