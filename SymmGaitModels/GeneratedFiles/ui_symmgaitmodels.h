/********************************************************************************
** Form generated from reading UI file 'symmgaitmodels.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMMGAITMODELS_H
#define UI_SYMMGAITMODELS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SymmGaitModelsClass
{
public:
    QPushButton *pushButton;
    GLWidget *openGLWidget;

    void setupUi(QWidget *SymmGaitModelsClass)
    {
        if (SymmGaitModelsClass->objectName().isEmpty())
            SymmGaitModelsClass->setObjectName(QStringLiteral("SymmGaitModelsClass"));
        SymmGaitModelsClass->resize(673, 564);
        pushButton = new QPushButton(SymmGaitModelsClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 80, 75, 23));
        openGLWidget = new GLWidget(SymmGaitModelsClass);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(100, 10, 560, 460));

        retranslateUi(SymmGaitModelsClass);

        QMetaObject::connectSlotsByName(SymmGaitModelsClass);
    } // setupUi

    void retranslateUi(QWidget *SymmGaitModelsClass)
    {
        SymmGaitModelsClass->setWindowTitle(QApplication::translate("SymmGaitModelsClass", "SymmGaitModels", 0));
        pushButton->setText(QApplication::translate("SymmGaitModelsClass", "Wci\305\233nij!", 0));
    } // retranslateUi

};

namespace Ui {
    class SymmGaitModelsClass: public Ui_SymmGaitModelsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMMGAITMODELS_H
