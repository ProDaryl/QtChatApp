#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QByteArray>
#include <QDateTime>

class Message
{
private:
    int id;
    QString senderId;
    QString text;
    QByteArray image;
    QDateTime timestamp;
public:
    Message();

    Message(QString senderId, QString text, QByteArray image);

    QString getSenderId() const;
    QString getText() const;
    QByteArray getImage() const;

    void setSenderId(QString m_senderid) { senderId = m_senderid;}
    void setText(QString m_text) { text = m_text; }
    void setImage(QByteArray m_image) { image = m_image;}
    ~Message();
};

#endif // MESSAGE_H
