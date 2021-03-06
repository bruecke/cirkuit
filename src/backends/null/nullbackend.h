/*
    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA  02110-1301, USA.

    ---
    Copyright (C) 2009 Alexander Rieder <alexanderrieder@gmail.com>
    Copyright (C) 2011 Matteo Agostinelli <agostinelli@gmail.com>
 */

#ifndef _NULLBACKEND_H
#define _NULLBACKEND_H

#include "backend.h"

#include <QList>
#include <QVariant>

namespace Cirkuit 
{
    class DocumentSettings;
    class Generator;
}

class NullBackend : public Cirkuit::Backend
{
  Q_OBJECT
  public:
    explicit NullBackend( QObject* parent = 0, const QList<QVariant> args = QList<QVariant>());
    ~NullBackend();
    
    virtual bool checkRequirements() const;
    
    Cirkuit::DocumentSettings* documentSettings() const;
    Cirkuit::Generator* generator() const;

    QString id() const;
};


#endif /* _NULLBACKEND_H */
