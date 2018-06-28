sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install gcc-7
gcc-7 --version

sudo apt-add-repository "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-6.0 main"
sudo apt-get update
sudo apt-get install -y clang-6.0

sudo apt-get install cmake
sudo apt-get upgrade

sudo apt-get -y install gcc-5 g++-5
sudo apt-get -y install cmake python-pip
pip install --upgrade pip
sudo -H pip install conan
echo openssl trouble
gcc --version
g++ --version