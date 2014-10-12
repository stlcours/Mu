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
#ifndef KNMUSICHEADERLYRICS_H
#define KNMUSICHEADERLYRICS_H

#include "knmusicheaderlyricsbase.h"

class QTimeLine;
class KNMusicLyricsManager;
class KNMusicHeaderLyrics : public KNMusicHeaderLyricsBase
{
    Q_OBJECT
public:
    explicit KNMusicHeaderLyrics(QWidget *parent = 0);
    ~KNMusicHeaderLyrics();
    void setHeaderPlayer(KNMusicHeaderPlayerBase *player);

signals:

public slots:
    void reset();
    void loadLyricsForMusic(const QString &filePath);
    void onActionPositionChange(const qint64 &position);

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void onActionLyricsMoved(const int &frame);

private:
    inline QSize lyricsSize(const QString &lyricsText)
    {
        return fontMetrics().size(Qt::TextExpandTabs,
                                  lyricsText);
    }
    int lyricsLineDuration(const int &index);

    void startMovingAnime(const int &durationOffset,
                          const int &yOffset);

    KNMusicLyricsManager *m_lyricsManager;
    QTimeLine *m_moveToCurrent;
    int m_currentLyricsLine=-1, m_lyricsLines=0, m_currentLineOffsetY=0,
        m_leftSpacing=15, m_animationDuration=200;
    QColor m_normalText=QColor(100,100,100),
           m_highlightColor=QColor(0xf7, 0xcf, 0x3d);
};

#endif // KNMUSICHEADERLYRICS_H