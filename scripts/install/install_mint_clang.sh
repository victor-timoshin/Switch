sudo apt update
sudo apt install clang -y

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

./scripts/install/install_mint_gcc.sh