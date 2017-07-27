FROM ubuntu:trusty
# The list of installation packages follow the Qt's official web pages instruction:
# - http://doc.qt.io/qt-5/linux.html
# - http://wiki.qt.io/Building_Qt_5_from_Git
RUN apt-get update && apt-get upgrade -y && \
    apt-get -y build-dep qt5-default && apt-get install -y \
    # Build essentials
    build-essential perl python git \ 
    # Libxcb
    '^libxcb.*-dev' libx11-xcb-dev libglu1-mesa-dev libxrender-dev libxi-dev \
    # Accessibility
    flex bison gperf libicu-dev libxslt-dev ruby \
    # Qt WebEngine...
    libssl-dev libxcursor-dev libxcomposite-dev libxdamage-dev libxrandr-dev libdbus-1-dev \
    libfontconfig1-dev libcap-dev libxtst-dev libpulse-dev libudev-dev libpci-dev libnss3-dev \
    libasound2-dev libxss-dev libegl1-mesa-dev gperf bison \
    # ... and addittional dependencies on Ubuntu 14.04
    libbz2-dev libgcrypt11-dev libdrm-dev libcups2-dev libatkmm-1.6-dev \
    # Qt Multimedia
    libasound2-dev libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev
# Retrieve the source code, build the Qt version specified and install it.
RUN git clone git://code.qt.io/qt/qt5.git && cd qt5 && git checkout v5.9.0 \
    && perl init-repository --module-subset=default,-qtwebkit,-qtwebkit-examples,-qtwebengine \
    && ./configure -developer-build -opensource \
       -skip qt3d \
       -skip qtactiveqt \
       -skip qtandroidextras \
       -skip qtcanvas3d \
       -skip qtcharts \
       -skip qtconnectivity \
       -skip qtdatavis3d \
       -skip qtdoc \
       -skip qtdocgallery \
       -skip qtenginio \
       -skip qtfeedback \
       -skip qtgamepad \
       -skip qtimageformats \
       -skip qtlocation \
       -skip qtmacextras \
       -skip qtnewtworkauth \
       -skip qtpim \
       -skip qtpurchasing \
       -skip qtqa \
       -skip qtquick1 \
       -skip qtquickcontrols \
       -skip qtremoteobjects \
       -skip qtrepotools \
       -skip qtscript \
       -skip qtscxml \
       -skip qtsensors \
       -skip qtserialbus \
       -skip qtserialport \
       -skip qtspeech \
       -skip qtsvg \
       -skip qttools \
       -skip qtvirtualkeyboard \
       -skip qtwayland \
       -skip qtwebchannel \
       -skip qtwebengine \
       -skip qtwebkit \
       -skip qtwebkit-examples \
       -skip qtwebsockets \
       -skip qtwebview \
       -skip qtwineextras \
       -skip qtxmlpatterns \
       -confirm-license \
       -release \
       -silent \
       -nomake examples -nomake tests -nomake doc \
    && make -j4 \
    && make install
    
    
    
    
    

