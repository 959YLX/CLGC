FROM ubuntu:20.04

LABEL Usage="build CLGC service"
LABEL Author="geekylx@hotmail.com"

ENV TZ=Asia/Shanghai

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone && \ 
apt-get update && \
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

RUN apt-get install -y libboost-dev zlib1g-dev && \
cd /mnt/dependencies && \
wget https://github.com/chenshuo/muduo/archive/v2.0.2.tar.gz && \
tar -zxf v2.0.2.tar.gz && cd muduo-2.0.2/ && ./build install && \
cd ../build/release-install-cpp11/ && \
cp -r include/muduo /usr/local/include && \
cp lib/* /usr/local/lib/

WORKDIR /root/src

CMD [ "/bin/bash" ]