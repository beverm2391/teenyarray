from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys
import setuptools
import os

__version__ = '0.0.1' # TODO: read from file or git tag or something


def workspace():
    """Returns the path to the workspace root directory"""
    return os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

ext_modules = [
    Extension(
        'teenyarray',
        [
            f'{workspace()}/src/pybind-example.cpp'
            # ! Add more files here
        ],
        include_dirs=[
            f"{workspace()}/extern/pybind11/include",
        ],
        extra_compile_args=['-std=c++11'], # this gets passed to the compiler
        language='c++',
    ),
]

setup(
    name='teenyarray',
    version=__version__,
    author='Ben Everman',
    author_email='',
    url='https://github.com/beverm2391/teenyarray',
    description='A teeny array library',
    long_description='',
    ext_modules=ext_modules, # modules to compile
    install_requires=['pybind11>=2.4'], # this right?
    setup_requires=['pybind11>=2.4'], # this right?
    cmdclass={'build_ext': build_ext},
    zip_safe=False,
)