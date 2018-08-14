
#import <CoreBluetooth/CoreBluetooth.h>

@interface CBPeripheral(EDrive)

@property (nonatomic, strong) NSString *macAddress;
@property (nonatomic, strong) NSString *batteryLevel;
@property (nonatomic, strong) NSDate *date;
@end
