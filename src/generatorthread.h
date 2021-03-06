/***************************************************************************
*   Copyright (C) 2011 by Matteo Agostinelli                              *
*   agostinelli@gmail.com                                                 *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
***************************************************************************/

#ifndef GENERATORTHREAD_H
#define GENERATORTHREAD_H

#include "format.h"

#include <QThread>
#include <QImage>

class RenderThread;
namespace Cirkuit
{
class Generator;
class Backend;
}

namespace KTextEditor
{
    class Document;
}

class GeneratorThread : public QThread
{
    Q_OBJECT
public:
    GeneratorThread(QObject* parent = 0);
    ~GeneratorThread();
    
    QString previewUrl() const;
    
protected:
    Cirkuit::Format m_input, m_output;
    
    void run();
    
public slots:
    void generate(const Cirkuit::Format& in, const Cirkuit::Format& out, Cirkuit::Backend* backend = 0, KTextEditor::Document* doc = 0, bool saveToFile = false, double scaleFactor=1.0);
    void setScaleFactor(double scaleFactor);
    
signals:
    void previewReady(const QImage);
    void previewUrl(const QString);
    void fileReady(const QString);
    
    void error(const QString& appname, const QString& msg);
    void output(const QString& appname, const QString& msg);
    void fail();
    void success();
    
    void backendChanged(QString);
    
private:
    KTextEditor::Document* m_doc;
    Cirkuit::Backend* m_backend;
    RenderThread* m_render;
    bool m_saveToFile;
    double m_scaleFactor;
    
    QString m_previewUrl;
};

#endif // GENERATORTHREAD_H
