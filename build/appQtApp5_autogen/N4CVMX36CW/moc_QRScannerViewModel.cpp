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
    "isAudioChanged",
    "qrCodeAdded",
    "QRCodeData",
    "data",
    "qrCodesCleared",
    "qrCodeModelChanged",
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
    "toggleAudio",
    "setVideoSink",
    "QVideoSink*",
    "videoSink",
    "qrCodeModel",
    "clearQRCodes",
    "currentDate",
    "currentTime",
    "availableCameras",
    "selectedCamera",
    "isStreaming",
    "isLoading",
    "qrCodeData",
    "qrCodeDataLatest",
    "isAudio",
    "userModel",
    "UserModel*"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN18QRScannerViewModelE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
      12,  194, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  158,    2, 0x06,   13 /* Public */,
       3,    0,  159,    2, 0x06,   14 /* Public */,
       4,    0,  160,    2, 0x06,   15 /* Public */,
       5,    0,  161,    2, 0x06,   16 /* Public */,
       6,    0,  162,    2, 0x06,   17 /* Public */,
       7,    0,  163,    2, 0x06,   18 /* Public */,
       8,    1,  164,    2, 0x06,   19 /* Public */,
      10,    0,  167,    2, 0x06,   21 /* Public */,
      11,    0,  168,    2, 0x06,   22 /* Public */,
      12,    0,  169,    2, 0x06,   23 /* Public */,
      13,    0,  170,    2, 0x06,   24 /* Public */,
      14,    1,  171,    2, 0x06,   25 /* Public */,
      17,    0,  174,    2, 0x06,   27 /* Public */,
      18,    0,  175,    2, 0x06,   28 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      19,    1,  176,    2, 0x0a,   29 /* Public */,
      22,    0,  179,    2, 0x08,   31 /* Private */,
      23,    1,  180,    2, 0x08,   32 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      25,    1,  183,    2, 0x02,   34 /* Public */,
      27,    0,  186,    2, 0x02,   36 /* Public */,
      28,    0,  187,    2, 0x02,   37 /* Public */,
      29,    0,  188,    2, 0x02,   38 /* Public */,
      30,    1,  189,    2, 0x02,   39 /* Public */,
      33,    0,  192,    2, 0x102,   41 /* Public | MethodIsConst  */,
      34,    0,  193,    2, 0x02,   42 /* Public */,

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
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   24,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::QObjectStar,
    QMetaType::Void,

 // properties: name, type, flags, notifyId, revision
      35, QMetaType::QString, 0x00015001, uint(0), 0,
      36, QMetaType::QString, 0x00015001, uint(1), 0,
      37, QMetaType::QStringList, 0x00015001, uint(2), 0,
      38, QMetaType::QString, 0x00015103, uint(3), 0,
      39, QMetaType::Bool, 0x00015001, uint(4), 0,
      40, QMetaType::Bool, 0x00015001, uint(5), 0,
      32, 0x80000000 | 31, 0x0001510b, uint(7), 0,
      41, QMetaType::QString, 0x00015001, uint(8), 0,
      42, QMetaType::QString, 0x00015001, uint(9), 0,
      33, QMetaType::QObjectStar, 0x00015001, uint(13), 0,
      43, QMetaType::Bool, 0x00015001, uint(10), 0,
      44, 0x80000000 | 45, 0x00015409, uint(-1), 0,

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
        // property 'qrCodeModel'
        QtPrivate::TypeAndForceComplete<QObject*, std::true_type>,
        // property 'isAudio'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'userModel'
        QtPrivate::TypeAndForceComplete<UserModel*, std::true_type>,
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
        // method 'isAudioChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'qrCodeAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QRCodeData &, std::false_type>,
        // method 'qrCodesCleared'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'qrCodeModelChanged'
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
        // method 'toggleAudio'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setVideoSink'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVideoSink *, std::false_type>,
        // method 'qrCodeModel'
        QtPrivate::TypeAndForceComplete<QObject *, std::false_type>,
        // method 'clearQRCodes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
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
        case 10: _t->isAudioChanged(); break;
        case 11: _t->qrCodeAdded((*reinterpret_cast< std::add_pointer_t<QRCodeData>>(_a[1]))); break;
        case 12: _t->qrCodesCleared(); break;
        case 13: _t->qrCodeModelChanged(); break;
        case 14: _t->processFrame((*reinterpret_cast< std::add_pointer_t<QVideoFrame>>(_a[1]))); break;
        case 15: _t->updateDateTime(); break;
        case 16: _t->handleCameraError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->setSelectedCamera((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->refreshCameraList(); break;
        case 19: _t->toggleStreaming(); break;
        case 20: _t->toggleAudio(); break;
        case 21: _t->setVideoSink((*reinterpret_cast< std::add_pointer_t<QVideoSink*>>(_a[1]))); break;
        case 22: { QObject* _r = _t->qrCodeModel();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 23: _t->clearQRCodes(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QVideoFrame >(); break;
            }
            break;
        case 21:
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
        {
            using _q_method_type = void (QRScannerViewModel::*)();
            if (_q_method_type _q_method = &QRScannerViewModel::isAudioChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _q_method_type = void (QRScannerViewModel::*)(const QRCodeData & );
            if (_q_method_type _q_method = &QRScannerViewModel::qrCodeAdded; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _q_method_type = void (QRScannerViewModel::*)();
            if (_q_method_type _q_method = &QRScannerViewModel::qrCodesCleared; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _q_method_type = void (QRScannerViewModel::*)();
            if (_q_method_type _q_method = &QRScannerViewModel::qrCodeModelChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVideoSink* >(); break;
        case 11:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< UserModel* >(); break;
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
        case 9: *reinterpret_cast< QObject**>(_v) = _t->qrCodeModel(); break;
        case 10: *reinterpret_cast< bool*>(_v) = _t->isAudio(); break;
        case 11: *reinterpret_cast< UserModel**>(_v) = _t->userModel(); break;
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
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
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

// SIGNAL 10
void QRScannerViewModel::isAudioChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void QRScannerViewModel::qrCodeAdded(const QRCodeData & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void QRScannerViewModel::qrCodesCleared()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void QRScannerViewModel::qrCodeModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}
QT_WARNING_POP
