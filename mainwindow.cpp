#include "mainwindow.hpp"
#include <QDebug>
#include <DToolTip>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_centralWidget(new QWidget(this)),
      m_listViewTestGroup(new QGroupBox(this)),
      m_labelTestGroup(new QGroupBox(this)),
      m_listView(new DListView(m_listViewTestGroup)),
      m_label(new DLabel(m_labelTestGroup)),
      m_contentLayout(new QHBoxLayout),
      m_listViewLayout(new QVBoxLayout),
      m_labelLayout(new QVBoxLayout),
      m_model(new QStandardItemModel(this))
{
    setCentralWidget(m_centralWidget);
    m_contentLayout->addWidget(m_listViewTestGroup, 1);
    m_contentLayout->addWidget(m_labelTestGroup, 1);
    m_centralWidget->setLayout(m_contentLayout);
    m_listViewTestGroup->setLayout(m_listViewLayout);
    m_labelTestGroup->setLayout(m_labelLayout);
    m_listViewLayout->addWidget(m_listView);
    initializeModel();
    m_listView->setItemSpacing(2);
    m_listView->setModel(m_model);
    m_listView->setUniformItemSizes(true);
    m_listView->setWordWrap(false);
    m_listView->setTextElideMode(Qt::ElideNone);
    DToolTip::setToolTipShowMode(m_listView, DToolTip::AlwaysShow);
    m_labelLayout->addWidget(m_label);
}

void MainWindow::addPlainItem(const QString &name)
{
    auto pItem = new DStandardItem(name);
    pItem->setEditable(false);
    m_model->appendRow(pItem);
}

void MainWindow::initializeModel()
{
    addPlainItem("This is first item.");
    addPlainItem("Short.");
    addPlainItem("Looooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooong with one word");
    addPlainItem("This is a very long item, but it is composed by a lot of short words.");
    addPlainItem("With newline.\nThe second sentence is just dummy.");
}
