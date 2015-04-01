/****************************************************************************
** Meta object code from reading C++ file 'prop_dlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "prop_dlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'prop_dlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PropDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x05,
      37,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   11,   11,   11, 0x08,
      66,   11,   11,   11, 0x08,
      74,   11,   11,   11, 0x08,
      82,   11,   11,   11, 0x08,
      90,   11,   11,   11, 0x08,
      98,   11,   11,   11, 0x08,
     106,   11,   11,   11, 0x08,
     114,   11,   11,   11, 0x08,
     122,   11,   11,   11, 0x08,
     130,   11,   11,   11, 0x08,
     138,   11,   11,   11, 0x08,
     146,   11,   11,   11, 0x08,
     153,   11,   11,   11, 0x08,
     164,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PropDialog[] = {
    "PropDialog\0\0w,h\0sizeChanged(int,int)\0"
    "propUpdated()\0applyChanges()\0setC0()\0"
    "setC1()\0setC2()\0setC3()\0setC4()\0setC5()\0"
    "setC6()\0setC7()\0setC8()\0setC9()\0setF()\0"
    "getPathH()\0getPathF()\0"
};

void PropDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PropDialog *_t = static_cast<PropDialog *>(_o);
        switch (_id) {
        case 0: _t->sizeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->propUpdated(); break;
        case 2: _t->applyChanges(); break;
        case 3: _t->setC0(); break;
        case 4: _t->setC1(); break;
        case 5: _t->setC2(); break;
        case 6: _t->setC3(); break;
        case 7: _t->setC4(); break;
        case 8: _t->setC5(); break;
        case 9: _t->setC6(); break;
        case 10: _t->setC7(); break;
        case 11: _t->setC8(); break;
        case 12: _t->setC9(); break;
        case 13: _t->setF(); break;
        case 14: _t->getPathH(); break;
        case 15: _t->getPathF(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PropDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PropDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PropDialog,
      qt_meta_data_PropDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PropDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PropDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PropDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PropDialog))
        return static_cast<void*>(const_cast< PropDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PropDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void PropDialog::sizeChanged(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PropDialog::propUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
