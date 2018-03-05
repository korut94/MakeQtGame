FROM ubuntu:trusty

# To install a version of Doxygen from the binary archive: 
# RUN wget https://sourceforge.net/projects/doxygen/files/rel-$(VERSION)/doxygen-$(VERSION).linux.bin.tar.gz \
#     && tar -xf doxygen-$(VERSION).linux.bin.tar.gz && cd doxygen-$(VERSION) \
#     && bin/doxygen --help
#     # Remove doxytag from installation since it doesn't present into the binary archive
#     && sed -i '/doxytag/d' ./Makefile.in \
#     # The directory 'examples' has been already moved into the 'html' directory
#     && sed -i '/examples/d' ./Makefile.in \
#     && ./configure && make install
# Actually this solution doesn't work propertly due an error in the exec file (Syntax error: ")" unexpected).
# Waiting to find a solution.

RUN apt-get update && apt-get upgrade -y && apt-get install -y doxygen

RUN mkdir /source
VOLUME /source
WORKDIR /source

ENTRYPOINT doxygen