#include "skinize.h"
#include <QString>

QString Skinize()
{
    return "QDialog { background: #fff ; border: 0; }"
           "QStackedWidget { background: rgba(255,255,255,0.5) ; border: 0 }"
           "QScrollArea { background: rgba(255,255,255,0.5) ; border: 0 }"
            "#scrollAreaWidgetContents { background: #fff }"
           "#BG1_1 { background: #fff; border-radius: 0px; }"
           "#BG1_2 { background: #fff; border-radius: 0px; }"
           "#BG1_3 { background: #fff; border-radius: 0px; border: 0px}"
           "#SendCoinsEntry { background: #fff; border-radius: 2px; border: 0px solid}"
           "#frameFee { background: #fff; border-radius: 0px; }"
           "#frame { background: #fff; border-radius: 0px; }"
           "#frame2 { background: #fff; border-radius: 0px; }"
           "#frameCoinControl { background: #fff; border-radius: 0px; }"
           "#noNavtechLabel { background: #f4eb99; padding: 5px; border-radius: 5px}"
           "#frameReceivingAddress { background: #fff; border-radius: 0px; }"
           "QPushButton {  background: rgba(255,255,255,0.23); border: 1px solid #4682B4; border-radius: 3px; padding: 6px; margin: 3px; text-transform: uppercase; color: #6495ED; font-size: 11px; font-weight: Bold }"
           "QPushButton:hover {  background-color: #B5B5E2; border: 1px solid #4682B4; border-radius: 3px; padding: 6px; margin: 3px; text-transform: uppercase; color: #6495ED; font-size: 11px; font-weight: Bold }"
           "QPushButton:pressed {  background-color: #DEA2ED; border: 1px solid #4682B4; border-radius: 3px; padding: 6px; margin: 3px; text-transform: uppercase; color: #6495ED; font-size: 11px; font-weight: Bold }"
           "QLineEdit { background: #fff; border-radius: 4px; border: 1px solid #7d7d7d; padding:5px }"
           "#unlockStakingButton { border-image: url(:/icons/lock_closed)  0 0 0 0 stretch stretch; border: 0px; }"
           "QLabel { color: #0055cc }"
           "QCheckBox { color: #0055cc }";
}
