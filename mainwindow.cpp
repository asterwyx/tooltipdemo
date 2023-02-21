#include "mainwindow.hpp"
#include <QDebug>
#include <DToolTip>
#include <QAbstractListModel>
#include "selectormodel.hpp"
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
      m_model(new QStandardItemModel(this)),
      m_listViewHint(new QLabel(m_listViewTestGroup)),
      m_listViewSelector(new QComboBox(m_listViewTestGroup)),
      m_labelHint(new QLabel(m_labelTestGroup)),
      m_labelSelector(new QComboBox(m_labelTestGroup))
{
    setCentralWidget(m_centralWidget);
    m_contentLayout->addWidget(m_listViewTestGroup, 1);
    m_contentLayout->addWidget(m_labelTestGroup, 1);
    m_centralWidget->setLayout(m_contentLayout);

    // Setup ListView test
    m_listViewTestGroup->setLayout(m_listViewLayout);
    // Select DListView ToolTip show mode
    {
        QHBoxLayout *selectorLayout = new QHBoxLayout;
        m_listViewHint->setText("选择DListView的ToolTip显示方式:");
        selectorLayout->addWidget(m_listViewHint);
        m_listViewSelector->setModel(new SelectorModel);
        selectorLayout->addWidget(m_listViewSelector);
        m_listViewLayout->addLayout(selectorLayout);
    }
    // Setup ListView
    m_listViewLayout->addWidget(m_listView);
    initializeModel();
    m_listView->setItemSpacing(2);
    m_listView->setModel(m_model);
    m_listView->setUniformItemSizes(true);
    m_listView->setWordWrap(false);
    m_listView->setTextElideMode(Qt::ElideRight);
    DToolTip::setToolTipShowMode(m_listView, DToolTip::ShowWhenElided);

    // Setup DLabel test
    m_labelTestGroup->setLayout(m_labelLayout);

    // Select DLabel ToolTip show mode
    {
        QHBoxLayout *selectorLayout = new QHBoxLayout;
        m_labelHint->setText("选择DLabel的ToolTip显示方式:");
        selectorLayout->addWidget(m_labelHint);
        QListView *view = new QListView;
        SelectorModel *selector = new SelectorModel;
        view->setModel(selector);
        m_labelSelector->setModel(selector);
        m_labelSelector->setView(view);
        selectorLayout->addWidget(m_labelSelector);
        m_labelLayout->addLayout(selectorLayout);
    }
    m_labelLayout->addWidget(m_label);
    m_label->setText("这是一个非常长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长的测试Label");
    m_label->setElideMode(Qt::ElideRight);
    DToolTip::setToolTipShowMode(m_label, DToolTip::ShowWhenElided);
}

void MainWindow::addPlainItem(const QString &name)
{
    DStandardItem *pItem = new DStandardItem(name);
    pItem->setEditable(false);
    m_model->appendRow(pItem);
}

void MainWindow::initializeModel()
{
    addPlainItem("This is first item.");
    addPlainItem("Short.");
    addPlainItem("Looooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooong item within one word");
    addPlainItem("This is a very long item, but it is composed by a lot of short words.");
    addPlainItem("With newline.\nThe second sentence is just dummy.");
}
