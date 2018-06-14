#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include "framewindow.h"
#include "QtAwesome.h"

QT_BEGIN_NAMESPACE
class QAction;
class QListWidget;
class QMenu;
class QTextEdit;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QApplication* app);

private slots:
    void openVideoFile();
    void runProcess();
    void setting();
    void about();
    void insertCustomer(const QString &customer);
    void addParagraph(const QString &paragraph);

private:
    void createActions();
    void createStatusBar();
    void createDockWindows();

    QTextEdit *textEdit;
    QListWidget *customerList;
    QListWidget *paragraphsList;

    // QtAwesome
    QtAwesome* awesome;

    // Dock Windows
    FrameWindow* originalFrameBoard;
    FrameWindow* enhencedFrameBorad;

    // Center Window
    FrameWindow* centerFrameBoard;

    // Save Video file full path
    QString VideoFilePath;

    // Video Capture
    cv::VideoCapture capture;

    QMenu *viewMenu;
};

#endif
