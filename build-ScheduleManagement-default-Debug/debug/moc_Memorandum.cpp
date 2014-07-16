/****************************************************************************
** Meta object code from reading C++ file 'Memorandum.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ScheduleManagement/Memorandum.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Memorandum.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Memorandum[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      24,   11,   11,   11, 0x0a,
      39,   11,   11,   11, 0x0a,
      51,   11,   11,   11, 0x0a,
      64,   11,   11,   11, 0x0a,
      81,   11,   11,   11, 0x0a,
      94,   11,   11,   11, 0x0a,
     109,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Memorandum[] = {
    "Memorandum\0\0addMemora()\0submitMemora()\0"
    "cancelAdd()\0nextMemora()\0previousMemora()\0"
    "editMemora()\0removeMemora()\0selectDate()\0"
};

void Memorandum::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Memorandum *_t = static_cast<Memorandum *>(_o);
        switch (_id) {
        case 0: _t->addMemora(); break;
        case 1: _t->submitMemora(); break;
        case 2: _t->cancelAdd(); break;
        case 3: _t->nextMemora(); break;
        case 4: _t->previousMemora(); break;
        case 5: _t->editMemora(); break;
        case 6: _t->removeMemora(); break;
        case 7: _t->selectDate(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Memorandum::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Memorandum::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Memorandum,
      qt_meta_data_Memorandum, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Memorandum::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Memorandum::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Memorandum::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Memorandum))
        return static_cast<void*>(const_cast< Memorandum*>(this));
    return QWidget::qt_metacast(_clname);
}

int Memorandum::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
