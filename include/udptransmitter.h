/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef UDPTRANSMITTER_H
#define UDPTRANSMITTER_H

#include <QDialog>
#include <QHostAddress>
#include <QTimer>
#include <QElapsedTimer>
#include "helper.h"
#include "udpmessage.h"
QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QUdpSocket;
QT_END_NAMESPACE

class UDPTransmitter : public QObject
{
    Q_OBJECT

public:
    UDPTransmitter(QWidget *parent = 0);
    bool set_server_info(QString _ipaddress,uint16_t port);
    void set_debugmode(bool v)
    {
        debug_mode = v;
    }
    void Start()
    {
        qDebug() << "Starting UDP Transmitter with: " << server << ":" << port;
        start = true;
        RemoteControl_AB10_timer.start();
        ArmControl_AB26_timer.start();
        Command_AB02_timer.start();
        Heartbeat_AB31_timer.start();
    }

    bool send_RemoteControl_0xAB10(quint64 timestamp,int axis1,int axis2,int axis3,int axis4,int axis5,int axis6,int axis7,int axis8,
                                   int button1,int button2,int button3,int button4, int button5,int button6,int button7,int button8);
    bool send_ArmControl_0xAB26(int device,int axis1,int axis2,int axis3,int axis4,int axis5,int axis6,int button1,int button2,int button3,int button4,int button5,int button6);
    bool send_Command_0xAB02(int command,int option1,int option2,int option3, std::string commandtext, std::string description);
    bool send_Heartbeat_0xAB31(std::string hostname,uint64_t t,uint64_t t2);
    bool send_TuneControlGroup_0xAB39(std::string name, std::string type, double v1, double v2, double v3, int maxvalue, int minvalue, int defaultvalue);

signals:
private:
    bool start;
    bool debug_mode;
    QUdpSocket *xmit_socket;
    QTimer timer;
    QString server;
    uint16_t port;
    UDPMessageHandler *udpmessagehandler;

    QElapsedTimer RemoteControl_AB10_timer;
    QElapsedTimer ArmControl_AB26_timer;
    QElapsedTimer Command_AB02_timer;
    QElapsedTimer Heartbeat_AB31_timer;
    QElapsedTimer TuneControlGroup_0A39_timer;

};

#endif
