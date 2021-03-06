#############################################################################
# Makefile for building: a.out
# Generated by qmake (3.0) (Qt 5.5.1)
# Project:  Masterclass.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt5/bin/qmake -o Makefile Masterclass.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT5BUILD -DQT_NO_DEBUG -DQT_OPENGL_LIB -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -std=c++0x -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -isystem /usr/local/include/bullet -Iinclude -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtOpenGL -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -Imoc -Iinclude -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64
QMAKE         = /usr/lib/x86_64-linux-gnu/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = a.out1.0.0
DISTDIR = /home/george/projects/MPC-Masterclass.git/obj/a.out1.0.0
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS) -L/usr/X11R6/lib64 -L/usr/local/lib -lBulletDynamics -lBulletCollision -lLinearMath -lopenvdb -lHalf -ltbb -lassimp -lQt5OpenGL -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = obj/

####### Files

SOURCES       = src/floorPlane.cpp \
		src/glscene.cpp \
		src/line.cpp \
		src/main.cpp \
		src/mainwindow.cpp \
		src/mesh.cpp \
		src/model.cpp \
		src/modelController.cpp \
		src/openVDBTools.cpp \
		src/physicsBody.cpp \
		src/physicsWorld.cpp \
		src/settings.cpp \
		src/sphere.cpp \
		src/springSettings.cpp \
		src/tabInfo.cpp qrc_shaders.cpp \
		qrc_style.cpp \
		moc/moc_glscene.cpp \
		moc/moc_mainwindow.cpp \
		moc/moc_settings.cpp \
		moc/moc_springSettings.cpp \
		moc/moc_tabInfo.cpp
OBJECTS       = obj/floorPlane.o \
		obj/glscene.o \
		obj/line.o \
		obj/main.o \
		obj/mainwindow.o \
		obj/mesh.o \
		obj/model.o \
		obj/modelController.o \
		obj/openVDBTools.o \
		obj/physicsBody.o \
		obj/physicsWorld.o \
		obj/settings.o \
		obj/sphere.o \
		obj/springSettings.o \
		obj/tabInfo.o \
		obj/qrc_shaders.o \
		obj/qrc_style.o \
		obj/moc_glscene.o \
		obj/moc_mainwindow.o \
		obj/moc_settings.o \
		obj/moc_springSettings.o \
		obj/moc_tabInfo.o
DIST          = shaders/simple.vert \
		shaders/simple.frag \
		Masterclass.pro include/floorPlane.h \
		include/glscene.h \
		include/line.h \
		include/mainwindow.h \
		include/mesh.h \
		include/model.h \
		include/modelController.h \
		include/openVDBTools.h \
		include/physicsBody.h \
		include/physicsWorld.h \
		include/settings.h \
		include/sphere.h \
		include/springSettings.h \
		include/tabInfo.h \
		include/types.h \
		include/ui_mainwindow.h \
		include/ui_springSettings.h \
		include/ui_tabInfo.h src/floorPlane.cpp \
		src/glscene.cpp \
		src/line.cpp \
		src/main.cpp \
		src/mainwindow.cpp \
		src/mesh.cpp \
		src/model.cpp \
		src/modelController.cpp \
		src/openVDBTools.cpp \
		src/physicsBody.cpp \
		src/physicsWorld.cpp \
		src/settings.cpp \
		src/sphere.cpp \
		src/springSettings.cpp \
		src/tabInfo.cpp
QMAKE_TARGET  = a.out
DESTDIR       = #avoid trailing-slash linebreak
TARGET        = a.out


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

