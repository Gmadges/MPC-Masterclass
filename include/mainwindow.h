#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

class Model;

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

    void addObjectSetting(std::string fileName, std::shared_ptr<Model> pModel);

    void closeTab(int idx);
    void clearAll();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
