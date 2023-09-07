#ifndef FILEMANGER_MAINWINDOW_H
#define FILEMANGER_MAINWINDOW_H

#include "PasswordWindow.h"
#include "FileTreeWidget.h"
#include "TextFilePreviewWidget.h"
#include "ImageFilePreviewWidget.h"
#include "VideoFilePreviewWidget.h"
#include "AudioFilePreview.h"
#include "dialogs/NewFileDialog.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QSplitter>

enum RIGHT_WIDGET_TYPE {
    TEXT = 1,
    IMAGE = 2,
    VIDEO = 3,
    AUDIO = 4,
};

class MainWindow : public QMainWindow {
Q_OBJECT;
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void initLayout();

    void initConnections();

    void initWidgets();

    void initMenus();

    void initActions();

    void setRightWidget(QWidget* new_right_widget, RIGHT_WIDGET_TYPE type, const QString& file_path, const QString& file_name);

    PasswordWindow* pw;

    QGridLayout *layout;
    QWidget *centralWidget;

    FileTreeWidget *left;
//    TextPreviewWidget* right;
//    VideoFilePreviewWidget *right;
    QWidget *right;

    QSplitter *splitter;

    QMenu *fileMenu;
    QAction *createFolder;
    QAction *createFile;

public slots:
    void initAll();

private slots:

    void changeRightWidget();

    void newFile();

    void newFolder();
};


namespace extension {
    const QVector<QString> TEXT_EXTENSIONS = {"txt", "py", "cpp", "c", "ini", "md"};
    const QVector<QString> AUDIO_EXTENSIONS = {"mp3", "wma", "wav"};
    const QVector<QString> VIDEO_EXTENSIONS = {"mp4", "mov"};
    const QVector<QString> IMAGE_EXTENSIONS = {"png", "jpg", "jpeg", "bmp", "svg", "webp"};

    inline bool isTextFile(const QString &file_extension);

    inline bool isAudioFile(const QString &file_extension);

    inline bool isVideoFile(const QString &file_extension);

    inline bool isImageFile(const QString &file_extension);
};

#endif //FILEMANGER_MAINWINDOW_H
