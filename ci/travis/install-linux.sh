sudo add-apt-repository -y ppa:jonathonf/gcc-7.1
sudo add-apt-repository -y ppa:ubuntu-toolchain-r/stable
sudo apt-add-repository "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-6.0 main"
sudo apt-get update -qq

sudo apt-get install -qq g++-5
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-5 90

sudo apt-get install -qq gcc-7

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