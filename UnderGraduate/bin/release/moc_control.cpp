/****************************************************************************
** Meta object code from reading C++ file 'control.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Control/control.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Control_t {
    QByteArrayData data[16];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Control_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Control_t qt_meta_stringdata_Control = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Control"
QT_MOC_LITERAL(1, 8, 11), // "TimerTicked"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "DutyControl"
QT_MOC_LITERAL(4, 33, 15), // "sld_open_change"
QT_MOC_LITERAL(5, 49, 5), // "value"
QT_MOC_LITERAL(6, 55, 16), // "sld_ratio_change"
QT_MOC_LITERAL(7, 72, 18), // "sld_x_scale_change"
QT_MOC_LITERAL(8, 91, 18), // "sld_y_scale_change"
QT_MOC_LITERAL(9, 110, 19), // "sld_y_center_change"
QT_MOC_LITERAL(10, 130, 15), // "btn_start_click"
QT_MOC_LITERAL(11, 146, 15), // "btn_pause_click"
QT_MOC_LITERAL(12, 162, 13), // "btn_end_click"
QT_MOC_LITERAL(13, 176, 14), // "btn_duty_click"
QT_MOC_LITERAL(14, 191, 14), // "btn_open_click"
QT_MOC_LITERAL(15, 206, 15) // "btn_close_click"

    },
    "Control\0TimerTicked\0\0DutyControl\0"
    "sld_open_change\0value\0sld_ratio_change\0"
    "sld_x_scale_change\0sld_y_scale_change\0"
    "sld_y_center_change\0btn_start_click\0"
    "btn_pause_click\0btn_end_click\0"
    "btn_duty_click\0btn_open_click\0"
    "btn_close_click"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Control[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    1,   81,    2, 0x08 /* Private */,
       6,    1,   84,    2, 0x08 /* Private */,
       7,    1,   87,    2, 0x08 /* Private */,
       8,    1,   90,    2, 0x08 /* Private */,
       9,    1,   93,    2, 0x08 /* Private */,
      10,    0,   96,    2, 0x08 /* Private */,
      11,    0,   97,    2, 0x08 /* Private */,
      12,    0,   98,    2, 0x08 /* Private */,
      13,    0,   99,    2, 0x08 /* Private */,
      14,    0,  100,    2, 0x08 /* Private */,
      15,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Control::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Control *_t = static_cast<Control *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TimerTicked(); break;
        case 1: _t->DutyControl(); break;
        case 2: _t->sld_open_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sld_ratio_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sld_x_scale_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->sld_y_scale_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->sld_y_center_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->btn_start_click(); break;
        case 8: _t->btn_pause_click(); break;
        case 9: _t->btn_end_click(); break;
        case 10: _t->btn_duty_click(); break;
        case 11: _t->btn_open_click(); break;
        case 12: _t->btn_close_click(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Control::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Control.data,
      qt_meta_data_Control,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Control::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Control::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Control.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Control::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
