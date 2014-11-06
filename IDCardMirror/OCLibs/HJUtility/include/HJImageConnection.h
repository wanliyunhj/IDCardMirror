//
//  HJImageConnection.h
//
//  Created by hujin on 14-2-14.
//  Copyright (c) 2014年 HJ. All rights reserved.
//

#import "HJConnection.h"

@interface HJImageConnection : HJConnection

//如果本地存在该图片，则返回NO；否则返回YES
- (BOOL)constructImageConnWithURL:(NSString *)imageURL withLocalPath:(NSString *)lp;

@end
