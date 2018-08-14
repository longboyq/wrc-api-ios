//
//  YLFKBlueToothManager.h
//  wrc-sdk-ios
//
//  Created by Tony.Long on 2018/8/2.
//  Copyright © 2018年 Tony.Long. All rights reserved.
//

#import <CoreBluetooth/CoreBluetooth.h>
#import "CBPeripheral+EDrive.h"
#import "YLFKBlueToothControl.h"

// 亿连方控类型
typedef enum{
    YLFKTypeNormal,  //普通亿连方控
    YLFKTypeMini, //亿连方控mini
} YLFKType;

// 蓝牙设备状态
typedef NS_ENUM(NSInteger, BlueToothState) {
    BlueToothStateCannotUse = 0,               // 当前设备蓝牙不可用
    BlueToothStatePoweredOff,                  // 当前设备蓝牙已关闭
    BlueToothStatePoweredOn,                   // 当前设备蓝牙可用
};

// 扫描结果
typedef NS_ENUM(NSInteger, BlueToothScanState) {
    ScanBlueToothStateError = 0,               // 设备状态错误
    ScanTimeout,                               // 10s 后扫描超时
    ScanOK,                                    // 扫描成功
};

// 蓝牙连接状态
typedef NS_ENUM(NSInteger, BlueToothConnState) {
    BlueToothConnStateDisconnect,               //连接断开
    BlueToothConnStateConnectionFailure,        // 连接失败
    BlueToothConnStateConnected,                // 连接成功
};


/**
 *  方控按键代理委托  type返回按键代码
 */
@protocol YLFKBlueToothControlServiceDelegate <NSObject>
@optional
-(void)YLFKBlueToothKeyDownEvent:(BLEKeyCode)keyCode action:(BLEAction)action;
@end

/**
 *  蓝牙设备状态回调
 */
typedef void(^CentralManagerStateHandler)(BlueToothState state);

/**
 *  扫描结果回调
 */
typedef void(^ScanPeripheral)(CBPeripheral *peripheral, BlueToothScanState state);

/**
 *  连接状态监听
 */
typedef void(^ConnectPeripheralHandler)(BlueToothConnState result, CBPeripheral *peripheral, NSError *error);

@interface YLFKBlueToothManager : NSObject
@property(weak, nonatomic)id<YLFKBlueToothControlServiceDelegate> delegate;       // 方控按键代理
@property(nonatomic, assign, readonly)YLFKType ylfkType;               // 方控硬件类型
@property(nonatomic, strong)CBPeripheral *connectedPeripheral;         // 当前连接到的外设

+ (instancetype)sharedInstance;

/**
 *  蓝牙连接管理初始化
 @param handler        连接状态回调
 */
-(void)iniCenterManager:(ConnectPeripheralHandler)handler;

/**
 *  是否已连接设备
 */
-(BOOL)isConnected;

/**
 * BlocK机制来监听中心的状态，只有设备状态为BlueToothStatePoweredOn 才能后面的操作，如扫描，连接等
 */
- (void)setDeviceStateObserver:(CentralManagerStateHandler)handler;

/**
 扫描外设
 
 @param block        回调
 @param uuidFilter   过滤亿连方控设备的UUID
 */
- (void)ScanDevice:(ScanPeripheral)block uuidFilter:(NSArray<NSString *> *) uuidFilter;


/**
 *  停止扫描
 */
- (void) stopScan;

/**
 *  连接设备
 */
- (void)connectedWithPeripheral:(CBPeripheral *)peripheral handler:(ConnectPeripheralHandler)handler;

/**
 *  断开链接
 *
 *  @param peripheral 外设 传nil测断开当前连接的设备
 */
- (void)cannelWithPeripheral:(CBPeripheral *)peripheral;
@end
