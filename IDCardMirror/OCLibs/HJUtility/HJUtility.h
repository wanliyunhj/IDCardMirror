//
//  HJUtility.h
//  HJUtility
//
//  Created by 胡瑨 on 14/11/5.
//  Copyright (c) 2014年 HJ. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "HJConnection.h"
#import "HJConnectionPool.h"
#import "HJImageConnection.h"
#import "HJImageLoader.h"

#import "HJLoopThread.h"

#import "HJTimer.h"

#import "HJRemoteConfig.h"

#import "HJToastView.h"

#import "HJCustomAlertBaseView.h"
#import "HJPopupPresentMode.h"

#import "HJVersionControl.h"

#ifdef DEBUG
#define DebugLog(format, ...) NSLog(format, ## __VA_ARGS__)
#else
#define DebugLog(format, ...)
#endif
