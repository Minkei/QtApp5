/****************************************************************************
** Meta object code from reading C++ file 'LoginViewModel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../ViewModels/LoginViewModel.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LoginViewModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
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
struct qt_meta_tag_ZN14LoginViewModelE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN14LoginViewModelE = QtMocHelpers::stringData(
    "LoginViewModel",
    "emailChanged",
    "",
    "passwordChanged",
    "errorMessageChanged",
    "loginSuccess",
    "isLoadingChanged",
    "onLoginSuccess",
    "idToken",
    "onLoginFailed",
    "errorMessage",
    "loginByViewModel",
    "email",
    "password",
    "isLoading"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN14LoginViewModelE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       4,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    5 /* Public */,
       3,    0,   63,    2, 0x06,    6 /* Public */,
       4,    0,   64,    2, 0x06,    7 /* Public */,
       5,    0,   65,    2, 0x06,    8 /* Public */,
       6,    0,   66,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,   67,    2, 0x08,   10 /* Private */,
       9,    1,   70,    2, 0x08,   12 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,   73,    2, 0x02,   14 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,

 // methods: parameters
    QMetaType::Void,

 // properties: name, type, flags, notifyId, revision
      12, QMetaType::QString, 0x00015103, uint(0), 0,
      13, QMetaType::QString, 0x00015103, uint(1), 0,
      10, QMetaType::QString, 0x00015001, uint(2), 0,
      14, QMetaType::Bool, 0x00015001, uint(4), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject LoginViewModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN14LoginViewModelE.offsetsAndSizes,
    qt_meta_data_ZN14LoginViewModelE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN14LoginViewModelE_t,
        // property 'email'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'password'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'errorMessage'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'isLoading'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LoginViewModel, std::true_type>,
        // method 'emailChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'passwordChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'errorMessageChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loginSuccess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'isLoadingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onLoginSuccess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onLoginFailed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'loginByViewModel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void LoginViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<LoginViewModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->emailChanged(); break;
        case 1: _t->passwordChanged(); break;
        case 2: _t->errorMessageChanged(); break;
        case 3: _t->loginSuccess(); break;
        case 4: _t->isLoadingChanged(); break;
        case 5: _t->onLoginSuccess((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->onLoginFailed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->loginByViewModel(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (LoginViewModel::*)();
            if (_q_method_type _q_method = &LoginViewModel::emailChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (LoginViewModel::*)();
            if (_q_method_type _q_method = &LoginViewModel::passwordChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (LoginViewModel::*)();
            if (_q_method_type _q_method = &LoginViewModel::errorMessageChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (LoginViewModel::*)();
            if (_q_method_type _q_method = &LoginViewModel::loginSuccess; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (LoginViewModel::*)();
            if (_q_method_type _q_method = &LoginViewModel::isLoadingChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->email(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->password(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->errorMessage(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->isLoading(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setEmail(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setPassword(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *LoginViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN14LoginViewModelE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LoginViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void LoginViewModel::emailChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LoginViewModel::passwordChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LoginViewModel::errorMessageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void LoginViewModel::loginSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void LoginViewModel::isLoadingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
