//
//  HJConnection.h
//
//  Created by hujin on 14-2-13.
//  Copyright (c) 2014年 HJ. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HJConnectionBody.h"

typedef void (^didReceiveResponseBlock)(id conn, NSURLResponse * response);
typedef void (^didChangeConnectionProgressBlock)(id conn, NSNumber * progress);
typedef void (^didFinishLoadingBlock)(id conn, id data);
typedef void (^didFailWithErrorBlock)(id conn, NSError * error);

@class HJConnectionPool;
@class HJTimer;

@interface HJConnection : NSObject <HJConnectionBodyDelegate>
{
    HJTimer * timeoutTimer;
    OperationStatus connStatus;
    NSString * connectionTag;
}

@property (nonatomic, strong) id identify;
@property (nonatomic, strong) NSString * connectionTag;
@property (nonatomic, strong) HJConnectionBody * connectionBody;
@property (nonatomic, strong) NSMutableData * connectionData;
@property (nonatomic, strong) NSString * connectionURL;
@property (nonatomic, weak) HJConnectionPool * connectionPool;
@property (nonatomic, assign) NSTimeInterval timeoutInterval;

- (void)start;
- (void)cancel;

- (OperationStatus)queryConnectionStatus;
- (NSString *)getConnectionTag;

- (BOOL)isEqualToConnection:(HJConnection *)connection;
- (void)resetConnectionBody:(HJConnectionBody *)connectionBody;

- (void)runFinishCallback:(id)data;
- (void)runFailCallback:(NSError *)error;

//block接口
- (void)startConnectionWithFinishedBlock:(didFinishLoadingBlock)finishedBlock withFailedBlock:(didFailWithErrorBlock)failedBlock;
- (void)startConnectionWithReceivedDataBlock:(didChangeConnectionProgressBlock)receivedDataBlock withFinishedBlock:(didFinishLoadingBlock)finishedBlock withFailedBlock:(didFailWithErrorBlock)failedBlock;

- (void)startConnectionWithFinishedBlock:(didFinishLoadingBlock)finishedBlock withFailedBlock:(didFailWithErrorBlock)failedBlock inPool:(HJConnectionPool *)pool;
- (void)startConnectionWithReceivedDataBlock:(didChangeConnectionProgressBlock)receivedDataBlock withFinishedBlock:(didFinishLoadingBlock)finishedBlock withFailedBlock:(didFailWithErrorBlock)failedBlock inPool:(HJConnectionPool *)pool;

@end
