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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SymmGaitModelsClass
{
public:
    QPushButton *RepaintButton;
    GLWidget *OpenGLWidget;
    QLineEdit *MarkerNrLineEdit;
    QLabel *MarkerLabel;
    QGroupBox *CoordRadioGroupBox;
    QRadioButton *XRadioButton;
    QRadioButton *YRadioButton;
    QRadioButton *ZRadioButton;
    QPushButton *LoadMatrixButton;
    QLabel *LoadedMatrixTitleLabel;
    QLabel *LoadedMatrixNameLabel;

    void setupUi(QWidget *SymmGaitModelsClass)
    {
        if (SymmGaitModelsClass->objectName().isEmpty())
            SymmGaitModelsClass->setObjectName(QStringLiteral("SymmGaitModelsClass"));
        SymmGaitModelsClass->resize(729, 564);
        RepaintButton = new QPushButton(SymmGaitModelsClass);
        RepaintButton->setObjectName(QStringLiteral("RepaintButton"));
        RepaintButton->setGeometry(QRect(20, 510, 75, 23));
        OpenGLWidget = new GLWidget(SymmGaitModelsClass);
        OpenGLWidget->setObjectName(QStringLiteral("OpenGLWidget"));
        OpenGLWidget->setGeometry(QRect(160, 10, 560, 460));
        MarkerNrLineEdit = new QLineEdit(SymmGaitModelsClass);
        MarkerNrLineEdit->setObjectName(QStringLiteral("MarkerNrLineEdit"));
        MarkerNrLineEdit->setGeometry(QRect(10, 130, 121, 20));
        MarkerLabel = new QLabel(SymmGaitModelsClass);
        MarkerLabel->setObjectName(QStringLiteral("MarkerLabel"));
        MarkerLabel->setGeometry(QRect(10, 110, 131, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        MarkerLabel->setFont(font);
        CoordRadioGroupBox = new QGroupBox(SymmGaitModelsClass);
        CoordRadioGroupBox->setObjectName(QStringLiteral("CoordRadioGroupBox"));
        CoordRadioGroupBox->setGeometry(QRect(10, 160, 121, 51));
        CoordRadioGroupBox->setFont(font);
        XRadioButton = new QRadioButton(CoordRadioGroupBox);
        XRadioButton->setObjectName(QStringLiteral("XRadioButton"));
        XRadioButton->setGeometry(QRect(10, 20, 31, 17));
        YRadioButton = new QRadioButton(CoordRadioGroupBox);
        YRadioButton->setObjectName(QStringLiteral("YRadioButton"));
        YRadioButton->setGeometry(QRect(50, 20, 31, 17));
        ZRadioButton = new QRadioButton(CoordRadioGroupBox);
        ZRadioButton->setObjectName(QStringLiteral("ZRadioButton"));
        ZRadioButton->setGeometry(QRect(90, 20, 31, 17));
        LoadMatrixButton = new QPushButton(SymmGaitModelsClass);
        LoadMatrixButton->setObjectName(QStringLiteral("LoadMatrixButton"));
        LoadMatrixButton->setGeometry(QRect(10, 80, 121, 21));
        LoadedMatrixTitleLabel = new QLabel(SymmGaitModelsClass);
        LoadedMatrixTitleLabel->setObjectName(QStringLiteral("LoadedMatrixTitleLabel"));
        LoadedMatrixTitleLabel->setGeometry(QRect(10, 10, 91, 16));
        LoadedMatrixTitleLabel->setFont(font);
        LoadedMatrixNameLabel = new QLabel(SymmGaitModelsClass);
        LoadedMatrixNameLabel->setObjectName(QStringLiteral("LoadedMatrixNameLabel"));
        LoadedMatrixNameLabel->setGeometry(QRect(10, 30, 131, 41));
        LoadedMatrixNameLabel->setWordWrap(true);

        retranslateUi(SymmGaitModelsClass);

        QMetaObject::connectSlotsByName(SymmGaitModelsClass);
    } // setupUi

    void retranslateUi(QWidget *SymmGaitModelsClass)
    {
        SymmGaitModelsClass->setWindowTitle(QApplication::translate("SymmGaitModelsClass", "SymmGaitModels", 0));
        RepaintButton->setText(QApplication::translate("SymmGaitModelsClass", "Repaint", 0));
        MarkerLabel->setText(QApplication::translate("SymmGaitModelsClass", "Marker Number (1-26)", 0));
        CoordRadioGroupBox->setTitle(QApplication::translate("SymmGaitModelsClass", "Coordinate", 0));
        XRadioButton->setText(QApplication::translate("SymmGaitModelsClass", "X", 0));
        YRadioButton->setText(QApplication::translate("SymmGaitModelsClass", "Y", 0));
        ZRadioButton->setText(QApplication::translate("SymmGaitModelsClass", "Z", 0));
        LoadMatrixButton->setText(QApplication::translate("SymmGaitModelsClass", "Load Another Matrix", 0));
        LoadedMatrixTitleLabel->setText(QApplication::translate("SymmGaitModelsClass", "Loaded Matrix:", 0));
        LoadedMatrixNameLabel->setText(QApplication::translate("SymmGaitModelsClass", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class SymmGaitModelsClass: public Ui_SymmGaitModelsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMMGAITMODELS_H
