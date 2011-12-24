/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/ 

#ifndef GLOBALTIMER_H
#define GLOBALTIMER_H

#include <QObject>
#include "dcpp/Singleton.h"
#include <auto_ptr.h>

class QTimer;

class GlobalTimer: public QObject, public dcpp::Singleton<GlobalTimer> {
    friend class dcpp::Singleton<GlobalTimer>;
    Q_OBJECT
public:
    
    quint64 getTicks() const;
    
Q_SIGNALS:
    void second();
    void minute();
    
private Q_SLOTS:
    void slotTick();
    
private:
    GlobalTimer();
    GlobalTimer(const GlobalTimer &);
    virtual ~GlobalTimer();
    GlobalTimer &operator=(const GlobalTimer&);
    
    std::auto_ptr<QTimer> timer;
    quint64 tickCount;
};

#endif // GLOBALTIMER_H
