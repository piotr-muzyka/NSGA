/****************************************************************************
** Meta object code from reading C++ file 'udav_wnd.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "udav_wnd.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udav_wnd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   34,   11,   11, 0x0a,
      58,   11,   11,   11, 0x0a,
      75,   11,   11,   11, 0x0a,
      92,   85,   11,   11, 0x0a,
     119,   11,   11,   11, 0x08,
     128,   11,   11,   11, 0x08,
     137,   11,   11,   11, 0x08,
     144,   11,   11,   11, 0x08,
     153,   11,   11,   11, 0x08,
     161,   11,   11,   11, 0x08,
     171,   11,   11,   11, 0x08,
     188,   11,   11,   11, 0x08,
     199,   11,   11,   11, 0x08,
     214,   11,   11,   11, 0x08,
     230,   11,   11,   11, 0x08,
     244,   11,   11,   11, 0x08,
     257,   11,   11,   11, 0x08,
     270,   11,   11,   11, 0x08,
     284,   11,   11,   11, 0x08,
     295,   11,   11,   11, 0x08,
     323,  319,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0n,i\0gotoLine(int,int)\0"
    "bottom\0setEditPos(bool)\0editPosChanged()\0"
    "refresh()\0w,name\0addPanel(QWidget*,QString)\0"
    "newDoc()\0choose()\0save()\0saveAs()\0"
    "about()\0aboutQt()\0openRecentFile()\0"
    "showHelp()\0updateHidden()\0hiddenClicked()\0"
    "messClicked()\0properties()\0setAsterix()\0"
    "warnChanged()\0showHint()\0"
    "setCurrentFile(QString)\0txt\0"
    "setStatus(QString)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->gotoLine((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->setEditPos((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->editPosChanged(); break;
        case 3: _t->refresh(); break;
        case 4: _t->addPanel((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->newDoc(); break;
        case 6: _t->choose(); break;
        case 7: _t->save(); break;
        case 8: _t->saveAs(); break;
        case 9: _t->about(); break;
        case 10: _t->aboutQt(); break;
        case 11: _t->openRecentFile(); break;
        case 12: _t->showHelp(); break;
        case 13: _t->updateHidden(); break;
        case 14: _t->hiddenClicked(); break;
        case 15: _t->messClicked(); break;
        case 16: _t->properties(); break;
        case 17: _t->setAsterix(); break;
        case 18: _t->warnChanged(); break;
        case 19: _t->showHint(); break;
        case 20: _t->setCurrentFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->setStatus((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::gotoLine(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
