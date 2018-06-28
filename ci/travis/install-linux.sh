echo info cmake
sudo apt-get install cmake
sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt update
sudo apt --force-yes  install g++-7 -y

sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-7 60 \
                         --slave /usr/bin/g++ g++ /usr/bin/g++-7 
sudo update-alternatives --config gcc
echo info gcc
gcc --version
g++ --version

# sudo apt-add-repository "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-6.0 main"
# sudo apt update
# sudo apt-get install -y clang-6.0

echo info pip
sudo apt-get install python-pip -y
#sudo pip install --upgrade pip

echo info conan
sudo -H pip install conan
