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
    QByteArrayData data[27];
    char stringdata0[244];
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
QT_MOC_LITERAL(12, 97, 8), // "setAlpha"
QT_MOC_LITERAL(13, 106, 5), // "value"
QT_MOC_LITERAL(14, 112, 7), // "setBeta"
QT_MOC_LITERAL(15, 120, 5), // "setK0"
QT_MOC_LITERAL(16, 126, 10), // "setMaxIter"
QT_MOC_LITERAL(17, 137, 10), // "setEtaZiel"
QT_MOC_LITERAL(18, 148, 9), // "setRadius"
QT_MOC_LITERAL(19, 158, 10), // "setCVRatio"
QT_MOC_LITERAL(20, 169, 10), // "paintField"
QT_MOC_LITERAL(21, 180, 9), // "QPainter&"
QT_MOC_LITERAL(22, 190, 1), // "p"
QT_MOC_LITERAL(23, 192, 9), // "paintGrid"
QT_MOC_LITERAL(24, 202, 13), // "paintLineNode"
QT_MOC_LITERAL(25, 216, 14), // "paintFieldNode"
QT_MOC_LITERAL(26, 231, 12) // "newIteration"

    },
    "TSPwidget\0environmentChanged\0\0ok\0"
    "TSPends\0startTSP\0number\0stopTSP\0clear\0"
    "interval\0setInterval\0msec\0setAlpha\0"
    "value\0setBeta\0setK0\0setMaxIter\0"
    "setEtaZiel\0setRadius\0setCVRatio\0"
    "paintField\0QPainter&\0p\0paintGrid\0"
    "paintLineNode\0paintFieldNode\0newIteration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TSPwidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x06 /* Public */,
       4,    1,  117,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,  120,    2, 0x0a /* Public */,
       5,    0,  123,    2, 0x2a /* Public | MethodCloned */,
       7,    0,  124,    2, 0x0a /* Public */,
       8,    0,  125,    2, 0x0a /* Public */,
       9,    0,  126,    2, 0x0a /* Public */,
      10,    1,  127,    2, 0x0a /* Public */,
      12,    1,  130,    2, 0x0a /* Public */,
      14,    1,  133,    2, 0x0a /* Public */,
      15,    1,  136,    2, 0x0a /* Public */,
      16,    1,  139,    2, 0x0a /* Public */,
      17,    1,  142,    2, 0x0a /* Public */,
      18,    1,  145,    2, 0x0a /* Public */,
      19,    1,  148,    2, 0x0a /* Public */,
      20,    1,  151,    2, 0x08 /* Private */,
      23,    1,  154,    2, 0x08 /* Private */,
      24,    1,  157,    2, 0x08 /* Private */,
      25,    1,  160,    2, 0x08 /* Private */,
      26,    0,  163,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 21,   22,
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
        case 8: _t->setAlpha((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->setBeta((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->setK0((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->setMaxIter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setEtaZiel((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->setRadius((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->setCVRatio((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->paintField((*reinterpret_cast< QPainter(*)>(_a[1]))); break;
        case 16: _t->paintGrid((*reinterpret_cast< QPainter(*)>(_a[1]))); break;
        case 17: _t->paintLineNode((*reinterpret_cast< QPainter(*)>(_a[1]))); break;
        case 18: _t->paintFieldNode((*reinterpret_cast< QPainter(*)>(_a[1]))); break;
        case 19: _t->newIteration(); break;
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
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
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
