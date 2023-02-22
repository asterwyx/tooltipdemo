#include "mainwindow.h"
#include <QDebug>
#include <DToolTip>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_centralWidget(new QWidget(this)),
      m_listViewTestGroup(new QGroupBox(this)),
      m_labelTestGroup(new QGroupBox(this)),
      m_listView(new DListView(m_listViewTestGroup)),
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
    static constexpr int InitialIndex = 2;
    static constexpr DToolTip::ToolTipShowMode InitialMode = DToolTip::ShowWhenElided;
    // Setup ListView test
    m_listViewTestGroup->setLayout(m_listViewLayout);
    // Select DListView ToolTip show mode
    {
        QHBoxLayout *selectorLayout = new QHBoxLayout;
        m_listViewHint->setText("选择DListView的ToolTip显示方式:");
        selectorLayout->addWidget(m_listViewHint);
        m_listViewSelector->addItem("默认", DToolTip::Default);
        m_listViewSelector->addItem("始终显示", DToolTip::AlwaysShow);
        m_listViewSelector->addItem("折叠时显示", DToolTip::ShowWhenElided);
        m_listViewSelector->addItem("始终不显示", DToolTip::NotShow);
        m_listViewSelector->setCurrentIndex(InitialIndex); // ShowWhenElided
        selectorLayout->addWidget(m_listViewSelector);
        m_listViewLayout->addLayout(selectorLayout);
    }
    // Connect signal
    connect(m_listViewSelector, SIGNAL(currentIndexChanged(int)), this, SLOT(onIndexChanged(int)));
    // Setup ListView
    m_listViewLayout->addWidget(m_listView);
    auto addPlainItem = [&](const QString &item) {
        DStandardItem *pItem = new DStandardItem(item);
        pItem->setEditable(false);
        m_model->appendRow(pItem);
    };
    addPlainItem("短项");
    addPlainItem("长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长项");
    addPlainItem("This is a very long item composed by a lot of short English words to test wrap");
    addPlainItem("Loooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooong word item");
    addPlainItem("带有换行符号的项\n第二句只是填充");
    m_listView->setItemSpacing(2);
    m_listView->setFixedWidth(WidgetWidth);
    m_listView->setModel(m_model);
    m_listView->setUniformItemSizes(true);
    m_listView->setWordWrap(false);
    m_listView->setTextElideMode(Qt::ElideRight);
    DToolTip::setToolTipShowMode(m_listView, InitialMode);
    // Setup DLabel test
    m_labelTestGroup->setLayout(m_labelLayout);
    // Select DLabel ToolTip show mode
    {
        QHBoxLayout *selectorLayout = new QHBoxLayout;
        m_labelHint->setText("选择DLabel的ToolTip显示方式:");
        selectorLayout->addWidget(m_labelHint);
        m_labelSelector->addItem("默认", DToolTip::Default);
        m_labelSelector->addItem("始终显示", DToolTip::AlwaysShow);
        m_labelSelector->addItem("折叠时显示", DToolTip::ShowWhenElided);
        m_labelSelector->addItem("始终不显示", DToolTip::NotShow);
        m_labelSelector->setCurrentIndex(InitialIndex); // ShowWhenElided
        selectorLayout->addWidget(m_labelSelector);
        m_labelLayout->addLayout(selectorLayout);
    }
    // Connect signal
    connect(m_labelSelector, SIGNAL(currentIndexChanged(int)), this, SLOT(onIndexChanged(int)));
    auto setupLabel = [&] (const QString &text) {
        DLabel *testLabel = new DLabel(this);
        testLabel->setText(text);
        testLabel->setFixedWidth(WidgetWidth);
        testLabel->setElideMode(Qt::ElideRight);
        m_labelLayout->addWidget(testLabel);
        DToolTip::setToolTipShowMode(testLabel, InitialMode);
        m_labels.append(testLabel);
    };

    setupLabel("这是一个非常长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长的测试Label");
    setupLabel("短Label");
    setupLabel("带有换行符号的测试Label\n第二个句子仅仅是填充");
    setupLabel("This is a very long label composed by a lot of short English words to test wrap");
    setupLabel("Loooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooong word label");
}

void MainWindow::onIndexChanged(int index)
{
    QComboBox *selector = qobject_cast<QComboBox *>(sender());
    if (selector)
    {
        DToolTip::ToolTipShowMode mode = qvariant_cast<DToolTip::ToolTipShowMode>(selector->itemData(index));
        if (selector == m_listViewSelector) {
            DToolTip::setToolTipShowMode(m_listView, mode);
        } else if (selector == m_labelSelector) {
            for(auto &label : m_labels)
            {
                DToolTip::setToolTipShowMode(label, mode);
            }
        } else {
            Q_UNUSED(index)
        }
    }
}
