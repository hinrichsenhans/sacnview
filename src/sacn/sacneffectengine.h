// Copyright 2016 Tom Barthel-Steer
// http://www.tomsteer.net
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SACNEFFECTENGINE_H
#define SACNEFFECTENGINE_H

#include <QObject>
#include <QImage>
#include <QPixmap>
#include "sacnsender.h"

static const QStringList FX_MODE_DESCRIPTIONS = { "Manual",
        "Ramp",
        "Sinewave",
        "Chase",
        "Vertical Bars",
        "Horizontal Bars",
        "Text",
        "Date"};

class sACNEffectEngine : public QObject
{
    Q_OBJECT
public:
    enum FxMode {
        FxManual,
        FxRamp,
        FxSinewave,
        FxChase,
        FxVerticalBar,
        FxHorizontalBar,
        FxText,
        FxDate
    };


    enum DateStyle {
        dsUSA,
        dsEU
    };

    explicit sACNEffectEngine();
    virtual ~sACNEffectEngine();
    void setSender(sACNSentUniverse *sender);
    QString text() { return m_text;};
    sACNEffectEngine::FxMode mode() { return m_mode;};
    qreal rate() { return m_rate;};
signals:
    void setLevel(quint16 address, quint8 value);
    void setLevel(quint16 start, quint16 end, quint8 value);
    void fxLevelChange(int level);
    void textImageChanged(QPixmap pixmap);
public slots:
    void setMode(sACNEffectEngine::FxMode mode);

    void start();
    void pause();
    void clear();

    void setStartAddress(quint16 start);
    void setEndAddress(quint16 end);
    void setRange(quint16 start, quint16 end);

    void setText(QString text);

    void setDateStyle(sACNEffectEngine::DateStyle style);

    void setRate(qreal hz);

    void setManualLevel(int level);

private slots:
    void timerTick();
private:
    QThread *m_thread;
    sACNSentUniverse *m_sender;
    QTimer *m_timer;
    FxMode m_mode;
    DateStyle m_dateStyle;
    QString m_text;
    qreal m_rate;
    quint16 m_start;
    quint16 m_end;
    quint16 m_index;
    quint8 m_data;
    quint8 m_manualLevel;
    QImage m_renderedImage;
    quint8 *m_image;
    int m_imageWidth;

    // Render a single line of variable width text
    void renderText(QString text);
    // Render a two-line text, larger top smaller bottom (for date/time)
    void renderText(QString top, QString bottom);
    void renderText(QString text, int yStart, bool big);
};

Q_DECLARE_METATYPE(sACNEffectEngine::FxMode)

#endif // SACNEFFECTENGINE_H
