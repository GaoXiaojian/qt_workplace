#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 重置窗口大小
    resize(600,400);

    // 1、菜单栏（仅允许有1个）
    // 创建菜单栏
    QMenuBar *menuBar = new QMenuBar(this);
    // 并添加到窗口中
    setMenuBar(menuBar);

    // 添加菜单
    QMenu* fileMenu = new QMenu("文件");
    menuBar->addMenu(fileMenu);
    QMenu* editMenu = new QMenu("编辑");
    menuBar->addMenu(editMenu);

    // 创建菜单项
    QAction* newAction = fileMenu->addAction("新建");
    QAction* openAction = fileMenu->addAction("打开");
    fileMenu->addSeparator(); //添加分隔线
    QAction* closeAction = fileMenu->addAction("关闭");


    // 2、工具栏（允许有多个）
    QToolBar* toolBar = new QToolBar(this);
    // 并添加到窗口中
    addToolBar(Qt::TopToolBarArea, toolBar); // 把初始停靠在上边
    // 设置只允许上面和左侧停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::TopToolBarArea);
    // 设置不允许浮动到中间
    toolBar->setFloatable(false);
    //  设置是否可以移动
    toolBar->setMovable(true);
    // 设置内容
    toolBar->addAction(newAction);
    toolBar->addAction(openAction);
    toolBar->addSeparator();  // 分隔符
    toolBar->addAction(closeAction);

    // 3、状态栏 （最多一个）
    // 新建
    QStatusBar * statusBar = new QStatusBar(this);
    // 并添加到窗口中
    setStatusBar(statusBar);
    // 放置标签
    QLabel* label1 = new QLabel("提示1", this);
    statusBar->addWidget(label1); // 从左侧开始放置

    QLabel* label2 = new QLabel("提示2", this);
    statusBar->addPermanentWidget(label2); // 从右侧开始放置

    // 4、铆接部件（浮动窗口） 可以有多个
    QDockWidget* dockWidget = new QDockWidget("浮动", this);
    // 并添加到窗口中
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget); // 设置默认停靠在中心部件下面
    // 设置只允许停靠上和下 区域
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);


    // 5、中心部件（只允许一个）
    QTextEdit* textEdit = new QTextEdit(this);
    // 并添加到窗口中
    setCentralWidget(textEdit);

}

MainWindow::~MainWindow()
{
}

