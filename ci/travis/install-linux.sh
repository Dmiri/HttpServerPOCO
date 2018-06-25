sudo add-apt-repository -y ppa:ubuntu-toolchain-r/stable
sudo apt-get update -qq

sudo apt-get install -qq g++-5
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-5 90

# sudo apt-get install -qq gcc-7


wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
sudo apt-add-repository "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-6.0 main"
sudo apt-get update
sudo apt-get install -y clang-6.0

sudo apt-get install cmake
sudo apt-get upgrade

sudo apt-get install openssl libssl-dev

# sudo cmake -DENABLE_SEVENZIP=OFF ..
# sudo apt-get install build-essential libssl-dev libffi-dev python3-dev python3-pip
# sudo pip3 install python-patch
# sudo pip3 install python-node-semver
# sudo pip3 install python-distro
# sudo pip3 install python-pluginbase

# sudo pip install -r conans/requirements.txt
# sudo git clone https://github.com/conan-io/conan.git
# sudo cd conan
# sudo pip install -r conans/requirements.txt
sudo pip install conan


# sudo apt-get install openssl libssl-dev
# sudo pip install --build Poco


# CMAKE_VERSION=3.3.2
# CMAKE_VERSION_DIR=v3.3

# CMAKE_OS=Linux-x86_64
# CMAKE_TAR=cmake-$CMAKE_VERSION-$CMAKE_OS.tar.gz
# CMAKE_URL=http://www.cmake.org/files/$CMAKE_VERSION_DIR/$CMAKE_TAR
# CMAKE_DIR=$(pwd)/cmake-$CMAKE_VERSION

# wget --quiet $CMAKE_URL
# mkdir -p $CMAKE_DIR
# tar --strip-components=1 -xzf $CMAKE_TAR -C $CMAKE_DIR
# export PATH=$CMAKE_DIR/bin:$PATH