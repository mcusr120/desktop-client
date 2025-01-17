#ifndef IKEV2_CONFIGURATOR_H
#define IKEV2_CONFIGURATOR_H

#include <QObject>
#include <QProcessEnvironment>

#include "configurator_base.h"
#include "core/defs.h"

class Ikev2Configurator : ConfiguratorBase
{
    Q_OBJECT
public:
    Ikev2Configurator(std::shared_ptr<Settings> settings,
        std::shared_ptr<ServerController> serverController, QObject *parent = nullptr);

    struct ConnectionData {
        QByteArray clientCert; // p12 client cert
        QByteArray caCert; // p12 server cert
        QString clientId;
        QString password; // certificate password
        QString host; // host ip
    };

    QString genIkev2Config(const ServerCredentials &credentials, DockerContainer container,
        const QJsonObject &containerConfig, ErrorCode *errorCode = nullptr);

    QString genIkev2Config(const ConnectionData &connData);
    QString genMobileConfig(const ConnectionData &connData);
    QString genStrongSwanConfig(const ConnectionData &connData);

    ConnectionData prepareIkev2Config(const ServerCredentials &credentials,
        DockerContainer container, ErrorCode *errorCode = nullptr);
};

#endif // IKEV2_CONFIGURATOR_H
