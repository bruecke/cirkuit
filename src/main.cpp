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

#include <KAboutData>
#include <KLocalizedString>

#include <QApplication>
#include <QCommandLineParser>
#include <QDir>

#include "cirkuitconfig.h"
#include "mainwindow.h"

int main (int argc, char *argv[])
{
    QApplication app(argc, argv);

    KLocalizedString::setApplicationDomain("cirkuit"); // set translation catalogue name for KAboutData

    KAboutData aboutData(QStringLiteral("cirkuit"),
                         i18n("Cirkuit"),
                         QStringLiteral(VERSION),
                         i18n("An application to generate publication-ready figures. "
                              "It is a KDE frontend for Circuit Macros by J. D. Aplevich, TikZ and Gnuplot."),
                         KAboutLicense::GPL,
                         i18n("(c) 2011 Matteo Agostinelli"),
                         i18n("Visit the <a href=http://www.ece.uwaterloo.ca/~aplevich/Circuit_macros>Circuit Macros</a> "
                              "and <a href=http://www.texample.net/tikz>TikZ</a> websites for further information."),
                         QStringLiteral("http://projects.kde.org/cirkuit"));

    aboutData.addAuthor(i18n("Matteo Agostinelli"),
                        i18n("Maintainer"),
                        QStringLiteral("matteo@agostinelli.me"),
                        QStringLiteral("http://agostinelli.me"));

    KAboutData::setApplicationData(aboutData);

    QCommandLineParser parser;
    parser.addPositionalArgument(QStringLiteral("+[File]"), i18n("Document to open"));
    aboutData.setupCommandLine(&parser); // add help, version, license, author option and set all infos about cirkuit

    parser.process(app);
    aboutData.processCommandLine(&parser); // evaluate author and license option

    MainWindow* window = new MainWindow();

    const QStringList args = parser.positionalArguments();
    if (args.count()) {
        // allow relative files (even non existing)
        QUrl url = QUrl::fromUserInput(args.at(0), QDir::currentPath(), QUrl::AssumeLocalFile);
        window->loadFile(url);
    }

    window->show();

    return app.exec();
}
