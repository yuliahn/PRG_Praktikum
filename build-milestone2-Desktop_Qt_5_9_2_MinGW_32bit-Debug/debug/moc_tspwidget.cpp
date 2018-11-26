/****************************************************************************
** Meta object code from reading C++ file 'tspwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../milestone2/tspwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tspwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TSPwidget_t {
    QByteArrayData data[17];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TSPwidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TSPwidget_t qt_meta_stringdata_TSPwidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TSPwidget"
QT_MOC_LITERAL(1, 10, 18), // "environmentChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 2), // "ok"
QT_MOC_LITERAL(4, 33, 7), // "TSPends"
QT_MOC_LITERAL(5, 41, 8), // "startTSP"
QT_MOC_LITERAL(6, 50, 6), // "number"
QT_MOC_LITERAL(7, 57, 7), // "stopTSP"
QT_MOC_LITERAL(8, 65, 5), // "clear"
QT_MOC_LITERAL(9, 71, 8), // "interval"
QT_MOC_LITERAL(10, 80, 11), // "setInterval"
QT_MOC_LITERAL(11, 92, 4), // "msec"
QT_MOC_LITERAL(12, 97, 9), // "paintGrid"
QT_MOC_LITERAL(13, 107, 9), // "QPainter&"
QT_MOC_LITERAL(14, 117, 1), // "p"
QT_MOC_LITERAL(15, 119, 13), // "paintUniverse"
QT_MOC_LITERAL(16, 133, 12) // "newIteration"

    },
    "TSPwidget\0environmentChanged\0\0ok\0"
    "TSPends\0startTSP\0number\0stopTSP\0clear\0"
    "interval\0setInterval\0msec\0paintGrid\0"
    "QPainter&\0p\0paintUniverse\0newIteration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TSPwidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   75,    2, 0x0a /* Public */,
       5,    0,   78,    2, 0x2a /* Public | MethodCloned */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    1,   82,    2, 0x0a /* Public */,
      12,    1,   85,    2, 0x08 /* Private */,
      15,    1,   88,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,

       0        // eod
};

void TSPwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TSPwidget *_t = static_cast<TSPwidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->environmentChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->TSPends((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->startTSP((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->startTSP(); break;
        case 4: _t->stopTSP(); break;
        case 5: _t->clear(); break;
        case 6: { int _r = _t->interval();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->setInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->paintGrid((*reinterpret_cast< QPainter(*)>(_a[1]))); break;
        case 9: _t->paintUniverse((*reinterpret_cast< QPainter(*)>(_a[1]))); break;
        case 10: _t->newIteration(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TSPwidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TSPwidget::environmentChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TSPwidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TSPwidget::TSPends)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject TSPwidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TSPwidget.data,
      qt_meta_data_TSPwidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TSPwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TSPwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TSPwidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TSPwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void TSPwidget::environmentChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TSPwidget::TSPends(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