$(TARGET): include/ui_mainwindow.h include/ui_springSettings.h include/ui_tabInfo.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Masterclass.pro .qmake.cache /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.cache \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/c++11.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		Masterclass.pro \
		shaders.qrc \
		QDarkStyleSheet/qdarkstyle/style.qrc \
		/usr/lib/x86_64-linux-gnu/libQt5OpenGL.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Widgets.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Gui.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Core.prl
	$(QMAKE) -o Makefile Masterclass.pro
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
.qmake.cache:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/c++11.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
Masterclass.pro:
shaders.qrc:
QDarkStyleSheet/qdarkstyle/style.qrc:
/usr/lib/x86_64-linux-gnu/libQt5OpenGL.prl:
/usr/lib/x86_64-linux-gnu/libQt5Widgets.prl:
/usr/lib/x86_64-linux-gnu/libQt5Gui.prl:
/usr/lib/x86_64-linux-gnu/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile Masterclass.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents shaders.qrc QDarkStyleSheet/qdarkstyle/style.qrc $(DISTDIR)/
	$(COPY_FILE) --parents include/floorPlane.h include/glscene.h include/line.h include/mainwindow.h include/mesh.h include/model.h include/modelController.h include/openVDBTools.h include/physicsBody.h include/physicsWorld.h include/settings.h include/sphere.h include/springSettings.h include/tabInfo.h include/types.h include/ui_mainwindow.h include/ui_springSettings.h include/ui_tabInfo.h $(DISTDIR)/
	$(COPY_FILE) --parents src/floorPlane.cpp src/glscene.cpp src/line.cpp src/main.cpp src/mainwindow.cpp src/mesh.cpp src/model.cpp src/modelController.cpp src/openVDBTools.cpp src/physicsBody.cpp src/physicsWorld.cpp src/settings.cpp src/sphere.cpp src/springSettings.cpp src/tabInfo.cpp $(DISTDIR)/
	$(COPY_FILE) --parents forms/mainwindow.ui forms/springSettings.ui forms/tabInfo.ui $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

compiler_rcc_make_all: qrc_shaders.cpp qrc_style.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_shaders.cpp qrc_style.cpp
qrc_shaders.cpp: shaders.qrc \
		shaders/simple.frag \
		shaders/simple.vert \
		shaders/skinning.vert
	/usr/lib/x86_64-linux-gnu/qt5/bin/rcc -name shaders shaders.qrc -o qrc_shaders.cpp

qrc_style.cpp: QDarkStyleSheet/qdarkstyle/style.qrc \
		QDarkStyleSheet/qdarkstyle/rc/Vsepartoolbar.png \
		QDarkStyleSheet/qdarkstyle/rc/close-pressed.png \
		QDarkStyleSheet/qdarkstyle/rc/Hmovetoolbar.png \
		QDarkStyleSheet/qdarkstyle/rc/up_arrow.png \
		QDarkStyleSheet/qdarkstyle/rc/left_arrow_disabled.png \
		QDarkStyleSheet/qdarkstyle/rc/close-hover.png \
		QDarkStyleSheet/qdarkstyle/rc/checkbox_unchecked.png \
		QDarkStyleSheet/qdarkstyle/rc/radio_unchecked_disabled.png \
		QDarkStyleSheet/qdarkstyle/rc/radio_checked.png \
		QDarkStyleSheet/qdarkstyle/rc/checkbox_checked_disabled.png \
		QDarkStyleSheet/qdarkstyle/rc/Hsepartoolbar.png \
		QDarkStyleSheet/qdarkstyle/rc/sizegrip.png \
		QDarkStyleSheet/qdarkstyle/rc/down_arrow.png \
		QDarkStyleSheet/qdarkstyle/rc/stylesheet-branch-more.png \
		QDarkStyleSheet/qdarkstyle/rc/radio_unchecked.png \
		QDarkStyleSheet/qdarkstyle/rc/branch_closed-on.png \
		QDarkStyleSheet/qdarkstyle/rc/checkbox_unchecked_disabled.png \
		QDarkStyleSheet/qdarkstyle/rc/branch_open.png \
		QDarkStyleSheet/qdarkstyle/rc/left_arrow.png \
		QDarkStyleSheet/qdarkstyle/rc/stylesheet-branch-end.png \
		QDarkStyleSheet/qdarkstyle/rc/undock.png \
		QDarkStyleSheet/qdarkstyle/rc/right_arrow.png \
		QDarkStyleSheet/qdarkstyle/rc/checkbox_indeterminate.png \
		QDarkStyleSheet/qdarkstyle/rc/checkbox_checked_focus.png \
		QDarkStyleSheet/qdarkstyle/rc/stylesheet-vline.png \
		QDarkStyleSheet/qdarkstyle/rc/radio_checked_focus.png \
		QDarkStyleSheet/qdarkstyle/rc/branch_closed.png \
		QDarkStyleSheet/qdarkstyle/rc/right_arrow_disabled.png \
		QDarkStyleSheet/qdarkstyle/rc/down_arrow_disabled.png \
		QDarkStyleSheet/qdarkstyle/rc/branch_open-on.png \
		QDarkStyleSheet/qdarkstyle/rc/radio_unchecked_focus.png \
		QDarkStyleSheet/qdarkstyle/rc/Vmovetoolbar.png \
		QDarkStyleSheet/qdarkstyle/rc/transparent.png \
		QDarkStyleSheet/qdarkstyle/rc/close.png \
		QDarkStyleSheet/qdarkstyle/rc/radio_checked_disabled.png \
		QDarkStyleSheet/qdarkstyle/rc/checkbox_checked.png \
		QDarkStyleSheet/qdarkstyle/rc/up_arrow_disabled.png \
		QDarkStyleSheet/qdarkstyle/rc/checkbox_indeterminate_focus.png \
		QDarkStyleSheet/qdarkstyle/rc/checkbox_unchecked_focus.png \
		QDarkStyleSheet/qdarkstyle/style.qss
	/usr/lib/x86_64-linux-gnu/qt5/bin/rcc -name style QDarkStyleSheet/qdarkstyle/style.qrc -o qrc_style.cpp

