/****************************************************************************
** Meta object code from reading C++ file 'dat_pnl.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dat_pnl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dat_pnl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DatPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      28,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,    9,   43,    9, 0x0a,
      62,    9,    9,    9, 0x0a,
      74,   72,    9,    9, 0x08,
      92,   88,    9,    9, 0x08,
     110,    9,    9,    9, 0x08,
     117,    9,    9,    9, 0x08,
     124,    9,    9,    9, 0x08,
     131,    9,    9,    9, 0x08,
     139,    9,    9,    9, 0x08,
     146,    9,    9,    9, 0x08,
     153,    9,    9,    9, 0x08,
     163,    9,    9,    9, 0x08,
     170,    9,    9,    9, 0x08,
     179,    9,    9,    9, 0x08,
     188,    9,    9,    9, 0x08,
     197,    9,    9,    9, 0x08,
     206,    9,    9,    9, 0x08,
     213,    9,    9,    9, 0x08,
     225,    9,    9,    9, 0x08,
     232,    9,    9,    9, 0x08,
     241,    9,    9,    9, 0x08,
     248,    9,    9,    9, 0x08,
     256,    9,    9,    9, 0x08,
     263,    9,    9,    9, 0x08,
     270,    9,    9,    9, 0x08,
     277,    9,    9,    9, 0x08,
     287,  284,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DatPanel[] = {
    "DatPanel\0\0sliceChanged(int)\0nzChanged(int)\0"
    "QString\0dataOper()\0refresh()\0k\0"
    "setSlice(int)\0r,c\0putValue(int,int)\0"
    "load()\0save()\0copy()\0paste()\0plot()\0"
    "list()\0inrange()\0norm()\0normsl()\0"
    "create()\0reSize()\0squize()\0crop()\0"
    "rearrange()\0oper()\0newdat()\0hist()\0"
    "first()\0last()\0next()\0prev()\0gosl()\0"
    "nz\0setNz(int)\0"
};

void DatPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DatPanel *_t = static_cast<DatPanel *>(_o);
        switch (_id) {
        case 0: _t->sliceChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->nzChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { QString _r = _t->dataOper();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: _t->refresh(); break;
        case 4: _t->setSlice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->putValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->load(); break;
        case 7: _t->save(); break;
        case 8: _t->copy(); break;
        case 9: _t->paste(); break;
        case 10: _t->plot(); break;
        case 11: _t->list(); break;
        case 12: _t->inrange(); break;
        case 13: _t->norm(); break;
        case 14: _t->normsl(); break;
        case 15: _t->create(); break;
        case 16: _t->reSize(); break;
        case 17: _t->squize(); break;
        case 18: _t->crop(); break;
        case 19: _t->rearrange(); break;
        case 20: _t->oper(); break;
        case 21: _t->newdat(); break;
        case 22: _t->hist(); break;
        case 23: _t->first(); break;
        case 24: _t->last(); break;
        case 25: _t->next(); break;
        case 26: _t->prev(); break;
        case 27: _t->gosl(); break;
        case 28: _t->setNz((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DatPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DatPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DatPanel,
      qt_meta_data_DatPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DatPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DatPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DatPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DatPanel))
        return static_cast<void*>(const_cast< DatPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int DatPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void DatPanel::sliceChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DatPanel::nzChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
