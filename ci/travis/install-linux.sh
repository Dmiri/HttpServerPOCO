sudo add-apt-repository -y ppa:jonathonf/gcc-7.1
sudo apt update

sudo apt-get -y install gcc-7 g++-7

sudo apt-get -y install cmake python-pip

pip install --upgrade pip
sudo -H pip install conan
echo openssl trouble
gcc --version
g++ --version