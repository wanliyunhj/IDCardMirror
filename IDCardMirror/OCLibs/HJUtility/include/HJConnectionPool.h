//
//  HJConnectionPool.h
//
//  Created by hujin on 14-2-13.
//  Copyright (c) 2014年 HJ. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HJConnection.h"
@interface HJConnectionPool : NSObject{
    int maxWorkListCount;
}

- (id) init;
- (id) initWithWorkListCount:(int)count;//可以自行设置worklist大小，必须>0，才能生效，不设置或者设置<=0，使用默认值10；目前不限制上限

- (void) cleanPool;
- (void) cleanPoolWithTag:(NSString *)tag;

- (void) addConnection:(HJConnection *)connection;
- (void) addConnection:(HJConnection *)connection shouldPrioritize:(BOOL)shouldPrioritize;

- (void) removeConnection:(HJConnection *) connection;

- (NSInteger) queryPoolCount;//获取pool中所有HJConnection的总个数

@end
