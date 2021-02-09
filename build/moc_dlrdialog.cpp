/****************************************************************************
** Meta object code from reading C++ file 'dlrdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../dlrdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlrdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DlrDialog_t {
    QByteArrayData data[19];
    char stringdata0[341];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlrDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlrDialog_t qt_meta_stringdata_DlrDialog = {
    {
QT_MOC_LITERAL(0, 0, 9), // "DlrDialog"
QT_MOC_LITERAL(1, 10, 9), // "cmdToSend"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "data"
QT_MOC_LITERAL(4, 26, 19), // "on_closeBtn_clicked"
QT_MOC_LITERAL(5, 46, 22), // "on_valve_0_Btn_toggled"
QT_MOC_LITERAL(6, 69, 7), // "checked"
QT_MOC_LITERAL(7, 77, 22), // "on_valve_1_Btn_toggled"
QT_MOC_LITERAL(8, 100, 19), // "on_flushBtn_toggled"
QT_MOC_LITERAL(9, 120, 26), // "on_rpmSpinner_valueChanged"
QT_MOC_LITERAL(10, 147, 4), // "arg1"
QT_MOC_LITERAL(11, 152, 19), // "on_pump_Btn_toggled"
QT_MOC_LITERAL(12, 172, 29), // "on_heaterSpinner_valueChanged"
QT_MOC_LITERAL(13, 202, 20), // "on_updateBtn_clicked"
QT_MOC_LITERAL(14, 223, 18), // "calcValuesFromTime"
QT_MOC_LITERAL(15, 242, 16), // "QVector<QString>"
QT_MOC_LITERAL(16, 259, 30), // "on_heaterSlider_sliderReleased"
QT_MOC_LITERAL(17, 290, 27), // "on_rpmSlider_sliderReleased"
QT_MOC_LITERAL(18, 318, 22) // "on_valve_0_Btn_clicked"

    },
    "DlrDialog\0cmdToSend\0\0data\0on_closeBtn_clicked\0"
    "on_valve_0_Btn_toggled\0checked\0"
    "on_valve_1_Btn_toggled\0on_flushBtn_toggled\0"
    "on_rpmSpinner_valueChanged\0arg1\0"
    "on_pump_Btn_toggled\0on_heaterSpinner_valueChanged\0"
    "on_updateBtn_clicked\0calcValuesFromTime\0"
    "QVector<QString>\0on_heaterSlider_sliderReleased\0"
    "on_rpmSlider_sliderReleased\0"
    "on_valve_0_Btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlrDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   82,    2, 0x08 /* Private */,
       5,    1,   83,    2, 0x08 /* Private */,
       7,    1,   86,    2, 0x08 /* Private */,
       8,    1,   89,    2, 0x08 /* Private */,
       9,    1,   92,    2, 0x08 /* Private */,
      11,    1,   95,    2, 0x08 /* Private */,
      12,    1,   98,    2, 0x08 /* Private */,
      13,    0,  101,    2, 0x08 /* Private */,
      14,    1,  102,    2, 0x08 /* Private */,
      16,    0,  105,    2, 0x08 /* Private */,
      17,    0,  106,    2, 0x08 /* Private */,
      18,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    0x80000000 | 15, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DlrDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DlrDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cmdToSend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_closeBtn_clicked(); break;
        case 2: _t->on_valve_0_Btn_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_valve_1_Btn_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_flushBtn_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_rpmSpinner_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_pump_Btn_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_heaterSpinner_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_updateBtn_clicked(); break;
        case 9: { QVector<QString> _r = _t->calcValuesFromTime((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector<QString>*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->on_heaterSlider_sliderReleased(); break;
        case 11: _t->on_rpmSlider_sliderReleased(); break;
        case 12: _t->on_valve_0_Btn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DlrDialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DlrDialog::cmdToSend)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DlrDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DlrDialog.data,
    qt_meta_data_DlrDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DlrDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlrDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DlrDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DlrDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void DlrDialog::cmdToSend(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
