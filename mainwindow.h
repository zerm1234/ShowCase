#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include "framewindow.h"
#include "QtAwesome.h"
#include "controlboard.h"
#include <thread>
#include <mutex>

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

private:
    void createActions();
    void createStatusBar();
    void createDockWindows();

    static void ReadFrame(cv::VideoCapture* pcapture);
    static void ShowFrame(FrameWindow* frameWindow);

    QListWidget *customerList;
    QListWidget *paragraphsList;

    // QtAwesome
    QtAwesome* awesome;

    // Dock Windows
    FrameWindow* enhencedFrameBorad;
    FrameWindow* superResolutionFrameBorad;

    ControlBoard* controlBoard;

    // Center Window
    FrameWindow* centerFrameBoard;

    // Save Video file full path
    QString VideoFilePath;

    // Video Capture
    cv::VideoCapture capture;

    // Read frame thread
    std::thread* pReadFrameThread;
    std::thread* pShowFrameThread;

    QMenu *viewMenu;
};

#endif
