//
//  HJLoopThread.h
//
//  Created by hujin on 14-2-14.
//  Copyright (c) 2014年 HJ. All rights reserved.
//


#import <Foundation/Foundation.h>

typedef void (^onWorkThread)(void);

@interface HJLoopThread : NSObject

- (void)runUntilDone:(BOOL)wait bodyBlock:(onWorkThread)bodyBlock;
- (void)waitALoop;

@end
