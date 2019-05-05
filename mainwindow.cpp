#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionopen_triggered()
{
  QString fileName = QFileDialog::getOpenFileName(this,"open the file");
  QFile file(fileName);
  currentFile = fileName;
  if(!file.open(QIODevice::ReadOnly | QFile::Text))
  {
      QMessageBox::warning(this,"warning","can not open file"+file.errorString());
  }
  setWindowTitle(fileName);
  QTextStream in(&file);
  QString text = in.readAll();
  ui->textEdit->setText(text);
  file.close();
}

void MainWindow::on_actionnew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionsave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"save the file");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,"warning","can not save file"+file.errorString());
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out <<text;
    file.close();
}

void MainWindow::on_actionedit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actioncopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionpaste_triggered()
{
     ui->textEdit->paste();
}

void MainWindow::on_actionundo_triggered()
{
      ui->textEdit->undo();
}

void MainWindow::on_actionredo_triggered()
{
    ui->textEdit->redo();
}
