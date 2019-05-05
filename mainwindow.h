#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionopen_triggered();

    void on_actionnew_triggered();

    void on_actionsave_triggered();

    void on_actionedit_triggered();

    void on_actioncopy_triggered();

    void on_actionpaste_triggered();

    void on_actionundo_triggered();

    void on_actionredo_triggered();

private:
    Ui::MainWindow *ui;
   QString currentFile ="";

};

#endif // MAINWINDOW_H
