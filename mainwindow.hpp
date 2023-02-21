#include <QMainWindow>
#include <DListView>
#include <DLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QComboBox>


DWIDGET_USE_NAMESPACE

class MainWindow : public QMainWindow {

public:
    MainWindow(QWidget *parent = nullptr);

    void initializeModel();
    void addPlainItem(const QString &name);

private:
    QWidget *m_centralWidget;
    QGroupBox *m_listViewTestGroup;
    QGroupBox *m_labelTestGroup;
    DListView *m_listView;
    DLabel *m_label;
    QHBoxLayout *m_contentLayout;
    QVBoxLayout *m_listViewLayout;
    QVBoxLayout *m_labelLayout;
    QStandardItemModel *m_model;
    QLabel *m_listViewHint;
    QComboBox *m_listViewSelector;
    QLabel *m_labelHint;
    QComboBox *m_labelSelector;
};
