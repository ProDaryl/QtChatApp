#include "message.h"

Message::Message() {}

Message::Message(QString m_senderId, QString m_text, QByteArray m_image): senderId(m_senderId), text(m_text), image(m_image){}

QString Message::getSenderId() const {
    return senderId;
}

QString Message::getText() const {
    return text;
}

QByteArray Message::getImage() const {
    return image;
}

void setImage(QByteArray );

Message::~Message() {}
