/****************************************************************************
** Meta object code from reading C++ file 'calc_dlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "calc_dlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calc_dlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CalcDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   11,   11,   11, 0x0a,
      46,   11,   11,   11, 0x08,
      55,   11,   11,   11, 0x08,
      62,   11,   11,   11, 0x08,
      69,   11,   11,   11, 0x08,
      76,   11,   11,   11, 0x08,
      83,   11,   11,   11, 0x08,
      90,   11,   11,   11, 0x08,
      97,   11,   11,   11, 0x08,
     104,   11,   11,   11, 0x08,
     111,   11,   11,   11, 0x08,
     118,   11,   11,   11, 0x08,
     125,   11,   11,   11, 0x08,
     132,   11,   11,   11, 0x08,
     141,   11,   11,   11, 0x08,
     150,   11,   11,   11, 0x08,
     159,   11,   11,   11, 0x08,
     168,   11,   11,   11, 0x08,
     177,   11,   11,   11, 0x08,
     186,   11,   11,   11, 0x08,
     195,   11,   11,   11, 0x08,
     204,   11,   11,   11, 0x08,
     212,   11,   11,   11, 0x08,
     222,  220,   11,   11, 0x08,
     238,  220,   11,   11, 0x08,
     254,   11,   11,   11, 0x08,
     260,   11,   11,   11, 0x08,
     272,  268,   11,   11, 0x08,
     293,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CalcDialog[] = {
    "CalcDialog\0\0str\0putNumber(QString)\0"
    "evaluate()\0keyPut()\0key1()\0key2()\0"
    "key3()\0key4()\0key5()\0key6()\0key7()\0"
    "key8()\0key9()\0key0()\0keyE()\0keyDot()\0"
    "keyMul()\0keyDiv()\0keyAdd()\0keySub()\0"
    "keyBrO()\0keyBrC()\0keyFnc()\0keyPi()\0"
    "keyX2()\0s\0typeUpdate(int)\0funcUpdate(int)\0"
    "foc()\0clear()\0ind\0putText(QModelIndex)\0"
    "addResult()\0"
};

void CalcDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CalcDialog *_t = static_cast<CalcDialog *>(_o);
        switch (_id) {
        case 0: _t->putNumber((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->evaluate(); break;
        case 2: _t->keyPut(); break;
        case 3: _t->key1(); break;
        case 4: _t->key2(); break;
        case 5: _t->key3(); break;
        case 6: _t->key4(); break;
        case 7: _t->key5(); break;
        case 8: _t->key6(); break;
        case 9: _t->key7(); break;
        case 10: _t->key8(); break;
        case 11: _t->key9(); break;
        case 12: _t->key0(); break;
        case 13: _t->keyE(); break;
        case 14: _t->keyDot(); break;
        case 15: _t->keyMul(); break;
        case 16: _t->keyDiv(); break;
        case 17: _t->keyAdd(); break;
        case 18: _t->keySub(); break;
        case 19: _t->keyBrO(); break;
        case 20: _t->keyBrC(); break;
        case 21: _t->keyFnc(); break;
        case 22: _t->keyPi(); break;
        case 23: _t->keyX2(); break;
        case 24: _t->typeUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->funcUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->foc(); break;
        case 27: _t->clear(); break;
        case 28: _t->putText((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 29: _t->addResult(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CalcDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CalcDialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CalcDialog,
      qt_meta_data_CalcDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CalcDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CalcDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CalcDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CalcDialog))
        return static_cast<void*>(const_cast< CalcDialog*>(this));
    return QWidget::qt_metacast(_clname);
}

int CalcDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void CalcDialog::putNumber(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
