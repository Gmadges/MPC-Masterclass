#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>

class GLWidget : public QOpenGLWidget
{
public:
    GLWidget(QWidget *parent);
    ~GLWidget();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};

#endif // GLWidget_H