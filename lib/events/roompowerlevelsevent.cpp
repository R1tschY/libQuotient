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

#include "roompowerlevelsevent.h"

namespace Quotient {
RoomPowerLevelsEventContent::RoomPowerLevelsEventContent(const QJsonObject& json)
    : ban(json["ban"_ls].toInt(50)),
      events(fromJson<QMap<QString, int>>(json["events"_ls])),
      eventsDefault(json["events_default"_ls].toInt(0)),
      invite(json["invite"_ls].toInt(50)),
      kick(json["kick"_ls].toInt(50)),
      redact(json["redact"_ls].toInt(50)),
      stateDefault(json["state_default"_ls].toInt(50)),
      users(fromJson<QMap<QString, int>>(json["users"_ls])),
      usersDefault(json["users_default"_ls].toInt(0)),
      roomNotification(json["notifications"]["room"].toInt(50))
{}
}
