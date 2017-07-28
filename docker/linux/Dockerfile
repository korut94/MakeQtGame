FROM ubuntu:trusty

RUN apt-get update && apt-get upgrade -y && apt-get install -y software-properties-common && \
    apt-add-repository -y ppa:beineri/opt-qt591-trusty

RUN apt-get update && apt-get install -y \
    build-essential \
    libgl1-mesa-dev \
    qt59-meta-minimal

RUN ln -s /opt/qt59/bin/qmake /usr/bin/qmake

RUN mkdir /source
VOLUME /source
WORKDIR /source