compiler_moc_header_make_all: moc/moc_glscene.cpp moc/moc_mainwindow.cpp moc/moc_settings.cpp moc/moc_springSettings.cpp moc/moc_tabInfo.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc/moc_glscene.cpp moc/moc_mainwindow.cpp moc/moc_settings.cpp moc/moc_springSettings.cpp moc/moc_tabInfo.cpp
moc/moc_glscene.cpp: include/glscene.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/george/projects/MPC-Masterclass.git -I/usr/local/include/bullet -I/home/george/projects/MPC-Masterclass.git/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtOpenGL -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/5 -I/usr/include/x86_64-linux-gnu/c++/5 -I/usr/include/c++/5/backward -I/usr/lib/gcc/x86_64-linux-gnu/5/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/glscene.h -o moc/moc_glscene.cpp

moc/moc_mainwindow.cpp: include/mainwindow.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/george/projects/MPC-Masterclass.git -I/usr/local/include/bullet -I/home/george/projects/MPC-Masterclass.git/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtOpenGL -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/5 -I/usr/include/x86_64-linux-gnu/c++/5 -I/usr/include/c++/5/backward -I/usr/lib/gcc/x86_64-linux-gnu/5/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/mainwindow.h -o moc/moc_mainwindow.cpp

moc/moc_settings.cpp: include/types.h \
		include/settings.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/george/projects/MPC-Masterclass.git -I/usr/local/include/bullet -I/home/george/projects/MPC-Masterclass.git/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtOpenGL -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/5 -I/usr/include/x86_64-linux-gnu/c++/5 -I/usr/include/c++/5/backward -I/usr/lib/gcc/x86_64-linux-gnu/5/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/settings.h -o moc/moc_settings.cpp

moc/moc_springSettings.cpp: include/settings.h \
		include/types.h \
		include/springSettings.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/george/projects/MPC-Masterclass.git -I/usr/local/include/bullet -I/home/george/projects/MPC-Masterclass.git/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtOpenGL -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/5 -I/usr/include/x86_64-linux-gnu/c++/5 -I/usr/include/c++/5/backward -I/usr/lib/gcc/x86_64-linux-gnu/5/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/springSettings.h -o moc/moc_springSettings.cpp

moc/moc_tabInfo.cpp: include/types.h \
		include/tabInfo.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/george/projects/MPC-Masterclass.git -I/usr/local/include/bullet -I/home/george/projects/MPC-Masterclass.git/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtOpenGL -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/5 -I/usr/include/x86_64-linux-gnu/c++/5 -I/usr/include/c++/5/backward -I/usr/lib/gcc/x86_64-linux-gnu/5/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/tabInfo.h -o moc/moc_tabInfo.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: include/ui_mainwindow.h include/ui_springSettings.h include/ui_tabInfo.h
