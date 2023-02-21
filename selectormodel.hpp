#ifndef SELECTORMODEL_H
#define SELECTORMODEL_H

#include <QAbstractListModel>
#include <DToolTip>

DWIDGET_USE_NAMESPACE
class SelectorModel : public QAbstractListModel
{
    enum DataRole {
        IdRole = Qt::UserRole + 1
    };

public:
    explicit SelectorModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    void populate();

private:
    QMap<DToolTip::ToolTipShowMode, QString> m_selectorValues;
};

#endif // SELECTORMODEL_H
