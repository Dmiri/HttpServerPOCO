sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt update
sudo apt install g++-7 -y
sudo update-alternatives —install /usr/bin/gcc gcc /usr/bin/gcc-7 60 \
                                                    —slave /usr/bin/g++ g++ /usr/bin/g++-7
sudo update-alternatives —config gcc
gcc —version
g++ - version

# sudo apt-add-repository "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-6.0 main"
# sudo apt update
# sudo apt-get install -y clang-6.0

sudo apt-get install cmake

sudo apt-get -y install cmake python-pip
pip install --upgrade pip
pip install conan






# sudo add-apt-repository -y ppa:ubuntu-toolchain-r/stable
# sudo apt update
# sudo apt -y install gcc-5 g++-5
# sudo apt-get -y install gcc-7 g++-7
# gcc-7 --version
# g++-7 --version