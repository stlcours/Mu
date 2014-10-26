/*
 * Copyright (C) Kreogist Dev Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#ifndef KNMUSICSOLOMENU_H
#define KNMUSICSOLOMENU_H

#include "knmusicsolomenubase.h"

class KNMusicSoloMenu : public KNMusicSoloMenuBase
{
    Q_OBJECT
public:
    explicit KNMusicSoloMenu(QWidget *parent = 0);
    void setProxyModel(KNMusicProxyModel *model);
    void setCurrentIndex(const QModelIndex &itemIndex);

signals:

public slots:
    void retranslate();

private slots:
    void onActionOpenCurrentFile();
    void onActionShowInGraphicsShell();
    void onActionCopyFilePath();
    void onActionCopyItemText();

private:
    enum SoloMenuActions
    {
        PlayCurrent,
        Open,
        GetInfo,
        ShowInGraphicShell,
        CopyFilePath,
        CopyItemText,
        Delete,
        SoloMenuActionCount
    };
    void createActions();
    void updateActionsCaption();
    QString m_actionTitles[SoloMenuActionCount], m_itemText, m_filePath;
    QAction *m_actions[SoloMenuActionCount];
    KNMusicProxyModel *m_proxyModel;
};

#endif // KNMUSICSOLOMENU_H