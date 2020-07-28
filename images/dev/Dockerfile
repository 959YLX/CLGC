FROM ubuntu:20.04

LABEL Usage="build CLGC service"
LABEL Author="geekylx@hotmail.com"

RUN apt-get update && \
apt-get install -y autoconf automake libtool curl make g++ unzip wget cmake pkg-config && \
mkdir -p /mnt/dependencies && \
cd /mnt/dependencies && \ 
wget https://github.com/protocolbuffers/protobuf/releases/download/v3.12.3/protobuf-cpp-3.12.3.tar.gz && \
tar -zxf protobuf-cpp-3.12.3.tar.gz && \
cd protobuf-3.12.3/ && \
./configure && \
make && make check && make install && \
ldconfig && \
mkdir -p /root/src

WORKDIR /root/src

CMD [ "/bin/bash" ]