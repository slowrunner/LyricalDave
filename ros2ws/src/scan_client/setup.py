from setuptools import setup

package_name = 'scan_client'

setup(
    name=package_name,
    version='0.1',
    packages=[],
    py_modules=[
        'scan_client'
    ],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='slowrunner',
    maintainer_email='slowrunner@noreply.githum.com',
    author='slowrunner',
    keywords=['ROS'],
    classifiers=[
        'Intended Audience :: Developers',
        'License :: OSI Approved :: Apache Software License',
        'Programming Language :: Python',
        'Topic :: Software Development',
    ],
    description='ROS2 Client for /scan topic'
                'prints distance for 90,0,-90,180',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'scan_client = scan_client:main'
        ],
    },
)
