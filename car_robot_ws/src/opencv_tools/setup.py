import os
from glob import glob
from setuptools import setup
from setuptools import find_packages, setup

package_name = 'opencv_tools'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'models'), glob('models/*.tflite')),

    ],
     install_requires=[
        'setuptools',
        'ultralytics',
        'opencv-python',
        'numpy',
    ],
    zip_safe=True,
    maintainer='robogames',
    maintainer_email='vtcrolab@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            # 'detect_node = opencv_tools.detect_object_node:main',
            'detect_node = opencv_tools.detect_yolo_node:main',
        ],
    },
)
