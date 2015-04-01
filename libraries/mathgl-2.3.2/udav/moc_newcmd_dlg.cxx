/****************************************************************************
** Meta object code from reading C++ file 'newcmd_dlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "newcmd_dlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newcmd_dlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewCmdDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,   13,   13,   13, 0x08,
      64,   13,   13,   13, 0x08,
      81,   13,   13,   13, 0x08,
      98,   13,   13,   13, 0x08,
     111,   13,   13,   13, 0x08,
     123,   13,   13,   13, 0x08,
     135,   13,   13,   13, 0x08,
     144,   13,   13,   13, 0x08,
     153,   13,   13,   13, 0x08,
     167,  163,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NewCmdDialog[] = {
    "NewCmdDialog\0\0txt,replace\0"
    "result(QString,bool)\0typeChanged(int)\0"
    "nameChanged(int)\0kindChanged(int)\0"
    "insertData()\0insertOpt()\0insertStl()\0"
    "finish()\0zoomIn()\0zoomOut()\0txt\0"
    "parseCmd(QString)\0"
};

void NewCmdDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NewCmdDialog *_t = static_cast<NewCmdDialog *>(_o);
        switch (_id) {
        case 0: _t->result((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->typeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->nameChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->kindChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->insertData(); break;
        case 5: _t->insertOpt(); break;
        case 6: _t->insertStl(); break;
        case 7: _t->finish(); break;
        case 8: _t->zoomIn(); break;
        case 9: _t->zoomOut(); break;
        case 10: _t->parseCmd((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NewCmdDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NewCmdDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewCmdDialog,
      qt_meta_data_NewCmdDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewCmdDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewCmdDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewCmdDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewCmdDialog))
        return static_cast<void*>(const_cast< NewCmdDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewCmdDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void NewCmdDialog::result(const QString & _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
