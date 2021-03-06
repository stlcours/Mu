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
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef KNMUSICLIBRARYEMPTYHINT_H
#define KNMUSICLIBRARYEMPTYHINT_H

#include "kndropproxycontainer.h"

class QLabel;
class KNGlassButton;
/*!
 * \brief The KNMusicLibraryEmptyHint class provide a widget to show the empty
 * hint text of the library tabs. The widget will also be responsed for
 * activating the adding file dialog to library dialog.
 */
class KNMusicLibraryEmptyHint : public KNDropProxyContainer
{
    Q_OBJECT
public:
    /*!
     * \brief Construct a KNMusicLibraryEmptyHint widget.
     * \param parent The parent widget.
     */
    explicit KNMusicLibraryEmptyHint(QWidget *parent = 0);

signals:
    /*!
     * \brief When the add to library button is clicked, this signal will be
     * emitted.
     */
    void requireAddToLibrary();

public slots:

private slots:
    void retranslate();

private:
    inline KNGlassButton *generateButton(const QString &iconPath);
    QLabel *m_hintText;
    KNGlassButton *m_addMusic, *m_scanForMusic, *m_importLibrary;
};

#endif // KNMUSICLIBRARYEMPTYHINT_H
