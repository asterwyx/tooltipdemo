#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent), m_listView(new DListView(this)), m_label(new DLabel(this)) {}
