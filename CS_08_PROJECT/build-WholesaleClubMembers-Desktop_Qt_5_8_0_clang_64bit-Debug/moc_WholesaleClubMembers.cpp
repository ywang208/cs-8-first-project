/****************************************************************************
** Meta object code from reading C++ file 'WholesaleClubMembers.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WholesaleClubMembers/WholesaleClubMembers.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WholesaleClubMembers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WholesaleClubMembers_t {
    QByteArrayData data[6];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WholesaleClubMembers_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WholesaleClubMembers_t qt_meta_stringdata_WholesaleClubMembers = {
    {
QT_MOC_LITERAL(0, 0, 20), // "WholesaleClubMembers"
QT_MOC_LITERAL(1, 21, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 37), // "on_lineEdit_MemberEntry_retur..."
QT_MOC_LITERAL(4, 82, 27), // "on_pushButton_Clear_clicked"
QT_MOC_LITERAL(5, 110, 23) // "on_pushButton_2_clicked"

    },
    "WholesaleClubMembers\0on_pushButton_clicked\0"
    "\0on_lineEdit_MemberEntry_returnPressed\0"
    "on_pushButton_Clear_clicked\0"
    "on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WholesaleClubMembers[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

void WholesaleClubMembers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WholesaleClubMembers *_t = static_cast<WholesaleClubMembers *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->on_pushButton_clicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: _t->on_lineEdit_MemberEntry_returnPressed(); break;
        case 2: { bool _r = _t->on_pushButton_Clear_clicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject WholesaleClubMembers::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_WholesaleClubMembers.data,
      qt_meta_data_WholesaleClubMembers,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WholesaleClubMembers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WholesaleClubMembers::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WholesaleClubMembers.stringdata0))
        return static_cast<void*>(const_cast< WholesaleClubMembers*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int WholesaleClubMembers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
