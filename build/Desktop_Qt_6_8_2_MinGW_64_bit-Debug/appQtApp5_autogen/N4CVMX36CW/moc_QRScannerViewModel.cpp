/****************************************************************************
** Meta object code from reading C++ file 'QRScannerViewModel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../ViewModels/QRScannerViewModel.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QRScannerViewModel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18QRScannerViewModelE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN18QRScannerViewModelE = QtMocHelpers::stringData(
    "QRScannerViewModel",
    "currentDateChanged",
    "",
    "currentTimeChanged",
    "availableCamerasChanged",
    "selectedCameraChanged",
    "isStreamingChanged",
    "isLoadingChanged",
    "cameraErrorOccured",
    "errorMessage",
    "videoSinkChanged",
    "updateDateTime",
    "handleCameraError",
    "error",
    "setSelectedCamera",
    "camera",
    "refreshCameraList",
    "toggleStreaming",
    "setVideoSink",
    "QVideoSink*",
    "videoSink",
    "currentDate",
    "currentTime",
    "availableCameras",
    "selectedCamera",
    "isStreaming",
    "isLoading"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN18QRScannerViewModelE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       7,  120, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x06,    8 /* Public */,
       3,    0,   99,    2, 0x06,    9 /* Public */,
       4,    0,  100,    2, 0x06,   10 /* Public */,
       5,    0,  101,    2, 0x06,   11 /* Public */,
       6,    0,  102,    2, 0x06,   12 /* Public */,
       7,    0,  103,    2, 0x06,   13 /* Public */,
       8,    1,  104,    2, 0x06,   14 /* Public */,
      10,    0,  107,    2, 0x06,   16 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,  108,    2, 0x08,   17 /* Private */,
      12,    1,  109,    2, 0x08,   18 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      14,    1,  112,    2, 0x02,   20 /* Public */,
      16,    0,  115,    2, 0x02,   22 /* Public */,
      17,    0,  116,    2, 0x02,   23 /* Public */,
      18,    1,  117,    2, 0x02,   24 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,

 // properties: name, type, flags, notifyId, revision
      21, QMetaType::QString, 0x00015001, uint(0), 0,
      22, QMetaType::QString, 0x00015001, uint(1), 0,
      23, QMetaType::QStringList, 0x00015001, uint(2), 0,
      24, QMetaType::QString, 0x00015103, uint(3), 0,
      25, QMetaType::Bool, 0x00015001, uint(4), 0,
      26, QMetaType::Bool, 0x00015001, uint(5), 0,
      20, 0x80000000 | 19, 0x0001510b, uint(7), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QRScannerViewModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN18QRScannerViewModelE.offsetsAndSizes,
    qt_meta_data_ZN18QRScannerViewModelE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN18QRScannerViewModelE_t,
        // property 'currentDate'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'currentTime'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'availableCameras'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // property 'selectedCamera'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'isStreaming'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'isLoading'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'videoSink'
        QtPrivate::TypeAndForceComplete<QVideoSink*, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QRScannerViewModel, std::true_type>,
        // method 'currentDateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentTimeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'availableCamerasChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectedCameraChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'isStreamingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'isLoadingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cameraErrorOccured'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'videoSinkChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateDateTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleCameraError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setSelectedCamera'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'refreshCameraList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleStreaming'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setVideoSink'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVideoSink *, std::false_type>
    >,
    nullptr
} };

void QRScannerViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QRScannerViewModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->currentDateChanged(); break;
        case 1: _t->currentTimeChanged(); break;
        case 2: _t->availableCamerasChanged(); break;
        case 3: _t->selectedCameraChanged(); break;
        case 4: _t->isStreamingChanged(); break;
        case 5: _t->isLoadingChanged(); break;
        case 6: _t->cameraErrorOccured((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->videoSinkChanged(); break;
        case 8: _t->updateDateTime(); break;
        case 9: _t->handleCameraError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->setSelectedCamera((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->refreshCameraList(); break;
        case 12: _t->toggleStreaming(); break;
        case 13: _t->setVideoSink((*reinterpret_cast< std::add_pointer_t<QVideoSink*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QVideoSink* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (QRScannerViewModel::*)();
            if (_q_method_type _q_method = &QRScannerViewModel::currentDateChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (QRScannerViewModel::*)();
            if (_q_method_type _q_method = &QRScannerViewModel::currentTimeChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (QRScannerViewModel::*)();
            if (_q_method_type _q_method = &QRScannerViewModel::availableCamerasChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (QRScannerViewModel::*)();
            if (_q_method_type _q_method = &QRScannerViewModel::selectedCameraChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (QRScannerViewModel::*)();
            if (_q_method_type _q_method = &QRScannerViewModel::isStreamingChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (QRScannerViewModel::*)();
            if (_q_method_type _q_method = &QRScannerViewModel::isLoadingChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (QRScannerViewModel::*)(const QString & );
            if (_q_method_type _q_method = &QRScannerViewModel::cameraErrorOccured; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (QRScannerViewModel::*)();
            if (_q_method_type _q_method = &QRScannerViewModel::videoSinkChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVideoSink* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->currentDate(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->currentTime(); break;
        case 2: *reinterpret_cast< QStringList*>(_v) = _t->availableCameras(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->selectedCamera(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->isStreaming(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->isLoading(); break;
        case 6: *reinterpret_cast< QVideoSink**>(_v) = _t->videoSink(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 3: _t->setSelectedCamera(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setVideoSink(*reinterpret_cast< QVideoSink**>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QRScannerViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QRScannerViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN18QRScannerViewModelE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QRScannerViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QRScannerViewModel::currentDateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QRScannerViewModel::currentTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QRScannerViewModel::availableCamerasChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QRScannerViewModel::selectedCameraChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QRScannerViewModel::isStreamingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QRScannerViewModel::isLoadingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QRScannerViewModel::cameraErrorOccured(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QRScannerViewModel::videoSinkChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
