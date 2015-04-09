/****************************************************************************
** Meta object code from reading C++ file 'ClassManage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainFrame/ClassManage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClassManage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_clientListItem_t {
    QByteArrayData data[16];
    char stringdata[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_clientListItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_clientListItem_t qt_meta_stringdata_clientListItem = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 15),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 12),
QT_MOC_LITERAL(4, 45, 15),
QT_MOC_LITERAL(5, 61, 13),
QT_MOC_LITERAL(6, 75, 11),
QT_MOC_LITERAL(7, 87, 13),
QT_MOC_LITERAL(8, 101, 16),
QT_MOC_LITERAL(9, 118, 9),
QT_MOC_LITERAL(10, 128, 12),
QT_MOC_LITERAL(11, 141, 8),
QT_MOC_LITERAL(12, 150, 11),
QT_MOC_LITERAL(13, 162, 14),
QT_MOC_LITERAL(14, 177, 13),
QT_MOC_LITERAL(15, 191, 16)
    },
    "clientListItem\0chooseClassName\0\0"
    "sigClassName\0cancelClassName\0agreeClassSig\0"
    "sigClientId\0sigClientName\0disagreeClassSig\0"
    "quitClass\0sigQuitClass\0endClass\0"
    "sigEndClass\0itemBtnClicked\0agrBtnClicked\0"
    "disAgrBtnClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_clientListItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       5,    3,   65,    2, 0x06 /* Public */,
       8,    3,   72,    2, 0x06 /* Public */,
       9,    1,   79,    2, 0x06 /* Public */,
      11,    1,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   85,    2, 0x08 /* Private */,
      14,    0,   86,    2, 0x08 /* Private */,
      15,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,    6,    7,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void clientListItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        clientListItem *_t = static_cast<clientListItem *>(_o);
        switch (_id) {
        case 0: _t->chooseClassName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->cancelClassName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->agreeClassSig((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->disagreeClassSig((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->quitClass((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->endClass((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->itemBtnClicked(); break;
        case 7: _t->agrBtnClicked(); break;
        case 8: _t->disAgrBtnClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (clientListItem::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clientListItem::chooseClassName)) {
                *result = 0;
            }
        }
        {
            typedef void (clientListItem::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clientListItem::cancelClassName)) {
                *result = 1;
            }
        }
        {
            typedef void (clientListItem::*_t)(QString , int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clientListItem::agreeClassSig)) {
                *result = 2;
            }
        }
        {
            typedef void (clientListItem::*_t)(QString , int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clientListItem::disagreeClassSig)) {
                *result = 3;
            }
        }
        {
            typedef void (clientListItem::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clientListItem::quitClass)) {
                *result = 4;
            }
        }
        {
            typedef void (clientListItem::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clientListItem::endClass)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject clientListItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_clientListItem.data,
      qt_meta_data_clientListItem,  qt_static_metacall, 0, 0}
};


const QMetaObject *clientListItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *clientListItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_clientListItem.stringdata))
        return static_cast<void*>(const_cast< clientListItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int clientListItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void clientListItem::chooseClassName(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void clientListItem::cancelClassName(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void clientListItem::agreeClassSig(QString _t1, int _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void clientListItem::disagreeClassSig(QString _t1, int _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void clientListItem::quitClass(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void clientListItem::endClass(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_ClassManage_t {
    QByteArrayData data[20];
    char stringdata[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClassManage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClassManage_t qt_meta_stringdata_ClassManage = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 18),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 21),
QT_MOC_LITERAL(4, 54, 20),
QT_MOC_LITERAL(5, 75, 15),
QT_MOC_LITERAL(6, 91, 9),
QT_MOC_LITERAL(7, 101, 19),
QT_MOC_LITERAL(8, 121, 16),
QT_MOC_LITERAL(9, 138, 4),
QT_MOC_LITERAL(10, 143, 19),
QT_MOC_LITERAL(11, 163, 12),
QT_MOC_LITERAL(12, 176, 11),
QT_MOC_LITERAL(13, 188, 14),
QT_MOC_LITERAL(14, 203, 9),
QT_MOC_LITERAL(15, 213, 8),
QT_MOC_LITERAL(16, 222, 10),
QT_MOC_LITERAL(17, 233, 17),
QT_MOC_LITERAL(18, 251, 15),
QT_MOC_LITERAL(19, 267, 14)
    },
    "ClassManage\0ownClassBtnClicked\0\0"
    "joinedClassBtnClicked\0createListBtnClicked\0"
    "createClassSlot\0classname\0allClassItemClicked\0"
    "QListWidgetItem*\0item\0ownClassItemClicked\0"
    "applyToClass\0cancelApply\0agreeJoinClass\0"
    "className\0clientNo\0clientName\0"
    "disagreeJoinClass\0quitJoinedClass\0"
    "endJoinedClass"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClassManage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    1,   77,    2, 0x08 /* Private */,
       7,    1,   80,    2, 0x08 /* Private */,
      10,    1,   83,    2, 0x08 /* Private */,
      11,    1,   86,    2, 0x08 /* Private */,
      12,    1,   89,    2, 0x08 /* Private */,
      13,    3,   92,    2, 0x08 /* Private */,
      17,    3,   99,    2, 0x08 /* Private */,
      18,    1,  106,    2, 0x08 /* Private */,
      19,    1,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,   14,   15,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,   14,   15,   16,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,

       0        // eod
};

void ClassManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClassManage *_t = static_cast<ClassManage *>(_o);
        switch (_id) {
        case 0: _t->ownClassBtnClicked(); break;
        case 1: _t->joinedClassBtnClicked(); break;
        case 2: _t->createListBtnClicked(); break;
        case 3: _t->createClassSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->allClassItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->ownClassItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->applyToClass((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->cancelApply((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->agreeJoinClass((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 9: _t->disagreeJoinClass((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 10: _t->quitJoinedClass((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->endJoinedClass((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ClassManage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ClassManage.data,
      qt_meta_data_ClassManage,  qt_static_metacall, 0, 0}
};


const QMetaObject *ClassManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClassManage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClassManage.stringdata))
        return static_cast<void*>(const_cast< ClassManage*>(this));
    return QWidget::qt_metacast(_clname);
}

int ClassManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
