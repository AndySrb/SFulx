## needs windows compile options added
TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/main.cpp src/Window.cpp src/Game.cpp

HEADERS += src/Window.h src/Game.h

win32:: LIBS += -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system
-lsfml-system
else:unix: LIBS += -L$$PWD/../SFML-2.5.1-linux/lib/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system

#INCLUDEPATH += $$PWD/../SFML-2.5.1/include
DEPENDPATH += $$PWD/../SFML-2.5.1/include
