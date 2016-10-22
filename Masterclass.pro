
TARGET=Masterclass

OBJECTS_DIR=obj

QT+=gui opengl core

isEqual(QT_MAJOR_VERSION, 5) {
	cache()
	DEFINES +=QT5BUILD
}

MOC_DIR=moc
UI_DIR=./include

CONFIG-=app_bundle

SOURCES+= $$PWD/src/main.cpp    \
            $$PWD/src/mainWindow.cpp \
            $$PWD/src/glWidget.cpp

HEADERS+= $$PWD/include/mainWindow.h    \
            $$PWD/include/glWidget.h

FORMS+= $$PWD/src/mainWindow.ui

INCLUDEPATH += /usr/local/include/bullet ./include

LIBS += -L/usr/local/lib -lBulletDynamics  -lBulletCollision  -lLinearMath -lopenvdb -lpthread -lHalf -ltbb 

DESTDIR=./

# OTHER_FILES+= shaders/*.glsl \
#							README.md

CONFIG += console