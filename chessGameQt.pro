QT += quick

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/boardmodel.cpp \
    src/main.cpp \
    src/squaremodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

HEADERS += \
    src/boardmodel.h \
    src/squaremodel.h

win32: LIBS += -L$$PWD/../build/src/ -lChessGame_lib

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../build/src/ChessGame_lib.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../build/src/libChessGame_lib.a