compiler_uic_clean:
	-$(DEL_FILE) include/ui_mainwindow.h include/ui_springSettings.h include/ui_tabInfo.h
include/ui_mainwindow.h: forms/mainwindow.ui \
		include/glscene.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/uic forms/mainwindow.ui -o include/ui_mainwindow.h

include/ui_springSettings.h: forms/springSettings.ui
	/usr/lib/x86_64-linux-gnu/qt5/bin/uic forms/springSettings.ui -o include/ui_springSettings.h

include/ui_tabInfo.h: forms/tabInfo.ui \
		include/springSettings.h \
		include/settings.h \
		include/types.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/uic forms/tabInfo.ui -o include/ui_tabInfo.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_rcc_clean compiler_moc_header_clean compiler_uic_clean 

####### Compile

obj/floorPlane.o: src/floorPlane.cpp include/floorPlane.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/floorPlane.o src/floorPlane.cpp

obj/glscene.o: src/glscene.cpp include/glscene.h \
		include/modelController.h \
		include/model.h \
		include/physicsBody.h \
		include/types.h \
		include/physicsWorld.h \
		include/floorPlane.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/glscene.o src/glscene.cpp

obj/line.o: src/line.cpp include/line.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/line.o src/line.cpp

obj/main.o: src/main.cpp include/mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/main.o src/main.cpp

obj/mainwindow.o: src/mainwindow.cpp include/mainwindow.h \
		include/ui_mainwindow.h \
		include/glscene.h \
		include/tabInfo.h \
		include/types.h \
		include/modelController.h \
		include/model.h \
		include/physicsBody.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/mainwindow.o src/mainwindow.cpp

obj/mesh.o: src/mesh.cpp include/mesh.h \
		include/types.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/mesh.o src/mesh.cpp

obj/model.o: src/model.cpp include/model.h \
		include/physicsBody.h \
		include/types.h \
		include/mesh.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/model.o src/model.cpp

obj/modelController.o: src/modelController.cpp include/modelController.h \
		include/model.h \
		include/physicsBody.h \
		include/types.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/modelController.o src/modelController.cpp

obj/openVDBTools.o: src/openVDBTools.cpp include/openVDBTools.h \
		include/types.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/openVDBTools.o src/openVDBTools.cpp

obj/physicsBody.o: src/physicsBody.cpp include/physicsBody.h \
		include/types.h \
		include/physicsWorld.h \
		include/sphere.h \
		include/line.h \
		include/openVDBTools.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/physicsBody.o src/physicsBody.cpp

obj/physicsWorld.o: src/physicsWorld.cpp include/physicsWorld.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/physicsWorld.o src/physicsWorld.cpp

obj/settings.o: src/settings.cpp include/settings.h \
		include/types.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/settings.o src/settings.cpp

obj/sphere.o: src/sphere.cpp include/sphere.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/sphere.o src/sphere.cpp

obj/springSettings.o: src/springSettings.cpp include/springSettings.h \
		include/settings.h \
		include/types.h \
		include/ui_springSettings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/springSettings.o src/springSettings.cpp

obj/tabInfo.o: src/tabInfo.cpp include/tabInfo.h \
		include/types.h \
		include/model.h \
		include/physicsBody.h \
		include/ui_tabInfo.h \
		include/springSettings.h \
		include/settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/tabInfo.o src/tabInfo.cpp

obj/qrc_shaders.o: qrc_shaders.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/qrc_shaders.o qrc_shaders.cpp

obj/qrc_style.o: qrc_style.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/qrc_style.o qrc_style.cpp

obj/moc_glscene.o: moc/moc_glscene.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_glscene.o moc/moc_glscene.cpp

obj/moc_mainwindow.o: moc/moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_mainwindow.o moc/moc_mainwindow.cpp

obj/moc_settings.o: moc/moc_settings.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_settings.o moc/moc_settings.cpp

obj/moc_springSettings.o: moc/moc_springSettings.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_springSettings.o moc/moc_springSettings.cpp

obj/moc_tabInfo.o: moc/moc_tabInfo.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_tabInfo.o moc/moc_tabInfo.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

