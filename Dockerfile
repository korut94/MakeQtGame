FROM ubuntu:16.04

# Installation dependecies:
# Qt 5 and necessary dependencies (see https://wiki.qt.io/Install_Qt_5_on_Ubuntu)
# libtinyxml2-dev and zlib required from TMXParser
# git, openssh-client, ca-certificates to clone the repositories
RUN apt-get update && apt-get upgrade -y && apt-get install -y --no-install-recommends \
    build-essential \
    ca-certificates \
    cmake \
    git \
    libfontconfig1 \
    libglu1-mesa-dev \
    libtinyxml2-dev \
    mesa-common-dev \
    openssh-client \
    qtbase5-dev \
    zlibc zlib1g zlib1g-dev

# TMXParser install & download, for the map parsing.
RUN git clone https://github.com/sainteos/tmxparser.git /tmp/tmxparser/ \
    && mkdir /tmp/tmxparser/build && cd /tmp/tmxparser/build \
    && cmake .. && make && make install \
    && cd

