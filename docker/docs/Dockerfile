FROM ubuntu:trusty

# Need to give Doxygen v1.8.13
RUN echo "deb http://cz.archive.ubuntu.com/ubuntu zesty main" >> /etc/apt/sources.list
RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    doxygen

ENTRYPOINT doxygen

RUN mkdir /source
VOLUME /source
WORKDIR /source