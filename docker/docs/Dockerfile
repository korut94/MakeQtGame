FROM ubuntu:trusty

RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    doxygen

ENTRYPOINT doxygen

RUN mkdir /docs
VOLUME /docs
WORKDIR /docs