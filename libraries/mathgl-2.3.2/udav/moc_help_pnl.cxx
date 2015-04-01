/****************************************************************************
** Meta object code from reading C++ file 'help_pnl.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "help_pnl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'help_pnl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HelpPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   11,   10,   10, 0x0a,
      33,   10,   10,   10, 0x2a,
      44,   10,   10,   10, 0x0a,
      53,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HelpPanel[] = {
    "HelpPanel\0\0cmd\0showHelp(QString)\0"
    "showHelp()\0zoomIn()\0zoomOut()\0"
};

void HelpPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HelpPanel *_t = static_cast<HelpPanel *>(_o);
        switch (_id) {
        case 0: _t->showHelp((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->showHelp(); break;
        case 2: _t->zoomIn(); break;
        case 3: _t->zoomOut(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HelpPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HelpPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HelpPanel,
      qt_meta_data_HelpPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HelpPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HelpPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HelpPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HelpPanel))
        return static_cast<void*>(const_cast< HelpPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int HelpPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
