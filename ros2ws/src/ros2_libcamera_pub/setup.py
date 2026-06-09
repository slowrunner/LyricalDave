from setuptools import setup

package_name = 'ros2_libcamera_pub'

setup(
    name=package_name,
    version='2.3.2',
    packages=[],
    py_modules=[
        'libcamera_jpg_pub'
    ],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='slowrunner',
    maintainer_email='slowrunner@noreply.com',
    author='slowrunner',
    keywords=['ROS'],
    description='A hack to publish camera images on Unbuntu 22.04',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'libcamera_jpg_pub = libcamera_jpg_pub:main'
        ],
    },
)
