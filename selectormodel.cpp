#include "selectormodel.hpp"

SelectorModel::SelectorModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

int SelectorModel::rowCount(const QModelIndex &parent) const
{
    return m_selectorValues.size();
}

int SelectorModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant SelectorModel::data(const QModelIndex &index, int role) const
{
    auto row = index.row();
    auto keys = m_selectorValues.keys();
    switch (role) {
    case Qt::EditRole:
        return m_selectorValues[keys.at(row)];
    case DataRole::IdRole:
        return keys.at(row);
    default:
        return QVariant();
    }
}

void SelectorModel::populate()
{
    beginResetModel();
    m_selectorValues.clear();
    m_selectorValues.insert(DToolTip::Default, "默认");
    m_selectorValues.insert(DToolTip::AlwaysShow, "始终显示ToolTip");
    m_selectorValues.insert(DToolTip::ShowWhenElided, "仅在出现省略时显示ToolTip");
    m_selectorValues.insert(DToolTip::NotShow, "始终不显示ToolTip");
    endResetModel();
}
