FROM qt:linux

CMD qmake MakeQtGame.pro -spec linux-g++ && make qmake_all && \
    make && \
    cd /source/test/ \
    make check

