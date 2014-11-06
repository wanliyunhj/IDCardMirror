//
//  HJLoopThreadBody.h
//
//  Created by hujin on 14-2-14.
//  Copyright (c) 2014年 HJ. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HJLoopThread.h"

@interface HJLoopThreadBody : NSObject

- (void)runUntilDone:(BOOL)wait bodyBlock:(onWorkThread)bodyBlock;
- (void)stop;
- (void)waitALoop;

@end
