/****************************************************************************
** Meta object code from reading C++ file 'text_pnl.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "text_pnl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'text_pnl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TextPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   11,   10,   10, 0x05,
      37,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   56,   10,   10, 0x0a,
      80,   10,   10,   10, 0x2a,
      96,   10,   10,   10, 0x0a,
     129,  117,   10,   10, 0x0a,
     155,  151,   10,   10, 0x2a,
     172,   10,   10,   10, 0x0a,
     195,   10,   10,   10, 0x0a,
     208,   10,   10,   10, 0x0a,
     219,   10,   10,   10, 0x0a,
     229,   10,   10,   10, 0x0a,
     239,   10,   10,   10, 0x0a,
     249,   10,   10,   10, 0x0a,
     259,   10,   10,   10, 0x0a,
     271,  269,   10,   10, 0x0a,
     283,   10,   10,   10, 0x2a,
     292,   10,   10,   10, 0x0a,
     303,   10,   10,   10, 0x0a,
     317,   10,   10,   10, 0x0a,
     329,   10,   10,   10, 0x0a,
     351,  341,  336,   10, 0x0a,
     386,  379,  336,   10, 0x2a,
     413,  409,  336,   10, 0x2a,
     431,   10,  336,   10, 0x2a,
     456,  442,   10,   10, 0x0a,
     503,  492,   10,   10, 0x2a,
     542,  534,   10,   10, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_TextPanel[] = {
    "TextPanel\0\0s\0setCurrentFile(QString)\0"
    "setStatus(QString)\0f\0setEditorFont(QFont*)\0"
    "setEditorFont()\0animPutText(QString)\0"
    "txt,replace\0putLine(QString,bool)\0txt\0"
    "putLine(QString)\0setCursorPosition(int)\0"
    "addOptions()\0addStyle()\0insNVal()\0"
    "insFile()\0insPath()\0insFitF()\0insPrim()\0"
    "n\0newCmd(int)\0newCmd()\0addSetup()\0"
    "refreshData()\0printText()\0find()\0bool\0"
    "str,cs,fw\0findText(QString,bool,bool)\0"
    "str,cs\0findText(QString,bool)\0str\0"
    "findText(QString)\0findText()\0str,txt,cs,fw\0"
    "replText(QString,QString,bool,bool)\0"
    "str,txt,cs\0replText(QString,QString,bool)\0"
    "str,txt\0replText(QString,QString)\0"
};

void TextPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TextPanel *_t = static_cast<TextPanel *>(_o);
        switch (_id) {
        case 0: _t->setCurrentFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setStatus((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setEditorFont((*reinterpret_cast< QFont*(*)>(_a[1]))); break;
        case 3: _t->setEditorFont(); break;
        case 4: _t->animPutText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->putLine((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->putLine((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->setCursorPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->addOptions(); break;
        case 9: _t->addStyle(); break;
        case 10: _t->insNVal(); break;
        case 11: _t->insFile(); break;
        case 12: _t->insPath(); break;
        case 13: _t->insFitF(); break;
        case 14: _t->insPrim(); break;
        case 15: _t->newCmd((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->newCmd(); break;
        case 17: _t->addSetup(); break;
        case 18: _t->refreshData(); break;
        case 19: _t->printText(); break;
        case 20: _t->find(); break;
        case 21: { bool _r = _t->findText((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 22: { bool _r = _t->findText((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 23: { bool _r = _t->findText((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 24: { bool _r = _t->findText();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 25: _t->replText((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 26: _t->replText((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 27: _t->replText((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TextPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TextPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TextPanel,
      qt_meta_data_TextPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TextPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TextPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TextPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TextPanel))
        return static_cast<void*>(const_cast< TextPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int TextPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void TextPanel::setCurrentFile(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TextPanel::setStatus(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
