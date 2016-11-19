#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initStyleSheet();
    void initConnections();

    std::string browseFiles();
    void loadObject();

    void addObjectSetting(std::string fileName);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
