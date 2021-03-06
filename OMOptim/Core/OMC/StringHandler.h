/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Linkoping University,
 * Department of Computer and Information Science,
 * SE-58183 Linkoping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3
 * AND THIS OSMC PUBLIC LICENSE (OSMC-PL).
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES RECIPIENT'S
 * ACCEPTANCE OF THE OSMC PUBLIC LICENSE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from Linkoping University, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or
 * http://www.openmodelica.org, and in the OpenModelica distribution.
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS
 * OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 * Main Authors 2010: Syed Adeel Asghar, Sonia Tariq
 *
 */

#ifndef STRINGHANDLER_H
#define STRINGHANDLER_H

// QT Headers
#include <QtGlobal>
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#include <QtWidgets>
#else
#include <QtCore>
#include <QtGui>
#endif

class StringHandler
{
public:
    StringHandler();
    ~StringHandler();
    enum IconType {ICON, DIAGRAM, MODELICATEXT};
    enum ModelicaClasses {MODEL, CLASS, CONNECTOR, RECORD, BLOCK, FUNCTION, PACKAGE, PRIMITIVE, TYPE, PARAMETER,
                          CONSTANT, PROTECTED};
    static QString getModelicaClassType(int type);
    static QString getViewType(int type);
    static QString removeFirstLastCurlBrackets(QString value);
    static QString removeFirstLastBrackets(QString value);
    static QString removeFirstLastQuotes(QString value);
    static QString getSubStringFromDots(QString value);
    static QString removeLastDot(QString value);
    static QStringList getStrings(QString value);
    static QStringList getStrings(QString value, char start, char end);
    static QString getLastWordAfterDot(QString value);
    static QString getFirstWordBeforeDot(QString value);
    static QString removeLastSlashWord(QString value);
    static QString removeLastWordAfterDot(QString value);
    static QString removeComment(QString value);
};

#endif // STRINGHANDLER_H
