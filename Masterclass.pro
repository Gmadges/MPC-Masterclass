
TARGET=Masterclass

OBJECTS_DIR=obj

QT+=gui opengl core

isEqual(QT_MAJOR_VERSION, 5) {
	cache()
	DEFINES +=QT5BUILD
}

MOC_DIR=moc

CONFIG-=app_bundle

SOURCES+= $$PWD/src/main.cpp

# HEADERS+= $$PWD/include/NGLScene.h \
#          $$PWD/include/WindowParams.h

INCLUDEPATH += /usr/local/include/bullet ./include

LIBS += -L/usr/local/lib -lBulletDynamics  -lBulletCollision  -lLinearMath -lopenvdb -lpthread -lHalf -ltbb 

DESTDIR=./

# OTHER_FILES+= shaders/*.glsl \
#							README.md

CONFIG += console