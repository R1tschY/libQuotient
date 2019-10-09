/******************************************************************************
 * Copyright (C) 2019 QMatrixClient project
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef ROOMPOWERLEVELSEVENT_H
#define ROOMPOWERLEVELSEVENT_H

#include "stateevent.h"
#include "eventcontent.h"

namespace Quotient {
class RoomPowerLevelsEventContent : public EventContent::Base {
public:
    explicit RoomPowerLevelsEventContent() {}
    explicit RoomPowerLevelsEventContent(const QJsonObject& json);

    int ban;
    QMap<QString, int> events;
    int eventsDefault;
    int invite;
    int kick;
    int redact;
    int stateDefault;
    QMap<QString, int> users;
    int usersDefault;
    int roomNotification;

protected:
    void fillJson(QJsonObject* o) const override;
};

class RoomPowerLevelsEvent : public StateEvent<RoomPowerLevelsEventContent> {
    Q_GADGET
public:
    DEFINE_EVENT_TYPEID("m.room.power_levels", RoomPowerLevelsEvent)

    explicit RoomPowerLevelsEvent(const QJsonObject& obj)
        : StateEvent(typeId(), obj)
    {}

    int ban() { return content().ban; }
    QMap<QString, int> events() { return content().events; }
    int eventsDefault() { return content().eventsDefault; }
    int invite() { return content().invite; }
    int kick() { return content().kick; }
    int redact() { return content().redact; }
    int stateDefault() { return content().stateDefault; }
    QMap<QString, int> users() { return content().users; }
    int usersDefault() { return content().usersDefault; }
    int roomNotification() { return content().roomNotification; }
};
REGISTER_EVENT_TYPE(RoomPowerLevelsEvent)
}

#endif // ROOMPOWERLEVELSEVENT_H
