// * This file is part of the COLOBOT source code
// * Copyright (C) 2001-2008, Daniel ROUX & EPSITEC SA, www.epsitec.ch
// * Copyright (C) 2012, Polish Portal of Colobot (PPC)
// *
// * This program is free software: you can redistribute it and/or modify
// * it under the terms of the GNU General Public License as published by
// * the Free Software Foundation, either version 3 of the License, or
// * (at your option) any later version.
// *
// * This program is distributed in the hope that it will be useful,
// * but WITHOUT ANY WARRANTY; without even the implied warranty of
// * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// * GNU General Public License for more details.
// *
// * You should have received a copy of the GNU General Public License
// * along with this program. If not, see  http://www.gnu.org/licenses/.

// autonuclear.h

#pragma once


#include "object/auto/auto.h"



enum AutoNuclearPhase
{
    ANUP_STOP       = 1,
    ANUP_WAIT       = 2,
    ANUP_CLOSE      = 3,
    ANUP_GENERATE   = 4,
    ANUP_OPEN       = 5,
};



class CAutoNuclear : public CAuto
{
public:
    CAutoNuclear(CInstanceManager* iMan, CObject* object);
    ~CAutoNuclear();

    void        DeleteObject(bool bAll=false);

    void        Init();
    bool        EventProcess(const Event &event);
    Error       GetError();

    bool        CreateInterface(bool bSelect);

    bool        Write(char *line);
    bool        Read(char *line);

protected:
    CObject*    SearchUranium();
    bool        SearchVehicle();
    void        CreatePower();

protected:
    AutoNuclearPhase    m_phase;
    float               m_progress;
    float               m_speed;
    float               m_timeVirus;
    float               m_lastParticle;
    Math::Vector            m_pos;
    int                 m_channelSound;
};

