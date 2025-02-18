/****************************************************************************
** Meta object code from reading C++ file 'QRScannerViewModel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ViewModels/QRScannerViewModel.h"
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
    "qrCodeDataChanged",
    "qrCodeDataLatestChanged",
    "processFrame",
    "QVideoFrame",
    "frame",
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
    "isLoading",
    "qrCodeData",
    "qrCodeDataLatest"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN18QRScannerViewModelE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       9,  143, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x06,   10 /* Public */,
       3,    0,  117,    2, 0x06,   11 /* Public */,
       4,    0,  118,    2, 0x06,   12 /* Public */,
       5,    0,  119,    2, 0x06,   13 /* Public */,
       6,    0,  120,    2, 0x06,   14 /* Public */,
       7,    0,  121,    2, 0x06,   15 /* Public */,
       8,    1,  122,    2, 0x06,   16 /* Public */,
      10,    0,  125,    2, 0x06,   18 /* Public */,
      11,    0,  126,    2, 0x06,   19 /* Public */,
      12,    0,  127,    2, 0x06,   20 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    1,  128,    2, 0x0a,   21 /* Public */,
      16,    0,  131,    2, 0x08,   23 /* Private */,
      17,    1,  132,    2, 0x08,   24 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      19,    1,  135,    2, 0x02,   26 /* Public */,
      21,    0,  138,    2, 0x02,   28 /* Public */,
      22,    0,  139,    2, 0x02,   29 /* Public */,
      23,    1,  140,    2, 0x02,   30 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24,   25,

 // properties: name, type, flags, notifyId, revision
      26, QMetaType::QString, 0x00015001, uint(0), 0,
      27, QMetaType::QString, 0x00015001, uint(1), 0,
      28, QMetaType::QStringList, 0x00015001, uint(2), 0,
      29, QMetaType::QString, 0x00015103, uint(3), 0,
      30, QMetaType::Bool, 0x00015001, uint(4), 0,
      31, QMetaType::Bool, 0x00015001, uint(5), 0,
      25, 0x80000000 | 24, 0x0001510b, uint(7), 0,
      32, QMetaType::QString, 0x00015001, uint(8), 0,
      33, QMetaType::QString, 0x00015001, uint(9), 0,

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
        // property 'qrCodeData'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'qrCodeDataLatest'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
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
        // method 'qrCodeDataChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'qrCodeDataLatestChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVideoFrame &, std::false_type>,
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
        case 8: _t->qrCodeDataChanged(); break;
        case 9: _t->qrCodeDataLatestChanged(); break;
        case 10: _t->processFrame((*reinterpret_cast< std::add_pointer_t<QVideoFrame>>(_a[1]))); break;
        case 11: _t->updateDateTime(); break;
        case 12: _t->handleCameraError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->setSelectedCamera((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->refreshCameraList(); break;
        case 15: _t->toggleStreaming(); break;
        case 16: _t->setVideoSink((*reinterpret_cast< std::add_pointer_t<QVideoSink*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QVideoFrame >(); break;
            }
            break;
        case 16:
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
        {
            using _q_method_type = void (QRScannerViewModel::*)();
            if (_q_method_type _q_method = &QRScannerViewModel::qrCodeDataChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _q_method_type = void (QRScannerViewModel::*)();
            if (_q_method_type _q_method = &QRScannerViewModel::qrCodeDataLatestChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 9;
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
        case 7: *reinterpret_cast< QString*>(_v) = _t->qrCodeData(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->qrCodeDataLatest(); break;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
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

// SIGNAL 8
void QRScannerViewModel::qrCodeDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void QRScannerViewModel::qrCodeDataLatestChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
