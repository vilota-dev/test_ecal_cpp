1. Install capnproto dependency
```
curl -O https://capnproto.org/capnproto-c++-0.10.3.tar.gz
tar zxf capnproto-c++-0.10.3.tar.gz
cd capnproto-c++-0.10.3
./configure
make -j6
sudo make install
```

2. Build this repository
```
git clone https://github.com/vilota-dev/test_ecal_cpp.git
cd test_ecal_cpp
git submodule update --init --recursive
mkdir build && cd build
cmake ..
make -j6
```
