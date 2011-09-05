// $Id$
/**
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR 
 * THIS OSMC PUBLIC LICENSE (OSMC-PL). 
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES RECIPIENT'S ACCEPTANCE
 * OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3, ACCORDING TO RECIPIENTS CHOICE. 
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or  
 * http://www.openmodelica.org, and in the OpenModelica distribution. 
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 * Main contributor 2010, Hubert Thierot, CEP - ARMINES (France)
 * Main contributor 2010, Hubert Thierot, CEP - ARMINES (France)

 	@file WidgetSelPointScan.cpp
 	@brief Comments for file documentation.
 	@author Hubert Thieriot, hubert.thieriot@mines-paristech.fr
 	Company : CEP - ARMINES (France)
 	http://www-cep.ensmp.fr/english/
 	@version 
*/

#include "WidgetSelPointScan.h"
#include <QtGui/QSortFilterProxyModel>
#include "GuiTools.h"

namespace Ui
{
	class WidgetSelPointScanClass;
}

WidgetSelPointScan::WidgetSelPointScan(MOOptVector* _variables,QWidget *parent)
: QWidget(parent),
 ui(new Ui::WidgetSelPointScanClass)
{
	ui->setupUi(this);

	variables = _variables;
	
	connect(variables,SIGNAL(useScanChanged()),this,SLOT(onChangedUseScan()));
	connect(variables,SIGNAL(usePointsChanged()),this,SLOT(onChangedUsePoints()));
	
	
	update();

	
}

WidgetSelPointScan::~WidgetSelPointScan()
{
    delete ui;
}
void WidgetSelPointScan::onChangedUseScan()
{
	bool show = variables->getUseScan();
	ui->widgetScans->setVisible(show);
}
void WidgetSelPointScan::onChangedUsePoints()
{
	bool show = variables->getUsePoints();
	ui->widgetPoints->setVisible(show);
}
void WidgetSelPointScan::onChangedNbScans()
{
}
void WidgetSelPointScan::onChangedNbPoints()
{
}
void WidgetSelPointScan::update()
{
	ui->sliderScans->setMinimum(0);
	ui->sliderScans->setMaximum(variables->nbScans());
	ui->sliderScans->setValue(variables->curScan());

	onChangedUseScan();

	ui->sliderPoints->setMinimum(0);
	ui->sliderPoints->setMaximum(variables->nbPoints());
	ui->sliderPoints->setValue(variables->curPoint());
}
