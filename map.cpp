/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Mobility Components.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in 
** accordance with the Qt Commercial License Agreement provided with
** the Software or, alternatively, in accordance with the terms
** contained in a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#include "map.h"

#include <QtGui>
#include <QGeoCoordinate>
#include <QProcessEnvironment>
#include <QNetworkProxy>
#include <QNetworkProxyFactory>
#include <qnetworkconfigmanager.h>


QTM_USE_NAMESPACE//shit!!!!

MapWindow::MapWindow(QWidget *parent) :
        QDialog(parent)
{
    QGraphicsScene *sc = new QGraphicsScene;

    m_qgv = new QGraphicsView(sc, this);
    m_qgv->setVisible(1);
    m_qgv->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_qgv->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

      // Set Internet Access Point
    QNetworkConfigurationManager manager;
    QNetworkConfiguration cfg = manager.defaultConfiguration();


    //set callbacks and start internet connection
    m_session = new QNetworkSession(cfg, this);

    QHBoxLayout *main = new QHBoxLayout;
    main->addWidget(m_qgv);
    setLayout(main);
    connect(m_session, SIGNAL(opened()), this, SLOT(networkSessionOpened()));
    m_session->open();//shit!!forget this thing!!!
}

void MapWindow::networkSessionOpened()
{

    //get provider, we are hardcoding it to nokia
    setProvider("nokia");
    //set up the map widget
    setupMap();
}

void MapWindow::setProvider(QString providerId)
{
    QGeoServiceProvider *m_serviceProvider = new QGeoServiceProvider(providerId);
    m_mapManager = m_serviceProvider->mappingManager();
}

void MapWindow::setupMap()
{
    m_mapWidget = new MapWidget(m_mapManager);
    m_qgv->scene()->addItem(m_mapWidget);
    m_mapWidget->setCenter(QGeoCoordinate(39.962,116.38));
    m_mapWidget->setZoomLevel(13);

}

MapWidget::MapWidget(QGeoMappingManager *manager) : QGraphicsGeoMap(manager)
{
    m_panActive = false;
}

MapWidget::~MapWidget() {}


void MapWidget::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    setFocus();
    if (event->button() == Qt::LeftButton) {
        m_panActive = true;
    }

    event->accept();
}

void MapWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        if (m_panActive) {
            m_panActive = false;
        }
    }

    event->accept();
}


void MapWidget::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (m_panActive) {
        pan(event->lastPos().x() - event->pos().x(), event->lastPos().y() - event->pos().y());
    }

    event->accept();
}

void MapWidget::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    setFocus();

    pan(event->lastPos().x() -  size().width() / 2.0, event->lastPos().y() - size().height() / 2.0);
    if (zoomLevel() < maximumZoomLevel())
        setZoomLevel(zoomLevel() + 1);

    event->accept();
}
