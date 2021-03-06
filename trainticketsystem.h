#ifndef TRAINTICKETSYSTEM_H
#define TRAINTICKETSYSTEM_H

#include <QString>
#include <QByteArray>
#include <QTcpSocket>

typedef unsigned short int USI;

class TrainTicketSystem
{
protected:
    USI port;

    QString request_string;

public:
    TrainTicketSystem();

    // request & response function
    void request(const QString& re);
    void request(const int& renum);
    void send_request(QTcpSocket* socket);
    QString response(const QByteArray& request);

    // codes
    enum ServerOrder{
        AssignPort,
        StatusbarMessage,
        ConnectionReject,
        LoginStatus,
        SendStationTable,
        SendTrainInquiry,
        DataTransferEnd

    };

    enum ClientOrder{
        Login,
        AskStationTable,
        TrainInquiry
    };

    enum Usertype{
        GUEST,
        CLIENT,
        STAFF,
        MANAGER
    };

    // usertype
    QString usertypeStr(int n);

};

#endif // TRAINTICKETSYSTEM_H
