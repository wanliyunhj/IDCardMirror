
#import <Foundation/Foundation.h>
#import "HJLoopThread.h"

@interface HJLRUImageCache : NSObject

@property (nonatomic, strong) HJLoopThread * loopThread;

//获取image cache
+(HJLRUImageCache*)sharedInstance;

//init一个cache，可以选择cache大小
+(void)startLRUCache;
+(void)startLRUCacheWithSize:(int)cacheSize;

//可以查看cache内容
-(void)enableLRUCacheLog:(BOOL)enabled;

//清空cache里面的所有内容
-(void)clearCache;

//从cache里面获取一个图片
-(void)loadImage:(NSDictionary *)item;

@end
