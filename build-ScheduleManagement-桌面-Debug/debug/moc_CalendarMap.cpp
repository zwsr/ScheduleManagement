/****************************************************************************
** Meta object code from reading C++ file 'CalendarMap.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ScheduleManagement/CalendarMap.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CalendarMap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CalendarMap[] = {

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
      13,   12,   12,   12, 0x0a,
      27,   12,   12,   12, 0x0a,
      43,   12,   12,   12, 0x0a,
      68,   12,   12,   12, 0x0a,
      83,   12,   12,   12, 0x0a,
     103,   12,   12,   12, 0x0a,
     125,   12,   12,   12, 0x0a,
     144,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CalendarMap[] = {
    "CalendarMap\0\0Day_clicked()\0Month_clicked()\0"
    "SpecifiedMonth_clicked()\0Year_clicked()\0"
    "NextMonth_clicked()\0FowardMonth_clicked()\0"
    "NextYear_clicked()\0FowardYear_clicked()\0"
};

void CalendarMap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CalendarMap *_t = static_cast<CalendarMap *>(_o);
        switch (_id) {
        case 0: _t->Day_clicked(); break;
        case 1: _t->Month_clicked(); break;
        case 2: _t->SpecifiedMonth_clicked(); break;
        case 3: _t->Year_clicked(); break;
        case 4: _t->NextMonth_clicked(); break;
        case 5: _t->FowardMonth_clicked(); break;
        case 6: _t->NextYear_clicked(); break;
        case 7: _t->FowardYear_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CalendarMap::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CalendarMap::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CalendarMap,
      qt_meta_data_CalendarMap, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CalendarMap::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CalendarMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CalendarMap::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CalendarMap))
        return static_cast<void*>(const_cast< CalendarMap*>(this));
    return QWidget::qt_metacast(_clname);
}

int CalendarMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
