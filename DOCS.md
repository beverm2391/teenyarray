# Devloper Docs

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