#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
    tr("Open Image"), ".",
    tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
    image= cv::imread(fileName.toStdString());
    cv::namedWindow("Original Image");
    cv::imshow("Original Image", image);
}

void MainWindow::on_pushButton_2_clicked()
{
    if(image.empty())
    {
        QMessageBox::about(this,tr("Error"),tr("No image selected"));
        return;
    }
    cv::flip(image,image,1);
    cv::namedWindow("Output Image",CV_WINDOW_AUTOSIZE);
    QString dirName=QFileDialog::getExistingDirectory(this,tr("Select Output Directory"));
    cv::imwrite(dirName.toStdString()+"/Flipped.png",image);
    cv::imshow("Output Image", image);
}
