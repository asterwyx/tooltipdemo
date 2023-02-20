#include <DMainWindow>

#include <DListView>
#include <DLabel>

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow {

public:
    MainWindow(QWidget *parent = nullptr);

private:
    DListView *m_listView;
    DLabel *m_label;
};
