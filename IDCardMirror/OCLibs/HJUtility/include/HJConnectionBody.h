//
//  HJConnectionBody.h
//
//  Created by hujin on 14-2-13.
//  Copyright (c) 2014年 HJ. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HJConnectionBodyCore.h"

#define hjConnectionBodyCallBack(targetList, sel, ...) \
NSMutableArray * tempArray = [HJConnectionBody nonRetainingArray]; \
for (id __weak item in targetList) { \
[tempArray addObject:item]; \
} \
for (id __weak target in tempArray) { \
if ([target respondsToSelector:sel]) { \
hjCallBack(target, sel, ## __VA_ARGS__) \
} \
}

#define hjCallBack(target, sel, ...) \
IMP imp = [target methodForSelector:sel]; \
void (*func)(id, SEL, ...) = (void *)imp; \
func(target, sel, ## __VA_ARGS__);

typedef enum {
    OperationStatus_Init,
    OperationStatus_Running,
    OperationStatus_Finished,
    OperationStatus_Failed,
    OperationStatus_Canceled
}OperationStatus;

@class HJConnectionBody;

@protocol HJConnectionBodyDelegate <NSObject>

- (void)hjConnectionBody:(HJConnectionBody *)connection didReceiveData:(NSData *)data;
- (void)hjConnectionBody:(HJConnectionBody *)connection didFailWithError:(NSError *)error;
- (void)hjConnectionBodyDidFinishLoading:(HJConnectionBody *)connection;

@end

@interface HJConnectionBody : NSObject <HJConnectionBodyCoreDelegate>

- (id)initWithRequestURL:(NSString *)requestURL withDelegate:(id)delegate;
- (id)initWithRequest:(NSURLRequest *)request withDelegate:(id)delegate;

- (void)start;
- (void)stopWithHJConnection:(id <HJConnectionBodyDelegate>)connection;

- (void)addHJConnectionToList:(id <HJConnectionBodyDelegate>)connection;

- (OperationStatus)queryConnectionStatus;
- (long long)queryContentLength;

@end
