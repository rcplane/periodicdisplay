/**********************************************************************
  ImportDialog - Import File Dialog

  Copyright (C) 2008 Geoffrey Hutchison

  This file is part of the Avogadro molecular editor project.
  For more information, see <http://avogadro.openmolecules.net/>

  Avogadro is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  Avogadro is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
  02110-1301, USA.
 **********************************************************************/

#ifndef IMPORTDIALOG_H
#define IMPORTDIALOG_H

#include "ui_importdialog.h"

class QAbstractButton;
namespace OpenBabel{
  class OBFormat;  
}

namespace Avogadro {

  class MainWindow;
  
  class ImportDialog : public QDialog
  {
    Q_OBJECT

    public:
      ImportDialog(MainWindow *mainWindow);

    private Q_SLOTS:
      void updateFilename(bool);
      void changedFormat(int);
      void changedOptions(int);
    
      void accepted();
      void rejected();
      void buttonClicked(QAbstractButton *button);

    private:
      Ui::ImportFileDialog ui;

      MainWindow *m_mainWindow;
      QString     m_filename;
      int         m_currentFormat;
      
      // format pointers and descriptions
      QList<OpenBabel::OBFormat*> m_formatList;
  };

} // end namespace Avogadro

#endif
