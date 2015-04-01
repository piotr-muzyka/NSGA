/****************************************************************************
** Meta object code from reading C++ file 'plot_pnl.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "plot_pnl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plot_pnl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PlotPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      18,   10,   10,   10, 0x05,
      39,   10,   10,   10, 0x05,
      58,   10,   10,   10, 0x05,
      75,   10,   10,   10, 0x05,
      87,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     103,   99,   10,   10, 0x0a,
     130,  126,   10,   10, 0x0a,
     145,   10,   10,   10, 0x2a,
     157,   10,   10,   10, 0x0a,
     167,   10,   10,   10, 0x08,
     185,   10,   10,   10, 0x08,
     192,   10,   10,   10, 0x08,
     204,   10,   10,   10, 0x08,
     219,  216,   10,   10, 0x08,
     235,   10,   10,   10, 0x08,
     247,   10,   10,   10, 0x08,
     256,   10,   10,   10, 0x08,
     266,   10,   10,   10, 0x08,
     276,  273,   10,   10, 0x08,
     290,  273,   10,   10, 0x08,
     304,   10,   10,   10, 0x08,
     321,   10,   10,   10, 0x08,
     340,  336,   10,   10, 0x08,
     356,  336,   10,   10, 0x08,
     372,   10,   10,   10, 0x08,
     385,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PlotPanel[] = {
    "PlotPanel\0\0save()\0animPutText(QString)\0"
    "setStatus(QString)\0animSwitch(bool)\0"
    "giveFocus()\0clearWarn()\0txt\0"
    "animParseText(QString)\0pos\0setCurPos(int)\0"
    "setCurPos()\0execute()\0animText(QString)\0"
    "next()\0nextSlide()\0prevSlide()\0st\0"
    "animStart(bool)\0animSetup()\0adjust()\0"
    "pressF9()\0stop()\0id\0setStyle(int)\0"
    "setSubId(int)\0deleteSelected()\0"
    "hideSelected()\0cmd\0putCmd(QString)\0"
    "insCmd(QString)\0movePlotUp()\0"
    "movePlotDown()\0"
};

void PlotPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PlotPanel *_t = static_cast<PlotPanel *>(_o);
        switch (_id) {
        case 0: _t->save(); break;
        case 1: _t->animPutText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setStatus((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->animSwitch((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->giveFocus(); break;
        case 5: _t->clearWarn(); break;
        case 6: _t->animParseText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->setCurPos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setCurPos(); break;
        case 9: _t->execute(); break;
        case 10: _t->animText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->next(); break;
        case 12: _t->nextSlide(); break;
        case 13: _t->prevSlide(); break;
        case 14: _t->animStart((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->animSetup(); break;
        case 16: _t->adjust(); break;
        case 17: _t->pressF9(); break;
        case 18: _t->stop(); break;
        case 19: _t->setStyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->setSubId((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->deleteSelected(); break;
        case 22: _t->hideSelected(); break;
        case 23: _t->putCmd((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: _t->insCmd((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 25: _t->movePlotUp(); break;
        case 26: _t->movePlotDown(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PlotPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PlotPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlotPanel,
      qt_meta_data_PlotPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PlotPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PlotPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PlotPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PlotPanel))
        return static_cast<void*>(const_cast< PlotPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int PlotPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void PlotPanel::save()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PlotPanel::animPutText(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlotPanel::setStatus(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PlotPanel::animSwitch(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PlotPanel::giveFocus()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void PlotPanel::clearWarn()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
