# sudo add-apt-repository -y ppa:jonathonf/gcc-7.1
sudo apt update

sudo apt-get -y install gcc-5 g++-5
CC = gcc-5
CXX = g++-5
sudo apt-get -y install cmake python-pip
gcc -xc++ -E -v -
pip install --upgrade pip
sudo -H pip install conan
echo openssl trouble
gcc --version
g++ --version