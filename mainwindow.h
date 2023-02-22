#include <QMainWindow>
#include <DListView>
#include <DLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QComboBox>


DWIDGET_USE_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    static constexpr quint32 WidgetWidth = 400;
    MainWindow(QWidget *parent = nullptr);

public Q_SLOTS:
    void onIndexChanged(int index);

private:
    QWidget *m_centralWidget;
    QGroupBox *m_listViewTestGroup;
    QGroupBox *m_labelTestGroup;
    DListView *m_listView;
    QHBoxLayout *m_contentLayout;
    QVBoxLayout *m_listViewLayout;
    QVBoxLayout *m_labelLayout;
    QStandardItemModel *m_model;
    QLabel *m_listViewHint;
    QComboBox *m_listViewSelector;
    QLabel *m_labelHint;
    QComboBox *m_labelSelector;
    QList<DLabel *> m_labels;
};
