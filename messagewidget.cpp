// messagewidget.cpp
#include "messagewidget.h"

MessageWidget::MessageWidget(QString senderName, QString messageText, QByteArray imageData, QWidget *parent)
    : QWidget(parent)
{
    senderLabel = new QLabel(senderName);
    textLabel = new QLabel(messageText);
    imageLabel = new QLabel();

    if (!imageData.isEmpty()) {
        QPixmap pixmap;
        pixmap.loadFromData(imageData);
        pixmap = pixmap.scaled(64, 64, Qt::KeepAspectRatio);
        imageLabel->setPixmap(pixmap);
    }

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *textLayout = new QHBoxLayout();
    textLayout->addWidget(senderLabel);
    textLayout->addWidget(textLabel);

    mainLayout->addLayout(textLayout);
    if (!imageData.isEmpty()) {
        mainLayout->addWidget(imageLabel);
    }

    setLayout(mainLayout);

    // Add styling
    senderLabel->setStyleSheet("font-weight: bold; color: #555;");
    textLabel->setStyleSheet("color: #333;");
    setStyleSheet("background-color: #f0f0f0; border-radius: 5px; padding: 5px;");
}

MessageWidget::~MessageWidget() {}
