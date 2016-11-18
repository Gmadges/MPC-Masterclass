TARGET=a.out

TEMPLATE=app

OBJECTS_DIR=obj

QT+=gui opengl core

isEqual(QT_MAJOR_VERSION, 5) {
	cache()
	DEFINES +=QT5BUILD
}

MOC_DIR=moc
UI_DIR=./include

CONFIG-=app_bundle

SOURCES += $$PWD/src/*.cpp
HEADERS  += $$PWD/include/*.h     

FORMS+= $$PWD/forms/mainwindow.ui

INCLUDEPATH += /usr/local/include/bullet ./include

LIBS += -L/usr/local/lib -lBulletDynamics  -lBulletCollision  -lLinearMath -lopenvdb -lpthread -lHalf -ltbb -lassimp

DESTDIR=./

DISTFILES += \
    $$PWD/shaders/simple.vert \
    $$PWD/shaders/simple.frag


RESOURCES += shaders.qrc

CONFIG += console c++11