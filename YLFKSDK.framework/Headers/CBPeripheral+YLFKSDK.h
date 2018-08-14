
#import <CoreBluetooth/CoreBluetooth.h>

@interface CBPeripheral(YLFKSDK)

@property (nonatomic, strong) NSString *macAddress;
@property (nonatomic, strong) NSString *batteryLevel;
@property (nonatomic, strong) NSDate *date;
@end
