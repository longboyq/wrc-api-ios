#亿连方控车载版 SDK IOS 接入说明

---------------
##目录
[一、简介](#简介)

[二、配置开发环境](#配置开发环境)

[三、SDK接入步骤](#SDK接入步骤)

------------------
<h2 id="简介">一、简介</h2>

亿连方控车载版SDK是一款为第三方应用提供与亿连方控硬件连接的SDK，基于IOS平台，诚邀各开发者与亿连一起建立车生态。当前版本仅支持ios 8.0及以上版本和蓝牙4.0以上的IOS设备。

 **Tips：同一时间只能有一个SDK与亿连方控连接。**


<h2 id="配置开发环境">二、配置开发环境</h2>

在ios工程中加入SDK所需的framework文件，并在项目General选项中添加framework引用，以xcode为例，如下图所示，加入亿连开放平台SDK：

![加入SDK](docs/img/2.jpg)

<h2 id="SDK接入步骤">三、SDK接入步骤</h2>

1、 获得SDK实例：

```objective-c
BLEManager *manager = [BLEManager sharedInstance];
```
添加delegate:
```objective-c
self.manager.delegate = self;
```

2、 检查系统环境是否可用

```objective-c
[self.manager setDeviceStateObserver:^(BlueToothState state) {
}];
```
设置蓝牙设备状态。从回调中可以得到蓝牙是否可用
**Tips：检查IOS版本需要8.0以上，蓝牙4.0。BlueToothState系统是否支持方控**

3、 SDK初始化

```objective-c
[self.manager iniCenterManager:^(BlueToothConnState result, CBPeripheral *peripheral, NSError *error) {
}];
```
初始化管理器，如果有设备已连接则直接回调。

**Tips：确保SDK初始化后才能执行后面的方法。**

4、 开始扫描亿连方控

```objective-c
[self.manager ScanDevice:^(CBPeripheral *peripheral, BlueToothScanState state) {
} uuidFilter:nil];
```
第一个参数为Callback类型，如果扫描成功会返回BlueToothScanState状态

**Tips：可以通过第二个参数uuidFilter过滤亿连方控设备的UUID，只有uuidFilter与申请方控的UUID完全匹配才能扫描到方控并回调到ScanDevice。**

5、 连接亿连方控

```objective-c
    [self.manager connectedWithPeripheral:self.peripheral handler:^(BlueToothConnState result, CBPeripheral *peripheral, NSError *error) {
    }];
```
参数peripheral为ScanDevice方法扫描到的亿连方控设备，第二个参数则是连接是否成功的回调。

6、 判断亿连方控是否连接

```objective-c
self.manager.isConnected
```

7、 断开亿驾方控连接

```objective-c
[self.manager cannelWithPeripheral:peripheral];
```
参数peripheral为需要断开的设备，如果传nil则默认断开当前连接的设备。

8、按键事件回调
```objective-c
-(void)bleKeyDownEvent:(BLEKeyCode)keyCode action:(BLEAction)action
```
连接完成后方控按下会调用该委托。第一个参数keyCode说明当前是什么键，第二隔参数action说明是单击还是长按。

