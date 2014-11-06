//
//  HJRemoteConfig.h
//  HJRemoteConfig
//
//  Created by 胡瑨 on 14-4-21.
//  Copyright (c) 2014年 HJ. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface HJRemoteConfig : NSObject

@property (nonatomic, strong) NSDictionary * data;

+ (HJRemoteConfig *)sharedInstance;

- (void)startWithURLString:(NSString *)urlString initailDataFile:(NSString *)filepath;

@end
