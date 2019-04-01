#ifndef HELPER_H
#define HELPER_H
#include "/home/robot/catkin_ws/src/icarus_rover_v2/include/Definitions.h"

enum CameraStatus {
    UNDEFINED = 0,
    AVAILABLE = 1,
    TIMEOUT = 2,
};
struct UDPMessageInfo
{
    std::string id;
    std::string name;
    uint64_t rx_count;
    uint64_t tx_count;
};

struct Resource
{
    double ReceivedTime;
    std::string NodeName;
    qint64 ram_used_Mb;
    qint16 cpu_used_perc;
};
struct CameraStream
{
    std::string ip;
    std::string hostname;
    std::string DeviceName;
    uint32_t port;
    bool available;
};

struct Diagnostic
{
    std::string DeviceName;
    std::string NodeName;
    int System;
    int Subsystem;
    int Component;
    int DiagnosticType;
    int Level;
    int Message;
    std::string Description;
};
struct Port
{
    std::string name;
    std::string Capability;
    uint32_t number;
};

struct Node
{
    qint64 time_delta_ms;
    std::string NodeName;
    int Level;
};
struct Device
{
    std::string ParentDevice;
    std::string DeviceName;
    std::string Architecture;
    std::string DeviceType;
    std::string DeviceParent;
    std::string PrimaryIP;
    std::string Capability;
    int Level;
    qint64 time_delta_ms;
    std::vector<Node> Nodes;
};

struct Axis
{
    int id;
    QString name;
    double deadband;
    qint32 value;
    qint32 min;
    qint32 max;
    bool invert;
    qint32 neutral;
    qint32 in_value;
    qint32 out_value;
};
struct Joystick
{
    QString name;
    std::vector<Axis> axes;
};
struct Gain
{
    QString type;
    double P;
    double I;
    double D;
    double P_default;
    double I_default;
    double D_default;
    double P_min;
    double P_max;
    double I_min;
    double I_max;
    double D_min;
    double D_max;
};
struct ControlGroup
{
    QString name;
    Gain gain;
};
#endif
