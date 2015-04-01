/****************************************************************************
** Meta object code from reading C++ file 'mem_pnl.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mem_pnl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mem_pnl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MemPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      20,    9,    9,    9, 0x08,
      33,   31,    9,    9, 0x08,
      47,    9,    9,    9, 0x28,
      58,    9,    9,    9, 0x08,
      69,    9,    9,    9, 0x08,
      82,    9,    9,    9, 0x08,
     100,   92,    9,    9, 0x08,
     122,   92,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MemPanel[] = {
    "MemPanel\0\0refresh()\0newTable()\0n\0"
    "editData(int)\0editData()\0infoData()\0"
    "delAllData()\0delData()\0row,col\0"
    "tableClicked(int,int)\0tableDClicked(int,int)\0"
};

void MemPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MemPanel *_t = static_cast<MemPanel *>(_o);
        switch (_id) {
        case 0: _t->refresh(); break;
        case 1: _t->newTable(); break;
        case 2: _t->editData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->editData(); break;
        case 4: _t->infoData(); break;
        case 5: _t->delAllData(); break;
        case 6: _t->delData(); break;
        case 7: _t->tableClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->tableDClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MemPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MemPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MemPanel,
      qt_meta_data_MemPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MemPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MemPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MemPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MemPanel))
        return static_cast<void*>(const_cast< MemPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int MemPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
