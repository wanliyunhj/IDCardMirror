//
//  HJConnectionBodyCore.h
//
//  Created by hujin on 14-2-13.
//  Copyright (c) 2014年 HJ. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HJConnectionBodyCore;

@protocol HJConnectionBodyCoreDelegate <NSObject>

- (void)hjConnectionBodyCore:(HJConnectionBodyCore *)connection didReceiveResponse:(NSURLResponse *)response;
- (void)hjConnectionBodyCore:(HJConnectionBodyCore *)connection didReceiveData:(NSData *)data;
- (void)hjConnectionBodyCore:(HJConnectionBodyCore *)connection didFailWithError:(NSError *)error;
- (void)hjConnectionBodyCoreDidFinishLoading:(HJConnectionBodyCore *)connection;

@end

@interface HJConnectionBodyCore : NSObject <NSURLConnectionDelegate,NSURLConnectionDataDelegate>

- (id)initWithRequestURL:(NSString *)requestURL withDelegate:(id)delegate;
- (id)initWithRequest:(NSURLRequest *)request withDelegate:(id)delegate;
- (void)start;
- (void)stop;

@end
