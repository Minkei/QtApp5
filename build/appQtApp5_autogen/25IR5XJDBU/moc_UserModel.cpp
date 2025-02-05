/****************************************************************************
** Meta object code from reading C++ file 'UserModel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Models/UserModel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UserModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
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
struct qt_meta_tag_ZN9UserModelE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN9UserModelE = QtMocHelpers::stringData(
    "UserModel",
    "emailChanged",
    "",
    "displayNameChanged",
    "photoUrlChanged",
    "emailVerifiedChanged",
    "idTokenChanged",
    "localIdChanged",
    "setEmail",
    "email",
    "setDisplayName",
    "displayName",
    "setPhotoUrl",
    "photoUrl",
    "setEmailVerified",
    "emailVerified",
    "setIdToken",
    "idToken",
    "setLocalId",
    "localId",
    "updateFromJson",
    "jsonObject",
    "clearUserData",
    "saveToSetting",
    "loadFromSetting"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN9UserModelE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       6,  140, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x06,    7 /* Public */,
       3,    0,  111,    2, 0x06,    8 /* Public */,
       4,    0,  112,    2, 0x06,    9 /* Public */,
       5,    0,  113,    2, 0x06,   10 /* Public */,
       6,    0,  114,    2, 0x06,   11 /* Public */,
       7,    0,  115,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,  116,    2, 0x0a,   13 /* Public */,
      10,    1,  119,    2, 0x0a,   15 /* Public */,
      12,    1,  122,    2, 0x0a,   17 /* Public */,
      14,    1,  125,    2, 0x0a,   19 /* Public */,
      16,    1,  128,    2, 0x0a,   21 /* Public */,
      18,    1,  131,    2, 0x0a,   23 /* Public */,
      20,    1,  134,    2, 0x0a,   25 /* Public */,
      22,    0,  137,    2, 0x0a,   27 /* Public */,
      23,    0,  138,    2, 0x0a,   28 /* Public */,
      24,    0,  139,    2, 0x0a,   29 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QJsonObject,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags, notifyId, revision
       9, QMetaType::QString, 0x00015103, uint(0), 0,
      11, QMetaType::QString, 0x00015103, uint(1), 0,
      13, QMetaType::QString, 0x00015103, uint(2), 0,
      15, QMetaType::Bool, 0x00015103, uint(3), 0,
      17, QMetaType::QString, 0x00015103, uint(4), 0,
      19, QMetaType::QString, 0x00015103, uint(5), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject UserModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN9UserModelE.offsetsAndSizes,
    qt_meta_data_ZN9UserModelE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN9UserModelE_t,
        // property 'email'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'displayName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'photoUrl'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'emailVerified'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'idToken'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'localId'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UserModel, std::true_type>,
        // method 'emailChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'displayNameChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'photoUrlChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'emailVerifiedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'idTokenChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'localIdChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setEmail'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setDisplayName'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setPhotoUrl'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setEmailVerified'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setIdToken'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setLocalId'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'updateFromJson'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'clearUserData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveToSetting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadFromSetting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void UserModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<UserModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->emailChanged(); break;
        case 1: _t->displayNameChanged(); break;
        case 2: _t->photoUrlChanged(); break;
        case 3: _t->emailVerifiedChanged(); break;
        case 4: _t->idTokenChanged(); break;
        case 5: _t->localIdChanged(); break;
        case 6: _t->setEmail((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->setDisplayName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->setPhotoUrl((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->setEmailVerified((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->setIdToken((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->setLocalId((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->updateFromJson((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 13: _t->clearUserData(); break;
        case 14: _t->saveToSetting(); break;
        case 15: _t->loadFromSetting(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (UserModel::*)();
            if (_q_method_type _q_method = &UserModel::emailChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (UserModel::*)();
            if (_q_method_type _q_method = &UserModel::displayNameChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (UserModel::*)();
            if (_q_method_type _q_method = &UserModel::photoUrlChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (UserModel::*)();
            if (_q_method_type _q_method = &UserModel::emailVerifiedChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (UserModel::*)();
            if (_q_method_type _q_method = &UserModel::idTokenChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (UserModel::*)();
            if (_q_method_type _q_method = &UserModel::localIdChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->email(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->displayName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->photoUrl(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->emailVerified(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->idToken(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->localId(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setEmail(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setDisplayName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setPhotoUrl(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setEmailVerified(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setIdToken(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setLocalId(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *UserModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN9UserModelE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UserModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void UserModel::emailChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void UserModel::displayNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void UserModel::photoUrlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void UserModel::emailVerifiedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void UserModel::idTokenChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void UserModel::localIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
