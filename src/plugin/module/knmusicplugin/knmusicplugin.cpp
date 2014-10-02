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
#include <QBoxLayout>

//Music Global.
#include "knmusicglobal.h"

//Ports
#include "knmusicbackend.h"

#include "kncategorytabwidget.h"
#include "knmusicplugin.h"

#include <QDebug>

KNMusicPlugin::KNMusicPlugin(QObject *parent) :
    KNAbstractMusicPlugin(parent)
{
    //Initial the music global.
    m_musicGlobal=KNMusicGlobal::instance();
    //Initial infrastructure.
    initialInfrastructure();

    //Load plugins.
//    loadBackend();

    //Do the translation at the last.
    retranslate();
}

QString KNMusicPlugin::caption()
{
    return m_caption;
}

QPixmap KNMusicPlugin::icon()
{
    return QPixmap(":/plugin/music/common/icon.png");
}

QWidget *KNMusicPlugin::centralWidget()
{
    return m_centralWidget;
}

QWidget *KNMusicPlugin::headerWidget()
{
    return m_headerWidget;
}

void KNMusicPlugin::loadBackend(KNMusicBackend *plugin)
{
    ;
}

void KNMusicPlugin::retranslate()
{
    m_caption=tr("Music");
}

void KNMusicPlugin::addMusicCategory(const QPixmap &icon,
                                     const QString &caption,
                                     QWidget *widget)
{
    m_centralWidget->addTab(icon, caption, widget);
}

void KNMusicPlugin::addLeftHeaderWidget(QWidget *widget,
                                        int stretch,
                                        Qt::Alignment alignment)
{
    m_headerLeftLayout->addWidget(widget, stretch, alignment);
}

void KNMusicPlugin::addRightHeaderWidget(QWidget *widget,
                                         int stretch,
                                         Qt::Alignment alignment)
{
    m_headerRightLayout->addWidget(widget, stretch, alignment);
}

void KNMusicPlugin::initialInfrastructure()
{
    //Initial central widget.
    m_centralWidget=new KNCategoryTabWidget;

    //Initial header widget.
    m_headerWidget=new QWidget;
    //Set header properties.
    m_headerWidget->setContentsMargins(0,0,0,0);
    //Set header layout.
    QBoxLayout *headerLayout=new QBoxLayout(QBoxLayout::LeftToRight,
                                            m_headerWidget);
    headerLayout->setContentsMargins(0,0,0,0);
    headerLayout->setSpacing(0);
    m_headerWidget->setLayout(headerLayout);
    //Initial left layout.
    m_headerLeftLayout=new QBoxLayout(QBoxLayout::LeftToRight,
                                      headerLayout->widget());
    m_headerLeftLayout->setContentsMargins(0,0,0,0);
    m_headerLeftLayout->setSpacing(0);
    headerLayout->addLayout(m_headerLeftLayout);
    //Initial right layout.
    m_headerRightLayout=new QBoxLayout(QBoxLayout::RightToLeft,
                                       headerLayout->widget());
    m_headerRightLayout->setContentsMargins(0,0,0,0);
    m_headerRightLayout->setSpacing(0);
    headerLayout->addLayout(m_headerRightLayout);
}
