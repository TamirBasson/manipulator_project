from setuptools import find_packages
from setuptools import setup

setup(
    name='manipulator_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('manipulator_interfaces', 'manipulator_interfaces.*')),
)
