#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dialog.h"
#include <QListView>
#include <QProgressBar>
#include <QMainWindow>
#include <QDir>
#include "olistview.h"
#include "lineidentifire.h"
#include "linereader.h"
#include "preprocessor.h"
#include "scalevaraibles.h"
#include <qstringlistmodel.h>
#include <qmessagebox.h>
#include<manual.h>
#include "progressWidget/progresswidget.h"
#include "charDebugWidget/chardebug.h"
#include <QMainWindow>
typedef QList<QImage> QImageList;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void readMemberVariable();
    void initMemWidget();
    void connectWidget();
    void showBanglaText();
    void setImage();
    void updateOpenListView();
    void loadBanglaText(QString resultTextFile);
    bool mainImageToBinImage(QStringList &list);
    void convertAndSave(QStringList m_openFileList,QImageList m_binImageList,int startIdxList,int endIdxList);
    bool saveBinBrille(QStringList binData);
    bool showFrontPage();
private slots:
    void on_environmenVariableAction_triggered();
    void on_DebugAction_triggered();
    void onCnvrtClick();
    void onCnvrtAllClick();
    void removeForOpenView();
    void removeForResultView();
    void ontextBtnClicked();
    void onimageBtnClicked();
    void onOpenListViewItemClicked();
    void onResultListViewItemClicked(int index=-1);
    void on_openFiles();
    void on_addFiles();
    void on_saveFiles();
    void on_saveBinFiles();
    void on_savePDFFiles();
    void on_Print();
    void about();
    void on_home();

protected:
 void closeEvent(QCloseEvent *event);
 bool event(QEvent *event) override;

private:
    Ui::MainWindow *ui;
    bool shouldProceed();
    void createActions();

public:

    // imageLabel
    //ImageLabel *imageLabel;
    // scrollArea
    //QScrollArea *scrollArea;
    // input position
    QPoint inputPt;
    // input box
    //QLineEdit *inputBox;
    // QListOpenListView
    // OListView *openListView,*resultListView;
    progressWidget progressWdgt;
    // QPushButton
    //QPushButton *convrt,*convrtAll;
    CharDebug w;
    // QLabel
    //QLabel *brailleTextLabel,*brailleImageLabel;
    // ------memberVariable-----------
    QStringList m_openFileList,m_resultFileList,nameList;
    QList<QString> _banglaText,_binText;
    QImage m_imageToShow;
    QImageList m_resultImagesList,m_binImageList;
    QString m_textToShow;
    //QPoint m_errDot,m_errCh,m_distBetDot,m_distBetCh;
    //int m_minDotWidth,m_maxDotWidth;
    QDir m_currentImageDir;
    bool isSaving = false,binaryFiles=false;
    //------------------model-------------------------
    QStringListModel *resultModel = nullptr;
    QMessageBox msgBox;
    // --------------action for context menu------------
    QAction *actionselectAllForOpen,*actionselectAllForResult,*actionRemoveFileForResult,*actionSaveFiles;
    QAction *exportAsPdfForResult,*actionPrint;
    QAction *actionHome;
    // ----------- QMenu -------------------
    QMenu *menu;
    QAction *actionSaveAsText,*actionSaveAsPdf;
    // image processor
    LineIdentifire lineIdentifire;
    Linereader lineReader;
    PreProcessor preProcessor;
    ScaleVaraibles scaleVar;
    // ---- others ----------
    Manual abt;
};
#endif // MAINWINDOW_H
