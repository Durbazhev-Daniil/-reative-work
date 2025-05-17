/****************************************************************************
** Meta object code from reading C++ file 'webmonitor.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../webmonitor.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webmonitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10WebMonitorE_t {};
} // unnamed namespace

template <> constexpr inline auto WebMonitor::qt_create_metaobjectdata<qt_meta_tag_ZN10WebMonitorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "WebMonitor",
        "parameterValueChanged",
        "",
        "CurrencyType",
        "currency",
        "value",
        "fetchData",
        "processReply",
        "QNetworkReply*",
        "reply"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'parameterValueChanged'
        QtMocHelpers::SignalData<void(CurrencyType, const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QString, 5 },
        }}),
        // Slot 'fetchData'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'processReply'
        QtMocHelpers::SlotData<void(QNetworkReply *)>(7, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<WebMonitor, qt_meta_tag_ZN10WebMonitorE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject WebMonitor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10WebMonitorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10WebMonitorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10WebMonitorE_t>.metaTypes,
    nullptr
} };

void WebMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<WebMonitor *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->parameterValueChanged((*reinterpret_cast< std::add_pointer_t<CurrencyType>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->fetchData(); break;
        case 2: _t->processReply((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (WebMonitor::*)(CurrencyType , const QString & )>(_a, &WebMonitor::parameterValueChanged, 0))
            return;
    }
}

const QMetaObject *WebMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10WebMonitorE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WebMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void WebMonitor::parameterValueChanged(CurrencyType _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}
QT_WARNING_POP
