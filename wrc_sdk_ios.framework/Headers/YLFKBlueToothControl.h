//
//  YLFKBlueToothControl.h
//  testwrc
//
//  Created by Tony.Long on 2018/8/8.
//  Copyright © 2018年 Tony.Long. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_OPTIONS(NSInteger, BLEKeyCode) {
    KEY_CENTER = 0,            //中间键
    KEY_LEFT_UP = 1,           //左上键
    KEY_LEFT_DOWN = 2,         //左下键
    KEY_RIGHT_UP = 3,          //右上键
    KEY_RIGHT_DOWN = 4,        //右下键
    KEY_MINI_UP = 41,          //方控mini上键
    KEY_MINI_CENTER = 42,      //方控mini中键
    KEY_MINI_DOWN = 43,        //方控mini下键
};

typedef NS_OPTIONS(NSInteger, BLEAction) {
    ACTION_SINGLE_CLICK = 0,            //单击
    ACTION_LONG_PRESSED = 1,            //长按
};

@interface YLFKBlueToothControl : NSObject

@end
