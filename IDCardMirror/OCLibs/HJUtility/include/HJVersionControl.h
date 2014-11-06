//
//  HJVersionControl.h
//
//  Created by 胡瑨 on 14-3-11.
//  Copyright (c) 2014年 HJ. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface HJVersionControl : NSObject

//返回当前的启动版本号
@property (nonatomic, strong) NSString *currentLaunchVersion;

//返回app第一次安装后启动的版本号
@property (nonatomic, strong) NSString * firstLaunchVersion;

//返回app上一次启动的版本号
@property (nonatomic, strong) NSString * lastLaunchVersion;

+ (HJVersionControl *)sharedInstance;

- (NSComparisonResult)compareVersionString1:(NSString *)version1 toVersionString2:(NSString *)version2;

- (BOOL)isOSVersionPriorTo:(float)version;

@end
